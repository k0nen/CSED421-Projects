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
 * Module: EduBtM_InsertObject.c
 *
 * Description :
 *  Insert an ObjectID 'oid' into a Btree whose key value is 'kval'. 
 *
 * Exports:
 *  Four EduBtM_InsertObject(ObjectID*, PageID*, KeyDesc*, KeyValue*, ObjectID*, Pool*, DeallocListElem*)
 */


#include "EduBtM_common.h"
#include "BfM.h"
#include "EduBtM_Internal.h"
#include "OM_Internal.h"



/*@================================
 * EduBtM_InsertObject() 
 *================================*/
/*
 * Function: Four EduBtM_InsertObject(ObjectID*, PageID*, KeyDesc*, KeyValue*, ObjectID*, Pool*, DeallocListElem*)
 * 
 * Description :
 * (Following description is for original ODYSSEUS/COSMOS BtM.
 *  For ODYSSEUS/EduCOSMOS EduBtM, refer to the EduBtM project manual.)
 *
 *  Insert an ObjectID 'oid' into a Btree whose key value is 'kval'. 
 *  If an overflow page is created as the result of the insert, it may occur
 *  merging or redistibuting two leaves and this may affect the root.
 *
 * Returns:
 *  error code
 *    eBADPARAMETER_BTM
 *    some errors caused by function calls
 */
Four EduBtM_InsertObject(
    ObjectID *catObjForFile,	/* IN catalog object of B+ tree file */
    PageID   *root,		/* IN the root of Btree */
    KeyDesc  *kdesc,		/* IN key descriptor */
    KeyValue *kval,		/* IN key value */
    ObjectID *oid,		/* IN ObjectID which will be inserted */
    Pool     *dlPool,		/* INOUT pool of dealloc list */
    DeallocListElem *dlHead) /* INOUT head of the dealloc list */
{
    int i;
    Four e;			/* error number */
    Boolean lh;			/* for spliting */
    Boolean lf;			/* for merging */
    InternalItem item;		/* Internal Item */
    SlottedPage *catPage;	/* buffer page containing the catalog object */
    sm_CatOverlayForBtree *catEntry; /* pointer to Btree file catalog information */
    PhysicalFileID pFid;	 /* B+-tree file's FileID */

    
    /*@ check parameters */
    
    if (catObjForFile == NULL) ERR(eBADPARAMETER_BTM);
    
    if (root == NULL) ERR(eBADPARAMETER_BTM);

    if (kdesc == NULL) ERR(eBADPARAMETER_BTM);

    if (kval == NULL) ERR(eBADPARAMETER_BTM);

    if (oid == NULL) ERR(eBADPARAMETER_BTM);    

    /* Error check whether using not supported functionality by EduBtM */
    for(i=0; i<kdesc->nparts; i++)
    {
        if(kdesc->kpart[i].type!=SM_INT && kdesc->kpart[i].type!=SM_VARSTRING)
            ERR(eNOTSUPPORTED_EDUBTM);
    }
    
    
    return(eNOERROR);
    
}   /* EduBtM_InsertObject() */
