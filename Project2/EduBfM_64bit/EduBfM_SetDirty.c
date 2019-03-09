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
 * Module: EduBfM_SetDirty.c
 *
 * Description: 
 *  Set the dirty bit of an entry in the buffer table.
 * 
 * Exports:
 *  Four EduBfM_SetDirty(TrainID*, Four)
 *
 * Notes:
 *  This function should be called if the user modify the buffer.
 */


#include "EduBfM_common.h"
#include "EduBfM_Internal.h"



/*@================================
 * EduBfM_SetDirty()
 *================================*/
/*
 * Function: Four EduBfM_SetDirty(TrainID*, Four)
 *
 * Description: 
 * (Following description is for original ODYSSEUS/COSMOS BfM.
 *  For ODYSSEUS/EduCOSMOS EduBfM, refer to the EduBfM project manual.)
 *
 *  Set the dirty bit of an entry in the buffer table.
 *  Look up the entry in the using given parameters and set the dirty
 *  bit of the entry.
 * 
 * Returns:
 *  error code
 *    eBADBUFFERTYPE_BFM - bad buffer type
 *    some errors caused by function calls
 */
Four EduBfM_SetDirty(
    TrainID             *trainId,               /* IN which train has been modified in the buffer?  */
    Four                type )                  /* IN buffer type */
{
    Four                index;                  /* an index of the buffer table & pool */


    /*@ Is the paramter valid? */
    if (IS_BAD_BUFFERTYPE(type)) ERR(eBADBUFFERTYPE_BFM);



    return( eNOERROR );

}  /* EduBfM_SetDirty */
