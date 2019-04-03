/******************************************************************************/
/*                                                                            */
/*    ODYSSEUS/EduCOSMOS Educational-Purpose Object Storage System            */
/*                                                                            */
/*    Developed by Professor Kyu-Young Whang et al.                           */
/*                                                                            */
/*    Database and Multimedia Laboratory                                      */
/*                                                                            */
/*    Computer Science Department and                                         */
/*    Advanced Information Technology Research Center (AITrc)                 */
/*    Korea Advanced Institute of Science and Technology (KAIST)              */
/*                                                                            */
/*    e-mail: kywhang@cs.kaist.ac.kr                                          */
/*    phone: +82-42-350-7722                                                  */
/*    fax: +82-42-350-8380                                                    */
/*                                                                            */
/*    Copyright (c) 1995-2013 by Kyu-Young Whang                              */
/*                                                                            */
/*    All rights reserved. No part of this software may be reproduced,        */
/*    stored in a retrieval system, or transmitted, in any form or by any     */
/*    means, electronic, mechanical, photocopying, recording, or otherwise,   */
/*    without prior written permission of the copyright owner.                */
/*                                                                            */
/******************************************************************************/
/*
 * Module : EduOM_CreateObject.c
 * 
 * Description :
 *  EduOM_CreateObject() creates a new object near the specified object.
 *
 * Exports:
 *  Four EduOM_CreateObject(ObjectID*, ObjectID*, ObjectHdr*, Four, char*, ObjectID*)
 */

#include <string.h>
#include "EduOM_common.h"
#include "RDsM.h"		/* for the raw disk manager call */
#include "BfM.h"		/* for the buffer manager call */
#include "EduOM_Internal.h"

/*@================================
 * EduOM_CreateObject()
 *================================*/
/*
 * Function: Four EduOM_CreateObject(ObjectID*, ObjectID*, ObjectHdr*, Four, char*, ObjectID*)
 * 
 * Description :
 * (Following description is for original ODYSSEUS/COSMOS OM.
 *  For ODYSSEUS/EduCOSMOS EduOM, refer to the EduOM project manual.)
 *
 * (1) What to do?
 * EduOM_CreateObject() creates a new object near the specified object.
 * If there is no room in the page holding the specified object,
 * it trys to insert into the page in the available space list. If fail, then
 * the new object will be put into the newly allocated page.
 *
 * (2) How to do?
 *	a. Read in the near slotted page
 *	b. See the object header
 *	c. IF large object THEN
 *	       call the large object manager's lom_ReadObject()
 *	   ELSE 
 *		   IF moved object THEN 
 *				call this function recursively
 *		   ELSE 
 *				copy the data into the buffer
 *		   ENDIF
 *	   ENDIF
 *	d. Free the buffer page
 *	e. Return
 *
 * Returns:
 *  error code
 *    eBADCATALOGOBJECT_OM
 *    eBADLENGTH_OM
 *    eBADUSERBUF_OM
 *    some error codes from the lower level
 *
 * Side Effects :
 *  0) A new object is created.
 *  1) parameter oid
 *     'oid' is set to the ObjectID of the newly created object.
 */
Four EduOM_CreateObject(
    ObjectID  *catObjForFile,	/* IN file in which object is to be placed */
    ObjectID  *nearObj,		/* IN create the new object near this object */
    ObjectHdr *objHdr,		/* IN from which tag is to be set */
    Four      length,		/* IN amount of data */
    char      *data,		/* IN the initial data for the object */
    ObjectID  *oid)		/* OUT the object's ObjectID */
{
    Four        e;		/* error number */
    ObjectHdr   objectHdr;	/* ObjectHdr with tag set from parameter */


    /*@ parameter checking */
    
    if (catObjForFile == NULL) ERR(eBADCATALOGOBJECT_OM);
    
    if (length < 0) ERR(eBADLENGTH_OM);

    if (length > 0 && data == NULL) return(eBADUSERBUF_OM);

	/* Error check whether using not supported functionality by EduOM */
	if(ALIGNED_LENGTH(length) > LRGOBJ_THRESHOLD) ERR(eNOTSUPPORTED_EDUOM);
    
    // Initialize header
    objectHdr.length = 0;
    objectHdr.properties = 0x0;
    if(objHdr != NULL) {
        objectHdr.tag = objHdr->tag;
    }
    else {
        objectHdr.tag = 0;
    }

    e = eduom_CreateObject(
        catObjForFile,
        nearObj,
        &objectHdr,
        length,
        data,
        oid
    );
    if(e) ERR(e);
    
    return(eNOERROR);
}

/*@================================
 * eduom_CreateObject()
 *================================*/
/*
 * Function: Four eduom_CreateObject(ObjectID*, ObjectID*, ObjectHdr*, Four, char*, ObjectID*)
 *
 * Description :
 * (Following description is for original ODYSSEUS/COSMOS OM.
 *  For ODYSSEUS/EduCOSMOS EduOM, refer to the EduOM project manual.)
 *
 *  eduom_CreateObject() creates a new object near the specified object; the near
 *  page is the page holding the near object.
 *  If there is no room in the near page and the near object 'nearObj' is not
 *  NULL, a new page is allocated for object creation (In this case, the newly
 *  allocated page is inserted after the near page in the list of pages
 *  consiting in the file).
 *  If there is no room in the near page and the near object 'nearObj' is NULL,
 *  it trys to create a new object in the page in the available space list. If
 *  fail, then the new object will be put into the newly allocated page(In this
 *  case, the newly allocated page is appended at the tail of the list of pages
 *  cosisting in the file).
 *
 * Returns:
 *  error Code
 *    eBADCATALOGOBJECT_OM
 *    eBADOBJECTID_OM
 *    some errors caused by fuction calls
 */
Four eduom_CreateObject(
                        ObjectID	*catObjForFile,	/* IN file in which object is to be placed */
                        ObjectID 	*nearObj,	/* IN create the new object near this object */
                        ObjectHdr	*objHdr,	/* IN from which tag & properties are set */
                        Four	length,		/* IN amount of data */
                        char	*data,		/* IN the initial data for the object */
                        ObjectID	*oid)		/* OUT the object's ObjectID */
{
    Four        e;		/* error number */
    Four	neededSpace;	/* space needed to put new object [+ header] */
    SlottedPage *apage;		/* pointer to the slotted page buffer */
    Four        alignedLen;	/* aligned length of initial data */
    Boolean     needToAllocPage;/* Is there a need to alloc a new page? */
    PageID      pid;            /* PageID in which new object to be inserted */
    PageID      nearPid;
    Four        firstExt;	/* first Extent No of the file */
    Object      *obj;		/* point to the newly created object */
    Two         i;		/* index variable */
    sm_CatOverlayForData *catEntry; /* pointer to data file catalog information */
    SlottedPage *catPage;	/* pointer to buffer containing the catalog */
    FileID      fid;		/* ID of file where the new object is placed */
    Two         eff;		/* extent fill factor of file */
    Boolean     isTmp;
    PhysicalFileID pFid;
    
    
    /*@ parameter checking */
    
    if (catObjForFile == NULL) ERR(eBADCATALOGOBJECT_OM);
    
    if (objHdr == NULL) ERR(eBADOBJECTID_OM);
    
    /* Error check whether using not supported functionality by EduOM */
    if(ALIGNED_LENGTH(length) > LRGOBJ_THRESHOLD) ERR(eNOTSUPPORTED_EDUOM);
    

    MAKE_PHYSICALFILEID(pFid, catObjForFile->volNo, catObjForFile->pageNo);
    e = BfM_GetTrain(&pFid, &catPage, PAGE_BUF);
    if(e) ERR(e);
    GET_PTR_TO_CATENTRY_FOR_DATA(catObjForFile, catPage, catEntry);

    alignedLen = ALIGNED_LENGTH(length);
    neededSpace = sizeof(ObjectHdr) + alignedLen + sizeof(SlottedPageSlot);

    // Determine the page to insert
    if(nearObj != NULL) {
        MAKE_PAGEID(nearPid, nearObj->volNo, nearObj->pageNo);
        e = BfM_GetTrain(&nearPid, &apage, PAGE_BUF);
        if(e) ERRB1(e, &pFid, PAGE_BUF);

        // If page with nearObj has enough space
        if(neededSpace <= SP_FREE(apage)) {
            pid = nearPid;
            needToAllocPage = FALSE;
            e = om_RemoveFromAvailSpaceList(catObjForFile, &nearPid, apage);
            if(e) ERRB1(e, &nearPid, PAGE_BUF);
        }
        else {
            needToAllocPage = TRUE;
        }
    }
    else {
        // Check availspaceList
        fid = catEntry->fid;
        MAKE_PAGEID(pid, fid.volNo, NIL);

        if(neededSpace <= SP_10SIZE && catEntry->availSpaceList10 != NIL) {
            pid.pageNo = catEntry->availSpaceList10;
        }
        else if(neededSpace <= SP_20SIZE && catEntry->availSpaceList20 != NIL) {
            pid.pageNo = catEntry->availSpaceList20;
        }
        else if(neededSpace <= SP_30SIZE && catEntry->availSpaceList30 != NIL) {
            pid.pageNo = catEntry->availSpaceList30;
        }
        else if(neededSpace <= SP_40SIZE && catEntry->availSpaceList40 != NIL) {
            pid.pageNo = catEntry->availSpaceList40;
        }
        else if(neededSpace <= SP_50SIZE && catEntry->availSpaceList50 != NIL) {
            pid.pageNo = catEntry->availSpaceList50;
            printf("aaaaa\n");
        }

        if(pid.pageNo != NIL) {
            needToAllocPage = FALSE;

            e = BfM_GetTrain(&pid, &apage, PAGE_BUF);
            if(e) ERRB1(e, &catPage, PAGE_BUF);
            e = om_RemoveFromAvailSpaceList(catObjForFile, &pid, apage);
            if(e) ERRB1(e, &catPage, PAGE_BUF);
        }
        else {
            // Check last page of file for space
            pid.pageNo = catEntry->lastPage;
            e = BfM_GetTrain(&pid, &apage, PAGE_BUF);
            if(e) ERRB1(e, &catPage, PAGE_BUF);

            if(neededSpace <= SP_FREE(apage)) {
                needToAllocPage = FALSE;
            }
            else {
                needToAllocPage = TRUE;
            }
            
        }
    }

    // Allocate a new page if necessary
    if(needToAllocPage) {


        if(nearObj != NULL) {

        }
        else {

        }
    }

    // Compact page if necessary
    if(neededSpace > SP_CFREE(apage)) {
        e = EduOM_CompactPage(apage, NIL);
        if(e) ERRB1(e, &nearPid, PAGE_BUF);
    }

    // Insert object to page
    i = 0;
    while(i < apage->header.nSlots) {
        if(apage->slot[-i].offset == EMPTYSLOT) {
            break;
        }
        i++;
    }
    if(i == apage->header.nSlots) {
        apage->header.nSlots++;
    }
    
    apage->slot[-i].offset = apage->header.free;
    obj = &(apage->data[apage->slot[-i].offset]);
    obj->header.length = length;
    obj->header.properties = 0x0;
    memcpy(obj->data, data, length);

    apage->header.free += sizeof(ObjectHdr) + alignedLen;

    om_PutInAvailSpaceList(catObjForFile, &pid, apage);

    oid->pageNo = pid.pageNo;
    oid->volNo = pid.volNo;
    oid->slotNo = i;
    om_GetUnique(&pid, &oid->unique);

    // Free resources
    BfM_FreeTrain(&pid, PAGE_BUF);
    BfM_FreeTrain(&pFid, PAGE_BUF);
    if(nearObj != NIL && needToAllocPage) {
        BfM_FreeTrain(&nearPid, PAGE_BUF);
    }

    return(eNOERROR);
    
} /* eduom_CreateObject() */
