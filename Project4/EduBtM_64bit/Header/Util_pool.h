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
#ifndef _UTIL_POOL_H_
#define _UTIL_POOL_H_


/*@
 * Type Definitions
 */
/*
 * Type Definition for subpool header
 * For each subpool, a subpool header is defined.
 * The subpool header is dynamically allocated at once with the subpool.
 */
struct _SubpoolHdr {
    Four 		count;			/* # of elements in the freed list *//* YRK22JUL2003-2 */
    char 		*firstElem;		/* pointer to the first freed element */
						/* freed elements make a linked list. */
    struct _SubpoolHdr 	*nextSubpool; 		/* pointer to next subpool */
};

typedef struct _SubpoolHdr SubpoolHdr;

/*
 * Type definition for Pool.
 * Pool consists of the subpools of same size.
 */
struct _Pool {
    Four        elemSize;		/* element size *//* YRK22JUL2003-2 */
    Four        maxElemInSubpool;	/* maximum elements in subpool *//* YRK22JUL2003-2 */
    SubpoolHdr *subpoolPtr;		/* pointer to the first subpool */
};

typedef struct _Pool Pool;


#endif /* _UTIL_POOL_H_ */
