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
 * Module: edubfm_ReadTrain.c
 *
 * Description : 
 *  Read a train into the buffer.
 *
 * Exports:
 *  edubfm_ReadTrain()
 */


#include "EduBfM_common.h"
#include "RDsM.h"
#include "RM.h"                 /* YKL05MAR97 */
#include "EduBfM_Internal.h"



/*@================================
 * edubfm_ReadTrain()
 *================================*/
/*
 * Function: Four edubfm_ReadTrain(TrainID*, char*, Four)
 *
 * Description:
 * (Following description is for original ODYSSEUS/COSMOS BfM.
 *  For ODYSSEUS/EduCOSMOS EduBfM, refer to the EduBfM project manual.)
 *
 *  Using the given parameters, trainId and type,  read a train from
 *  the disk  and load it into the given buffer.   If the error occurs 
 *  when RDsM_ReadTrain() is called, simply return it.  The function has
 *  no code for checking input parameters since this will be done RDsM,
 *  especially RDsM_ReadTrain().
 *
 * Returns;
 *  error code
 *    some errors caused by RDsM_ReadTrain()
 *
 * Side effects
 *  1) parameter aTrain
 *     a buffer specified by 'aTrain' is filled with a disk content
 */
Four edubfm_ReadTrain(
    TrainID *trainId,		/* IN which train? */
    char    *aTrain,		/* OUT a pointer to buffer */
    Four    type )		/* IN buffer type */
{
    Four e;			/* for error */


	/* Error check whether using not supported functionality by EduBfM */
	if (RM_IS_ROLLBACK_REQUIRED()) ERR(eNOTSUPPORTED_EDUBFM);



    return( eNOERROR );

}  /* edubfm_ReadTrain */
