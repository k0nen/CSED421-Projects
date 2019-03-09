#
# Makefile for ../EduBfM directory
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

EXEC = EduBfM_Test
all: $(EXEC)

INTERFACE = EduBfM_DiscardAll.o EduBfM_FlushAll.o EduBfM_FreeTrain.o \
			EduBfM_GetTrain.o EduBfM_SetDirty.o

NONINTERFACE = edubfm_AllocTrain.o edubfm_FlushTrain.o edubfm_Hash.o edubfm_ReadTrain.o

TESTMODULE = EduBfM_Test.o EduBfM_TestModule.o

EduBfM_Test: $(TESTMODULE) EduBfM.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

EduBfM.o: $(INTERFACE) $(NONINTERFACE)
	@echo ld -r ~~~ -o $@
	@ld -r $^ cosmos.o -o $@
	chmod -x $@

.c.o:
	$(CC) $(CFLAGS) -c $<

clean: 
	$(RM) -f $(EXEC) $(INTERFACE) $(NONINTERFACE) $(TESTMODULE) EduBfM.o
