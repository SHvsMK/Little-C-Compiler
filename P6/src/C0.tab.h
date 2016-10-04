/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     number = 258,
     ident = 259,
     plus = 260,
     minus = 261,
     times = 262,
     divd = 263,
     mod = 264,
     lparen = 265,
     rparen = 266,
     lbrace = 267,
     rbrace = 268,
     becomes = 269,
     leq = 270,
     neq = 271,
     geq = 272,
     lss = 273,
     gtr = 274,
     eql = 275,
     integersym = 276,
     voidsym = 277,
     returnsym = 278,
     dosym = 279,
     ifsym = 280,
     constsym = 281,
     mainsym = 282,
     whilesym = 283,
     comma = 284,
     semicolon = 285
   };
#endif
/* Tokens.  */
#define number 258
#define ident 259
#define plus 260
#define minus 261
#define times 262
#define divd 263
#define mod 264
#define lparen 265
#define rparen 266
#define lbrace 267
#define rbrace 268
#define becomes 269
#define leq 270
#define neq 271
#define geq 272
#define lss 273
#define gtr 274
#define eql 275
#define integersym 276
#define voidsym 277
#define returnsym 278
#define dosym 279
#define ifsym 280
#define constsym 281
#define mainsym 282
#define whilesym 283
#define comma 284
#define semicolon 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 9 "config/C0.y"

	char *name;
	int numval;
	int ival;
	ASTNode node;



/* Line 2068 of yacc.c  */
#line 119 "src/C0.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;

