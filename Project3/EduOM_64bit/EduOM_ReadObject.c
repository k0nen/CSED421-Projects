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
 * Module : EduOM_ReadObject.c
 * 
 * Description : 
 *  EduOM_ReadObject() causes data to be read from the object identified by 'oid'
 *  into the user specified buffer 'buf'.
 *
 * Exports:
 *  Four EduOM_ReadObject(ObjectID*, Four, Four, char*)
 */


#include <string.h>
#include "EduOM_common.h"
#include "BfM.h"		/* for the buffer manager call */
#include "LOT.h"		/* for the large object manager call */
#include "EduOM_Internal.h"



/*@================================
 * EduOM_ReadObject()
 *================================*/
/*
 * Function: Four EduOM_ReadObject(ObjectID*, Four, Four, char*)
 * 
 * Description : 
 * (Following description is for original ODYSSEUS/COSMOS OM.
 *  For ODYSSEUS/EduCOSMOS EduOM, refer to the EduOM project manual.)
 *
 *  (1) What to do?
 *  EduOM_ReadObject() causes data to be read from the object identified by 'oid'
 *  into the user specified buffer 'buf'. The byte range to be read are
 *  specified by start position 'start' and the number of bytes 'length'.
 *  The 'length' bytes from 'start' are copied from the disk to the user buffer
 *  'buf'. eIf 'length' is REMAINDER, the data from 'start' to end of the
 *  object are to be read(In this case we assume 'buf' can accomadate bytes
 *  to be read).
 *  This routine returns the number of bytes to read.
 *
 *  (2) How to do?
 *  a. Read in the slotted page
 *  b. See the object header
 *  c. IF moved object THEN
 *	   call this routine recursively with the forwarded object's identifier
 *     ELSE 
 *	   IF large object THEN 
 *             call the large object manager's LOT_ReadObject()
 *	   ELSE 
 *	       copy the data into the user buffer 'buf'
 *	   ENDIF
 *     ENDIF
 *  d. Free the buffer page
 *  e. Return
 *
 * Returns:
 *  1) number of bytes actually read (values greater than or equal to 0)
 *  2) Error Code (negative values)
 *    eBADOBJECTID_OM
 *    eBADLENGTH_OM
 *    eBADUSERBUF_OM
 *    eBADSTART_OM
 *    some errors caused by function calls
 */
Four EduOM_ReadObject(
    ObjectID 	*oid,		/* IN object to read */
    Four     	start,		/* IN starting offset of read */
    Four     	length,		/* IN amount of data to read */
    char     	*buf)		/* OUT user buffer to return the read data */
{
    Four     	e;              /* error code */
    PageID 	pid;		/* page containing object specified by 'oid' */
    SlottedPage	*apage;		/* pointer to the buffer of the page  */
    Object	*obj;		/* pointer to the object in the slotted page */
    Four	offset;		/* offset of the object in the page */

    
    
    /*@ check parameters */

    if (oid == NULL) ERR(eBADOBJECTID_OM);

    if (length < 0 && length != REMAINDER) ERR(eBADLENGTH_OM);
    
    if (buf == NULL) ERR(eBADUSERBUF_OM);

    

    return(length);
    
} /* EduOM_ReadObject() */
