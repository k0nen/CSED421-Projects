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
#define GENERAL_ERR_BASE                         1
#define BTM_ERR_BASE                             7

/*
 * Error Definitions for GENERAL_ERR_BASE
 */
#define eBADCURSOR                               ERR_ENCODE_ERROR_CODE(GENERAL_ERR_BASE,9)

/*
 * Error Definitions for OM_ERR_BASE
 */
#define eBADPARAMETER_BTM                        ERR_ENCODE_ERROR_CODE(BTM_ERR_BASE,0)
#define eBADBTREEPAGE_BTM                        ERR_ENCODE_ERROR_CODE(BTM_ERR_BASE,1)
#define eBADPAGE_BTM                             ERR_ENCODE_ERROR_CODE(BTM_ERR_BASE,2)
#define eNOTFOUND_BTM                            ERR_ENCODE_ERROR_CODE(BTM_ERR_BASE,3)
#define eDUPLICATEDOBJECTID_BTM                  ERR_ENCODE_ERROR_CODE(BTM_ERR_BASE,4)
#define eBADCOMPOP_BTM                           ERR_ENCODE_ERROR_CODE(BTM_ERR_BASE,5)
#define eDUPLICATEDKEY_BTM                       ERR_ENCODE_ERROR_CODE(BTM_ERR_BASE,6)
#define eBADPAGETYPE_BTM                         ERR_ENCODE_ERROR_CODE(BTM_ERR_BASE,7)
#define eEXCEEDMAXDEPTHOFBTREE_BTM               ERR_ENCODE_ERROR_CODE(BTM_ERR_BASE,8)
#define eTRAVERSEPATH_BTM                        ERR_ENCODE_ERROR_CODE(BTM_ERR_BASE,9)
#define eNOSUCHTREELATCH_BTM                     ERR_ENCODE_ERROR_CODE(BTM_ERR_BASE,10)
#define eDELETEOBJECTFAILED_BTM                  ERR_ENCODE_ERROR_CODE(BTM_ERR_BASE,11)
#define eBADCACHETREELATCHCELLPTR_BTM            ERR_ENCODE_ERROR_CODE(BTM_ERR_BASE,12)
#define NUM_ERRORS_BTM_ERR_BASE                  13
#define eNOTSUPPORTED_EDUBTM                     ERR_ENCODE_ERROR_CODE(BTM_ERR_BASE,14)
