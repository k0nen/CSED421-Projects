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
 * Module:	EduBtM_DropIndex.c
 *
 * Description : 
 *  Drop the B+ tree Index specified by 'rootPid', a root PageID of the B+tree.
 *
 * Exports:
 *  Four EduBtM_DropIndex(FileID*, PageID*, Pool*, DeallocListElem*)
 */


#include "EduBtM_common.h"
#include "EduBtM_Internal.h"



/*@================================
 * EduBtM_DropIndex()
 *================================*/
/* 
 * Function: Four EduBtM_DropIndex(FileID*, PageID*, Pool*, DeallocListElem*)
 *
 * Description : 
 * (Following description is for original ODYSSEUS/COSMOS BtM.
 *  For ODYSSEUS/EduCOSMOS EduBtM, refer to the EduBtM project manual.)
 *
 *  Drop the B+ tree Index specified by 'rootPid', a root PageID of the B+tree.
 *
 * Returns:
 *  error code
 *    some errors : by other function calls
 */
Four EduBtM_DropIndex(
    PhysicalFileID *pFid,	/* IN FileID of the Btree file */
    PageID *rootPid,		/* IN root PageID to be dropped */
    Pool   *dlPool,		/* INOUT pool of the dealloc list elements */
    DeallocListElem *dlHead) /* INOUT head of the dealloc list */
{
    Four e;			/* for the error number */


    /*@ Free all pages concerned with the root. */

	
    return(eNOERROR);
    
} /* EduBtM_DropIndex() */
