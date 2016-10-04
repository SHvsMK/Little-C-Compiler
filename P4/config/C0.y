%{
#include <stdio.h>
%}

%locations

%token number
%token ident
%token plus minus times divd mod
%token lparen rparen lbrace rbrace
%token becomes
%token leq neq geq lss gtr eql
%token integersym voidsym returnsym dosym ifsym elsesym constsym mainsym whilesym
%token comma semicolon

%%
Program	: CDecl IntDecl VDecl mainsym lparen rparen lbrace IntDecl Stmt rbrace
	;

CDecl	:
	| constsym ident becomes number CID semicolon CDecl
	;

IntDecl	:
	| integersym ident BN CID semicolon IntDecl
	;

CID	:
	| comma ident BN CID
	;

BN	:
	| becomes number
	;
VDecl	:
	| voidsym ident lparen rparen lbrace CDecl IntDecl Stmt rbrace VDecl
	;

Stmt	:
	| ident IDT semicolon Stmt
	| ifsym lparen cond rparen lbrace Stmt rbrace elsesym lbrace Stmt rbrace Stmt
	| whilesym lparen cond rparen lbrace Stmt rbrace Stmt
	| returnsym semicolon Stmt
	;

IDT	: becomes Exp
	| lparen rparen
	;

cond	: Exp RelOp Exp
	;

RelOp	: eql
	| leq
	| geq
	| lss
	| gtr
	| neq
	;

Exp:	front Term TM
	;

front	:
	| plus
	| minus
	;

TM	:
	| plus Term TM
	| minus Term TM
	;

Term	: Factor FT
	;

FT	:
	| times Factor FT
	| divd Factor FT
	| mod Factor
	;

Factor	: ident
	| number
	| lparen Exp rparen
	;
%%

yyerror(char *message)
{
  printf("%s\n",message);
}

int main(int argc, char *argv[])
{
  if(yyparse() == 0)
  printf("Success!\n");
  else
  {
	printf("Fail\n");
  	printf("Error position:%d %d\n",yylloc.first_line, yylloc.first_column);
  }
  return(0);
}
