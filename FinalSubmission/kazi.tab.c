
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 12 "kazi.y"

    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<math.h>
    #include "identifier.c"
    int yyparse();
    int yylex();
    int yyerror();
    int ifdone[1000];
    struct datatype casedata;
    int caseflag;
    int ifptr=0;
    int dimencount = 0;
    struct ll_identifier *root=NULL,*last=NULL;
    int typenow = -1;
    int gcd(int a, int b) 
    { 
        if (b == 0) 
            return a; 
        return gcd(b, a % b);  
    }
    extern FILE *infotext;


/* Line 189 of yacc.c  */
#line 99 "kazi.tab.c"

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

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 36 "kazi.y"

    #ifndef __DT__
    #define __DT__
    struct __DT__ datatype {
        int type;
        char *strval;
        int intval;
        double doubleval;
    };
    #endif



/* Line 209 of yacc.c  */
#line 137 "kazi.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NAME = 258,
     VARACCESS = 259,
     NUM = 260,
     STR = 261,
     FUNC = 262,
     CLASS = 263,
     INIT = 264,
     INT = 265,
     DOUBLE = 266,
     STRING = 267,
     CONST = 268,
     VOID = 269,
     VAR = 270,
     ELSEIF = 271,
     ELSE = 272,
     IF = 273,
     SWITCH = 274,
     CASE = 275,
     def_ault = 276,
     FOR = 277,
     WHILE = 278,
     DO = 279,
     CONTINUE = 280,
     RETURN = 281,
     RIGHT_ASSIGN = 282,
     LEFT_ASSIGN = 283,
     ADD_ASSIGN = 284,
     SUB_ASSIGN = 285,
     MUL_ASSIGN = 286,
     DIV_ASSIGN = 287,
     MOD_ASSIGN = 288,
     AND_ASSIGN = 289,
     XOR_ASSIGN = 290,
     OR_ASSIGN = 291,
     RIGHT_OP = 292,
     LEFT_OP = 293,
     INC_OP = 294,
     DEC_OP = 295,
     PTR_OP = 296,
     AND_OP = 297,
     OR_OP = 298,
     LE_OP = 299,
     GE_OP = 300,
     EQ_OP = 301,
     NE_OP = 302,
     PRINT = 303,
     SIN = 304,
     TAN = 305,
     LOG = 306,
     LOG10 = 307,
     COS = 308,
     ACOS = 309,
     ASIN = 310,
     ATAN = 311,
     GCD = 312,
     LCM = 313,
     POW = 314,
     IMPORT = 315
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 47 "kazi.y"

    char text[1009];
    struct datatype val;



/* Line 214 of yacc.c  */
#line 221 "kazi.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 233 "kazi.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   923

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNRULES -- Number of states.  */
#define YYNSTATES  294

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,     2,     2,     2,     2,     2,     2,
      64,    65,    71,    68,    67,    69,     2,    70,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,    63,
      72,    79,    73,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    80,     2,    81,    77,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,    78,    62,    76,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    74
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    16,    23,    24,
      36,    38,    40,    42,    44,    46,    47,    52,    53,    59,
      64,    65,    68,    71,    74,    77,    80,    83,    86,    89,
      92,    95,    96,   106,   107,   114,   118,   119,   122,   123,
     133,   135,   137,   139,   144,   149,   154,   159,   164,   169,
     176,   181,   186,   193,   200,   204,   208,   212,   216,   220,
     224,   228,   232,   236,   240,   244,   248,   252,   256,   259,
     262,   266,   270,   273,   276,   280,   284,   286,   290,   294,
     302,   306,   310,   312,   316,   317,   318,   328,   333,   337,
     340,   352,   356,   358,   362,   365,   368,   372,   376,   380,
     384,   388,   392,   396,   400,   408,   418,   419,   426,   427,
     432,   434,   435,   440,   441,   446
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      83,     0,    -1,    -1,    85,    83,    -1,   100,    83,    -1,
      84,    83,    -1,   117,    83,    -1,     8,     3,    61,    90,
      62,    63,    -1,    -1,     7,     3,    64,    88,    65,    41,
      87,    86,    61,    90,    62,    -1,    10,    -1,    11,    -1,
      12,    -1,    14,    -1,     3,    -1,    -1,     3,    66,    87,
      89,    -1,    -1,    67,     3,    66,    87,    89,    -1,    67,
       3,    66,    87,    -1,    -1,    96,    90,    -1,   100,    90,
      -1,   108,    90,    -1,   107,    90,    -1,   111,    90,    -1,
      95,    90,    -1,   112,    90,    -1,    99,    90,    -1,   113,
      90,    -1,    91,    90,    -1,    -1,    19,    64,    98,    65,
      66,    92,    61,    93,    62,    -1,    -1,    20,    98,    66,
      90,    94,    93,    -1,    21,    66,    90,    -1,    -1,    98,
      63,    -1,    -1,    18,    64,    98,    65,    61,    90,    62,
      97,   105,    -1,     5,    -1,     6,    -1,     4,    -1,    49,
      64,    98,    65,    -1,    55,    64,    98,    65,    -1,    54,
      64,    98,    65,    -1,    53,    64,    98,    65,    -1,    51,
      64,    98,    65,    -1,    52,    64,    98,    65,    -1,    59,
      64,    98,    67,    98,    65,    -1,    50,    64,    98,    65,
      -1,    56,    64,    98,    65,    -1,    58,    64,    98,    67,
      98,    65,    -1,    57,    64,    98,    67,    98,    65,    -1,
      98,    68,    98,    -1,    98,    69,    98,    -1,    98,    70,
      98,    -1,    98,    71,    98,    -1,    98,    44,    98,    -1,
      98,    45,    98,    -1,    98,    72,    98,    -1,    98,    73,
      98,    -1,    98,    46,    98,    -1,    98,    47,    98,    -1,
      64,    98,    65,    -1,    98,    42,    98,    -1,    98,    43,
      98,    -1,    98,    74,    98,    -1,    75,    98,    -1,    76,
      98,    -1,    98,    77,    98,    -1,    98,    78,    98,    -1,
      26,    95,    -1,    26,    63,    -1,    15,   101,    63,    -1,
     102,    67,   101,    -1,   102,    -1,     3,    66,    87,    -1,
       3,    79,    98,    -1,     3,    66,   103,    71,    64,    98,
      65,    -1,     3,    66,   103,    -1,    80,   104,    81,    -1,
      87,    -1,    80,   104,    81,    -1,    -1,    -1,    16,    64,
      98,    65,    61,    90,    62,   106,   105,    -1,    17,    61,
      90,    62,    -1,   110,    67,   107,    -1,   110,    63,    -1,
      22,    64,   109,    63,    98,    63,   109,    65,    61,    90,
      62,    -1,   110,    67,   109,    -1,   110,    -1,     4,    79,
      98,    -1,     4,    39,    -1,     4,    40,    -1,     4,    29,
      98,    -1,     4,    30,    98,    -1,     4,    31,    98,    -1,
       4,    32,    98,    -1,     4,    33,    98,    -1,     4,    34,
      98,    -1,     4,    35,    98,    -1,     4,    36,    98,    -1,
      23,    64,    98,    65,    61,    90,    62,    -1,    24,    61,
      90,    62,    23,    64,    98,    65,    63,    -1,    -1,    48,
      64,   114,   115,    65,    63,    -1,    -1,    98,   116,    67,
     115,    -1,    98,    -1,    -1,    60,   118,   119,    63,    -1,
      -1,     3,    67,   120,   119,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    71,    72,    73,    74,    77,    90,    90,
     106,   107,   108,   109,   110,   119,   120,   122,   123,   124,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   139,   139,   146,   146,   153,   158,   159,   164,   164,
     174,   177,   181,   204,   212,   220,   228,   236,   244,   252,
     265,   273,   281,   294,   307,   310,   313,   316,   319,   322,
     325,   328,   331,   334,   337,   340,   343,   346,   349,   352,
     355,   358,   364,   367,   371,   373,   374,   376,   385,   411,
     430,   450,   452,   453,   455,   456,   456,   462,   468,   469,
     472,   478,   479,   480,   513,   550,   587,   623,   659,   695,
     731,   767,   803,   839,   877,   882,   886,   886,   890,   890,
     893,   897,   897,   901,   901,   904
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "VARACCESS", "NUM", "STR",
  "FUNC", "CLASS", "INIT", "INT", "DOUBLE", "STRING", "CONST", "VOID",
  "VAR", "ELSEIF", "ELSE", "IF", "SWITCH", "CASE", "def_ault", "FOR",
  "WHILE", "DO", "CONTINUE", "RETURN", "RIGHT_ASSIGN", "LEFT_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "RIGHT_OP", "LEFT_OP", "INC_OP",
  "DEC_OP", "PTR_OP", "AND_OP", "OR_OP", "LE_OP", "GE_OP", "EQ_OP",
  "NE_OP", "PRINT", "SIN", "TAN", "LOG", "LOG10", "COS", "ACOS", "ASIN",
  "ATAN", "GCD", "LCM", "POW", "IMPORT", "'{'", "'}'", "';'", "'('", "')'",
  "':'", "','", "'+'", "'-'", "'/'", "'*'", "'<'", "'>'", "\"&\"", "'!'",
  "'~'", "'^'", "'|'", "'='", "'['", "']'", "$accept", "starthere",
  "classgrammer", "function", "$@1", "TYPE", "fparameter", "fsparameter",
  "statement", "switchgrammer", "$@2", "casegrammer", "$@3", "mathexpr",
  "ifgrammer", "$@4", "expression", "returnstmt", "declaration",
  "varriables", "varriable", "arraydim", "arrayx", "elsifgrmr", "$@5",
  "asgngrammer", "forgrammer", "forassign", "ASGNVAR", "whilegrammer",
  "dowhilegrameer", "printgrammer", "$@6", "manyexprgm", "$@7",
  "importgrammer", "$@8", "manyname", "$@9", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   123,   125,    59,    40,    41,    58,    44,    43,    45,
      47,    42,    60,    62,   316,    33,   126,    94,   124,    61,
      91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    83,    83,    83,    83,    84,    86,    85,
      87,    87,    87,    87,    87,    88,    88,    89,    89,    89,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    92,    91,    94,    93,    93,    93,    95,    97,    96,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    99,    99,   100,   101,   101,   102,   102,   102,
     102,   103,   104,   104,   105,   106,   105,   105,   107,   107,
     108,   109,   109,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   111,   112,   114,   113,   116,   115,
     115,   118,   117,   120,   119,   119
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     6,     0,    11,
       1,     1,     1,     1,     1,     0,     4,     0,     5,     4,
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     0,     9,     0,     6,     3,     0,     2,     0,     9,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     6,     6,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     3,     2,     2,     3,     3,     1,     3,     3,     7,
       3,     3,     1,     3,     0,     0,     9,     4,     3,     2,
      11,     3,     1,     3,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     7,     9,     0,     6,     0,     4,
       1,     0,     4,     0,     4,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,   111,     0,     2,     2,     2,     2,
       0,     0,     0,     0,    76,     0,     1,     5,     3,     4,
       6,    15,    20,     0,     0,    74,     0,   115,     0,     0,
       0,    42,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    20,    20,     0,
      20,    20,    20,    20,     0,    20,    20,    20,    14,    10,
      11,    12,    13,     0,    77,    80,    42,    78,    75,   113,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,     0,     0,     0,     0,     0,    20,    73,
      72,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    68,    69,     0,    30,    26,    21,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,    22,    24,    23,
      89,     0,    25,    27,    29,     0,    82,     0,     0,     0,
      17,     0,    96,    97,    98,    99,   100,   101,   102,   103,
      93,     0,     0,     0,     0,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,     7,    65,    66,    58,    59,    62,    63,    54,    55,
      56,    57,    60,    61,    67,    70,    71,    88,     0,    81,
       0,   114,     0,    16,     8,     0,     0,     0,     0,     0,
       0,   108,     0,    43,    50,    47,    48,    46,    45,    44,
      51,     0,     0,     0,    83,     0,     0,     0,    20,    31,
       0,    91,    20,     0,     0,     0,     0,     0,     0,    79,
       0,    20,     0,     0,     0,     0,     0,     0,   107,    53,
      52,    49,    17,     0,    38,    36,     0,   104,     0,   109,
      18,     9,    84,     0,     0,     0,     0,     0,     0,     0,
      39,     0,    20,    32,    20,   105,     0,    20,    20,    35,
       0,     0,     0,    33,    90,     0,    87,    36,    20,    34,
       0,    85,    84,    86
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,   227,   146,    30,   203,    55,    56,
     243,   265,   287,    57,    58,   262,    59,    60,    61,    13,
      14,    75,   147,   270,   292,    62,    63,   164,    64,    65,
      66,    67,   168,   212,   234,     9,    15,    28,   149
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -203
static const yytype_int16 yypact[] =
{
      31,    -1,     8,    16,  -203,    21,    31,    31,    31,    31,
     -37,   -26,   -48,   -22,   -30,    47,  -203,  -203,  -203,  -203,
    -203,    55,   110,    12,   207,  -203,    16,     0,     5,     6,
       9,   211,  -203,  -203,    13,    25,    26,    29,    15,   151,
      30,    53,    58,    59,    60,    62,    63,    66,    67,    71,
      73,    74,   207,   207,   207,    33,   110,   110,   110,   230,
     110,   110,   110,   110,   -47,   110,   110,   110,  -203,  -203,
    -203,  -203,  -203,    22,  -203,    68,  -203,   845,  -203,  -203,
    -203,    37,    99,   207,   207,   207,   207,   207,   207,   207,
     207,  -203,  -203,   207,   207,   207,   137,   207,   110,  -203,
    -203,  -203,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   267,   845,   845,    79,  -203,  -203,  -203,
     207,   207,   207,   207,   207,   207,  -203,   207,   207,   207,
     207,   207,   207,   207,   207,   207,  -203,  -203,  -203,  -203,
    -203,   137,  -203,  -203,  -203,    22,  -203,    65,    83,    47,
      76,    37,   845,   845,   845,   845,   845,   845,   845,   845,
     845,   278,   315,   211,    85,    84,   326,    88,   207,   363,
     374,   411,   422,   459,   470,   507,   518,   555,   567,   604,
    -203,  -203,   845,   845,   845,   845,   845,   845,   845,   845,
     845,   845,   845,   845,   845,   845,   845,  -203,    72,  -203,
     207,  -203,   149,  -203,  -203,    93,   104,   207,   137,   111,
     148,   615,   108,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,   207,   207,   207,  -203,   652,   114,   116,   110,  -203,
     664,  -203,   110,   117,   115,   121,   701,   712,   749,  -203,
      37,   110,   125,   128,   137,   129,   207,   207,  -203,  -203,
    -203,  -203,    76,   130,  -203,    23,   113,  -203,   760,  -203,
    -203,  -203,    40,   207,   124,   131,   133,   132,   152,   135,
    -203,   797,   110,  -203,   110,  -203,   207,   110,   110,  -203,
     155,   808,   156,  -203,  -203,   159,  -203,    23,   110,  -203,
     166,  -203,    40,  -203
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -203,    46,  -203,  -203,  -203,    -6,  -203,   -23,   -53,  -203,
    -203,   -57,  -203,   192,  -203,  -203,   -24,  -203,   112,   206,
    -203,  -203,    91,   -59,  -203,    96,  -203,  -202,   -95,  -203,
    -203,  -203,  -203,    -9,  -203,  -203,  -203,   100,  -203
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -111
static const yytype_int16 yytable[] =
{
      77,   165,    10,   117,   118,   119,   231,   136,   137,   138,
     139,    11,   142,   143,   144,    68,   140,    74,    23,    12,
     141,    16,    69,    70,    71,    68,    72,    21,   113,   114,
     115,    24,    69,    70,    71,    22,    72,    26,     1,     2,
      68,    25,   256,   263,   264,   167,     3,    69,    70,    71,
      27,    72,    17,    18,    19,    20,   268,   269,    29,   152,
     153,   154,   155,   156,   157,   158,   159,    79,    80,   160,
     161,   162,    81,   166,    82,   150,    98,    94,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,    95,
      96,     4,    73,    97,   101,   116,   182,   183,   184,   185,
     186,   187,   145,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     8,   165,    31,    32,    33,   102,     8,     8,
       8,     8,   103,   104,   105,     3,   106,   107,    34,    35,
     108,   109,    36,    37,    38,   110,    39,   111,   112,   148,
     151,   163,   181,   202,   211,   204,   199,   200,   207,   165,
     210,   208,   226,   224,   228,    76,    32,    33,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
     229,   233,   232,   235,    52,   242,   225,   241,   266,   245,
     240,   246,   247,   230,   248,    53,    54,   254,   253,   255,
     272,   257,   261,   273,   274,   275,   277,   236,   237,   238,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    76,    32,    33,    99,    52,   276,   284,   286,   279,
     288,   280,   258,   211,   282,   283,    53,    54,   291,   260,
     289,   100,    78,   293,   252,   290,   198,   197,   259,   271,
      83,    84,    85,    86,    87,    88,    89,    90,     0,   201,
      91,    92,   281,     0,     0,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,     0,     0,     0,
       0,    52,   120,   121,   122,   123,   124,   125,     0,     0,
       0,     0,    53,    54,     0,     0,     0,     0,     0,     0,
      93,     0,     0,   126,     0,     0,     0,     0,   127,   128,
     129,   130,   131,   132,   133,     0,     0,   134,   135,   120,
     121,   122,   123,   124,   125,     0,     0,     0,     0,     0,
     120,   121,   122,   123,   124,   125,     0,     0,     0,     0,
       0,     0,   180,     0,     0,   127,   128,   129,   130,   131,
     132,   133,     0,   205,   134,   135,   127,   128,   129,   130,
     131,   132,   133,     0,     0,   134,   135,   120,   121,   122,
     123,   124,   125,     0,     0,     0,     0,     0,   120,   121,
     122,   123,   124,   125,     0,     0,     0,     0,     0,     0,
     206,     0,     0,   127,   128,   129,   130,   131,   132,   133,
       0,   209,   134,   135,   127,   128,   129,   130,   131,   132,
     133,     0,     0,   134,   135,   120,   121,   122,   123,   124,
     125,     0,     0,     0,     0,     0,   120,   121,   122,   123,
     124,   125,     0,     0,     0,     0,     0,     0,   213,     0,
       0,   127,   128,   129,   130,   131,   132,   133,     0,   214,
     134,   135,   127,   128,   129,   130,   131,   132,   133,     0,
       0,   134,   135,   120,   121,   122,   123,   124,   125,     0,
       0,     0,     0,     0,   120,   121,   122,   123,   124,   125,
       0,     0,     0,     0,     0,     0,   215,     0,     0,   127,
     128,   129,   130,   131,   132,   133,     0,   216,   134,   135,
     127,   128,   129,   130,   131,   132,   133,     0,     0,   134,
     135,   120,   121,   122,   123,   124,   125,     0,     0,     0,
       0,     0,   120,   121,   122,   123,   124,   125,     0,     0,
       0,     0,     0,     0,   217,     0,     0,   127,   128,   129,
     130,   131,   132,   133,     0,   218,   134,   135,   127,   128,
     129,   130,   131,   132,   133,     0,     0,   134,   135,   120,
     121,   122,   123,   124,   125,     0,     0,     0,     0,     0,
     120,   121,   122,   123,   124,   125,     0,     0,     0,     0,
       0,     0,   219,     0,     0,   127,   128,   129,   130,   131,
     132,   133,     0,   220,   134,   135,   127,   128,   129,   130,
     131,   132,   133,     0,     0,   134,   135,   120,   121,   122,
     123,   124,   125,     0,     0,     0,     0,     0,     0,   120,
     121,   122,   123,   124,   125,     0,     0,     0,     0,     0,
       0,     0,   221,   127,   128,   129,   130,   131,   132,   133,
       0,     0,   134,   135,   222,   127,   128,   129,   130,   131,
     132,   133,     0,     0,   134,   135,   120,   121,   122,   123,
     124,   125,     0,     0,     0,     0,     0,   120,   121,   122,
     123,   124,   125,     0,     0,     0,     0,     0,     0,     0,
       0,   223,   127,   128,   129,   130,   131,   132,   133,     0,
    -110,   134,   135,   127,   128,   129,   130,   131,   132,   133,
       0,     0,   134,   135,   120,   121,   122,   123,   124,   125,
       0,     0,     0,     0,     0,     0,   120,   121,   122,   123,
     124,   125,     0,     0,     0,     0,     0,   239,     0,     0,
     127,   128,   129,   130,   131,   132,   133,   244,     0,   134,
     135,     0,   127,   128,   129,   130,   131,   132,   133,     0,
       0,   134,   135,   120,   121,   122,   123,   124,   125,     0,
       0,     0,     0,     0,   120,   121,   122,   123,   124,   125,
       0,     0,     0,     0,     0,     0,   249,     0,     0,   127,
     128,   129,   130,   131,   132,   133,     0,   250,   134,   135,
     127,   128,   129,   130,   131,   132,   133,     0,     0,   134,
     135,   120,   121,   122,   123,   124,   125,     0,     0,     0,
       0,     0,   120,   121,   122,   123,   124,   125,     0,     0,
       0,     0,     0,     0,   251,     0,     0,   127,   128,   129,
     130,   131,   132,   133,     0,   267,   134,   135,   127,   128,
     129,   130,   131,   132,   133,     0,     0,   134,   135,   120,
     121,   122,   123,   124,   125,     0,     0,     0,     0,     0,
     120,   121,   122,   123,   124,   125,     0,     0,     0,     0,
       0,     0,     0,   278,     0,   127,   128,   129,   130,   131,
     132,   133,     0,   285,   134,   135,   127,   128,   129,   130,
     131,   132,   133,     0,     0,   134,   135,   120,   121,   122,
     123,   124,   125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,   128,   129,   130,   131,   132,   133,
       0,     0,   134,   135
};

static const yytype_int16 yycheck[] =
{
      24,    96,     3,    56,    57,    58,   208,    60,    61,    62,
      63,     3,    65,    66,    67,     3,    63,    23,    66,     3,
      67,     0,    10,    11,    12,     3,    14,    64,    52,    53,
      54,    79,    10,    11,    12,    61,    14,    67,     7,     8,
       3,    63,   244,    20,    21,    98,    15,    10,    11,    12,
       3,    14,     6,     7,     8,     9,    16,    17,     3,    83,
      84,    85,    86,    87,    88,    89,    90,    67,    63,    93,
      94,    95,    66,    97,    65,    81,    61,    64,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    64,
      64,    60,    80,    64,    64,    62,   120,   121,   122,   123,
     124,   125,    80,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,   208,     4,     5,     6,    64,     6,     7,
       8,     9,    64,    64,    64,    15,    64,    64,    18,    19,
      64,    64,    22,    23,    24,    64,    26,    64,    64,    71,
      41,     4,    63,    67,   168,   151,    81,    64,    63,   244,
      62,    67,     3,    81,    61,     4,     5,     6,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      66,    23,    61,    65,    64,   228,   200,    61,    65,   232,
      66,    64,    67,   207,    63,    75,    76,    62,   241,    61,
      66,    62,    62,    62,    61,    63,    61,   221,   222,   223,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     4,     5,     6,    63,    64,    64,    62,    62,   272,
      61,   274,   246,   247,   277,   278,    75,    76,    62,   252,
     287,    39,    26,   292,   240,   288,   145,   141,   247,   263,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,   149,
      39,    40,   276,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    64,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    -1,    63,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,    77,    78,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    68,    69,    70,    71,    72,
      73,    74,    -1,    65,    77,    78,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    77,    78,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    68,    69,    70,    71,    72,    73,    74,
      -1,    65,    77,    78,    68,    69,    70,    71,    72,    73,
      74,    -1,    -1,    77,    78,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    68,    69,    70,    71,    72,    73,    74,    -1,    65,
      77,    78,    68,    69,    70,    71,    72,    73,    74,    -1,
      -1,    77,    78,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    68,
      69,    70,    71,    72,    73,    74,    -1,    65,    77,    78,
      68,    69,    70,    71,    72,    73,    74,    -1,    -1,    77,
      78,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    68,    69,    70,
      71,    72,    73,    74,    -1,    65,    77,    78,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,    77,    78,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    68,    69,    70,    71,    72,
      73,    74,    -1,    65,    77,    78,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    77,    78,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    -1,    77,    78,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    -1,    77,    78,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      65,    77,    78,    68,    69,    70,    71,    72,    73,    74,
      -1,    -1,    77,    78,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      68,    69,    70,    71,    72,    73,    74,    63,    -1,    77,
      78,    -1,    68,    69,    70,    71,    72,    73,    74,    -1,
      -1,    77,    78,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    68,
      69,    70,    71,    72,    73,    74,    -1,    65,    77,    78,
      68,    69,    70,    71,    72,    73,    74,    -1,    -1,    77,
      78,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    68,    69,    70,
      71,    72,    73,    74,    -1,    65,    77,    78,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,    77,    78,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    -1,    65,    77,    78,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    77,    78,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    72,    73,    74,
      -1,    -1,    77,    78
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,    15,    60,    83,    84,    85,   100,   117,
       3,     3,     3,   101,   102,   118,     0,    83,    83,    83,
      83,    64,    61,    66,    79,    63,    67,     3,   119,     3,
      88,     4,     5,     6,    18,    19,    22,    23,    24,    26,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    64,    75,    76,    90,    91,    95,    96,    98,
      99,   100,   107,   108,   110,   111,   112,   113,     3,    10,
      11,    12,    14,    80,    87,   103,     4,    98,   101,    67,
      63,    66,    65,    29,    30,    31,    32,    33,    34,    35,
      36,    39,    40,    79,    64,    64,    64,    64,    61,    63,
      95,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    98,    98,    98,    62,    90,    90,    90,
      42,    43,    44,    45,    46,    47,    63,    68,    69,    70,
      71,    72,    73,    74,    77,    78,    90,    90,    90,    90,
      63,    67,    90,    90,    90,    80,    87,   104,    71,   120,
      87,    41,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,     4,   109,   110,    98,    90,   114,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      65,    63,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,   107,   104,    81,
      64,   119,    67,    89,    87,    65,    65,    63,    67,    65,
      62,    98,   115,    65,    65,    65,    65,    65,    65,    65,
      65,    67,    67,    67,    81,    98,     3,    86,    61,    66,
      98,   109,    61,    23,   116,    65,    98,    98,    98,    65,
      66,    61,    90,    92,    63,    90,    64,    67,    63,    65,
      65,    65,    87,    90,    62,    61,   109,    62,    98,   115,
      89,    62,    97,    20,    21,    93,    65,    65,    16,    17,
     105,    98,    66,    62,    61,    63,    64,    61,    66,    90,
      90,    98,    90,    90,    62,    65,    62,    94,    61,    93,
      90,    62,   106,   105
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 67 "kazi.y"
    {
                fprintf(infotext,"\nCompiled Successfully\n\n");
                fprint_all(root,infotext);
            ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 77 "kazi.y"
    {
                    int res = addNewClass(&root,&last,(yyvsp[(2) - (6)].text),"");
                    if(!res)
                    {
                        printf("Compilation Error ::  this name :: %s is already declared\n",(yyvsp[(2) - (6)].text));
                        exit(-1);
                    }
                    else{
                        fprintf(infotext,"Class declared :: %s\n",(yyvsp[(2) - (6)].text));
                    }
                ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 90 "kazi.y"
    {
                char *val;
                int n = log10(typenow) + 1;
                val = calloc(n + 1, sizeof(char));
                snprintf(val, n, "%ld", typenow);
                int res = addNewFunc(&root,&last,(yyvsp[(2) - (7)].text),val);
                if(!res)
                {
                    printf("Compilation Error ::  Varribale %s is already declared\n",(yyvsp[(2) - (7)].text));
                    exit(-1);
                }
                else{
                    fprintf(infotext,"Function declared :: %s\n",(yyvsp[(2) - (7)].text));
                }
            ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 106 "kazi.y"
    { typenow = 1;;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 107 "kazi.y"
    { typenow = 2;;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 108 "kazi.y"
    { typenow = 3;;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 109 "kazi.y"
    { typenow = 4;;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 110 "kazi.y"
    {  
                struct ll_identifier* res = getVal(&root,(yyvsp[(1) - (1)].text));
                if(res==NULL || res->data.type!=6){
                    printf("Error :: Class Name Not defined\n");
                    exit(-1);
                }
                typenow = res->data.intval;
            ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 139 "kazi.y"
    {
                    casedata = (yyvsp[(3) - (5)].val);
                    fprintf(infotext,"Switch Case declared\n");
                    fprint_datatype(casedata,infotext);
                ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 146 "kazi.y"
    {
                    if(caseflag == 0 && evaluate((yyvsp[(2) - (4)].val),casedata,"==").intval == 1){
                        caseflag = 1;
                        fprintf(infotext,"Case executed :: ");
                        fprint_datatype((yyvsp[(2) - (4)].val),infotext);
                    }
                ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 153 "kazi.y"
    {
                    if(caseflag == 0){
                        fprintf(infotext,"Defualt executed\n");
                    }
                ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 159 "kazi.y"
    {
                    printf("Value of the expression :: ");
                    print_datatype((yyvsp[(1) - (2)].val));
            ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 164 "kazi.y"
    {
                ifptr++;
                if(boolvalue((yyvsp[(3) - (7)].val))){
                    fprintf(infotext,"IF executed \n");
                    ifdone[ifptr] = 1;
                }
            ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 170 "kazi.y"
    {
                ifptr--;
            ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 174 "kazi.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val);
                     //print_datatype($1);
            ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 177 "kazi.y"
    {
                (yyval.val) = (yyvsp[(1) - (1)].val); 
                //print_datatype($1);
            ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 181 "kazi.y"
    {
                struct ll_identifier* res = isDeclared(&root,(yyvsp[(1) - (1)].text));
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",(yyvsp[(1) - (1)].text));
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                else 
                {
                    if(res->data.type==2)
                        (yyval.val) = make_datatype_int(res->data.intval);
                    else if(res->data.type==3)
                        (yyval.val) = make_datatype_double(res->data.doubleval);
                    else if(res->data.type==4){
                        (yyval.val) = make_datatype_char(res->data.strval);
                    }
                }
            ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 204 "kazi.y"
    {
                    if((yyvsp[(3) - (4)].val).type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = (yyvsp[(3) - (4)].val).type==2?(yyvsp[(3) - (4)].val).intval:(yyvsp[(3) - (4)].val).doubleval;
                    fprintf(infotext,"Value of the expression :: %f\n",sin(val));
            ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 212 "kazi.y"
    {
                    if((yyvsp[(3) - (4)].val).type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = (yyvsp[(3) - (4)].val).type==2?(yyvsp[(3) - (4)].val).intval:(yyvsp[(3) - (4)].val).doubleval;
                    fprintf(infotext,"Value of the expression :: %f\n",asin(val));
            ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 220 "kazi.y"
    {
                    if((yyvsp[(3) - (4)].val).type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = (yyvsp[(3) - (4)].val).type==2?(yyvsp[(3) - (4)].val).intval:(yyvsp[(3) - (4)].val).doubleval;
                    fprintf(infotext,"Value of the expression :: %f\n",acos(val));
            ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 228 "kazi.y"
    {
                    if((yyvsp[(3) - (4)].val).type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = (yyvsp[(3) - (4)].val).type==2?(yyvsp[(3) - (4)].val).intval:(yyvsp[(3) - (4)].val).doubleval;
                    fprintf(infotext,"Value of the expression :: %f\n",cos(val));
            ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 236 "kazi.y"
    {
                    if((yyvsp[(3) - (4)].val).type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = (yyvsp[(3) - (4)].val).type==2?(yyvsp[(3) - (4)].val).intval:(yyvsp[(3) - (4)].val).doubleval;
                    fprintf(infotext,"Value of the expression :: %f\n",log(val));
            ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 244 "kazi.y"
    {
                    if((yyvsp[(3) - (4)].val).type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = (yyvsp[(3) - (4)].val).type==2?(yyvsp[(3) - (4)].val).intval:(yyvsp[(3) - (4)].val).doubleval;
                    fprintf(infotext,"Value of the expression :: %f\n",log10(val));
            ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 252 "kazi.y"
    {
                    if((yyvsp[(3) - (6)].val).type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    if((yyvsp[(5) - (6)].val).type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = (yyvsp[(3) - (6)].val).type==2?(yyvsp[(3) - (6)].val).intval:(yyvsp[(3) - (6)].val).doubleval;
                    double p = (yyvsp[(5) - (6)].val).type==2?(yyvsp[(5) - (6)].val).intval:(yyvsp[(5) - (6)].val).doubleval;
                    fprintf(infotext,"Value of the expression :: %f\n",pow(val,p));
            ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 265 "kazi.y"
    {
                    if((yyvsp[(3) - (4)].val).type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = (yyvsp[(3) - (4)].val).type==2?(yyvsp[(3) - (4)].val).intval:(yyvsp[(3) - (4)].val).doubleval;
                    fprintf(infotext,"Value of the expression :: %f\n",tan(val));
            ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 273 "kazi.y"
    {
                    if((yyvsp[(3) - (4)].val).type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = (yyvsp[(3) - (4)].val).type==2?(yyvsp[(3) - (4)].val).intval:(yyvsp[(3) - (4)].val).doubleval;
                    fprintf(infotext,"Value of the expression :: %f\n",atan(val));
            ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 281 "kazi.y"
    {
                    if((yyvsp[(3) - (6)].val).type!=2){
                        printf("Compilation Error :: Cannot override for other than Int\n");
                        exit(-1);
                    }
                    if((yyvsp[(5) - (6)].val).type!=2){
                        printf("Compilation Error :: Cannot override for other than Int\n");
                        exit(-1);
                    }
                    int val1 = (yyvsp[(3) - (6)].val).intval; 
                    int val2 = (yyvsp[(5) - (6)].val).intval; 
                    fprintf(infotext,"Value of the expression :: %d\n",val1*val2/gcd(val1,val2));
            ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 294 "kazi.y"
    {
                    if((yyvsp[(3) - (6)].val).type!=2){
                        printf("Compilation Error :: Cannot override for other than Int\n");
                        exit(-1);
                    }
                    if((yyvsp[(5) - (6)].val).type!=2){
                        printf("Compilation Error :: Cannot override for other than Int\n");
                        exit(-1);
                    }
                    int val1 = (yyvsp[(3) - (6)].val).intval; 
                    int val2 = (yyvsp[(5) - (6)].val).intval; 
                    fprintf(infotext,"Value of the expression :: %d\n",gcd(val1,val2));
            ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 307 "kazi.y"
    { 
                (yyval.val) = evaluate((yyvsp[(1) - (3)].val),(yyvsp[(3) - (3)].val),"+");
            ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 310 "kazi.y"
    { 
                (yyval.val) = evaluate((yyvsp[(1) - (3)].val),(yyvsp[(3) - (3)].val),"-");
            ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 313 "kazi.y"
    { 
                (yyval.val) = evaluate((yyvsp[(1) - (3)].val),(yyvsp[(3) - (3)].val),"/");
            ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 316 "kazi.y"
    { 
                (yyval.val) = evaluate((yyvsp[(1) - (3)].val),(yyvsp[(3) - (3)].val),"*");
            ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 319 "kazi.y"
    { 
                (yyval.val) = evaluate((yyvsp[(1) - (3)].val),(yyvsp[(3) - (3)].val),"<=");
            ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 322 "kazi.y"
    { 
                (yyval.val) = evaluate((yyvsp[(1) - (3)].val),(yyvsp[(3) - (3)].val),">=");
            ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 325 "kazi.y"
    { 
                (yyval.val) = evaluate((yyvsp[(1) - (3)].val),(yyvsp[(3) - (3)].val),"<");
            ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 328 "kazi.y"
    { 
                (yyval.val) = evaluate((yyvsp[(1) - (3)].val),(yyvsp[(3) - (3)].val),">");
            ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 331 "kazi.y"
    { 
                (yyval.val) = evaluate((yyvsp[(1) - (3)].val),(yyvsp[(3) - (3)].val),"==");
            ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 334 "kazi.y"
    { 
                (yyval.val) = evaluate((yyvsp[(1) - (3)].val),(yyvsp[(3) - (3)].val),"!=");
            ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 337 "kazi.y"
    { 
                (yyval.val) = (yyvsp[(2) - (3)].val);
            ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 340 "kazi.y"
    {
                (yyval.val) = make_datatype_int(boolvalue((yyvsp[(1) - (3)].val)) && boolvalue((yyvsp[(3) - (3)].val)));
            ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 343 "kazi.y"
    {
                (yyval.val) = make_datatype_int(boolvalue((yyvsp[(1) - (3)].val)) || boolvalue((yyvsp[(3) - (3)].val)));
            ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 346 "kazi.y"
    {
                (yyval.val) = make_datatype_int(_intvalue((yyvsp[(1) - (3)].val)) & _intvalue((yyvsp[(3) - (3)].val)));
            ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 349 "kazi.y"
    {
                (yyval.val) = make_datatype_int(!_intvalue((yyvsp[(2) - (2)].val)));
            ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 352 "kazi.y"
    {
                (yyval.val) = make_datatype_int(~_intvalue((yyvsp[(2) - (2)].val)));
            ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 355 "kazi.y"
    {
                (yyval.val) = make_datatype_int(_intvalue((yyvsp[(1) - (3)].val)) ^ _intvalue((yyvsp[(3) - (3)].val)));
            ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 358 "kazi.y"
    {
                (yyval.val) = make_datatype_int(_intvalue((yyvsp[(1) - (3)].val)) | _intvalue((yyvsp[(3) - (3)].val)));
            ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 364 "kazi.y"
    {
    fprintf(infotext,"return occured\n");
;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 367 "kazi.y"
    {
                fprintf(infotext,"return occured\n");
            ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 376 "kazi.y"
    {
                int res = addNewVal(&root,&last,(yyvsp[(1) - (3)].text),"");
                if(!res)
                {
                    printf("Compilation Error ::  Varribale %s is already declared\n",(yyvsp[(1) - (3)].text));
                    exit(-1);
                }
                fprintf(infotext,"varriable declared : %s\n",(yyvsp[(1) - (3)].text));
            ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 385 "kazi.y"
    {
                char *val;
                if ((yyvsp[(3) - (3)].val).type == 2) {
                    (yyvsp[(3) - (3)].val).type = 4;
                    int n = log10((yyvsp[(3) - (3)].val).intval) + 1;
                    val = calloc(n + 1, sizeof(char));
                    snprintf(val, n + 1, "%ld", (yyvsp[(3) - (3)].val).intval);
                }
                else if ((yyvsp[(3) - (3)].val).type == 3) {
                    (yyvsp[(3) - (3)].val).type = 4;
                    val = calloc(51, sizeof(char));
                    snprintf(val, 50, "%lf", (yyvsp[(3) - (3)].val).doubleval);
                }
                else{
                    val = (yyvsp[(3) - (3)].val).strval;
                }
                int res = addNewVal(&root,&last,(yyvsp[(1) - (3)].text),val);
                if(!res)
                {
                    printf("Compilation Error ::  Varribale %s is already declared\n",(yyvsp[(1) - (3)].text));
                    exit(-1);
                }
                else{
                    fprintf(infotext,"varriable declared : %s\n",(yyvsp[(1) - (3)].text));
                }
            ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 411 "kazi.y"
    {
                char *val;
                //printf("dimencount :: %d\n",dimencount);
                int n = log10(dimencount) + 2;
                val = calloc(n + 1, sizeof(char));
                char *temp = calloc(n,sizeof(char));
                snprintf(temp, n, "%ld", dimencount);
                val[0]='`';
                strcat(val,temp);
                int res = addNewVal(&root,&last,(yyvsp[(1) - (7)].text),val);
                if(!res)
                {
                    printf("Compilation Error ::  Varribale %s is already declared\n",(yyvsp[(1) - (7)].text));
                    exit(-1);
                }
                else{
                    fprintf(infotext,"Array declared : %s Dimension : %d\n",(yyvsp[(1) - (7)].text),dimencount);
                }
            ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 430 "kazi.y"
    {
                char *val;
                //printf("dimencount :: %d\n",dimencount);
                int n = log10(dimencount) + 2;
                val = calloc(n + 1, sizeof(char));
                char *temp = calloc(n,sizeof(char));
                snprintf(temp, n, "%ld", dimencount);
                val[0]='`';
                strcat(val,temp);
                int res = addNewVal(&root,&last,(yyvsp[(1) - (3)].text),val);
                if(!res)
                {
                    printf("Compilation Error ::  Varribale %s is already declared\n",(yyvsp[(1) - (3)].text));
                    exit(-1);
                }
                else{
                    fprintf(infotext,"Array declared : %s Dimension : %d\n",(yyvsp[(1) - (3)].text),dimencount);
                }
            ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 450 "kazi.y"
    {dimencount++;;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 452 "kazi.y"
    {dimencount = 0;;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 453 "kazi.y"
    {dimencount++;;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 456 "kazi.y"
    {
                if(ifdone[ifptr]==0 && boolvalue((yyvsp[(3) - (7)].val))){
                    ifdone[ifptr]=1;
                    fprintf(infotext,"ELSE IF executed\n");
                }
            ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 462 "kazi.y"
    {
                if(ifdone[ifptr]==0){
                    fprintf(infotext,"ELSE executed\n");
                }
            ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 472 "kazi.y"
    {
                fprintf(infotext,"for loop executed with expression : ");
                fprint_datatype((yyvsp[(5) - (11)].val),infotext);
            ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 480 "kazi.y"
    {
                struct ll_identifier* res = isDeclared(&root,(yyvsp[(1) - (3)].text));
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",(yyvsp[(1) - (3)].text));
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                else 
                {
                    if((yyvsp[(3) - (3)].val).type == 2){
                        int n = log10((yyvsp[(3) - (3)].val).intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",(yyvsp[(3) - (3)].val).intval);
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",(yyvsp[(1) - (3)].text),(yyvsp[(3) - (3)].val).intval);
                    }
                    else if((yyvsp[(3) - (3)].val).type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",(yyvsp[(3) - (3)].val).doubleval);
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",(yyvsp[(1) - (3)].text),(yyvsp[(3) - (3)].val).doubleval);
                    }
                    else{
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),(yyvsp[(3) - (3)].val).strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",(yyvsp[(1) - (3)].text),(yyvsp[(3) - (3)].val).strval);
                    }
                }
            ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 513 "kazi.y"
    {
                struct ll_identifier* res = isDeclared(&root,(yyvsp[(1) - (2)].text));
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",(yyvsp[(1) - (2)].text));
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp1,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.doubleval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp1 = make_datatype_int(1);
                tmp2 = evaluate(tmp,tmp1,"+");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,(yyvsp[(1) - (2)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",(yyvsp[(1) - (2)].text),tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.doubleval);
                        setVal(&root,&last,(yyvsp[(1) - (2)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",(yyvsp[(1) - (2)].text),tmp2.doubleval);
                }
                else{
                        setVal(&root,&last,(yyvsp[(1) - (2)].text),tmp2.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",(yyvsp[(1) - (2)].text),tmp2.strval);
                }
            ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 550 "kazi.y"
    {
                struct ll_identifier* res = isDeclared(&root,(yyvsp[(1) - (2)].text));
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",(yyvsp[(1) - (2)].text));
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp1,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.doubleval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp1 = make_datatype_int(1);
                tmp2 = evaluate(tmp,tmp1,"-");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,(yyvsp[(1) - (2)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",(yyvsp[(1) - (2)].text),tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.doubleval);
                        setVal(&root,&last,(yyvsp[(1) - (2)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",(yyvsp[(1) - (2)].text),tmp2.doubleval);
                }
                else{
                        setVal(&root,&last,(yyvsp[(1) - (2)].text),tmp2.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",(yyvsp[(1) - (2)].text),tmp2.strval);
                }
            ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 587 "kazi.y"
    {
                struct ll_identifier* res = isDeclared(&root,(yyvsp[(1) - (3)].text));
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",(yyvsp[(1) - (3)].text));
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.doubleval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp2 = evaluate(tmp,(yyvsp[(3) - (3)].val),"+");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",(yyvsp[(1) - (3)].text),tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.doubleval);
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",(yyvsp[(1) - (3)].text),tmp2.doubleval);
                }
                else{
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),tmp2.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",(yyvsp[(1) - (3)].text),tmp2.strval);
                }
            ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 623 "kazi.y"
    {
                struct ll_identifier* res = isDeclared(&root,(yyvsp[(1) - (3)].text));
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",(yyvsp[(1) - (3)].text));
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.doubleval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp2 = evaluate(tmp,(yyvsp[(3) - (3)].val),"-");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",(yyvsp[(1) - (3)].text),tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.doubleval);
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",(yyvsp[(1) - (3)].text),tmp2.doubleval);
                }
                else{
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),tmp2.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",(yyvsp[(1) - (3)].text),tmp2.strval);
                }
            ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 659 "kazi.y"
    {
                struct ll_identifier* res = isDeclared(&root,(yyvsp[(1) - (3)].text));
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",(yyvsp[(1) - (3)].text));
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.doubleval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp2 = evaluate(tmp,(yyvsp[(3) - (3)].val),"*");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",(yyvsp[(1) - (3)].text),tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.doubleval);
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",(yyvsp[(1) - (3)].text),tmp2.doubleval);
                }
                else{
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),tmp2.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",(yyvsp[(1) - (3)].text),tmp2.strval);
                }
            ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 695 "kazi.y"
    {
                struct ll_identifier* res = isDeclared(&root,(yyvsp[(1) - (3)].text));
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",(yyvsp[(1) - (3)].text));
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.doubleval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp2 = evaluate(tmp,(yyvsp[(3) - (3)].val),"/");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",(yyvsp[(1) - (3)].text),tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.doubleval);
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",(yyvsp[(1) - (3)].text),tmp2.doubleval);
                }
                else{
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),tmp2.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",(yyvsp[(1) - (3)].text),tmp2.strval);
                }
            ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 731 "kazi.y"
    {
                struct ll_identifier* res = isDeclared(&root,(yyvsp[(1) - (3)].text));
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",(yyvsp[(1) - (3)].text));
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.doubleval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp2 = evaluate(tmp,(yyvsp[(3) - (3)].val),"%");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",(yyvsp[(1) - (3)].text),tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.doubleval);
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",(yyvsp[(1) - (3)].text),tmp2.doubleval);
                }
                else{
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),tmp2.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",(yyvsp[(1) - (3)].text),tmp2.strval);
                }
            ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 767 "kazi.y"
    {
                struct ll_identifier* res = isDeclared(&root,(yyvsp[(1) - (3)].text));
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",(yyvsp[(1) - (3)].text));
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.doubleval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp2 = evaluate(tmp,(yyvsp[(3) - (3)].val),"&");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",(yyvsp[(1) - (3)].text),tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.doubleval);
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",(yyvsp[(1) - (3)].text),tmp2.doubleval);
                }
                else{
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),tmp2.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",(yyvsp[(1) - (3)].text),tmp2.strval);
                }
            ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 803 "kazi.y"
    {
                struct ll_identifier* res = isDeclared(&root,(yyvsp[(1) - (3)].text));
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",(yyvsp[(1) - (3)].text));
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.doubleval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp2 = evaluate(tmp,(yyvsp[(3) - (3)].val),"^");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",(yyvsp[(1) - (3)].text),tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.doubleval);
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",(yyvsp[(1) - (3)].text),tmp2.doubleval);
                }
                else{
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),tmp2.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",(yyvsp[(1) - (3)].text),tmp2.strval);
                }
            ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 839 "kazi.y"
    {
                struct ll_identifier* res = isDeclared(&root,(yyvsp[(1) - (3)].text));
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",(yyvsp[(1) - (3)].text));
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.doubleval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp2 = evaluate(tmp,(yyvsp[(3) - (3)].val),"|");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",(yyvsp[(1) - (3)].text),tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.doubleval);
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",(yyvsp[(1) - (3)].text),tmp2.doubleval);
                }
                else{
                        setVal(&root,&last,(yyvsp[(1) - (3)].text),tmp2.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",(yyvsp[(1) - (3)].text),tmp2.strval);
                }
            ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 877 "kazi.y"
    {
                    fprintf(infotext,"While loop executed with expression : ");
                    fprint_datatype((yyvsp[(3) - (7)].val),infotext);
                ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 882 "kazi.y"
    {
                    fprintf(infotext,"Do While loop executed with expression : ");
                    fprint_datatype((yyvsp[(7) - (9)].val),infotext);
                ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 886 "kazi.y"
    {
                    fprintf(infotext,"PRINT :: ")
                ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 890 "kazi.y"
    {
                    fprint_datatype((yyvsp[(1) - (1)].val),infotext);
                ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 893 "kazi.y"
    {
                    fprint_datatype((yyvsp[(1) - (1)].val),infotext);
                ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 897 "kazi.y"
    {
                    fprintf(infotext,"imported module :: ");
                ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 901 "kazi.y"
    {
                    fprintf(infotext,"%s , ",(yyvsp[(1) - (2)].text));
                ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 904 "kazi.y"
    {
                    fprintf(infotext,"%s\n",(yyvsp[(1) - (1)].text));
                ;}
    break;



/* Line 1455 of yacc.c  */
#line 3045 "kazi.tab.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 907 "kazi.y"

extern char yytext[];
extern int column;
int yyerror(char *s){
    fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
