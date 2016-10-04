%{

%}

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
for	return( forsym );

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
"/"	return( div );
"%"	return( mod );
"("	return( lparen );
")"	return( rparen );
"{"	return( lbrace );
"}"	return( rbrace );
","	return( comma );
";"	return( semicolon );

{identifier}	return( ident );

{dec_num}	{
				num =atol( yytext );
				return( number );
			}
{hex_num}	{
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
				return( number );
			}
{oct_num}	{
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