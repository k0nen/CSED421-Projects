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
#ifndef _EDUBTM_BASICTYPES_H_
#define _EDUBTM_BASICTYPES_H_


/*
 * Type definitions for the basic types
 */
/* one byte data type */
typedef char                    One;
typedef unsigned char           UOne;

/* two bytes data type */
typedef short                   Two;
typedef unsigned short          UTwo;

/* four bytes data type */
typedef int                     Four;
typedef unsigned int            UFour;

/* eight bytes data type */
typedef long                    Eight;
typedef unsigned long           UEight;

/* invarialbe size data type */       
typedef char                    One_Invariable;
typedef unsigned char           UOne_Invariable;
typedef Two                     Two_Invariable;
typedef UTwo                    UTwo_Invariable;
typedef Four                    Four_Invariable;
typedef UFour                   UFour_Invariable;
typedef Eight                   Eight_Invariable;
typedef UEight                  UEight_Invariable;

/* Boolean Type */
typedef enum { FALSE, TRUE } Boolean;

/* Comparison Operator */
/* WARNING: DO NOT change the number. The numbers have some meanings; bit properties. */
typedef enum {SM_EQ=0x1, SM_LT=0x2, SM_LE=0x3, SM_GT=0x4, SM_GE=0x5, SM_NE=0x6, SM_EOF=0x10, SM_BOF=0x20} CompOp;

/* data & memory align type */
typedef Four_Invariable         ALIGN_TYPE;

#define CONSTANT_CASTING_TYPE   int


#endif /* _EDUBTM_BASICTYPES_H_ */
