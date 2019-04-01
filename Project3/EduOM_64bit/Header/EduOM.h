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
#ifndef _EDUOM_H_
#define _EDUOM_H_


#include "EduOM_Internal.h"
#include "Util_pool.h"



/*@
 * Function Prototypes
 */
/* Interface Function Prototypes */
Four EduOM_CompactPage(SlottedPage*, Two);
Four EduOM_CreateObject(ObjectID*, ObjectID*, ObjectHdr*, Four, void*, ObjectID*);
Four EduOM_DestroyObject(ObjectID*, ObjectID*, Pool*, DeallocListElem*);
Four EduOM_NextObject(ObjectID*, ObjectID*, ObjectID*, ObjectHdr*);
Four EduOM_PrevObject(ObjectID*, ObjectID*, ObjectID*, ObjectHdr*);
Four EduOM_ReadObject(ObjectID*, Four, Four, void*);

Four OM_DumpObject(ObjectID *);


#endif /* _EDUOM_H_ */
