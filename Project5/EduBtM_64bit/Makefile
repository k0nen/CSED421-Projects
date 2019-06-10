#
# Makefile for ../EduBtM directory
#

.KEEP_STATE:

RM = /bin/rm

# Use ANSI/C compiler
CC = gcc

# directory of #include files
INCLUDE = ./Header

LIB = -lm

CFLAGS = -w -g -fsigned-char -fPIC -I$(INCLUDE)
#CFLAGS = -w -O2 -fsigned-char -fPIC -I$(INCLUDE)

EXEC = EduBtM_Test
all: $(EXEC)

INTERFACE = EduBtM_CreateIndex.o EduBtM_DeleteObject.o EduBtM_DropIndex.o \
			EduBtM_Fetch.o EduBtM_FetchNext.o EduBtM_InsertObject.o

NONINTERFACE = edubtm_BinarySearch.o edubtm_Compact.o edubtm_Compare.o \
			   edubtm_Delete.o edubtm_FirstObject.o edubtm_FreePages.o \
			   edubtm_InitPage.o edubtm_Insert.o edubtm_LastObject.o \
			   edubtm_Split.o edubtm_root.o

TESTMODULE = EduBtM_Test.o EduBtM_TestModule.o

EduBtM_Test: $(TESTMODULE) EduBtM.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

EduBtM.o: $(INTERFACE) $(NONINTERFACE)
	@echo ld -r ~~~ -o $@
	@ld -r $^ cosmos.o -o $@
	chmod -x $@

clean: 
	$(RM) -f $(EXEC) $(INTERFACE) $(NONINTERFACE) $(TESTMODULE) EduBtM.o
