/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     lbracket = 269,
     rbracket = 270,
     becomes = 271,
     leq = 272,
     neq = 273,
     geq = 274,
     lss = 275,
     gtr = 276,
     eql = 277,
     integersym = 278,
     arraysym = 279,
     voidsym = 280,
     funcintegersym = 281,
     returnsym = 282,
     dosym = 283,
     ifsym = 284,
     constsym = 285,
     mainsym = 286,
     whilesym = 287,
     forsym = 288,
     Getnumsym = 289,
     Putnumsym = 290,
     comma = 291,
     semicolon = 292
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
#define lbracket 269
#define rbracket 270
#define becomes 271
#define leq 272
#define neq 273
#define geq 274
#define lss 275
#define gtr 276
#define eql 277
#define integersym 278
#define arraysym 279
#define voidsym 280
#define funcintegersym 281
#define returnsym 282
#define dosym 283
#define ifsym 284
#define constsym 285
#define mainsym 286
#define whilesym 287
#define forsym 288
#define Getnumsym 289
#define Putnumsym 290
#define comma 291
#define semicolon 292




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 9 "config/C0.y"
{
	char *name;
	int numval;
	int ival;
	ASTNode node;
}
/* Line 1529 of yacc.c.  */
#line 130 "src/C0.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
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
