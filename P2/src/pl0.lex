%{

#include "pl0.h"
#include <stdio.h>

long cxtp = 0;

void stringmake()
{
	printf("%s", yytext);
}

%}

%x COMMENT

blank			[ \t]*
digit			[0-9]
alpha			[A-Za-z]
alpha_num		({alpha}|{digit})
hex_digit		[0-9A-Fa-f]
identifier		{alpha}{alpha_num}*
dec_num			0|[1-9][0-9]*
hex_num			0[xX]{hex_digit}+
oct_num			0[0-7]+

%%



begin		{stringmake();return( beginsym );}
call		{stringmake();return( callsym );}
const		{stringmake();return( constsym );}
do		{stringmake();return( dosym );}
end		{stringmake();return( endsym );}
if		{stringmake();return( ifsym );}
odd		{stringmake();return( oddsym );}
procedure	{stringmake();return( procsym );}
then		{stringmake();return( thensym );}
var		{stringmake();return( varsym );}
while		{stringmake();return( whilesym );}

"<="		{stringmake();return( leq );}
"<>"		{stringmake();return( neq );}
">="		{stringmake();return( geq );}
"<"		{stringmake();return( lss );}
">"		{stringmake();return( gtr );}

":="		{stringmake();return( becomes );}

"+"		{stringmake();return( plus );}
"-"		{stringmake();return( minus );}
"*"		{stringmake();return( times );}
"/"		{stringmake();return( slash );}
"("		{stringmake();return( lparen );}
")"		{stringmake();return( rparen );}
"="		{stringmake();return( eql );}
","		{stringmake();return( comma );}
"."		{stringmake();return( period );}
";"		{stringmake();return( semicolon );}

":"		{stringmake();return( nul );}

{identifier}	{stringmake(); strcpy(id, yytext); return( ident );}

{dec_num}		{
					stringmake();
					num =atol( yytext );
					return( number );
				}
{hex_num}	{
				num = 0;
				stringmake();
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
				return( number );
			}
{oct_num}	{
				num = 0;
				stringmake();
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
				return( number );
			}

{blank}	{
			stringmake();
		}

"\n"			{
				stringmake();
				printf("%5ld ", cx);
				ll = 0;
			}

"/*"			BEGIN( COMMENT );
<COMMENT>"*/"		BEGIN( INITIAL );
<COMMENT>.
<COMMENT>\n
<COMMENT><<EOF>>	printf("EOF in comment");

%%

void getsym()
{
	if( cxtp==0) {
		printf("%5ld ", cx);
		cxtp=1;
}	
	sym = yylex();
}
