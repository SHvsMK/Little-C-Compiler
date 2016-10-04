CINC	 = -Iinclude
CONF	 = config
SRC	 = src
BIN	 = bin
UTILSRC  = $(SRC)/ast.c
UTILSRC1  = $(SRC)/ast1.c
UTILSRC2  = $(SRC)/ast2.c

CC       = gcc -g $(CINC)
LEX      = flex -i -I 
YACC     = bison -d -y -v

all:	C0 C01 C02
# Generates a compiler for a simple expression language,
# the grammar is ambiguous, and uses precedence declarations
C0:	$(CONF)/C0.y $(CONF)/C0.lex
	@mkdir -p ${BIN}
	@mkdir -p ${SRC}
	$(YACC) -b C0 -o $(SRC)/C0.tab.c $(CONF)/C0.y
	$(LEX) -o$(SRC)/C0.lex.c $(CONF)/C0.lex
	$(CC) -DDEBUG -o $(BIN)/C0 $(SRC)/C0.lex.c $(SRC)/C0.tab.c $(UTILSRC) -ll -lm

C01:	$(CONF)/C01.y $(CONF)/C0.lex
	@mkdir -p ${BIN}
	@mkdir -p ${SRC}
	$(YACC) -b C01 -o $(SRC)/C01.tab.c $(CONF)/C01.y
	$(LEX) -o$(SRC)/C01.lex.c $(CONF)/C01.lex
	$(CC) -DDEBUG -o $(BIN)/C01 $(SRC)/C01.lex.c $(SRC)/symtab1.c $(SRC)/C01.tab.c $(UTILSRC1) -ll -lm

C02:	$(CONF)/C02.y $(CONF)/C0.lex
	@mkdir -p ${BIN}
	@mkdir -p ${SRC}
	$(YACC) -b C02 -o $(SRC)/C02.tab.c $(CONF)/C02.y
	$(LEX) -o$(SRC)/C02.lex.c $(CONF)/C02.lex
	$(CC) -DDEBUG -o $(BIN)/C02 $(SRC)/C02.lex.c $(SRC)/symtab2.c $(SRC)/C02.tab.c $(UTILSRC2) -ll -lm

clean:
	rm -f *.BAK *.o core *~* *.a 
	rm -f $(SRC)/*.tab.h $(SRC)/*.tab.c
	rm -f $(SRC)/*.lex.c *.out
	rm -f $(SRC)/*.output

cleanall:
	rm -f *.BAK *.o core *~* *.a 
	rm -f $(SRC)/*.tab.h $(SRC)/*.tab.c
	rm -f $(SRC)/*.lex.c *.out
	rm -f $(SRC)/*.output
	rm -f $(BIN)/*
