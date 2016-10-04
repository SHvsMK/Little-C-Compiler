%{
#include <stdio.h>
#include <math.h>
#include <common2.h>
ASTTree ast;
Table symtab;
%}

%union {
	char *name;
	int numval;
	int ival;
	ASTNode node;
}

%locations

%token number
%token ident
%token plus minus times divd mod
%token lparen rparen lbrace rbrace
%token becomes
%token leq neq geq lss gtr eql
%token integersym voidsym returnsym dosym ifsym elsesym constsym mainsym whilesym
%token comma semicolon

%type <numval> number
%type <name> ident
%type <ival> plus minus times divd mod becomes leq neq geq lss gtr eql RelOp front
%type <node> Program CDecl IntDecl BN VDecl Stmt IDT cond Exp TM Term FT Factor CIDC CIDI

%%
goal	: Program
	{
	 debug("goal ::= Program");
	 ast->root = $1;
	}
	;

Program	: CDecl IntDecl VDecl mainsym lparen rparen lbrace IntDecl Stmt rbrace
	{
	 debug("Program ::= CDecl IntDecl VDecl mainsym lparen rparen lbrace IntDecl Stmt rbrace");
	 $$ = newProgram($1, $2, $3, $8, $9);
	 setLoc($$, (Loc)&(@$));
	}
	;

CDecl	:
	{
	 debug("CDecl ::= null");
	 $$ = newnull();
	}
	| constsym ident becomes front number CIDC semicolon CDecl
	{
	 debug("CDecl ::= constsym ident becomes number CIDC semicolon CDecl");
	 $$ = newCDecl(symtab,$2, $4, $5, $6, $8);
	 setLoc($$, (Loc)&(@$));
	}
	;

CIDC	:
	{
	 debug("CIDC ::= null");
	 $$ = newnull();
	}
	| comma ident becomes front number CIDC
	{
	 debug("CIDC ::= comma ident becomes number CIDC");
	 $$ = newCIDC(symtab,$2, $4, $5, $6);
	 setLoc($$, (Loc)&(@$));
	}
	;

IntDecl	:
	{
	 debug("IntDecl ::= null");
	 $$ = newnull();
	}
	| integersym ident BN CIDI semicolon IntDecl
	{
	 debug("IntDecl ::= integersym ident BN CIDI semicolon IntDecl");
	 $$ = newIntDecl(symtab,$2, $3, $4, $6);
	 setLoc($$, (Loc)&(@$));
	}
	;

CIDI	:
	{
	 debug("CIDI ::= null");
	 $$ = newnull();
	}
	| comma ident BN CIDI
	{
	 debug("CIDI ::= comma ident BN CIDI");
	 $$ = newCIDI(symtab,$2, $3, $4);
	 setLoc($$, (Loc)&(@$));
	}
	;

BN	:
	{
	 debug("BN ::= null");
	 $$ = newnull();
	}
	| becomes front number
	{
	 debug("BN ::= becomes number");
	 $$ = newBN($2, $3);
	 setLoc($$, (Loc)&(@$));
	}
	;

VDecl	:
	{
	 debug("VDecl ::= null");
	 $$ = newnull();
	}
	| voidsym ident lparen rparen lbrace CDecl IntDecl Stmt rbrace VDecl
	{
	 debug("VDecl ::= voidsym ident lparen rparen lbrace CDecl IntDecl Stmt rbrace VDecl");
	 $$ = newVDecl(symtab, $2, $6, $7, $8, $10);
	 setLoc($$, (Loc)&(@$));
	}
	;

Stmt	:
	{
	 debug("Stmt ::= null");
	 $$ = newnull();
	}
	| Factor IDT semicolon Stmt
	{
	 debug("Stmt ::= ident IDT semicolon Stmt");
	 $$ = newASGN($1, $2, $4);
	 setLoc($$, (Loc)&(@$));
	}
	| ifsym lparen cond rparen lbrace Stmt rbrace elsesym lbrace Stmt rbrace Stmt
	{
	 debug("Stmt ::= ifsym lparen cond rparen lbrace Stmt rbrace elsesym lbrace Stmt rbrace Stmt");
	 $$ = newIF($3, $6, $10, $12);
	 setLoc($$, (Loc)&(@$));
	}
	| whilesym lparen cond rparen lbrace Stmt rbrace Stmt
	{
	 debug("Stmt ::= whilesym lparen cond rparen lbrace Stmt rbrace Stmt");
	 $$ = newWHILE($3, $6, $8);
	 setLoc($$, (Loc)&(@$));
	}
	| returnsym semicolon Stmt
	{
	 debug("Stmt ::= returnsym semicolon Stmt");
	 $$ = newRETURN($3);
	 setLoc($$, (Loc)&(@$));
	}
	;

IDT	: becomes Exp
	{
	 debug("IDT ::= becomes Exp");
	 $$ = newBE($2);
	 setLoc($$, (Loc)&(@$));
	}
	| lparen rparen
	{
	 debug("IDT ::= lpare rparen");
	 $$ = newLR();
	 setLoc($$, (Loc)&(@$));
	}
	;

cond	: Exp RelOp Exp
	{
	 debug("cond ::= Exp RelOp Exp");
	 $$ = newcond($1, $2, $3);
	 setLoc($$, (Loc)&(@$));
	}
	;

RelOp	: eql
	{
	 debug("RelOp ::= eql");
	 $$ = 1;
	}
	| leq
	{
	 debug("RelOp ::= leq");
	 $$ = 2;
	}
	| geq
	{
	 debug("RelOp ::= geq");
	 $$ = 3;
	}
	| lss
	{
	 debug("RelOp ::= lss");
	 $$ = 4;
	}
	| gtr
	{
	 debug("RelOp ::= gtr");
	 $$ = 5;
	}
	| neq
	{
	 debug("RelOp ::= neq");
	 $$ = 6;
	}
	;

Exp	:front Term TM
	{
	 debug("Exp ::= front Term front TM");
	 $$ = newExp($1, $2, $3);
	 setLoc($$, (Loc)&(@$));
	}
	;

front	:
	{
	 debug("front ::= null");
	 $$ = 0;
	}
	| plus
	{
	 debug("front ::= plus");
	 $$ = 1;
	}
	| minus
	{
	 debug("front ::= minus");
	 $$ = 2;
	}
	;

TM	:
	{
	 debug("TM ::= null");
	 $$ = newnull();
	}
	| plus Term TM
	{
	 debug("TM ::= plus Term TM");
	 $$ = newTM($1, $2, $3);
	 setLoc($$, (Loc)&(@$));
	}
	| minus Term TM
	{
	 debug("TM ::= minus Term TM");
	 $$ = newTM($1, $2, $3);
	 setLoc($$, (Loc)&(@$));
	}
	;

Term	: Factor FT
	{
	 debug("Term = Factor FT");
	 $$ = newTerm($1, $2);
	 setLoc($$, (Loc)&(@$));
	}
	;

FT	:
	{
	 debug("FT ::= null");
	 $$ = newnull();
	}
	| times Factor FT
	{
	 debug("FT ::= times Factor FT");
	 $$ = newFT($1, $2, $3);
	 setLoc($$, (Loc)&(@$));
	}
	| divd Factor FT
	{
	 debug("FT ::= divd Factor FT");
	 $$ = newFT($1, $2, $3);
	 setLoc($$, (Loc)&(@$));
	}
	| mod Factor FT
	{
	 debug("FT ::= mod Factor FT");
	 $$ = newFT($1, $2, $3);
	 setLoc($$, (Loc)&(@$));
	}
	;

Factor	: ident
	{
	 debug("Factor ::= ident");
	 $$ = newFactori(symtab, $1);
	 setLoc($$, (Loc)&(@$));
	}
	| number
	{
	 debug("Factor ::= number");
	 $$ = newFactorn($1);
	 setLoc($$, (Loc)&(@$));
	}
	| lparen Exp rparen
	{
	 debug("Factor ::= lparen Exp rparen");
	 $$ = newFactorE($2);
	 setLoc($$, (Loc)&(@$));
	}
	;
%%

yyerror(char *message)
{
  printf("%s\n",message);
}

int main(int argc, char *argv[])
{
  symtab = newTable();
  ast = newAST();
  printf("This AST uses the symtab made by myself!\n");
  printf("Parsing ...\n");
  if(yyparse() == 0)
  {
	printf("Success!\n");
	printf("\n\nDump the program from the generated AST:\n");
	dumpAST(ast->root);
  }
  else
  {
	printf("Fail\n");
  	printf("Error position:%d %d\n",yylloc.first_line, yylloc.first_column);
  }
  return(0);
}
