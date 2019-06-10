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
#ifndef _EDUBTM_H_
#define _EDUBTM_H_


#include "EduBtM_Internal.h"
#include "Util_pool.h"



/*@
 * Function Prototypes
 */
/* Interface Function Prototypes */
Four EduBtM_CreateIndex(ObjectID*, PageID*);
Four EduBtM_DeleteObject(ObjectID*, PageID*, KeyDesc*, KeyValue*, ObjectID*, Pool*, DeallocListElem*);
Four EduBtM_DropIndex(PhysicalFileID*, PageID*, Pool*, DeallocListElem*);
Four EduBtM_Fetch(PageID*, KeyDesc*, KeyValue*, Four, KeyValue*, Four, BtreeCursor*);
Four EduBtM_FetchNext(PageID*, KeyDesc*, KeyValue*, Four, BtreeCursor*, BtreeCursor*);
Four EduBtM_InsertObject(ObjectID*, PageID*, KeyDesc*, KeyValue*, ObjectID*, Pool*, DeallocListElem*);


#endif /* _EDUBTM_H_ */
