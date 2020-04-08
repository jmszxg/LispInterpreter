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
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_LETSTAR = 258,
     T_LAMBDA = 259,
     T_INPUT = 260,
     T_PRINT = 261,
     T_IF = 262,
     T_EXIT = 263,
     T_PROGN = 264,
     T_LPAREN = 265,
     T_RPAREN = 266,
     T_ADD = 267,
     T_MULT = 268,
     T_DIV = 269,
     T_SUB = 270,
     T_AND = 271,
     T_OR = 272,
     T_NOT = 273,
     T_LT = 274,
     T_GT = 275,
     T_LE = 276,
     T_GE = 277,
     T_EQ = 278,
     T_NE = 279,
     T_T = 280,
     T_NIL = 281,
     T_IDENT = 282,
     T_INTCONST = 283,
     T_STRCONST = 284,
     T_UNKNOWN = 285
   };
#endif
/* Tokens.  */
#define T_LETSTAR 258
#define T_LAMBDA 259
#define T_INPUT 260
#define T_PRINT 261
#define T_IF 262
#define T_EXIT 263
#define T_PROGN 264
#define T_LPAREN 265
#define T_RPAREN 266
#define T_ADD 267
#define T_MULT 268
#define T_DIV 269
#define T_SUB 270
#define T_AND 271
#define T_OR 272
#define T_NOT 273
#define T_LT 274
#define T_GT 275
#define T_LE 276
#define T_GE 277
#define T_EQ 278
#define T_NE 279
#define T_T 280
#define T_NIL 281
#define T_IDENT 282
#define T_INTCONST 283
#define T_STRCONST 284
#define T_UNKNOWN 285




/* Copy the first part of user declarations.  */
#line 20 "scherrerlester.y"



#include <stdio.h>
#include "SymbolTable.h"
#include "SymbolTableEntry.h"
#include <stack>





stack<SYMBOL_TABLE> scopeStack;

int numLines = 1; 

int numberCurrentParams = 0;
int numExprParams = 0;

void printRule(const char *, const char *);
void yyerror(const char *s); // void since we don't return, just exit.
void printToken(const char* tokenType, const char* lexeme);
void printStringEnding(const char *s, const int end);
void printIntegerEnding(const int i, const int end);
void printBooleanEnding(const int b, const int end);
void enterScope();
void leaveScope();
bool findEntryInAnyScope(const string name);
int findTypeOfEntry(const string name);
int findIntegerValue(const string name);
int findBooleanValue(const string name);
char* findStringValue(const string name);
int findReturnTypeOfEntry(const string name);
int findNumParamsOfEntry(const string name);

extern "C" 
{
    int yyparse(void);
    int yylex(void);
    int yywrap() { return 1; }
}



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
#line 64 "scherrerlester.y"
{
	char* text;
	int intVal;
	TYPE_INFO typeInfo;
}
/* Line 193 of yacc.c.  */
#line 206 "scherrerlester.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 219 "scherrerlester.tab.c"

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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   78

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNRULES -- Number of states.  */
#define YYNSTATES  63

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    15,    17,    19,
      21,    23,    25,    27,    29,    31,    33,    35,    37,    40,
      42,    43,    45,    48,    52,    57,    63,    64,    70,    73,
      75,    78,    80,    82,    84,    86,    88,    90,    92,    94,
      96,    98,   100,   102,   104,   106,   108,   110
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      32,     0,    -1,    -1,    32,    33,    -1,    34,    -1,    27,
      -1,    10,    35,    11,    -1,    28,    -1,    29,    -1,    25,
      -1,    26,    -1,    39,    -1,    40,    -1,    41,    -1,    43,
      -1,    44,    -1,    36,    -1,     8,    -1,    38,    37,    -1,
      45,    -1,    -1,     9,    -1,    50,    33,    -1,    46,    33,
      33,    -1,     7,    33,    33,    33,    -1,     3,    10,    42,
      11,    33,    -1,    -1,    42,    10,    27,    33,    11,    -1,
       6,    33,    -1,     5,    -1,    33,    45,    -1,    33,    -1,
      47,    -1,    48,    -1,    49,    -1,    13,    -1,    15,    -1,
      14,    -1,    12,    -1,    16,    -1,    17,    -1,    19,    -1,
      20,    -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,
      18,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    90,    90,    93,   106,   116,   133,   144,   154,   164,
     174,   186,   197,   207,   217,   227,   237,   247,   255,   292,
     301,   307,   315,   330,   502,   560,   577,   581,   589,   618,
     641,   652,   664,   671,   678,   686,   691,   696,   701,   707,
     712,   718,   723,   728,   733,   738,   743,   749
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_LETSTAR", "T_LAMBDA", "T_INPUT",
  "T_PRINT", "T_IF", "T_EXIT", "T_PROGN", "T_LPAREN", "T_RPAREN", "T_ADD",
  "T_MULT", "T_DIV", "T_SUB", "T_AND", "T_OR", "T_NOT", "T_LT", "T_GT",
  "T_LE", "T_GE", "T_EQ", "T_NE", "T_T", "T_NIL", "T_IDENT", "T_INTCONST",
  "T_STRCONST", "T_UNKNOWN", "$accept", "N_START", "N_EXPR", "N_CONST",
  "N_PARENTHESIZED_EXPR", "N_PROGN_OR_USERFUNCTCALL", "N_ACTUAL_PARAMS",
  "N_FUNCT_NAME", "N_ARITHLOGIC_EXPR", "N_IF_EXPR", "N_LET_EXPR",
  "N_ID_EXPR_LIST", "N_PRINT_EXPR", "N_INPUT_EXPR", "N_EXPR_LIST",
  "N_BIN_OP", "N_ARITH_OP", "N_LOG_OP", "N_REL_OP", "N_UN_OP", 0
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
     285
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    32,    33,    33,    33,    34,    34,    34,
      34,    35,    35,    35,    35,    35,    35,    35,    36,    37,
      37,    38,    39,    39,    40,    41,    42,    42,    43,    44,
      45,    45,    46,    46,    46,    47,    47,    47,    47,    48,
      48,    49,    49,    49,    49,    49,    49,    50
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       0,     1,     2,     3,     4,     5,     0,     5,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     9,    10,     5,     7,     8,     3,
       4,     0,    29,     0,     0,    17,    21,    38,    35,    37,
      36,    39,    40,    47,    41,    42,    43,    44,    45,    46,
       0,    16,    20,    11,    12,    13,    14,    15,     0,    32,
      33,    34,     0,    26,    28,     0,     6,    31,    18,    19,
       0,    22,     0,     0,    30,    23,     0,     0,    24,     0,
      25,     0,    27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    47,    10,    30,    31,    48,    32,    33,    34,
      35,    52,    36,    37,    49,    38,    39,    40,    41,    42
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -39
static const yytype_int8 yypact[] =
{
     -39,     1,   -39,    54,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,    -5,   -39,    -8,    -8,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
      -4,   -39,    -8,   -39,   -39,   -39,   -39,   -39,    -8,   -39,
     -39,   -39,    -8,   -39,   -39,    -8,   -39,    -8,   -39,   -39,
      -8,   -39,    -7,    -8,   -39,   -39,   -21,    -8,   -39,    -8,
     -39,    -3,   -39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -39,   -39,    -1,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,   -38,   -39,   -39,   -39,   -39,   -39
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       9,     2,     3,    56,    57,    43,    59,    46,    62,    54,
       0,     3,    44,    45,     0,     0,     0,     4,     5,     6,
       7,     8,     0,     0,     0,     0,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     0,     0,    50,     0,     0,
       0,    51,     0,     0,    53,     0,     0,     0,     0,    55,
       0,     0,    58,     0,     0,     0,    60,    11,    61,    12,
      13,    14,    15,    16,     0,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29
};

static const yytype_int8 yycheck[] =
{
       1,     0,    10,    10,    11,    10,    27,    11,    11,    47,
      -1,    10,    13,    14,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    42,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    53,    -1,    -1,    -1,    57,     3,    59,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,     0,    10,    25,    26,    27,    28,    29,    33,
      34,     3,     5,     6,     7,     8,     9,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      35,    36,    38,    39,    40,    41,    43,    44,    46,    47,
      48,    49,    50,    10,    33,    33,    11,    33,    37,    45,
      33,    33,    42,    33,    45,    33,    10,    11,    33,    27,
      33,    33,    11
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


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


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

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

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 90 "scherrerlester.y"
    {
				// printRule("START", "epsilon");
			;}
    break;

  case 3:
#line 94 "scherrerlester.y"
    {	
				// printRule("START", "START EXPR");
				printf("\n---- Completed parsing ----\n\n");
				if ((yyvsp[(2) - (2)].typeInfo).integerValue != UNDEFINED)
					printIntegerEnding((yyvsp[(2) - (2)].typeInfo).integerValue, 1);
				else if ((yyvsp[(2) - (2)].typeInfo).booleanValue != UNDEFINED)
					printBooleanEnding((yyvsp[(2) - (2)].typeInfo).booleanValue, 1);
				else if ((yyvsp[(2) - (2)].typeInfo).stringValue != UNDEF_STR)
					printStringEnding((yyvsp[(2) - (2)].typeInfo).stringValue, 1);
				
			;}
    break;

  case 4:
#line 107 "scherrerlester.y"
    {
				// printRule("EXPR", "CONST");
				(yyval.typeInfo).type = (yyvsp[(1) - (1)].typeInfo).type;
				(yyval.typeInfo).numParams = NOT_APPLICABLE;
				(yyval.typeInfo).returnType = NOT_APPLICABLE;
				(yyval.typeInfo).integerValue = (yyvsp[(1) - (1)].typeInfo).integerValue;
				(yyval.typeInfo).booleanValue = (yyvsp[(1) - (1)].typeInfo).booleanValue;
				(yyval.typeInfo).stringValue = (yyvsp[(1) - (1)].typeInfo).stringValue;
			;}
    break;

  case 5:
#line 117 "scherrerlester.y"
    {
				// printRule("EXPR", "IDENT");
				if(!findEntryInAnyScope(string((yyvsp[(1) - (1)].text))))
					yyerror("Undefined identifier");
				else
				{
					
					(yyval.typeInfo).type = findTypeOfEntry(string((yyvsp[(1) - (1)].text)));
					(yyval.typeInfo).integerValue = findIntegerValue(string((yyvsp[(1) - (1)].text)));
					(yyval.typeInfo).booleanValue = findBooleanValue(string((yyvsp[(1) - (1)].text)));
					(yyval.typeInfo).stringValue = findStringValue(string((yyvsp[(1) - (1)].text)));
					(yyval.typeInfo).numParams = UNDEFINED;
					(yyval.typeInfo).returnType = UNDEFINED;
				}
				
			;}
    break;

  case 6:
#line 134 "scherrerlester.y"
    {
				// printRule("EXPR","( PARENTHESIZED_EXPR )");
				(yyval.typeInfo).type = (yyvsp[(2) - (3)].typeInfo).type;
				(yyval.typeInfo).numParams = (yyvsp[(2) - (3)].typeInfo).numParams;
				(yyval.typeInfo).returnType = (yyvsp[(2) - (3)].typeInfo).returnType;
				(yyval.typeInfo).integerValue = (yyvsp[(2) - (3)].typeInfo).integerValue;
				(yyval.typeInfo).booleanValue = (yyvsp[(2) - (3)].typeInfo).booleanValue;
				(yyval.typeInfo).stringValue = (yyvsp[(2) - (3)].typeInfo).stringValue;
			;}
    break;

  case 7:
#line 145 "scherrerlester.y"
    {
				(yyval.typeInfo).type = INT;
				(yyval.typeInfo).numParams = UNDEFINED;
				(yyval.typeInfo).returnType = UNDEFINED;
				(yyval.typeInfo).stringValue = UNDEF_STR;
				(yyval.typeInfo).booleanValue = UNDEFINED;
				(yyval.typeInfo).integerValue = (yyvsp[(1) - (1)].intVal);
				// printRule("CONST", "INTCONST");
			;}
    break;

  case 8:
#line 155 "scherrerlester.y"
    {
				(yyval.typeInfo).type = STR;
				(yyval.typeInfo).numParams = UNDEFINED;
				(yyval.typeInfo).returnType = UNDEFINED;
				(yyval.typeInfo).stringValue = (yyvsp[(1) - (1)].text);
				(yyval.typeInfo).booleanValue = UNDEFINED;
				(yyval.typeInfo).integerValue = UNDEFINED;
				// printRule("CONST", "STRCONST");
			;}
    break;

  case 9:
#line 165 "scherrerlester.y"
    {
				(yyval.typeInfo).type = BOOL;
				(yyval.typeInfo).numParams = UNDEFINED;
				(yyval.typeInfo).returnType = UNDEFINED;
				(yyval.typeInfo).integerValue = UNDEFINED;
				(yyval.typeInfo).booleanValue = 1;
				(yyval.typeInfo).stringValue = UNDEF_STR;
				// printRule("CONST", "T");
			;}
    break;

  case 10:
#line 175 "scherrerlester.y"
    {
				(yyval.typeInfo).type = BOOL;
				(yyval.typeInfo).numParams = UNDEFINED;
				(yyval.typeInfo).returnType = UNDEFINED;
				(yyval.typeInfo).booleanValue = NIL;
				(yyval.typeInfo).integerValue = UNDEFINED;
				(yyval.typeInfo).stringValue = UNDEF_STR;
				// printRule("CONST","NIL");
			;}
    break;

  case 11:
#line 187 "scherrerlester.y"
    {
				(yyval.typeInfo).type = (yyvsp[(1) - (1)].typeInfo).type;
				(yyval.typeInfo).numParams = (yyvsp[(1) - (1)].typeInfo).numParams;
				(yyval.typeInfo).returnType = (yyvsp[(1) - (1)].typeInfo).returnType;
			
				(yyval.typeInfo).integerValue = (yyvsp[(1) - (1)].typeInfo).integerValue;
				(yyval.typeInfo).booleanValue = (yyvsp[(1) - (1)].typeInfo).booleanValue;
				(yyval.typeInfo).stringValue = (yyvsp[(1) - (1)].typeInfo).stringValue;
				// printRule("PARENTHESIZED_EXPR", "ARITHLOGIC_EXPR");
			;}
    break;

  case 12:
#line 198 "scherrerlester.y"
    {
				(yyval.typeInfo).type = (yyvsp[(1) - (1)].typeInfo).type;
				(yyval.typeInfo).numParams = (yyvsp[(1) - (1)].typeInfo).numParams;
				(yyval.typeInfo).returnType = (yyvsp[(1) - (1)].typeInfo).returnType;
				(yyval.typeInfo).integerValue = (yyvsp[(1) - (1)].typeInfo).integerValue;
				(yyval.typeInfo).booleanValue = (yyvsp[(1) - (1)].typeInfo).booleanValue;
				(yyval.typeInfo).stringValue = (yyvsp[(1) - (1)].typeInfo).stringValue;
				// printRule("PARENTHESIZED_EXPR", "IF_EXPR");
			;}
    break;

  case 13:
#line 208 "scherrerlester.y"
    {
				(yyval.typeInfo).type = (yyvsp[(1) - (1)].typeInfo).type;
				(yyval.typeInfo).numParams = (yyvsp[(1) - (1)].typeInfo).numParams;
				(yyval.typeInfo).returnType = (yyvsp[(1) - (1)].typeInfo).returnType;
				(yyval.typeInfo).integerValue = (yyvsp[(1) - (1)].typeInfo).integerValue;
				(yyval.typeInfo).booleanValue = (yyvsp[(1) - (1)].typeInfo).booleanValue;
				(yyval.typeInfo).stringValue = (yyvsp[(1) - (1)].typeInfo).stringValue;
				// printRule("PARENTHESIZED_EXPR", "LET_EXPR");
			;}
    break;

  case 14:
#line 218 "scherrerlester.y"
    {
				(yyval.typeInfo).type = (yyvsp[(1) - (1)].typeInfo).type;
				(yyval.typeInfo).numParams = (yyvsp[(1) - (1)].typeInfo).numParams;
				(yyval.typeInfo).returnType = (yyvsp[(1) - (1)].typeInfo).returnType;
				(yyval.typeInfo).integerValue = (yyvsp[(1) - (1)].typeInfo).integerValue;
				(yyval.typeInfo).booleanValue = (yyvsp[(1) - (1)].typeInfo).booleanValue;
				(yyval.typeInfo).stringValue = (yyvsp[(1) - (1)].typeInfo).stringValue;
				// printRule("PARENTHESIZED_EXPR", "PRINT_EXPR");
			;}
    break;

  case 15:
#line 228 "scherrerlester.y"
    {
				(yyval.typeInfo).type = (yyvsp[(1) - (1)].typeInfo).type;
				(yyval.typeInfo).numParams = (yyvsp[(1) - (1)].typeInfo).numParams;
				(yyval.typeInfo).returnType = (yyvsp[(1) - (1)].typeInfo).returnType;
				(yyval.typeInfo).integerValue = (yyvsp[(1) - (1)].typeInfo).integerValue;
				(yyval.typeInfo).booleanValue = (yyvsp[(1) - (1)].typeInfo).booleanValue;
				(yyval.typeInfo).stringValue = (yyvsp[(1) - (1)].typeInfo).stringValue;
				// printRule("PARENTHESIZED_EXPR", "INPUT_EXPR");
			;}
    break;

  case 16:
#line 238 "scherrerlester.y"
    {
				(yyval.typeInfo).type = (yyvsp[(1) - (1)].typeInfo).type;
				(yyval.typeInfo).numParams = (yyvsp[(1) - (1)].typeInfo).numParams;
				(yyval.typeInfo).returnType = (yyvsp[(1) - (1)].typeInfo).returnType;
				(yyval.typeInfo).integerValue = (yyvsp[(1) - (1)].typeInfo).integerValue;
				(yyval.typeInfo).booleanValue = (yyvsp[(1) - (1)].typeInfo).booleanValue;
				(yyval.typeInfo).stringValue = (yyvsp[(1) - (1)].typeInfo).stringValue;
				// printRule("PARENTHESIZED_EXPR", "PROGN_OR_USERFUNCTCALL");
			;}
    break;

  case 17:
#line 248 "scherrerlester.y"
    {
				// printRule("PARENTHESIZED_EXPR", "EXIT");
				printf("\nBye!");
				exit(1);
				
			;}
    break;

  case 18:
#line 256 "scherrerlester.y"
    {
				if ((yyvsp[(1) - (2)].typeInfo).type == PROGN_CODE)
				{
					if((yyvsp[(2) - (2)].typeInfo).type == UNDEFINED)
						(yyval.typeInfo).type = BOOL;
					else
						(yyval.typeInfo).type = (yyvsp[(2) - (2)].typeInfo).type;
				}
				else 
				{
					(yyval.typeInfo).type = (yyvsp[(1) - (2)].typeInfo).returnType;
					if((yyvsp[(2) - (2)].typeInfo).numParams > (yyvsp[(1) - (2)].typeInfo).numParams)
						yyerror("Too many parameters in function call");
					else if((yyvsp[(2) - (2)].typeInfo).numParams < (yyvsp[(1) - (2)].typeInfo).numParams)
					{
						yyerror("Too few parameters in function call");
					}
					// check that ident params is the same as actual params
				}
				(yyval.typeInfo).numParams = UNDEFINED;
				(yyval.typeInfo).returnType = UNDEFINED;
				if((yyvsp[(2) - (2)].typeInfo).type != UNDEFINED)
				{
					(yyval.typeInfo).integerValue = (yyvsp[(2) - (2)].typeInfo).integerValue;
					(yyval.typeInfo).booleanValue = (yyvsp[(2) - (2)].typeInfo).booleanValue;
					(yyval.typeInfo).stringValue = (yyvsp[(2) - (2)].typeInfo).stringValue;
				}
				else 
				{
					(yyval.typeInfo).integerValue = UNDEFINED;
					(yyval.typeInfo).stringValue = UNDEF_STR;
					(yyval.typeInfo).booleanValue = NIL;
				}
				// printRule("PROGN_OR_USERFUNCTCALL", "FUNCT_NAME EXPR_LIST");
			;}
    break;

  case 19:
#line 293 "scherrerlester.y"
    {
				(yyval.typeInfo).type = (yyvsp[(1) - (1)].typeInfo).type;
				(yyval.typeInfo).returnType = UNDEFINED;
				(yyval.typeInfo).numParams = numExprParams;
				numExprParams = 0;
				
			;}
    break;

  case 20:
#line 301 "scherrerlester.y"
    {
				(yyval.typeInfo).type = UNDEFINED;
				(yyval.typeInfo).returnType = UNDEFINED;
				(yyval.typeInfo).numParams = numExprParams;
			;}
    break;

  case 21:
#line 308 "scherrerlester.y"
    {
				(yyval.typeInfo).type = PROGN_CODE;
				(yyval.typeInfo).returnType = UNDEFINED;
				(yyval.typeInfo).numParams = UNDEFINED;
				// printRule("FUNCT_NAME", "PROGN");
			;}
    break;

  case 22:
#line 316 "scherrerlester.y"
    {
				if((yyvsp[(2) - (2)].typeInfo).type == FUNCTION)
					yyerror("Arg 1 cannot be a function");
				(yyval.typeInfo).type = BOOL;
				(yyval.typeInfo).returnType = UNDEFINED;
				(yyval.typeInfo).numParams = UNDEFINED;
				(yyval.typeInfo).integerValue = UNDEFINED;
				(yyval.typeInfo).stringValue = UNDEF_STR;
				if((yyvsp[(2) - (2)].typeInfo).booleanValue != NIL)
					(yyval.typeInfo).booleanValue = NIL;
				else
					(yyval.typeInfo).booleanValue = 1;
				// printRule("ARITHLOGIC_EXPR","UN_OP EXPR");
			;}
    break;

  case 23:
#line 331 "scherrerlester.y"
    {
				
				if((yyvsp[(1) - (3)].typeInfo).type == MULT || (yyvsp[(1) - (3)].typeInfo).type == SUB || (yyvsp[(1) - (3)].typeInfo).type == DIV || (yyvsp[(1) - (3)].typeInfo).type == ADD)
				{
					// anything that has an int in it has a 1 in the far right place in binary
					// so, we take the two values and & them together to check the bits they share,
					// and then and them with INT to only set the far right bit if set, and then check 
					// if that far right int is set. 
					if((((yyvsp[(2) - (3)].typeInfo).type & (yyvsp[(3) - (3)].typeInfo).type) & INT) == INT)
					{
						(yyval.typeInfo).type = INT;
						(yyval.typeInfo).numParams = UNDEFINED;
						(yyval.typeInfo).returnType = UNDEFINED;

						int val1 = (yyvsp[(2) - (3)].typeInfo).integerValue;
						int val2 = (yyvsp[(3) - (3)].typeInfo).integerValue;
						int endResult;
						//printf("%u   ", $1.type);
						switch ((yyvsp[(1) - (3)].typeInfo).type)
						{
							case MULT:
								endResult = val1 * val2;
								break;
							case DIV:
								if (val2 == 0)
									yyerror("Attempted division by zero");
								else
									endResult = val1 / val2; 
								break;
							case ADD:
								endResult = val1 + val2;
								break;
							case SUB:
								endResult = val1 - val2;
								break;
						}
						(yyval.typeInfo).integerValue = endResult;

					}
					// else if these don't work then we need to determine who is the issue, 
					// starting with the first N_EXPR.
					else if(((yyvsp[(2) - (3)].typeInfo).type & INT) != INT)
						yyerror("Arg 1 must be integer");
					else if(((yyvsp[(3) - (3)].typeInfo).type & INT) != INT)
						yyerror("Arg 2 must be integer");
				}
				else if((yyvsp[(1) - (3)].typeInfo).type == LT || (yyvsp[(1) - (3)].typeInfo).type == GT || (yyvsp[(1) - (3)].typeInfo).type == LE || (yyvsp[(1) - (3)].typeInfo).type == GE || (yyvsp[(1) - (3)].typeInfo).type == EQ || (yyvsp[(1) - (3)].typeInfo).type == NE)
				{
					// same bitwise logic as above
					if((yyvsp[(2) - (3)].typeInfo).type == FUNCTION)
						yyerror("Arg 1 must be integer or string");
					else if((yyvsp[(3) - (3)].typeInfo).type == FUNCTION)
						yyerror("Arg 2 must be integer or string");
					if((((yyvsp[(2) - (3)].typeInfo).type & (yyvsp[(3) - (3)].typeInfo).type) & INT) == INT)  
					{
						(yyval.typeInfo).type = BOOL;
						(yyval.typeInfo).numParams = UNDEFINED;
						(yyval.typeInfo).returnType = UNDEFINED;
						int val1 = (yyvsp[(2) - (3)].typeInfo).integerValue;
						int val2 = (yyvsp[(3) - (3)].typeInfo).integerValue;
						int endResult = NIL;
						
						switch((yyvsp[(1) - (3)].typeInfo).type)
						{
							case LT:
								if (val1 < val2)
									endResult = 1;
								break;
							case GT:
								if (val1 > val2)
									endResult = 1;
								break;
							case LE:
								if (val1 <= val2)
									endResult = 1;
								break;
							case GE:
								if (val1 >= val2)
									endResult = 1;
								break;
							case EQ:
								if (val1 == val2)
									endResult = 1;
								break;
							case NE:
								if (val1 != val2)
									endResult = 1;
								break;
						}
						(yyval.typeInfo).booleanValue = endResult;
						(yyval.typeInfo).stringValue = UNDEF_STR;
						(yyval.typeInfo).integerValue = UNDEFINED;
					}
					else if ((((yyvsp[(2) - (3)].typeInfo).type & (yyvsp[(3) - (3)].typeInfo).type) & STR) == STR)
					{
						(yyval.typeInfo).type = BOOL;
						(yyval.typeInfo).numParams = UNDEFINED;
						(yyval.typeInfo).returnType = UNDEFINED;
						string val1 = static_cast<string>((yyvsp[(2) - (3)].typeInfo).stringValue);
						string val2 = static_cast<string>((yyvsp[(3) - (3)].typeInfo).stringValue);
						int endResult = NIL;
						
						switch((yyvsp[(1) - (3)].typeInfo).type)
						{
							case LT:
								if (val1 < val2)
									endResult = 1;
								break;
							case GT:
								if (val1 > val2)
									endResult = 1;
								break;
							case LE:
								if (val1 <= val2)
									endResult = 1;
								break;
							case GE:
								if (val1 >= val2)
									endResult = 1;
								break;
							case EQ:
								if (val1 == val2)
									endResult = 1;
								break;
							case NE:
								if (val1 != val2)
									endResult = 1;
								break;
						}
						(yyval.typeInfo).booleanValue = endResult;
						(yyval.typeInfo).stringValue = UNDEF_STR;
						(yyval.typeInfo).integerValue = UNDEFINED;
					}
					
					else if(((yyvsp[(2) - (3)].typeInfo).type | INT_OR_STR) != INT_OR_STR)
						yyerror("Arg 1 must be integer or string");
					else if(((yyvsp[(3) - (3)].typeInfo).type | INT_OR_STR) != INT_OR_STR)
						yyerror("Arg 2 must be integer or string");
				}
				else if((yyvsp[(1) - (3)].typeInfo).type == AND || (yyvsp[(1) - (3)].typeInfo).type == OR)
				{
					if((yyvsp[(2) - (3)].typeInfo).type == FUNCTION)
						yyerror("Arg 1 cannot be a function");
					else if((yyvsp[(3) - (3)].typeInfo).type == FUNCTION)
						yyerror("Arg 2 cannot be a function");
					// same bitwise logic as above
					else if(((yyvsp[(2) - (3)].typeInfo).type | (yyvsp[(3) - (3)].typeInfo).type) != FUNCTION)
					{
						(yyval.typeInfo).type = BOOL;
						(yyval.typeInfo).numParams = UNDEFINED;
						(yyval.typeInfo).returnType = UNDEFINED;
						int endResult = NIL, val1 = (yyvsp[(2) - (3)].typeInfo).booleanValue, val2 = (yyvsp[(3) - (3)].typeInfo).booleanValue;
						switch((yyvsp[(1) - (3)].typeInfo).type)
						{
							case AND:
								if(val1 != NIL && val2 != NIL)
									endResult = 1;
								break;
							case OR:
								if(val1 != NIL || val2 != NIL)
									endResult = 1;
								break;
						}
						(yyval.typeInfo).booleanValue = endResult;
						(yyval.typeInfo).integerValue = UNDEFINED;
						(yyval.typeInfo).stringValue = UNDEF_STR;
					}
				}
				// printRule("ARITHLOGIC_EXPR", "BIN_OP EXPR EXPR");
			;}
    break;

  case 24:
#line 503 "scherrerlester.y"
    {
				
				//int theType;
				
				if((yyvsp[(2) - (4)].typeInfo).type == FUNCTION)
					yyerror("Arg 1 cannot be a function");
				else if((yyvsp[(3) - (4)].typeInfo).type == FUNCTION)
					yyerror("Arg 2 cannot be a function");
				else if((yyvsp[(4) - (4)].typeInfo).type == FUNCTION)
					yyerror("Arg 3 cannot be a function");
				/*
				else
				{
					if(($3.type | $4.type) == INT)
						theType = INT;
					else if(($3.type | $4.type) == STR)
						theType = STR;
					else if(($3.type | $4.type) == BOOL)
						theType = BOOL;
					// if we or the two types together and then and it with what we are checking, 
					// it should work
					else if((($3.type | $4.type) & INT_OR_STR) == INT_OR_STR)
						theType = INT_OR_STR;
					else if((($3.type | $4.type) & INT_OR_BOOL) == INT_OR_BOOL)
						theType = INT_OR_BOOL;
					else if((($3.type | $4.type) & STR_OR_BOOL) == STR_OR_BOOL)
						theType = STR_OR_BOOL;
					else if((($3.type | $4.type) & INT_OR_STR_OR_BOOL) == INT_OR_STR_OR_BOOL)
						theType = INT_OR_STR_OR_BOOL;
				}

					// can we get rid of all of the above now that we know the value of 
					// the if statement, and thus know for sure the type?

				*/
				// the below should be able to set everything correctly.
				if((yyvsp[(2) - (4)].typeInfo).booleanValue == NIL)
				{
					(yyval.typeInfo).integerValue = (yyvsp[(4) - (4)].typeInfo).integerValue;
					(yyval.typeInfo).booleanValue = (yyvsp[(4) - (4)].typeInfo).booleanValue;
					(yyval.typeInfo).stringValue = (yyvsp[(4) - (4)].typeInfo).stringValue;
					(yyval.typeInfo).type = (yyvsp[(4) - (4)].typeInfo).type;
					(yyval.typeInfo).numParams = (yyvsp[(4) - (4)].typeInfo).numParams;
					(yyval.typeInfo).returnType = (yyvsp[(4) - (4)].typeInfo).returnType;
				}
				else 
				{
					(yyval.typeInfo).integerValue = (yyvsp[(3) - (4)].typeInfo).integerValue;
					(yyval.typeInfo).booleanValue = (yyvsp[(3) - (4)].typeInfo).booleanValue;
					(yyval.typeInfo).stringValue = (yyvsp[(3) - (4)].typeInfo).stringValue;
					(yyval.typeInfo).type = (yyvsp[(3) - (4)].typeInfo).type;
					(yyval.typeInfo).numParams = (yyvsp[(3) - (4)].typeInfo).numParams;
					(yyval.typeInfo).returnType = (yyvsp[(3) - (4)].typeInfo).returnType;
				}	
				// printRule("IF_EXPR"," IF EXPR EXPR EXPR");
			;}
    break;

  case 25:
#line 561 "scherrerlester.y"
    {
				leaveScope();
				if((yyvsp[(5) - (5)].typeInfo).type == FUNCTION)
					yyerror("Arg 2 cannot be a function");
				(yyval.typeInfo).type = (yyvsp[(5) - (5)].typeInfo).type;
				(yyval.typeInfo).returnType = UNDEFINED;
				(yyval.typeInfo).numParams = UNDEFINED;
				(yyval.typeInfo).integerValue = (yyvsp[(5) - (5)].typeInfo).integerValue;
				(yyval.typeInfo).booleanValue = (yyvsp[(5) - (5)].typeInfo).booleanValue;
				(yyval.typeInfo).stringValue = (yyvsp[(5) - (5)].typeInfo).stringValue;
				// printRule("LET_EXPR", "let* ( ID_EXPR_LIST ) EXPR");
				
			;}
    break;

  case 26:
#line 577 "scherrerlester.y"
    { 
				// printRule("ID_EXPR_LIST", "epsilon");
			;}
    break;

  case 27:
#line 582 "scherrerlester.y"
    {
				// printRule("ID_EXPR_LIST","ID_EXPR_LIST ( IDENT EXPR )");
				bool found = scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(string((yyvsp[(3) - (5)].text)), (yyvsp[(4) - (5)].typeInfo).type, (yyvsp[(4) - (5)].typeInfo).returnType, (yyvsp[(4) - (5)].typeInfo).numParams, (yyvsp[(4) - (5)].typeInfo).integerValue, (yyvsp[(4) - (5)].typeInfo).booleanValue, (yyvsp[(4) - (5)].typeInfo).stringValue));
				if(!found)
					yyerror("Multiply defined identifer");
			;}
    break;

  case 28:
#line 590 "scherrerlester.y"
    {
				// printRule("PRINT_EXPR", "print EXPR");
				if((yyvsp[(2) - (2)].typeInfo).type == FUNCTION)
					yyerror("Arg 1 cannot be a function");
				(yyval.typeInfo).type = (yyvsp[(2) - (2)].typeInfo).type;
				(yyval.typeInfo).returnType = (yyvsp[(2) - (2)].typeInfo).returnType;
				(yyval.typeInfo).numParams = (yyvsp[(2) - (2)].typeInfo).numParams;
				(yyval.typeInfo).integerValue = (yyvsp[(2) - (2)].typeInfo).integerValue;
				(yyval.typeInfo).booleanValue = (yyvsp[(2) - (2)].typeInfo).booleanValue;
				(yyval.typeInfo).stringValue = (yyvsp[(2) - (2)].typeInfo).stringValue;
				if((yyval.typeInfo).integerValue != UNDEFINED)
				{
					printIntegerEnding((yyval.typeInfo).integerValue, 0);
					printf("\n");
				}
				else if((yyval.typeInfo).booleanValue != UNDEFINED)
				{
					printBooleanEnding((yyval.typeInfo).booleanValue, 0);
					printf("\n");
				}
				
				else if ((yyval.typeInfo).stringValue != UNDEF_STR)
				{
					printStringEnding((yyval.typeInfo).stringValue, 0);
					printf("\n");
				}
			;}
    break;

  case 29:
#line 619 "scherrerlester.y"
    {
				string readIn;
				getline(cin, readIn);
				
				if(readIn[0] == '+' || readIn[0] == '-' || isdigit(readIn[0]))
				{
					(yyval.typeInfo).type = INT;
					(yyval.typeInfo).integerValue = atoi(readIn.c_str());
				}
				else
				{
					(yyval.typeInfo).type = STR;
					// ugly code but it wouldn't let me assign it any othe rway
					char* temp;
					strcpy(temp, readIn.c_str());
					(yyval.typeInfo).stringValue = temp;
				}
				// printRule("INPUT_EXPR", "INPUT");
				(yyval.typeInfo).returnType = UNDEFINED;
				(yyval.typeInfo).numParams = UNDEFINED;
			;}
    break;

  case 30:
#line 642 "scherrerlester.y"
    {
				// printRule("EXPR_LIST", "EXPR EXPR_LIST");
				(yyval.typeInfo).type = (yyvsp[(2) - (2)].typeInfo).type;
				(yyval.typeInfo).integerValue = (yyvsp[(2) - (2)].typeInfo).integerValue;
				(yyval.typeInfo).booleanValue = (yyvsp[(2) - (2)].typeInfo).booleanValue;
				(yyval.typeInfo).stringValue = (yyvsp[(2) - (2)].typeInfo).stringValue;
				(yyval.typeInfo).returnType = UNDEFINED;
				(yyval.typeInfo).numParams = UNDEFINED;
				numExprParams++;
			;}
    break;

  case 31:
#line 653 "scherrerlester.y"
    {
				(yyval.typeInfo).type = (yyvsp[(1) - (1)].typeInfo).type;
				(yyval.typeInfo).integerValue = (yyvsp[(1) - (1)].typeInfo).integerValue;
				(yyval.typeInfo).booleanValue = (yyvsp[(1) - (1)].typeInfo).booleanValue;
				(yyval.typeInfo).stringValue = (yyvsp[(1) - (1)].typeInfo).stringValue;
				(yyval.typeInfo).returnType = UNDEFINED;
				(yyval.typeInfo).numParams = UNDEFINED;
				numExprParams++;
				// printRule("EXPR_LIST", "EXPR");
			;}
    break;

  case 32:
#line 665 "scherrerlester.y"
    {
				(yyval.typeInfo).type = (yyvsp[(1) - (1)].typeInfo).type;
				(yyval.typeInfo).returnType = UNDEFINED;
				(yyval.typeInfo).numParams = UNDEFINED;
				// printRule("BIN_OP", "ARITH_OP");
			;}
    break;

  case 33:
#line 672 "scherrerlester.y"
    {
				(yyval.typeInfo).type = (yyvsp[(1) - (1)].typeInfo).type;
				(yyval.typeInfo).returnType = UNDEFINED;
				(yyval.typeInfo).numParams = UNDEFINED;
				// printRule("BIN_OP", "LOG_OP");
			;}
    break;

  case 34:
#line 679 "scherrerlester.y"
    {
				(yyval.typeInfo).type = (yyvsp[(1) - (1)].typeInfo).type;
				(yyval.typeInfo).returnType = UNDEFINED;
				(yyval.typeInfo).numParams = UNDEFINED;
				// printRule("BIN_OP", "REL_OP");
			;}
    break;

  case 35:
#line 687 "scherrerlester.y"
    {
				(yyval.typeInfo).type = MULT;
				// printRule("ARITH_OP", "*");
			;}
    break;

  case 36:
#line 692 "scherrerlester.y"
    {
				(yyval.typeInfo).type = SUB;
				// printRule("ARITH_OP", "-");
			;}
    break;

  case 37:
#line 697 "scherrerlester.y"
    {
				(yyval.typeInfo).type = DIV;
				// printRule("ARITH_OP", "/");
			;}
    break;

  case 38:
#line 702 "scherrerlester.y"
    {
				(yyval.typeInfo).type = ADD;
				// printRule("ARITH_OP", "+");
			;}
    break;

  case 39:
#line 708 "scherrerlester.y"
    {
				(yyval.typeInfo).type = AND;
				// printRule("LOG_OP", "and");
			;}
    break;

  case 40:
#line 713 "scherrerlester.y"
    {
				(yyval.typeInfo).type = OR;
				// printRule("LOG_OP", "or");
			;}
    break;

  case 41:
#line 719 "scherrerlester.y"
    {
				(yyval.typeInfo).type = LT;
				// printRule("REL_OP", "<");
			;}
    break;

  case 42:
#line 724 "scherrerlester.y"
    {
				(yyval.typeInfo).type = GT;
				// printRule("REL_OP", ">");
			;}
    break;

  case 43:
#line 729 "scherrerlester.y"
    {
				(yyval.typeInfo).type = LE;
				// printRule("REL_OP", "<=");
			;}
    break;

  case 44:
#line 734 "scherrerlester.y"
    {
				(yyval.typeInfo).type = GE;
				// printRule("REL_OP", ">=");
			;}
    break;

  case 45:
#line 739 "scherrerlester.y"
    {
				(yyval.typeInfo).type = EQ;
				// printRule("REL_OP", "=");
			;}
    break;

  case 46:
#line 744 "scherrerlester.y"
    {
				(yyval.typeInfo).type = NE;
				// printRule("REL_OP", "!=");
			;}
    break;

  case 47:
#line 750 "scherrerlester.y"
    {
				// printRule("UN_OP", "not");
			;}
    break;


/* Line 1267 of yacc.c.  */
#line 2253 "scherrerlester.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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
		      yytoken, &yylval);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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


#line 758 "scherrerlester.y"


#include "lex.yy.c"
extern FILE *yyin;

void printRule(const char *lhs, const char *rhs) 
{
  printf("%s -> %s\n", lhs, rhs);
  return;
}

void yyerror(const char *s) 
{

  printf("Line %d: %s\n", numLines, s);
  printf("\nBye!");
  exit(1);
}

void printToken(const char* token, const char* lexeme) 
{
  printf("TOKEN: %s  LEXEME: %s\n", token, lexeme);
}
void printStringEnding(const char* s, const int end)
{
	if(end)
  		printf("\nValue of the expression is: %s\n", s);
	else
		printf("%s",s);
}
void printIntegerEnding(const int i, const int end)
{
	if(end)
		printf("\nValue of the expression is: %u\n", i);
	else
		printf("%u",i);
}
void printBooleanEnding(const int b, const int end)
{
	if (!end)
	{ 
		if (b != NIL)
		printf("t");
	else if(b == NIL)
		printf("nil");
	}
	else
	{
		if (b == 1)
			printf("\nValue of the expression is: %s\n", "t");
		else if(b == NIL)
			printf("\nValue of the expression is: %s\n", "nil");
	}	
}
void enterScope()
{
	scopeStack.push(SYMBOL_TABLE());
	// printf("\n___Entering new scope...\n\n");
}
void leaveScope()
{
	scopeStack.pop();
	// printf("\n___Exiting scope...\n\n");
}

bool findEntryInAnyScope(const string name)
{
	if(scopeStack.empty()) return(false);

	/*
		scopeStack.top() -> the most recent scope
		top().findEntry(name) -> findEntry inside of specific scope
	*/
	bool found = scopeStack.top().findEntry(name);
	if(found) 
		return(true);
	else
	{
		SYMBOL_TABLE tmp = scopeStack.top(); 
		scopeStack.pop();
		found = findEntryInAnyScope(name);
		scopeStack.push(tmp);
		return(found);
	}

}
// a modified version of findEntryinAnyScope that returns the typecode
int findTypeOfEntry(const string name)
{
	if(!findEntryInAnyScope(name))
		return NOT_FOUND;
	int type = NOT_FOUND;
	bool found = scopeStack.top().findEntry(name);
	if(found)
	{
		return(scopeStack.top().findType(name));
	}
	else
	{
		SYMBOL_TABLE tmp = scopeStack.top();
		scopeStack.pop();
		type = findTypeOfEntry(name);
		scopeStack.push(tmp);
		return(type);
	}
}
int findReturnTypeOfEntry(const string name)
{
	{
		if(!findEntryInAnyScope(name))
			return NOT_FOUND;
		int type = NOT_FOUND;
		bool found = scopeStack.top().findEntry(name);
		if(found)
		{
			return(scopeStack.top().findReturnType(name));
		}
		else
		{
			SYMBOL_TABLE tmp = scopeStack.top();
			scopeStack.pop();
			type = findReturnTypeOfEntry(name);
			scopeStack.push(tmp);
			return(type);
		}
	}
}
int findIntegerValue(const string name)
{
	bool found = scopeStack.top().findEntry(name);
	if(found)
		return scopeStack.top().findIntegerVal(name);
	else
	{
		SYMBOL_TABLE tmp = scopeStack.top();
		scopeStack.pop();
		int val = findIntegerValue(name);
		scopeStack.push(tmp);
		return(val);
	}
}
int findBooleanValue(const string name)
{
	bool found = scopeStack.top().findEntry(name);
	if(found)
		return scopeStack.top().findBooleanVal(name);
	else
	{
		SYMBOL_TABLE tmp = scopeStack.top();
		scopeStack.pop();
		int val = findBooleanValue(name);
		scopeStack.push(tmp);
		return(val);
	}
}
char* findStringValue(const string name)
{
	bool found = scopeStack.top().findEntry(name);
	if(found)
		return scopeStack.top().findStringVal(name);
	else
	{
		SYMBOL_TABLE tmp = scopeStack.top();
		scopeStack.pop();
		char* val = findStringValue(name);
		scopeStack.push(tmp);
		return(val);
	}
}
int findNumParamsOfEntry(const string name)
{
	{
		if(!findEntryInAnyScope(name))
			return NOT_FOUND;
		int type = NOT_FOUND;
		bool found = scopeStack.top().findEntry(name);
		if(found)
		{
			return(scopeStack.top().findNumParams(name));
		}
		else
		{
			SYMBOL_TABLE tmp = scopeStack.top();
			scopeStack.pop();
			type = findNumParamsOfEntry(name);
			scopeStack.push(tmp);
			return(type);
		}
	}
}
int main(int argc, char** argv) 
{
	if(argc < 1)
	{
		printf("You must specify a file in the command line!\n");
		exit(1);
	}
	yyin = fopen(argv[1], "r");
	do 
	{
		yyparse();
  	} while (!feof(yyin));
  	printf("\nBye!");
  	return(0);
}

