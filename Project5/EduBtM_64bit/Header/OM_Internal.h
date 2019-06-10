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
#ifndef _OM_INTERNAL_H_
#define _OM_INTERNAL_H_


/*
 *----------------- Typedefs for Page Structures --------------------
 */

/*
 * define a type for a slot that includes a unique number
 */
typedef struct {
    Two 	offset;		/* points to actual storage area */
    Unique	unique;		/* unique number */
} SlottedPageSlot;

/*
 * Typedef for the header of slotted page
 */
typedef struct {
    PageID pid;                 /* page id of this page, should be located on the beginnig */
    Four flags;                 /* flag to store page information */
    Four reserved;              /* reserved space to store page information */
    Two nSlots;			/* slots in use on the page */
    Two free;			/* offset of contiguous free area on page */
    Two unused;			/* number of unused bytes which are not part of the contiguous freespace */

    /* 
     * In Sparc machine, at this position 2 fill chars are included 
     */

    FileID fid;			/* fileID within its volume */
    Unique unique;		/* unique number to allocate */
    Unique uniqueLimit;		/* limit of valid unique numbers */
    ShortPageID nextPage;	/* Next PageID of data file */
    ShortPageID prevPage;	/* Prev PageID of data file */
    ShortPageID	spaceListPrev;	/* double linked list of xx% free pages */
    ShortPageID	spaceListNext;	/*   within the same file */
} SlottedPageHdr;

/*
 * Typedef for slotted page
 */
#define SP_FIXED (sizeof(SlottedPageHdr) + sizeof(SlottedPageSlot))

typedef struct {
    SlottedPageHdr header;	  /* header of the slotted page */
    char data[PAGESIZE-SP_FIXED]; /* data area */
    SlottedPageSlot slot[1];	  /* slot arrays, indexes backwards */
} SlottedPage;


#define GET_PTR_TO_CATENTRY_FOR_DATA(catObjForFile, catPage, catEntry) \
{	\
	Four offset = catPage->slot[-(catObjForFile->slotNo)].offset; \
	Object *obj = (Object *)&(catPage->data[offset]); \
	catEntry = (sm_CatOverlayForData*)obj->data; \
}

    
#endif /* _OM_INTERNAL_H_ */
