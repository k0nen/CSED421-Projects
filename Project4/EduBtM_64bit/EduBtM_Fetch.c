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
 * Module: EduBtM_Fetch.c
 *
 * Description :
 *  Find the first object satisfying the given condition.
 *  If there is no such object, then return with 'flag' field of cursor set
 *  to CURSOR_EOS. If there is an object satisfying the condition, then cursor
 *  points to the object position in the B+ tree and the object identifier
 *  is returned via 'cursor' parameter.
 *  The condition is given with a key value and a comparison operator;
 *  the comparison operator is one among SM_BOF, SM_EOF, SM_EQ, SM_LT, SM_LE, SM_GT, SM_GE.
 *
 * Exports:
 *  Four EduBtM_Fetch(PageID*, KeyDesc*, KeyValue*, Four, KeyValue*, Four, BtreeCursor*)
 */


#include <string.h>
#include "EduBtM_common.h"
#include "BfM.h"
#include "EduBtM_Internal.h"


/*@ Internal Function Prototypes */
Four edubtm_Fetch(PageID*, KeyDesc*, KeyValue*, Four, KeyValue*, Four, BtreeCursor*);



/*@================================
 * EduBtM_Fetch()
 *================================*/
/*
 * Function: Four EduBtM_Fetch(PageID*, KeyDesc*, KeyVlaue*, Four, KeyValue*, Four, BtreeCursor*)
 *
 * Description:
 * (Following description is for original ODYSSEUS/COSMOS BtM.
 *  For ODYSSEUS/EduCOSMOS EduBtM, refer to the EduBtM project manual.)
 *
 *  Find the first object satisfying the given condition. See above for detail.
 *
 * Returns:
 *  error code
 *    eBADPARAMETER_BTM
 *    some errors caused by function calls
 *
 * Side effects:
 *  cursor  : The found ObjectID and its position in the Btree Leaf
 *            (it may indicate a ObjectID in an  overflow page).
 */
Four EduBtM_Fetch(
    PageID   *root,		/* IN The current root of the subtree */
    KeyDesc  *kdesc,		/* IN Btree key descriptor */
    KeyValue *startKval,	/* IN key value of start condition */
    Four     startCompOp,	/* IN comparison operator of start condition */
    KeyValue *stopKval,		/* IN key value of stop condition */
    Four     stopCompOp,	/* IN comparison operator of stop condition */
    BtreeCursor *cursor)	/* OUT Btree Cursor */
{
    int i;
    Four e;		   /* error number */

    
    if (root == NULL) ERR(eBADPARAMETER_BTM);

    /* Error check whether using not supported functionality by EduBtM */
    for(i=0; i<kdesc->nparts; i++)
    {
        if(kdesc->kpart[i].type!=SM_INT && kdesc->kpart[i].type!=SM_VARSTRING)
            ERR(eNOTSUPPORTED_EDUBTM);
    }
    
    if(startCompOp == SM_BOF) {
        e = edubtm_FirstObject(root, kdesc, stopKval, stopCompOp, cursor);
        if(e) ERR(e);
    }
    else if(startCompOp == SM_EOF) {
        e = edubtm_LastObject(root, kdesc, stopKval, stopCompOp, cursor);
        if(e) ERR(e);
    }
    else {
        e = edubtm_Fetch(root, kdesc, startKval, startCompOp, stopKval, stopCompOp, cursor);
        if(e) ERR(e);
    }

    return(eNOERROR);

} /* EduBtM_Fetch() */



/*@================================
 * edubtm_Fetch()
 *================================*/
/*
 * Function: Four edubtm_Fetch(PageID*, KeyDesc*, KeyVlaue*, Four, KeyValue*, Four, BtreeCursor*)
 *
 * Description:
 * (Following description is for original ODYSSEUS/COSMOS BtM.
 *  For ODYSSEUS/EduCOSMOS EduBtM, refer to the EduBtM project manual.)
 *
 *  Find the first object satisfying the given condition.
 *  This function handles only the following conditions:
 *  SM_EQ, SM_LT, SM_LE, SM_GT, SM_GE.
 *
 * Returns:
 *  Error code *   
 *    eBADCOMPOP_BTM
 *    eBADBTREEPAGE_BTM
 *    some errors caused by function calls
 */
Four edubtm_Fetch(
    PageID              *root,          /* IN The current root of the subtree */
    KeyDesc             *kdesc,         /* IN Btree key descriptor */
    KeyValue            *startKval,     /* IN key value of start condition */
    Four                startCompOp,    /* IN comparison operator of start condition */
    KeyValue            *stopKval,      /* IN key value of stop condition */
    Four                stopCompOp,     /* IN comparison operator of stop condition */
    BtreeCursor         *cursor)        /* OUT Btree Cursor */
{
    Four                e;              /* error number */
    Four                cmp;            /* result of comparison */
    Two                 idx;            /* index */
    PageID              child;          /* child page when the root is an internla page */
    Two                 alignedKlen;    /* aligned size of the key length */
    BtreePage           *apage;         /* a Page Pointer to the given root */
    BtreeOverflow       *opage;         /* a page pointer if it necessary to access an overflow page */
    Boolean             found;          /* search result */
    PageID              *leafPid;       /* leaf page pointed by the cursor */
    Two                 slotNo;         /* slot pointed by the slot */
    PageID              ovPid;          /* PageID of the overflow page */
    PageNo              ovPageNo;       /* PageNo of the overflow page */
    PageID              prevPid;        /* PageID of the previous page */
    PageID              nextPid;        /* PageID of the next page */
    ObjectID            *oidArray;      /* array of the ObjectIDs */
    Two                 iEntryOffset;   /* starting offset of an internal entry */
    btm_InternalEntry   *iEntry;        /* an internal entry */
    Two                 lEntryOffset;   /* starting offset of a leaf entry */
    btm_LeafEntry       *lEntry;        /* a leaf entry */


    /* Error check whether using not supported functionality by EduBtM */
    int i;
    for(i=0; i<kdesc->nparts; i++)
    {
        if(kdesc->kpart[i].type!=SM_INT && kdesc->kpart[i].type!=SM_VARSTRING)
            ERR(eNOTSUPPORTED_EDUBTM);
    }

    e = BfM_GetTrain(root, &apage, PAGE_BUF);
    if(e) ERR(e);

    printf("aaaa\n");

    // Internal node
    if(apage->any.hdr.type & INTERNAL) {
        edubtm_BinarySearchInternal(&(apage->bi), kdesc, startKval, &idx);
        found = FALSE;

        printf("Fetch internal node - idx is %d, found is %d\n", idx, found);

        if(idx > -1) {
            iEntryOffset = apage->bi.slot[-idx];
            iEntry = &(apage->bi.data[iEntryOffset]);
            MAKE_PAGEID(child, root->volNo, iEntry->spid);
        }
        else MAKE_PAGEID(child, root->volNo, apage->bi.hdr.p0);

        e = EduBtM_Fetch(&child, kdesc, startKval, startCompOp, stopKval, stopCompOp, cursor);
        if(e) ERRB1(e, root, PAGE_BUF);
        e = BfM_FreeTrain(root, PAGE_BUF);
        if(e) ERR(e);
    }
    // Leaf node
    else if(apage->any.hdr.type & LEAF) {
        found = edubtm_BinarySearchLeaf(&(apage->bi), kdesc, startKval, &idx);
        printf("Fetch leaf node - idx is %d, found is %d\n", idx, found);

        slotNo = idx;
        leafPid = root;

        switch(startCompOp) {
        case SM_EQ:
            break;

        case SM_LT:
        case SM_LE:
            // Condition for using left slot
            if(startCompOp == SM_LT && found) slotNo--;

            // First object is in another page
            if(slotNo < 0) {
                MAKE_PAGEID(prevPid, root->volNo, apage->bl.hdr.prevPage);

                if(prevPid.pageNo == NIL) {
                    found = FALSE;
                }
                else {
                    e = BfM_FreeTrain(root, PAGE_BUF);
                    if(e) ERR(e);
                    e = BfM_GetTrain(&prevPid, &apage, PAGE_BUF);
                    if(e) ERR(e);

                    slotNo = apage->bl.hdr.nSlots - 1;
                    leafPid = &prevPid;
                }
            }
            break;

        case SM_GT:
        case SM_GE:
            if(startCompOp == SM_GT || !found) {
                slotNo++;

                found = TRUE;

                // First object is in another page
                if(slotNo >= apage->bl.hdr.nSlots) {
                    MAKE_PAGEID(nextPid, root->volNo, apage->bl.hdr.nextPage);

                    if(nextPid.pageNo == NIL) {
                        found = FALSE;
                    }
                    else {
                        e = BfM_FreeTrain(root, PAGE_BUF);
                        if(e) ERR(e);
                        e = BfM_GetTrain(&nextPid, &apage, PAGE_BUF);
                        if(e) ERR(e);

                        slotNo = 0;
                        leafPid = &nextPid;
                    }
                }
            }
            break;
        default:
            ERRB1(eBADCOMPOP_BTM, root, PAGE_BUF);
            break;
        }

        // If found, then set cursor
        if(found) {
            printf("found!\n");
            cursor->flag = CURSOR_ON;
            cursor->slotNo = slotNo;
            cursor->leaf = *leafPid;

            lEntryOffset = apage->bl.slot[-(cursor->slotNo)];
            lEntry = &(apage->bl.data[lEntryOffset]);
            alignedKlen = ALIGNED_LENGTH(lEntry->klen);

            cursor->key.len = alignedKlen;
            memcpy(cursor->key.val, lEntry->kval, cursor->key.len);

            oidArray = &(lEntry->kval[alignedKlen]);
            cursor->oid = oidArray[0];

            // Search end condition at the same time
            if(stopCompOp != SM_BOF && stopCompOp != SM_EOF && stopCompOp != SM_EQ) {
                cmp = btm_KeyCompare(kdesc, &cursor->key, stopKval);

                if(
                    cmp == EQUAL && (stopCompOp == SM_LT || stopCompOp == SM_GT) ||
                    cmp == LESS && (stopCompOp == SM_GT || stopCompOp == SM_GE) ||
                    cmp == GREAT && (stopCompOp == SM_LT || stopCompOp == SM_LE)
                ) {
                    printf("caught!");
                    cursor->flag = CURSOR_EOS;
                }
            }

            e = BfM_FreeTrain(leafPid, PAGE_BUF);
            if(e) ERR(e);
        }
        // Else, cursor points to nothing
        else {
            cursor->flag = CURSOR_EOS;
            e = BfM_FreeTrain(root, PAGE_BUF);
            if(e) ERR(e);
        }
    }
    // Invalid node
    else ERRB1(eBADBTREEPAGE_BTM, root, PAGE_BUF);

    return(eNOERROR);
    
} /* edubtm_Fetch() */

