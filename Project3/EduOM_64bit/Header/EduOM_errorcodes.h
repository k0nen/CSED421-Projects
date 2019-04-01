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
 * Macro Definitions
 */
#define ERR_ENCODE_ERROR_CODE(base,no)      ( -1 * (((base) << 16) | no) )

/*
 * Error Base Definitions
 */
#define OM_ERR_BASE                              6

/*
 * Error Definitions for OM_ERR_BASE
 */
#define eBADPARAMETER_OM                         ERR_ENCODE_ERROR_CODE(OM_ERR_BASE,0)
#define eBADOBJECTID_OM                          ERR_ENCODE_ERROR_CODE(OM_ERR_BASE,1)
#define eBADCATALOGOBJECT_OM                     ERR_ENCODE_ERROR_CODE(OM_ERR_BASE,2)
#define eBADLENGTH_OM                            ERR_ENCODE_ERROR_CODE(OM_ERR_BASE,3)
#define eBADSTART_OM                             ERR_ENCODE_ERROR_CODE(OM_ERR_BASE,4)
#define eBADFILEID_OM                            ERR_ENCODE_ERROR_CODE(OM_ERR_BASE,5)
#define eBADUSERBUF_OM                           ERR_ENCODE_ERROR_CODE(OM_ERR_BASE,6)
#define eBADPAGEID_OM                            ERR_ENCODE_ERROR_CODE(OM_ERR_BASE,7)
#define eTOOLARGESORTKEY_OM                      ERR_ENCODE_ERROR_CODE(OM_ERR_BASE,8)
#define eCANTALLOCEXTENT_BL_OM                   ERR_ENCODE_ERROR_CODE(OM_ERR_BASE,9)
#define NUM_ERRORS_OM_ERR_BASE                   10
#define eNOTSUPPORTED_EDUOM			             ERR_ENCODE_ERROR_CODE(OM_ERR_BASE,11)
