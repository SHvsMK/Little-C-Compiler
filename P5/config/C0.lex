/*
C0.lex
*/

%{
#include "common.h"
#include "C0.tab.h"
int yycolumn = 1;

#define YY_USER_ACTION if(yylloc.first_line != yylineno){yylloc.first_line = yylloc.last_line = yylineno;yycolumn = 0;} \
yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1; \
yycolumn += yyleng;
%}

%option yylineno

%x COMMENT

blank			[ \t]*
digit			[0-9]
alpha			[A-Za-z]
alpha_num		({alpha}|{digit})
hex_digit		[0-9A-Fa-f]
identifier		{alpha}{alpha_num}*
dec_num		0|[1-9][0-9]*
hex_num		0[xX]{hex_digit}+
oct_num			0[0-7]+

%%

int	return( integersym );
void	return( voidsym );
return	return( returnsym );
do	return( dosym );
while	return( whilesym );
if	return( ifsym );
else	return( elsesym );
const	return( constsym );
main	return( mainsym );

"<="	return( leq );
"!="	return( neq );
">="	return( geq );
"<"	return( lss );
">"	return( gtr );
"=="	return( eql );

"="	return( becomes );

"+"	return( plus );
"-"	return( minus );
"*"	return( times );
"/"	return( divd );
"%"	return( mod );
"("	return( lparen );
")"	return( rparen );
"{"	return( lbrace );
"}"	return( rbrace );
","	return( comma );
";"	return( semicolon );

{identifier}	{
			yylval.name = malloc(yyleng+1);
			yylval.name[yyleng] = '\0';
			strncpy(yylval.name, yytext, yyleng);
			return( ident );
		}

{dec_num}	{
				int num;
				num =atol( yytext );
				yylval.numval = num;
				return( number );
			}
{hex_num}	{
				int num;
				num = 0;
				int k = 0;
				char *words = yytext;
				words++;
				words++;
				while(*words)
				{
					if( *words >= '0' && *words <= '9' )
					num = num * 16 + *words - '0';
					else if( *words >= 'A' && *words <= 'F' )
					num = num * 16 + *words - 'A';
					else if( *words >= 'a' && *words <= 'f' )
					num = num * 16 + *words - 'a';
					k++;
					words++;
				}
				yylval.numval = num;
				return( number );
			}
{oct_num}	{
				int num;
				num = 0;
				int k = 0;
				char *words = yytext;
				words++;
				while(*words)
				{
					if( *words >= '0' && *words <= '7' )
					num = num * 8+ *words - '0';
					k++;
					words++;
				}
				yylval.numval = num;
				return( number );
			}

{blank}

"\n"	

"/*"			BEGIN( COMMENT );
<COMMENT>"*/"		BEGIN( INITIAL );
<COMMENT>.
<COMMENT>\n
<COMMENT><<EOF>>	printf("EOF in comment");

%%
