all: program

IDIR =./headers
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=./obj
SDIR=./src

_DEPS = ThreadFun.h CrossThread.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = ThreadFun.o CrossThread.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

ifeq ($(OS),Windows_NT)
	NDIR =./WIN
	LID = 
else
	NDIR = ./LINUX
	LIB = -pthread
endif

$(ODIR)/CrossThread.o: $(NDIR)/CrossThread.c $(DEPS)
	$(CC) $(LIB) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

program: $(OBJ)
	gcc $(LIB) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o program*
