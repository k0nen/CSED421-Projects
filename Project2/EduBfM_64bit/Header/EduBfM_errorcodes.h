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
#define BFM_ERR_BASE                             4

/*
 * Error Definitions for BFM_ERR_BASE
 */
#define eBADBUFFERTYPE_BFM                       ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,0)
#define eBADLATCHMODE_BFM                        ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,1)
#define eBADBUFFER_BFM                           ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,2)
#define eBADHASHKEY_BFM                          ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,3)
#define eBADBUFTBLENTRY_BFM                      ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,4)
#define eFLUSHFIXEDBUF_BFM                       ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,5)
#define eNOTFOUND_BFM                            ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,6)
#define eNOUNFIXEDBUF_BFM                        ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,7)
#define eBADBUFINDEX_BFM                         ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,8)
#define eNULLBUFACCESSCB_BFM                     ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,9)
#define eNOSUCHLOCKEXIST_BFM                     ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,10)
#define eALREADYMOUNTEDCOHERENCYVOLUME_BFM       ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,11)
#define eNOTMOUNTEDCOHERENCYVOLUME_BFM           ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,12)
#define eSHMGETFAILED_BFM                        ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,13)
#define eSHMCTLFAILED_BFM                        ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,14)
#define eSHMATFAILED_BFM                         ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,15)
#define eSHMDTFAILED_BFM                         ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,16)
#define eCREATEFILEFAILED_BFM                    ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,17)
#define eFILELOCKAGAIN_BFM                       ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,18)
#define eFILELOCKUNKNOWN_BFM                     ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,19)
#define eMUTEXCREATEBUSY_BFM                     ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,20)
#define eMUTEXCREATEINVAL_BFM                    ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,21)
#define eMUTEXCREATEFAULT_BFM                    ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,22)
#define eMUTEXCREATEUNKNOWN_BFM                  ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,23)
#define eMUTEXDESTROYINVAL_BFM                   ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,24)
#define eMUTEXDESTROYUNKNOWN_BFM                 ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,25)
#define eMUTEXLOCKAGAIN_BFM                      ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,26)
#define eMUTEXLOCKDEADLK_BFM                     ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,27)
#define eMUTEXLOCKUNKNOWN_BFM                    ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,28)
#define eMUTEXUNLOCKPERM_BFM                     ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,29)
#define eMUTEXUNLOCKUNKNOWN_BFM                  ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,30)
#define eMUTEXINITFAILED_BFM                     ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,31)
#define eBADLATCHCONVERSION_BFM                  ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,32)
#define eSEMCREATEACCES_BFM                      ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,33)
#define eSEMCREATEEXIST_BFM                      ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,34)
#define eSEMCREATEINTR_BFM                       ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,35)
#define eSEMCREATEINVAL_BFM                      ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,36)
#define eSEMCREATEMFILE_BFM                      ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,37)
#define eSEMCREATENAMETOOLONG_BFM                ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,38)
#define eSEMCREATENFILE_BFM                      ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,39)
#define eSEMCREATENOENT_BFM                      ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,40)
#define eSEMCREATENOSPC_BFM                      ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,41)
#define eSEMCREATENOSYS_BFM                      ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,42)
#define eSEMCREATEUNKNOWN_BFM                    ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,43)
#define eSEMCLOSEINVAL_BFM                       ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,44)
#define eSEMCLOSENOSYS_BFM                       ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,45)
#define eSEMCLOSEUNKNOWN_BFM                     ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,46)
#define eSEMDESTROYACCES_BFM                     ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,47)
#define eSEMDESTROYNAMETOOLONG_BFM               ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,48)
#define eSEMDESTROYENOENT_BFM                    ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,49)
#define eSEMDESTROYNOSYS_BFM                     ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,50)
#define eSEMDESTROYUNKNOWN_BFM                   ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,51)
#define eSEMPOSTINVAL_BFM                        ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,52)
#define eSEMPOSTUNKNOWN_BFM                      ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,53)
#define eSEMWAITINVAL_BFM                        ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,54)
#define eSEMWAITINTR_BFM                         ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,55)
#define eSEMWAITUNKNOWN_BFM                      ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,56)
#define eSIGHANDLERINSTALLFAILED_BFM             ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,57)
#define eFULLPROCTABLE_BFM                       ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,58)
#define eNOMORELOCKCONTROLBLOCKS_BFM             ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,59)
#define NUM_ERRORS_BFM_ERR_BASE                  60
#define eNOTSUPPORTED_EDUBFM		             ERR_ENCODE_ERROR_CODE(BFM_ERR_BASE,61)
