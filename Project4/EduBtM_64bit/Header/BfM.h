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
#ifndef _BFM_H_
#define _BFM_H_


/*@
 * Constant Definitions
 */
/* Buffer Types */
#define PAGE_BUF    0
#define LOT_LEAF_BUF 1


/*@
 * Function Prototypes
 */
/* Interface Function Prototypes */
Four BfM_FreeTrain(TrainID *, Four);
Four BfM_GetTrain(TrainID *, char **, Four);
Four BfM_GetNewTrain(TrainID *, char **, Four);
Four BfM_SetDirty(TrainID *, Four);


#endif /* _BFM_H_ */
