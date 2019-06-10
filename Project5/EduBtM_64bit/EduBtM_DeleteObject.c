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
 * Module: EduBtM_DeleteObject.c
 *
 * Description : 
 *  Delete from a B+tree an ObjectID 'oid' whose key value is given by "kval".
 *
 * Exports:
 *  Four EduBtM_DeleteObject(ObjectID*, PageID*, KeyDesc*, KeyValue*, ObjectID*)
 */


#include "EduBtM_common.h"
#include "BfM.h"
#include "OM_Internal.h"
#include "EduBtM_Internal.h"



/*@================================
 * EduBtM_DeleteObject()
 *================================*/
/*
 * Function: Four EduBtM_DeleteObject(ObjectID*, PageID*, KeyDesc*, KeyValue*, ObjectID*)
 *
 * Description : 
 * (Following description is for original ODYSSEUS/COSMOS BtM.
 *  For ODYSSEUS/EduCOSMOS EduBtM, refer to the EduBtM project manual.)
 *
 *  Delete from a B+tree an ObjectID 'oid' whose key value is given by "kval".
 *  The B+tree' is specified by the root PageID 'root' and its key descriptor
 *  'kdesc'.
 *
 *  Deleting an ObjectID causes redistributing internal pages or moving
 *  ObjectIDs in an overflow page to a leaf page. By this reason, the page
 *  may be splitted in spite of deleting. In this case, it is used the 'lh'
 *  flag and an internal item as similar to inserting.
 *
 * Returns:
 *  error code
 *    eBADPARAMETER_BTM
 *    some errors caused by fucntion calls
 */
Four EduBtM_DeleteObject(
    ObjectID *catObjForFile,	/* IN catalog object of B+-tree file */
    PageID   *root,		/* IN root Page IDentifier */
    KeyDesc  *kdesc,		/* IN a key descriptor */
    KeyValue *kval,		/* IN key value */
    ObjectID *oid,		/* IN Object IDentifier */
    Pool     *dlPool,		/* INOUT pool of dealloc list elements */
    DeallocListElem *dlHead) /* INOUT head of the dealloc list */
{
    int		i;
    Four    e;			/* error number */
    Boolean lf;			/* flag for merging */
    Boolean lh;			/* flag for splitting */
    InternalItem item;		/* Internal item */
    SlottedPage *catPage;	/* buffer page containing the catalog object */
    sm_CatOverlayForBtree *catEntry; /* pointer to Btree file catalog information */
    PhysicalFileID pFid;        /* B+-tree file's FileID */


    /*@ check parameters */
    if (catObjForFile == NULL) ERR(eBADPARAMETER_BTM);

    if (root == NULL) ERR(eBADPARAMETER_BTM);

    if (kdesc == NULL) ERR(eBADPARAMETER_BTM);

    if (kval == NULL) ERR(eBADPARAMETER_BTM);

    if (oid == NULL) ERR(eBADPARAMETER_BTM);
    
    if (dlPool == NULL || dlHead == NULL) ERR(eBADPARAMETER_BTM);

    /* Error check whether using not supported functionality by EduBtM */
    for(i=0; i<kdesc->nparts; i++)
    {
        if(kdesc->kpart[i].type!=SM_INT && kdesc->kpart[i].type!=SM_VARSTRING)
            ERR(eNOTSUPPORTED_EDUBTM);
    }


	/* Delete following 3 lines before implement this function */
	printf("Implementation of delete operation is optional (not compulsory),\n");
	printf("and delete operation has not been implemented yet.\n");
	return(eNOTSUPPORTED_EDUBTM);

    
    return(eNOERROR);
    
}   /* EduBtM_DeleteObject() */
