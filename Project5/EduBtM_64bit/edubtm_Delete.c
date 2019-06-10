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
 * Module: edubtm_Delete.c
 *
 * Description : 
 *  This function edubtm_Delete(...) recursively calls itself until the type
 *  of root page becomes LEAF.  If the root page is an internal page, it
 *  may get the proper child page using the binary search routine and then
 *  recursively calls itself using the child as a root page. If the filled
 *  area of the child page is less than half of the page, it should merge
 *  or redistribute using the given root, and set the flag 'f' according to
 *  the result status of the given root page.
 *
 *  If the root page is a leaf page , it find out the correct node (entry)
 *  using the binary search routine.  If the entry is normal,  it simply
 *  delete the ObjectID or the entry when the # of ObjectIDs becomes zero.
 *  The entry, however, is not normal, that is, if the overflow page is used,
 *  the special routine btm_DeleteOverflow(...) should be called. The # of
 *  ObjectIDs will be returned by the result of the btm_DeleteOverflow(...),
 *  if the total # of ObjectIDs is less than 1/4 of the page and the ObjectIDs
 *  in the overflow page should be moved to the leaf page. (This process may
 *  has a complicate problem which the leaf page may be splitted in spite of
 *  deleteing not inserting an ObjectID.)
 *
 *  Deleting an ObjectID may cause redistribute pages and by this reason, the
 *  page may be splitted.
 *
 * Exports:
 *  Four edubtm_Delete(ObjectID*, PageID*, KeyDesc*, KeyValue*, ObjectID*,
 *                  Boolean*, Boolean*, InternalItem*, Pool*, DeallocListElem*)
 *
 */


#include <string.h>
#include "EduBtM_common.h"
#include "Util.h"
#include "BfM.h"
#include "OM_Internal.h"	/* for "SlottedPage" including catalog object */
#include "EduBtM_Internal.h"


/*@ Internal Function Prototypes */
Four edubtm_DeleteLeaf(PhysicalFileID*, PageID*, BtreeLeaf*, KeyDesc*, KeyValue*, ObjectID*,
		    Boolean*, Boolean*, InternalItem*, Pool*, DeallocListElem*);



/*@================================
 * edubtm_Delete()
 *================================*/
/*
 * Function: Four edubtm_Delete(ObjectID*, PageID*, KeyDesc*, KeyValue*,
 *                           ObjectID*, Boolean*, Boolean*, InternalItem*)
 *
 * Description:
 * (Following description is for original ODYSSEUS/COSMOS BtM.
 *  For ODYSSEUS/EduCOSMOS EduBtM, refer to the EduBtM project manual.)
 *
 *
 * Returns:
 *  error code
 *    eBADBTREEPAGE_BTM
 *    some errors caused by function calls
 *
 * Side effects:
 *  f    : TRUE if the given root page is not half full.
 *  h    : TRUE if the given page is splitted.
 *  item : The internal item to be inserted into the parent if 'h' is TRUE.
 */
Four edubtm_Delete(
    ObjectID                    *catObjForFile, /* IN catalog object of B+ tree file */
    PageID                      *root,          /* IN root page */
    KeyDesc                     *kdesc,         /* IN a key descriptor */
    KeyValue                    *kval,          /* IN key value */
    ObjectID                    *oid,           /* IN Object IDentifier which will be deleted */
    Boolean                     *f,             /* OUT whether the root page is half full */
    Boolean                     *h,             /* OUT TRUE if it is spiltted. */
    InternalItem                *item,          /* OUT The internal item to be returned */
    Pool                        *dlPool,        /* INOUT pool of dealloc list elements */
    DeallocListElem             *dlHead)        /* INOUT head of the dealloc list */
{
    Four                        e;              /* error number */
    Boolean                     lf;             /* TRUE if a page is not half full */
    Boolean                     lh;             /* TRUE if a page is splitted */
    Two                         idx;            /* the index by the binary search */
    PageID                      child;          /* a child page when the root is an internal page */
    KeyValue                    tKey;           /* a temporary key */
    BtreePage                   *rpage;         /* for a root page */
    InternalItem                litem;          /* local internal item */
    btm_InternalEntry           *iEntry;        /* an internal entry */
    SlottedPage                 *catPage;       /* buffer page containing the catalog object */
    sm_CatOverlayForBtree       *catEntry;      /* pointer to Btree file catalog information */
    PhysicalFileID              pFid;           /* B+-tree file's FileID */
  

    /* Error check whether using not supported functionality by EduBtM */
	int i;
    for(i=0; i<kdesc->nparts; i++)
    {
        if(kdesc->kpart[i].type!=SM_INT && kdesc->kpart[i].type!=SM_VARSTRING)
            ERR(eNOTSUPPORTED_EDUBTM);
    }

        
    *h = *f = FALSE;
    
    
    /* Delete following 2 lines before implement this function */
    printf("Implementation of delete operation is optional (not compulsory),\n");
    printf("and delete operation has not been implemented yet.\n");


    return(eNOERROR);
    
}   /* edubtm_Delete() */



/*@================================
 * edubtm_DeleteLeaf()
 *================================*/
/*
 * Function: Four edubtm_DeleteLeaf(PhysicalFileID*, PageID*, BtreeLeaf*, KeyDesc*,
 *                               KeyValue*, ObjectID*, Boolean*, Boolean*,
 *                               InternalItem*, Pool*, DeallocListElem*)
 *
 * Description:
 * (Following description is for original ODYSSEUS/COSMOS BtM.
 *  For ODYSSEUS/EduCOSMOS EduBtM, refer to the EduBtM project manual.)
 *
 *
 * Returns:
 *  Error code
 *    eNOTFOUND_BTM
 *    some errors caused by function calls
 *
 * Side effects:
 *  f    : TRUE if the given root page is not half full.
 *  h    : TRUE if the given page is splitted.
 *  item : The internal item to be inserted into the parent if 'h' is TRUE.
 */ 
Four edubtm_DeleteLeaf(
    PhysicalFileID              *pFid,          /* IN FileID of the Btree file */
    PageID                      *pid,           /* IN PageID of the leaf page */
    BtreeLeaf                   *apage,         /* INOUT buffer for the Leaf Page */
    KeyDesc                     *kdesc,         /* IN a key descriptor */
    KeyValue                    *kval,          /* IN key value */
    ObjectID                    *oid,           /* IN ObjectID which will be deleted */
    Boolean                     *f,             /* OUT whether the root page is half full */
    Boolean                     *h,             /* OUT TRUE if it is spiltted. */
    InternalItem                *item,          /* OUT The internal item to be returned */
    Pool                        *dlPool,        /* INOUT pool of dealloc list elements */
    DeallocListElem             *dlHead)        /* INOUT head of a dealloc list */
{
    Four                        e;              /* error number */
    Two                         i;              /* index */
    Two                         of;             /* # of ObjectIDs of an overflow page when less than 1/4 */
    Two                         idx;            /* the index by the binary search */
    ObjectID                    tOid;           /* a Object IDentifier */
    BtreeOverflow               *opage;         /* for a overflow page */
    Boolean                     found;          /* Search Result */
    Two                         lEntryOffset;   /* starting offset of a leaf entry */
    btm_LeafEntry               *lEntry;        /* an entry in leaf page */
    ObjectID                    *oidArray;      /* start position of the ObjectID array */
    Two                         oidArrayElemNo; /* element number in the ObjectIDs array */
    Two                         entryLen;       /* length of the old leaf entry */
    Two                         newLen;         /* length of the new leaf entry */
    Two                         alignedKlen;    /* aligned length of the key length */
    PageID                      ovPid;          /* overflow page's PageID */
    DeallocListElem             *dlElem;        /* an element of the dealloc list */


    /* Error check whether using not supported functionality by EduBtM */
    for(i=0; i<kdesc->nparts; i++)
    {
        if(kdesc->kpart[i].type!=SM_INT && kdesc->kpart[i].type!=SM_VARSTRING)
            ERR(eNOTSUPPORTED_EDUBTM);
    }


    /* Delete following 2 lines before implement this function */
    printf("Implementation of delete operation is optional (not compulsory),\n");
    printf("and delete operation has not been implemented yet.\n");

	      
    return(eNOERROR);
    
} /* edubtm_DeleteLeaf() */
