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
 * Module :	EduBtM_CreateIndex.c
 *
 * Description : 
 *  Create the new B+ tree Index. 
 *
 * Exports:
 *  Four EduBtM_CreateIndex(ObjectID*, PageID*)
 */


#include "EduBtM_common.h"
#include "EduBtM_Internal.h"
#include "OM_Internal.h"
#include "BfM.h"



/*@================================
 * EduBtM_CreateIndex()
 *================================*/
/* 
 * Function: Four  EduBtM_CreateIndex(ObjectID*, PageID*)
 *
 * Description : 
 * (Following description is for original ODYSSEUS/COSMOS BtM.
 *  For ODYSSEUS/EduCOSMOS EduBtM, refer to the EduBtM project manual.)
 *
 *  Create the new B+ tree Index. 
 *  We allocate the root page and initialize it.
 *
 * Returns :
 *  error code
 *    some errors caused by function calls
 *
 * Side effects:
 *  The parameter rootPid is filled with the new root page's PageID. 
 */
Four EduBtM_CreateIndex(
    ObjectID *catObjForFile,	/* IN catalog object of B+ tree file */
    PageID *rootPid)		/* OUT root page of the newly created B+tree */
{
    Four e;			/* error number */
    Boolean isTmp;
    SlottedPage *catPage;	/* buffer page containing the catalog object */
    sm_CatOverlayForBtree *catEntry; /* pointer to Btree file catalog information */
    PhysicalFileID pFid;	/* physical file ID */



    return(eNOERROR);
    
} /* EduBtM_CreateIndex() */
