#
# Makefile for ../EduOM directory
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

EXEC = EduOM_Test
all: $(EXEC)

INTERFACE = EduOM_CompactPage.o EduOM_CreateObject.o EduOM_DestroyObject.o \
			EduOM_NextObject.o EduOM_PrevObject.o EduOM_ReadObject.o

TESTMODULE = EduOM_Test.o EduOM_TestModule.o

EduOM_Test: $(TESTMODULE) EduOM.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

EduOM.o: $(INTERFACE) $(NONINTERFACE)
	@echo ld -r ~~~ -o $@
	@ld -r $^ cosmos.o -o $@
	chmod -x $@

clean: 
	$(RM) -f $(EXEC) $(INTERFACE) $(NONINTERFACE) $(TESTMODULE) EduOM.o
