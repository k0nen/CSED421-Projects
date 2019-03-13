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
#ifndef _EDUBFM_COMMON_H_
#define _EDUBFM_COMMON_H_


#include <stdio.h>
#include "EduBfM_basictypes.h"
#include "EduBfM_error.h"

#define BEGIN_MACRO do {
#define END_MACRO } while(0)

#undef NIL
#define NIL -1			/* special value meaning "end of list", */

/*
 * Configuration Parameters
 */
typedef struct CfgParams_T_tag {
	char*   logVolumeDeviceList;    /* log volume device list */ /* YKL13AUG1998-1 */
    Boolean useDeadlockAvoidance;   /* use deadlock avoidance */
    Boolean useBulkFlush;       /* use bulkflush */
} CfgParams_T;

/*
** Type Definition of PageID
*/
typedef Four PageNo;
typedef Two VolNo;

typedef struct {
    PageNo pageNo;		/* a PageNo */
    VolNo volNo;		/* a VolNo */
} PageID;

#define PAGESIZE      4096      /* NOTE: PAGESIZE must be a multiple of read/write buffer align size */

/* Macro: SET_NILPAGEID(x)
 * Description: set pageNo of the page ID to NIL
 * Parameter:
 *  PageID x    : page ID
 */
#define SET_NILPAGEID(x)   ((x).pageNo = NIL)

/* Macro: IS_NILPAGEID(x)
 * Description: check whether pageNo of the page ID is NIL
 * Parameter:
 *  PageID x    : page ID
 * Returns: TRUE(1) if pageNo of the page ID is NIL, otherwise FALSE(0)
 */
#define IS_NILPAGEID(x)    (((x).pageNo == NIL) ? TRUE:FALSE)

/* Macro: PRINT_TRAINID(x,y)
 * Description: print the train ID with its additional information
 * Parameters:
 *  char *x     : string that represents the additional information of the train ID
 *  TrainID y   : train ID
 */
#define PRINT_PAGEID(x, y)	\
    (y == NULL) ? printf("%s = NULL", (x)) :	\
    printf("%s = {%-2ld, %4ld}\n", (x), (y)->volNo, (y)->pageNo )

/*
** Type Definition for Train
*/
typedef PageID TrainID;		/* use its first page's PageID as the TrainID */

#define PRINT_TRAINID(x,y) PRINT_PAGEID(x,y)

/*
 * Error Handling
 */
/* Error Number Indicating NO ERROR */
#define eNOERROR 0


#endif /* _EDUBFM_COMMON_H_ */
