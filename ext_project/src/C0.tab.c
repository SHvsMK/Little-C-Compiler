/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



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




/* Copy the first part of user declarations.  */
#line 1 "config/C0.y"

#include <stdio.h>
#include <math.h>
#include <common.h>
ASTTree ast;
Table symtab;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 9 "config/C0.y"
{
	char *name;
	int numval;
	int ival;
	ASTNode node;
}
/* Line 193 of yacc.c.  */
#line 185 "src/C0.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

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


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 210 "src/C0.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   182

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  190

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,    18,    19,    28,    29,    36,    37,
      44,    45,    50,    51,    60,    61,    66,    67,    71,    72,
      75,    78,    90,   102,   103,   107,   108,   113,   114,   119,
     128,   137,   150,   155,   162,   163,   165,   166,   169,   170,
     173,   177,   179,   181,   183,   185,   187,   189,   193,   194,
     196,   198,   199,   203,   207,   210,   211,   215,   219,   223,
     225,   230,   236,   238,   242,   246,   247,   250,   251,   255,
     256
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    40,    -1,    41,    43,    45,    48,    31,
      10,    11,    12,    43,    45,    53,    13,    -1,    -1,    30,
       4,    16,    60,     3,    42,    37,    41,    -1,    -1,    36,
       4,    16,    60,     3,    42,    -1,    -1,    23,     4,    47,
      44,    37,    43,    -1,    -1,    36,     4,    47,    44,    -1,
      -1,    24,     4,    14,     3,    15,    46,    37,    45,    -1,
      -1,    14,     3,    15,    46,    -1,    -1,    16,    60,     3,
      -1,    -1,    49,    48,    -1,    50,    48,    -1,    25,     4,
      10,    51,    11,    12,    41,    43,    45,    53,    13,    -1,
      26,     4,    10,    51,    11,    12,    41,    43,    45,    53,
      13,    -1,    -1,    23,     4,    52,    -1,    -1,    36,    23,
       4,    52,    -1,    -1,    64,    56,    37,    53,    -1,    29,
      10,    57,    11,    12,    53,    13,    53,    -1,    32,    10,
      57,    11,    12,    53,    13,    53,    -1,    33,    10,    55,
      37,    57,    37,    55,    11,    12,    53,    13,    53,    -1,
      27,    54,    37,    53,    -1,    35,    10,    59,    11,    37,
      53,    -1,    -1,    59,    -1,    -1,    64,    56,    -1,    -1,
      16,    59,    -1,    59,    58,    59,    -1,    22,    -1,    17,
      -1,    19,    -1,    20,    -1,    21,    -1,    18,    -1,    60,
      62,    61,    -1,    -1,     5,    -1,     6,    -1,    -1,     5,
      62,    61,    -1,     6,    62,    61,    -1,    64,    63,    -1,
      -1,     7,    64,    63,    -1,     8,    64,    63,    -1,     9,
      64,    63,    -1,     4,    -1,     4,    10,    65,    11,    -1,
       4,    14,    59,    15,    67,    -1,     3,    -1,    10,    59,
      11,    -1,    34,    10,    11,    -1,    -1,    59,    66,    -1,
      -1,    36,    59,    66,    -1,    -1,    14,    59,    15,    67,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    33,    33,    40,    49,    53,    62,    66,    75,    79,
      88,    92,   101,   105,   114,   118,   127,   131,   140,   144,
     150,   158,   166,   175,   179,   188,   192,   201,   205,   211,
     217,   223,   229,   235,   244,   248,   257,   261,   270,   274,
     282,   290,   295,   300,   305,   310,   315,   322,   331,   335,
     340,   348,   352,   358,   366,   375,   379,   385,   391,   399,
     405,   411,   417,   423,   429,   438,   442,   451,   455,   464,
     468
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "number", "ident", "plus", "minus",
  "times", "divd", "mod", "lparen", "rparen", "lbrace", "rbrace",
  "lbracket", "rbracket", "becomes", "leq", "neq", "geq", "lss", "gtr",
  "eql", "integersym", "arraysym", "voidsym", "funcintegersym",
  "returnsym", "dosym", "ifsym", "constsym", "mainsym", "whilesym",
  "forsym", "Getnumsym", "Putnumsym", "comma", "semicolon", "$accept",
  "goal", "Program", "CDecl", "CIDC", "IntDecl", "CIDI", "ArDecl", "AIDI",
  "BN", "FuncDecl", "VDecl", "IDecl", "Argu", "Argub", "Stmt", "Expx",
  "FStmt", "IDT", "cond", "RelOp", "Exp", "front", "TM", "Term", "FT",
  "Factor", "Argca", "Argcab", "Arb", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    41,    41,    42,    42,    43,    43,
      44,    44,    45,    45,    46,    46,    47,    47,    48,    48,
      48,    49,    50,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    53,    54,    54,    55,    55,    56,    56,
      57,    58,    58,    58,    58,    58,    58,    59,    60,    60,
      60,    61,    61,    61,    62,    63,    63,    63,    63,    64,
      64,    64,    64,    64,    64,    65,    65,    66,    66,    67,
      67
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,    12,     0,     8,     0,     6,     0,     6,
       0,     4,     0,     8,     0,     4,     0,     3,     0,     2,
       2,    11,    11,     0,     3,     0,     4,     0,     4,     8,
       8,    12,     4,     6,     0,     1,     0,     2,     0,     2,
       3,     1,     1,     1,     1,     1,     1,     3,     0,     1,
       1,     0,     3,     3,     2,     0,     3,     3,     3,     1,
       4,     5,     1,     3,     3,     0,     2,     0,     3,     0,
       4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     2,     8,     0,     1,     0,    12,    48,
      16,     0,    18,    49,    50,     0,    48,    10,     0,     0,
       0,     0,    18,    18,     6,     0,     0,     0,     0,     0,
       0,     0,    19,    20,     0,     0,    17,    16,     8,     0,
      23,    23,     0,     0,     4,    10,     9,    14,     0,     0,
       0,     0,    48,     5,    11,     0,     0,    25,     0,     0,
       8,     0,     0,    12,     0,    24,     4,     4,    12,     6,
      14,    13,     0,     8,     8,    27,     7,    15,    25,    12,
      12,    62,    59,    48,    48,     0,     0,     0,     0,     0,
       0,    38,    26,    27,    27,    48,    48,     0,     0,     0,
      35,    48,    48,    36,     0,    48,     3,    48,     0,     0,
       0,    67,     0,     0,    63,    51,    55,    27,     0,     0,
       0,     0,    38,    64,     0,    39,    27,    21,    22,    48,
      66,    60,    69,     0,     0,    47,     0,     0,     0,    54,
      32,     0,    42,    46,    43,    44,    45,    41,    48,     0,
      48,    37,     0,    28,    67,    48,    61,    51,    51,    55,
      55,    55,    27,    40,    27,     0,    27,    68,     0,    52,
      53,    56,    57,    58,     0,     0,    36,    33,    69,    27,
      27,     0,    70,    29,    30,     0,    27,     0,    27,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    35,     8,    27,    12,    56,    17,
      21,    22,    23,    49,    65,    90,    99,   121,   108,   118,
     148,   119,    98,   135,   115,   139,    91,   112,   130,   156
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -98
static const yytype_int16 yypact[] =
{
     -18,    28,    39,   -98,    23,    42,   -98,    63,    48,     4,
      58,    66,    -3,   -98,   -98,    76,     4,    67,    70,    88,
      90,    71,    -3,    -3,    68,   102,   103,    69,   105,    99,
     100,   101,   -98,   -98,   108,    77,   -98,    58,    23,    98,
      92,    92,   106,   104,   -18,    67,   -98,   107,   112,   111,
     113,   114,     4,   -98,   -98,   115,    82,    87,   116,   117,
      23,   122,   118,    48,   109,   -98,   -18,   -18,    48,    68,
     107,   -98,   123,    23,    23,    56,   -98,   -98,    87,    48,
      48,   -98,     7,     4,     8,   120,   121,   124,   125,   126,
     127,   128,   -98,    56,    56,    46,     4,   130,    16,   110,
     -98,     4,     4,    16,   131,     4,   -98,     4,   119,   132,
     133,   129,   137,   134,   -98,    29,    54,    56,   139,    79,
     140,   135,   128,   -98,   141,   -98,    56,   -98,   -98,     4,
     -98,   -98,   143,    16,    16,   -98,    16,    16,    16,   -98,
     -98,   142,   -98,   -98,   -98,   -98,   -98,   -98,     4,   146,
       4,   -98,   136,   -98,   129,     4,   -98,    29,    29,    54,
      54,    54,    56,   -98,    56,   138,    56,   -98,   144,   -98,
     -98,   -98,   -98,   -98,   147,   148,    16,   -98,   143,    56,
      56,   151,   -98,   -98,   -98,   152,    56,   150,    56,   -98
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -98,   -98,   -98,   -38,    74,   -30,    93,   -32,    83,   145,
      33,   -98,   -98,    96,    61,   -93,   -98,   -21,    44,   -97,
     -98,   -80,     2,   -76,   -69,   -83,   -96,   -98,    13,   -10
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -66
static const yytype_int16 yytable[] =
{
     109,   110,   116,    97,   100,   120,    53,   122,    46,    13,
      14,    15,     1,    13,    14,   111,   113,    95,    25,    81,
      82,    96,    19,    20,   140,   124,    83,   125,    73,    74,
      68,    71,     5,   153,   133,   134,    75,   116,   116,     6,
     159,   160,   161,    79,    80,   -34,     7,    93,    94,   154,
      88,    13,    14,   165,    61,    32,    33,   -65,     9,    81,
      82,   136,   137,   138,   157,   158,    83,    10,   163,   174,
      18,   175,    11,   177,    16,   168,   171,   172,   173,    24,
     122,   169,   170,    84,    28,    85,   183,   184,    86,    87,
      88,    89,    29,   187,    30,   189,   142,   143,   144,   145,
     146,   147,    31,    26,    34,    36,    38,    37,    39,    40,
      41,    42,    43,    47,    44,    48,    57,    51,    62,    63,
      52,    55,    58,    64,    59,    69,    60,    78,    66,    67,
     101,   102,    72,    70,   103,   104,   105,    50,    54,    92,
     106,   114,   123,    76,   107,   127,   128,   117,   131,   132,
     141,   149,   152,    77,   162,   181,   126,   155,   164,   178,
     179,   180,   185,   188,   186,   129,   151,   167,   182,     0,
       0,     0,   150,   166,     0,   176,     0,     0,     0,     0,
       0,     0,    45
};

static const yytype_int16 yycheck[] =
{
      93,    94,    98,    83,    84,   102,    44,   103,    38,     5,
       6,     9,    30,     5,     6,    95,    96,    10,    16,     3,
       4,    14,    25,    26,   117,   105,    10,   107,    66,    67,
      60,    63,     4,   126,     5,     6,    68,   133,   134,     0,
     136,   137,   138,    73,    74,    37,    23,    79,    80,   129,
      34,     5,     6,   150,    52,    22,    23,    11,    16,     3,
       4,     7,     8,     9,   133,   134,    10,     4,   148,   162,
       4,   164,    24,   166,    16,   155,   159,   160,   161,     3,
     176,   157,   158,    27,    14,    29,   179,   180,    32,    33,
      34,    35,     4,   186,     4,   188,    17,    18,    19,    20,
      21,    22,    31,    36,    36,     3,    37,     4,     3,    10,
      10,    10,     4,    15,    37,    23,     4,    11,     3,    37,
      16,    14,    11,    36,    11,     3,    12,     4,    12,    12,
      10,    10,    23,    15,    10,    10,    10,    41,    45,    78,
      13,    11,    11,    69,    16,    13,    13,    37,    11,    15,
      11,    11,    11,    70,    12,   176,    37,    14,    12,    15,
      13,    13,    11,    13,    12,    36,   122,   154,   178,    -1,
      -1,    -1,    37,    37,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    39,    40,    41,     4,     0,    23,    43,    16,
       4,    24,    45,     5,     6,    60,    16,    47,     4,    25,
      26,    48,    49,    50,     3,    60,    36,    44,    14,     4,
       4,    31,    48,    48,    36,    42,     3,     4,    37,     3,
      10,    10,    10,     4,    37,    47,    43,    15,    23,    51,
      51,    11,    16,    41,    44,    14,    46,     4,    11,    11,
      12,    60,     3,    37,    36,    52,    12,    12,    43,     3,
      15,    45,    23,    41,    41,    45,    42,    46,     4,    43,
      43,     3,     4,    10,    27,    29,    32,    33,    34,    35,
      53,    64,    52,    45,    45,    10,    14,    59,    60,    54,
      59,    10,    10,    10,    10,    10,    13,    16,    56,    53,
      53,    59,    65,    59,    11,    62,    64,    37,    57,    59,
      57,    55,    64,    11,    59,    59,    37,    13,    13,    36,
      66,    11,    15,     5,     6,    61,     7,     8,     9,    63,
      53,    11,    17,    18,    19,    20,    21,    22,    58,    11,
      37,    56,    11,    53,    59,    14,    67,    62,    62,    64,
      64,    64,    12,    59,    12,    57,    37,    66,    59,    61,
      61,    63,    63,    63,    53,    53,    37,    53,    15,    13,
      13,    55,    67,    53,    53,    11,    12,    53,    13,    53
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 34 "config/C0.y"
    {
	 debug("goal ::= Program");
	 ast->root = (yyvsp[(1) - (1)].node);
	}
    break;

  case 3:
#line 41 "config/C0.y"
    {
	 debug("Program ::= CDecl IntDecl ArDecl FuncDecl mainsym lparen rparen lbrace IntDecl ArDecl Stmt rbrace");
	 (yyval.node) = newProgram((yyvsp[(1) - (12)].node), (yyvsp[(2) - (12)].node), (yyvsp[(3) - (12)].node), (yyvsp[(4) - (12)].node), (yyvsp[(9) - (12)].node), (yyvsp[(10) - (12)].node), (yyvsp[(11) - (12)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 4:
#line 49 "config/C0.y"
    {
	 debug("CDecl ::= null");
	 (yyval.node) = newnull();
	}
    break;

  case 5:
#line 54 "config/C0.y"
    {
	 debug("CDecl ::= constsym ident becomes number CIDC semicolon CDecl");
	 (yyval.node) = newCDecl(symtab,(yyvsp[(2) - (8)].name), (yyvsp[(4) - (8)].ival), (yyvsp[(5) - (8)].numval), (yyvsp[(6) - (8)].node), (yyvsp[(8) - (8)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 6:
#line 62 "config/C0.y"
    {
	 debug("CIDC ::= null");
	 (yyval.node) = newnull();
	}
    break;

  case 7:
#line 67 "config/C0.y"
    {
	 debug("CIDC ::= comma ident becomes number CIDC");
	 (yyval.node) = newCIDC(symtab,(yyvsp[(2) - (6)].name), (yyvsp[(4) - (6)].ival), (yyvsp[(5) - (6)].numval), (yyvsp[(6) - (6)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 8:
#line 75 "config/C0.y"
    {
	 debug("IntDecl ::= null");
	 (yyval.node) = newnull();
	}
    break;

  case 9:
#line 80 "config/C0.y"
    {
	 debug("IntDecl ::= integersym ident BN CIDI semicolon IntDecl");
	 (yyval.node) = newIntDecl(symtab,(yyvsp[(2) - (6)].name), (yyvsp[(3) - (6)].node), (yyvsp[(4) - (6)].node), (yyvsp[(6) - (6)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 10:
#line 88 "config/C0.y"
    {
	 debug("CIDI ::= null");
	 (yyval.node) = newnull();
	}
    break;

  case 11:
#line 93 "config/C0.y"
    {
	 debug("CIDI ::= comma ident BN CIDI");
	 (yyval.node) = newCIDI(symtab,(yyvsp[(2) - (4)].name), (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 12:
#line 101 "config/C0.y"
    {
	 debug("ArDecl ::= null");
	 (yyval.node) = newnull();
	}
    break;

  case 13:
#line 106 "config/C0.y"
    {
	 debug("ArDecl ::= integersym ident lbracket number rbracket AIDI semicolon ArDecl");
	 (yyval.node) = newArDecl(symtab, (yyvsp[(2) - (8)].name), (yyvsp[(4) - (8)].numval), (yyvsp[(6) - (8)].node), (yyvsp[(8) - (8)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 14:
#line 114 "config/C0.y"
    {
	 debug("AIDI ::= null");
	 (yyval.node) = newnull();
	}
    break;

  case 15:
#line 119 "config/C0.y"
    {
	 debug("AIDI ::= lbracket number rbracket AIDI");
	 (yyval.node) = newAIDI((yyvsp[(2) - (4)].numval), (yyvsp[(4) - (4)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 16:
#line 127 "config/C0.y"
    {
	 debug("BN ::= null");
	 (yyval.node) = newnull();
	}
    break;

  case 17:
#line 132 "config/C0.y"
    {
	 debug("BN ::= becomes number");
	 (yyval.node) = newBN((yyvsp[(2) - (3)].ival), (yyvsp[(3) - (3)].numval));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 18:
#line 140 "config/C0.y"
    {
	 debug("FuncDecl ::= null");
	 (yyval.node) = newnull();
	}
    break;

  case 19:
#line 145 "config/C0.y"
    {
	 debug("FuncDecl ::= VDecl FuncDecl");
	 (yyval.node) = newFuncDecl((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 20:
#line 151 "config/C0.y"
    {
	 debug("FuncDecl ::= IDecl FuncDecl");
	 (yyval.node) = newFuncDecl((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 21:
#line 159 "config/C0.y"
    {
	 debug("VDecl ::= voidsym ident lparen Argu rparen lbrace CDecl IntDecl ArDecl Stmt rbrace");
	 (yyval.node) = newVDecl(symtab, (yyvsp[(2) - (11)].name), (yyvsp[(4) - (11)].node), (yyvsp[(7) - (11)].node), (yyvsp[(8) - (11)].node), (yyvsp[(9) - (11)].node), (yyvsp[(10) - (11)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 22:
#line 167 "config/C0.y"
    {
	 debug("IDecl ::= integersym ident laparen Argu rparen lbrace CDecl IntDecl ArDecl Stmt rbrace");
	 (yyval.node) = newIDecl(symtab, (yyvsp[(2) - (11)].name), (yyvsp[(4) - (11)].node), (yyvsp[(7) - (11)].node), (yyvsp[(8) - (11)].node), (yyvsp[(9) - (11)].node), (yyvsp[(10) - (11)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 23:
#line 175 "config/C0.y"
    {
	 debug("Argu ::= null");
	 (yyval.node) = newnull();
	}
    break;

  case 24:
#line 180 "config/C0.y"
    {
	 debug("Argu ::= integersym ident comma Argub");
	 (yyval.node) = newArgu(symtab, (yyvsp[(2) - (3)].name), (yyvsp[(3) - (3)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 25:
#line 188 "config/C0.y"
    {
	 debug("Argub ::= null");
	 (yyval.node) = newnull();
	}
    break;

  case 26:
#line 193 "config/C0.y"
    {
	 debug("Argub ::= comma integersym ident Argub");
	 (yyval.node) = newArgub(symtab, (yyvsp[(3) - (4)].name), (yyvsp[(4) - (4)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 27:
#line 201 "config/C0.y"
    {
	 debug("Stmt ::= null");
	 (yyval.node) = newnull();
	}
    break;

  case 28:
#line 206 "config/C0.y"
    {
	 debug("Stmt ::= Factor IDT semicolon Stmt");
	 (yyval.node) = newASGN((yyvsp[(1) - (4)].node), (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 29:
#line 212 "config/C0.y"
    {
	 debug("Stmt ::= ifsym lparen cond rparen lbrace Stmt rbrace Stmt");
	 (yyval.node) = newIF((yyvsp[(3) - (8)].node), (yyvsp[(6) - (8)].node), (yyvsp[(8) - (8)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 30:
#line 218 "config/C0.y"
    {
	 debug("Stmt ::= whilesym lparen cond rparen lbrace Stmt rbrace Stmt");
	 (yyval.node) = newWHILE((yyvsp[(3) - (8)].node), (yyvsp[(6) - (8)].node), (yyvsp[(8) - (8)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 31:
#line 224 "config/C0.y"
    {
	 debug("Stmt ::= forsym lparen Stmt semicolon cond semicolon Stmt rpareb lbrace Stmt rbrace Stmt");
	 (yyval.node) = newFOR((yyvsp[(3) - (12)].node), (yyvsp[(5) - (12)].node), (yyvsp[(7) - (12)].node), (yyvsp[(10) - (12)].node), (yyvsp[(12) - (12)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 32:
#line 230 "config/C0.y"
    {
	 debug("Stmt ::= returnsym Exp semicolon Stmt");
	 (yyval.node) = newRETURN((yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 33:
#line 236 "config/C0.y"
    {
	 debug("Stmt ::= Putnum lparen Exp rparen Stmt");
	 (yyval.node) = newPUT((yyvsp[(3) - (6)].node), (yyvsp[(6) - (6)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 34:
#line 244 "config/C0.y"
    {
	 debug("Expx ::= null");
	 (yyval.node) = newnull();
	}
    break;

  case 35:
#line 249 "config/C0.y"
    {
	 debug("Expx ::= Exp");
	 newExpx((yyvsp[(1) - (1)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 36:
#line 257 "config/C0.y"
    {
	 debug("FStmt ::= null");
	 (yyval.node) = newnull();
	}
    break;

  case 37:
#line 262 "config/C0.y"
    {
	 debug("FStmt ::= Factor IDT");
	 (yyval.node) = newFStmt((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 38:
#line 270 "config/C0.y"
    {
	 debug("IDT ::= null");
	 (yyval.node) = newnull();
	}
    break;

  case 39:
#line 275 "config/C0.y"
    {
	 debug("IDT ::= becomes Exp");
	 (yyval.node) = newBE((yyvsp[(2) - (2)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 40:
#line 283 "config/C0.y"
    {
	 debug("cond ::= Exp RelOp Exp");
	 (yyval.node) = newcond((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].ival), (yyvsp[(3) - (3)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 41:
#line 291 "config/C0.y"
    {
	 debug("RelOp ::= eql");
	 (yyval.ival) = 1;
	}
    break;

  case 42:
#line 296 "config/C0.y"
    {
	 debug("RelOp ::= leq");
	 (yyval.ival) = 2;
	}
    break;

  case 43:
#line 301 "config/C0.y"
    {
	 debug("RelOp ::= geq");
	 (yyval.ival) = 3;
	}
    break;

  case 44:
#line 306 "config/C0.y"
    {
	 debug("RelOp ::= lss");
	 (yyval.ival) = 4;
	}
    break;

  case 45:
#line 311 "config/C0.y"
    {
	 debug("RelOp ::= gtr");
	 (yyval.ival) = 5;
	}
    break;

  case 46:
#line 316 "config/C0.y"
    {
	 debug("RelOp ::= neq");
	 (yyval.ival) = 6;
	}
    break;

  case 47:
#line 323 "config/C0.y"
    {
	 debug("Exp ::= front Term TM");
	 (yyval.node) = newExp((yyvsp[(1) - (3)].ival), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 48:
#line 331 "config/C0.y"
    {
	 debug("front ::= null");
	 (yyval.ival) = 0;
	}
    break;

  case 49:
#line 336 "config/C0.y"
    {
	 debug("front ::= plus");
	 (yyval.ival) = 1;
	}
    break;

  case 50:
#line 341 "config/C0.y"
    {
	 debug("front ::= minus");
	 (yyval.ival) = 2;
	}
    break;

  case 51:
#line 348 "config/C0.y"
    {
	 debug("TM ::= null");
	 (yyval.node) = newnull();
	}
    break;

  case 52:
#line 353 "config/C0.y"
    {
	 debug("TM ::= plus Term TM");
	 (yyval.node) = newTM(1, (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 53:
#line 359 "config/C0.y"
    {
	 debug("TM ::= minus Term TM");
	 (yyval.node) = newTM(2, (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 54:
#line 367 "config/C0.y"
    {
	 debug("Term = Factor FT");
	 (yyval.node) = newTerm((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 55:
#line 375 "config/C0.y"
    {
	 debug("FT ::= null");
	 (yyval.node) = newnull();
	}
    break;

  case 56:
#line 380 "config/C0.y"
    {
	 debug("FT ::= times Factor FT");
	 (yyval.node) = newFT(1, (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 57:
#line 386 "config/C0.y"
    {
	 debug("FT ::= divd Factor FT");
	 (yyval.node) = newFT(2, (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 58:
#line 392 "config/C0.y"
    {
	 debug("FT ::= mod Factor FT");
	 (yyval.node) = newFT(3, (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 59:
#line 400 "config/C0.y"
    {
	 debug("Factor ::= ident");
	 (yyval.node) = newFactori(symtab, (yyvsp[(1) - (1)].name));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 60:
#line 406 "config/C0.y"
    {
	 debug("Factor ::= ident lparen Argca rapren");
	 (yyval.node) = newFactorf(symtab, (yyvsp[(1) - (4)].name), (yyvsp[(3) - (4)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 61:
#line 412 "config/C0.y"
    {
	 debug("Factor ::= ident lbracket Exp rbracket Arb");
	 (yyval.node) = newFactorA(symtab, (yyvsp[(1) - (5)].name), (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 62:
#line 418 "config/C0.y"
    {
	 debug("Factor ::= number");
	 (yyval.node) = newFactorn((yyvsp[(1) - (1)].numval));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 63:
#line 424 "config/C0.y"
    {
	 debug("Factor ::= lparen Exp rparen");
	 (yyval.node) = newFactorE((yyvsp[(2) - (3)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 64:
#line 430 "config/C0.y"
    {
	 debug("Factor ::= Getnumsym lparen rparen");
	 (yyval.node) = newFactorG();
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 65:
#line 438 "config/C0.y"
    {
	 debug("Argca ::= null");
	 (yyval.node) = newnull();
	}
    break;

  case 66:
#line 443 "config/C0.y"
    {
	 debug("Argca ::= Exp Argcab");
	 (yyval.node) = newArgca((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 67:
#line 451 "config/C0.y"
    {
	 debug("Argcab ::= null");
	 (yyval.node) = newnull();
	}
    break;

  case 68:
#line 456 "config/C0.y"
    {
	 debug("Argcab ::= comma Exp Argcab");
	 (yyval.node) = newArgcab((yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;

  case 69:
#line 464 "config/C0.y"
    {
	 debug("Arb ::= null");
	 (yyval.node) = newnull();
	}
    break;

  case 70:
#line 469 "config/C0.y"
    {
	 debug("Arb ::= lbracket Exp rbracket Arb");
	 (yyval.node) = newArb((yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node));
	 setLoc((yyval.node), (Loc)&((yyloc)));
	}
    break;


/* Line 1267 of yacc.c.  */
#line 2168 "src/C0.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 475 "config/C0.y"


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

