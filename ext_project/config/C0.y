%{
#include <stdio.h>
#include <math.h>
#include <common.h>
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
%token lparen rparen lbrace rbrace lbracket rbracket
%token becomes
%token leq neq geq lss gtr eql
%token integersym arraysym voidsym funcintegersym returnsym dosym ifsym constsym mainsym whilesym forsym Getnumsym Putnumsym
%token comma semicolon

%type <numval> number
%type <name> ident
%type <ival> plus minus times divd mod becomes leq neq geq lss gtr eql RelOp front
%type <node> Program CDecl IntDecl BN ArDecl AIDI FuncDecl IDecl VDecl Argu Argub Stmt IDT cond Exp TM Term FT Factor CIDC CIDI Argca Argcab Arb FStmt Expx

%%
goal	: Program
	{
	 debug("goal ::= Program");
	 ast->root = $1;
	}
	;

Program	: CDecl IntDecl ArDecl FuncDecl mainsym lparen rparen lbrace IntDecl ArDecl Stmt rbrace
	{
	 debug("Program ::= CDecl IntDecl ArDecl FuncDecl mainsym lparen rparen lbrace IntDecl ArDecl Stmt rbrace");
	 $$ = newProgram($1, $2, $3, $4, $9, $10, $11);
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

ArDecl	:
	{
	 debug("ArDecl ::= null");
	 $$ = newnull();
	}
	| arraysym ident lbracket number rbracket AIDI semicolon ArDecl
	{
	 debug("ArDecl ::= integersym ident lbracket number rbracket AIDI semicolon ArDecl");
	 $$ = newArDecl(symtab, $2, $4, $6, $8);
	 setLoc($$, (Loc)&(@$));
	}
	;

AIDI	:
	{
	 debug("AIDI ::= null");
	 $$ = newnull();
	}
	| lbracket number rbracket AIDI
	{
	 debug("AIDI ::= lbracket number rbracket AIDI");
	 $$ = newAIDI($2, $4);
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

FuncDecl:
	{
	 debug("FuncDecl ::= null");
	 $$ = newnull();
	}
	| VDecl FuncDecl
	{
	 debug("FuncDecl ::= VDecl FuncDecl");
	 $$ = newFuncDecl($1, $2);
	 setLoc($$, (Loc)&(@$));
	}
	| IDecl FuncDecl
	{
	 debug("FuncDecl ::= IDecl FuncDecl");
	 $$ = newFuncDecl($1, $2);
	 setLoc($$, (Loc)&(@$));
	}
	;

VDecl	: voidsym ident lparen Argu rparen lbrace CDecl IntDecl ArDecl Stmt rbrace
	{
	 debug("VDecl ::= voidsym ident lparen Argu rparen lbrace CDecl IntDecl ArDecl Stmt rbrace");
	 $$ = newVDecl(symtab, $2, $4, $7, $8, $9, $10);
	 setLoc($$, (Loc)&(@$));
	}
	;

IDecl	: funcintegersym ident lparen Argu rparen lbrace CDecl IntDecl ArDecl Stmt rbrace
	{
	 debug("IDecl ::= integersym ident laparen Argu rparen lbrace CDecl IntDecl ArDecl Stmt rbrace");
	 $$ = newIDecl(symtab, $2, $4, $7, $8, $9, $10);
	 setLoc($$, (Loc)&(@$));
	}
	;

Argu	:
	{
	 debug("Argu ::= null");
	 $$ = newnull();
	}
	| integersym ident Argub
	{
	 debug("Argu ::= integersym ident comma Argub");
	 $$ = newArgu(symtab, $2, $3);
	 setLoc($$, (Loc)&(@$));
	}
	;

Argub	:
	{
	 debug("Argub ::= null");
	 $$ = newnull();
	}
	| comma integersym ident Argub
	{
	 debug("Argub ::= comma integersym ident Argub");
	 $$ = newArgub(symtab, $3, $4);
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
	 debug("Stmt ::= Factor IDT semicolon Stmt");
	 $$ = newASGN($1, $2, $4);
	 setLoc($$, (Loc)&(@$));
	}
	| ifsym lparen cond rparen lbrace Stmt rbrace Stmt
	{
	 debug("Stmt ::= ifsym lparen cond rparen lbrace Stmt rbrace Stmt");
	 $$ = newIF($3, $6, $8);
	 setLoc($$, (Loc)&(@$));
	}
	| whilesym lparen cond rparen lbrace Stmt rbrace Stmt
	{
	 debug("Stmt ::= whilesym lparen cond rparen lbrace Stmt rbrace Stmt");
	 $$ = newWHILE($3, $6, $8);
	 setLoc($$, (Loc)&(@$));
	}
	| forsym lparen FStmt semicolon cond semicolon FStmt rparen lbrace Stmt rbrace Stmt
	{
	 debug("Stmt ::= forsym lparen Stmt semicolon cond semicolon Stmt rpareb lbrace Stmt rbrace Stmt");
	 $$ = newFOR($3, $5, $7, $10, $12);
	 setLoc($$, (Loc)&(@$));
	}
	| returnsym Expx semicolon Stmt
	{
	 debug("Stmt ::= returnsym Exp semicolon Stmt");
	 $$ = newRETURN($2, $4);
	 setLoc($$, (Loc)&(@$));
	}
	| Putnumsym lparen Exp rparen semicolon Stmt
	{
	 debug("Stmt ::= Putnum lparen Exp rparen Stmt");
	 $$ = newPUT($3, $6);
	 setLoc($$, (Loc)&(@$));
	}
	;

Expx	:
	{
	 debug("Expx ::= null");
	 $$ = newnull();
	}
	| Exp
	{
	 debug("Expx ::= Exp");
	 newExpx($1);
	 setLoc($$, (Loc)&(@$));
	}
	;

FStmt	:
	{
	 debug("FStmt ::= null");
	 $$ = newnull();
	}
	| Factor IDT 
	{
	 debug("FStmt ::= Factor IDT");
	 $$ = newFStmt($1, $2);
	 setLoc($$, (Loc)&(@$));
	}
	;

IDT	:
	{
	 debug("IDT ::= null");
	 $$ = newnull();
	}
	|becomes Exp
	{
	 debug("IDT ::= becomes Exp");
	 $$ = newBE($2);
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
	 debug("Exp ::= front Term TM");
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
	 $$ = newTM(1, $2, $3);
	 setLoc($$, (Loc)&(@$));
	}
	| minus Term TM
	{
	 debug("TM ::= minus Term TM");
	 $$ = newTM(2, $2, $3);
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
	 $$ = newFT(1, $2, $3);
	 setLoc($$, (Loc)&(@$));
	}
	| divd Factor FT
	{
	 debug("FT ::= divd Factor FT");
	 $$ = newFT(2, $2, $3);
	 setLoc($$, (Loc)&(@$));
	}
	| mod Factor FT
	{
	 debug("FT ::= mod Factor FT");
	 $$ = newFT(3, $2, $3);
	 setLoc($$, (Loc)&(@$));
	}
	;

Factor	: ident
	{
	 debug("Factor ::= ident");
	 $$ = newFactori(symtab, $1);
	 setLoc($$, (Loc)&(@$));
	}
	| ident lparen Argca rparen
	{
	 debug("Factor ::= ident lparen Argca rapren");
	 $$ = newFactorf(symtab, $1, $3);
	 setLoc($$, (Loc)&(@$));
	}
	| ident lbracket Exp rbracket Arb
	{
	 debug("Factor ::= ident lbracket Exp rbracket Arb");
	 $$ = newFactorA(symtab, $1, $3, $5);
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
	| Getnumsym lparen rparen
	{
	 debug("Factor ::= Getnumsym lparen rparen");
	 $$ = newFactorG();
	 setLoc($$, (Loc)&(@$));
	}
	;

Argca	:
	{
	 debug("Argca ::= null");
	 $$ = newnull();
	}
	| Exp Argcab
	{
	 debug("Argca ::= Exp Argcab");
	 $$ = newArgca($1, $2);
	 setLoc($$, (Loc)&(@$));
	}
	;

Argcab	:
	{
	 debug("Argcab ::= null");
	 $$ = newnull();
	}
	| comma Exp Argcab
	{
	 debug("Argcab ::= comma Exp Argcab");
	 $$ = newArgcab($2, $3);
	 setLoc($$, (Loc)&(@$));
	}
	;

Arb	:
	{
	 debug("Arb ::= null");
	 $$ = newnull();
	}
	| lbracket Exp rbracket Arb
	{
	 debug("Arb ::= lbracket Exp rbracket Arb");
	 $$ = newArb($2, $4);
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
	printf("\n\nGen_P_Code...\n");
	Gen_P_Code(ast->root);
	if(error_flag != 0)
	{
		if(error_flag == 1)
		printf("Const error!\n");
		else if(error_flag == 2)
		printf("undefined variable!\n");
		return 0;
	}
	cx = 0;
	tx = 0;
	dx = 0;
	Gen_P_Code(ast->root);
	Print_P_Code();
	//interpret();
  }
  else
  {
	printf("Fail\n");
  	printf("Error position:%d %d\n",yylloc.first_line, yylloc.first_column);
  }
  return(0);
}
