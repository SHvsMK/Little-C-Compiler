CONF	 = config
SRC	 = src
BIN	 = bin

CC       = gcc -g
LEX      = flex -i -I 
YACC     = bison -d -y -v

# Generates a compiler for a simple expression language,
# the grammar is ambiguous, and uses precedence declarations
C0:	$(CONF)/C0.y $(CONF)/C0.lex
	@mkdir -p ${BIN}
	@mkdir -p ${SRC}
	$(YACC) -b C0 -o $(SRC)/C0.tab.c $(CONF)/C0.y
	$(LEX) -o$(SRC)/C0.lex.c $(CONF)/C0.lex
	$(CC) -o $(BIN)/C0 $(SRC)/C0.lex.c $(SRC)/C0.tab.c -ll -lm

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
