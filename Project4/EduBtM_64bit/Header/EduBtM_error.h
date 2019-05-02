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
#ifndef __EDUBTM_ERROR_H__
#define __EDUBTM_ERROR_H__


/* include error code definitions */
#include "EduBtM_errorcodes.h"
#include "Util_errorLog.h"


/*
 * Macro Definitions
 */
#define PRTERR(e) \
BEGIN_MACRO \
Util_ErrorLog_Printf("Error : %d(%s) in %s:%d\n", ((Four_Invariable)(e)), Err_GetErrName(e), __FILE__, __LINE__); \
END_MACRO

#define ERR(e) \
BEGIN_MACRO \
    PRTERR(e); if (1) return(e); \
END_MACRO

#define ERRB1(e, pid, t) \
	BEGIN_MACRO \
    PRTERR(e); \
    (Four) BfM_FreeTrain((pid),(t)); \
    if (1) return(e); \
END_MACRO

#define ERRB2(e, pid1, t1, pid2, t2) \
BEGIN_MACRO \
    PRTERR(e); \
    (Four) BfM_FreeTrain((pid1),(t1)); \
    (Four) BfM_FreeTrain((pid2),(t2)); \
    if (1) return(e); \
END_MACRO

/*
 * Function Prototypes
 */
char *Err_GetErrName(Four);


#endif /* __EDUBTM_ERROR_H__ */
