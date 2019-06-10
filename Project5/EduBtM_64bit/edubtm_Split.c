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
 * Module: edubtm_Split.c
 *
 * Description : 
 *  This file has three functions about 'split'.
 *  'edubtm_SplitInternal(...) and edubtm_SplitLeaf(...) insert the given item
 *  after spliting, and return 'ritem' which should be inserted into the
 *  parent page.
 *
 * Exports:
 *  Four edubtm_SplitInternal(ObjectID*, BtreeInternal*, Two, InternalItem*, InternalItem*)
 *  Four edubtm_SplitLeaf(ObjectID*, PageID*, BtreeLeaf*, Two, LeafItem*, InternalItem*)
 */


#include <string.h>
#include "EduBtM_common.h"
#include "BfM.h"
#include "EduBtM_Internal.h"



/*@================================
 * edubtm_SplitInternal()
 *================================*/
/*
 * Function: Four edubtm_SplitInternal(ObjectID*, BtreeInternal*,Two, InternalItem*, InternalItem*)
 *
 * Description:
 * (Following description is for original ODYSSEUS/COSMOS BtM.
 *  For ODYSSEUS/EduCOSMOS EduBtM, refer to the EduBtM project manual.)
 *
 *  At first, the function edubtm_SplitInternal(...) allocates a new internal page
 *  and initialize it.  Secondly, all items in the given page and the given
 *  'item' are divided by halves and stored to the two pages.  By spliting,
 *  the new internal item should be inserted into their parent and the item will
 *  be returned by 'ritem'.
 *
 *  A temporary page is used because it is difficult to use the given page
 *  directly and the temporary page will be copied to the given page later.
 *
 * Returns:
 *  error code
 *    some errors caused by function calls
 *
 * Note:
 *  The caller should call BfM_SetDirty() for 'fpage'.
 */
Four edubtm_SplitInternal(
    ObjectID                    *catObjForFile,         /* IN catalog object of B+ tree file */
    BtreeInternal               *fpage,                 /* INOUT the page which will be splitted */
    Two                         high,                   /* IN slot No. for the given 'item' */
    InternalItem                *item,                  /* IN the item which will be inserted */
    InternalItem                *ritem)                 /* OUT the item which will be returned by spliting */
{
    Four                        e;                      /* error number */
    Two                         i;                      /* slot No. in the given page, fpage */
    Two                         j;                      /* slot No. in the splitted pages */
    Two                         k;                      /* slot No. in the new page */
    Two                         maxLoop;                /* # of max loops; # of slots in fpage + 1 */
    Four                        sum;                    /* the size of a filled area */
    Boolean                     flag=FALSE;             /* TRUE if 'item' become a member of fpage */
    PageID                      newPid;                 /* for a New Allocated Page */
    BtreeInternal               *npage;                 /* a page pointer for the new allocated page */
    Two                         fEntryOffset;           /* starting offset of an entry in fpage */
    Two                         nEntryOffset;           /* starting offset of an entry in npage */
    Two                         entryLen;               /* length of an entry */
    btm_InternalEntry           *fEntry;                /* internal entry in the given page, fpage */
    btm_InternalEntry           *nEntry;                /* internal entry in the new page, npage*/
    Boolean                     isTmp;


    
    return(eNOERROR);
    
} /* edubtm_SplitInternal() */



/*@================================
 * edubtm_SplitLeaf()
 *================================*/
/*
 * Function: Four edubtm_SplitLeaf(ObjectID*, PageID*, BtreeLeaf*, Two, LeafItem*, InternalItem*)
 *
 * Description: 
 * (Following description is for original ODYSSEUS/COSMOS BtM.
 *  For ODYSSEUS/EduCOSMOS EduBtM, refer to the EduBtM project manual.)
 *
 *  The function edubtm_SplitLeaf(...) is similar to edubtm_SplitInternal(...) except
 *  that the entry of a leaf differs from the entry of an internal and the first
 *  key value of a new page is used to make an internal item of their parent.
 *  Internal pages do not maintain the linked list, but leaves do it, so links
 *  are properly updated.
 *
 * Returns:
 *  Error code
 *  eDUPLICATEDOBJECTID_BTM
 *    some errors caused by function calls
 *
 * Note:
 *  The caller should call BfM_SetDirty() for 'fpage'.
 */
Four edubtm_SplitLeaf(
    ObjectID                    *catObjForFile, /* IN catalog object of B+ tree file */
    PageID                      *root,          /* IN PageID for the given page, 'fpage' */
    BtreeLeaf                   *fpage,         /* INOUT the page which will be splitted */
    Two                         high,           /* IN slotNo for the given 'item' */
    LeafItem                    *item,          /* IN the item which will be inserted */
    InternalItem                *ritem)         /* OUT the item which will be returned by spliting */
{
    Four                        e;              /* error number */
    Two                         i;              /* slot No. in the given page, fpage */
    Two                         j;              /* slot No. in the splitted pages */
    Two                         k;              /* slot No. in the new page */
    Two                         maxLoop;        /* # of max loops; # of slots in fpage + 1 */
    Four                        sum;            /* the size of a filled area */
    PageID                      newPid;         /* for a New Allocated Page */
    PageID                      nextPid;        /* for maintaining doubly linked list */
    BtreeLeaf                   tpage;          /* a temporary page for the given page */
    BtreeLeaf                   *npage;         /* a page pointer for the new page */
    BtreeLeaf                   *mpage;         /* for doubly linked list */
    btm_LeafEntry               *itemEntry;     /* entry for the given 'item' */
    btm_LeafEntry               *fEntry;        /* an entry in the given page, 'fpage' */
    btm_LeafEntry               *nEntry;        /* an entry in the new page, 'npage' */
    ObjectID                    *iOidArray;     /* ObjectID array of 'itemEntry' */
    ObjectID                    *fOidArray;     /* ObjectID array of 'fEntry' */
    Two                         fEntryOffset;   /* starting offset of 'fEntry' */
    Two                         nEntryOffset;   /* starting offset of 'nEntry' */
    Two                         oidArrayNo;     /* element No in an ObjectID array */
    Two                         alignedKlen;    /* aligned length of the key length */
    Two                         itemEntryLen;   /* length of entry for item */
    Two                         entryLen;       /* entry length */
    Boolean                     flag;
    Boolean                     isTmp;
 
    

    return(eNOERROR);
    
} /* edubtm_SplitLeaf() */
