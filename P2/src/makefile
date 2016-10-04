# This Makefile requires GNU make.
SHELL = /bin/sh
CC = gcc
PROGRAM = pl0
PROGRAML = pl0
OBJDIR = bin
BINDIR = bin
OBJS = ${OBJDIR}/pl0.o
CCOMPILE = ${CC} ${CFLAGS} -c
LEX      = flex -i -I 

all:	pl0lex

pl0lex: pl0.lex
	@mkdir -p ${BINDIR}
	$(LEX)  pl0.lex
	$(CC) -DLEXERGEN lex.yy.c pl0.c -o ${OBJDIR}/pl0 -ll

pl0:
	@mkdir -p ${BINDIR}
	$(CC) pl0.c -o ${BINDIR}/pl0 -ll

clean:
	rm -f ${OBJDIR}/pl0
	rm -f lex.yy.c
	rm -rf bin
