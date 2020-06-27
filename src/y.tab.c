/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

void yyerror(const char * format, ...);
int yylex();
extern int yylineno;

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "typeUtil.h"
/* Variable for the line count */


#line 79 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    DO = 260,
    WHILE = 261,
    STAR = 262,
    BAR = 263,
    ADD = 264,
    MINUS = 265,
    ASSIGN = 266,
    EQUAL_OP = 267,
    NOT_EQUAL_OP = 268,
    GT_OP = 269,
    GTE_OP = 270,
    LT_OP = 271,
    LTE_OP = 272,
    AND_OP = 273,
    OR_OP = 274,
    NOT_OP = 275,
    OPEN_BRACES = 276,
    CLOSE_BRACES = 277,
    OPEN_PAREN = 278,
    CLOSE_PAREN = 279,
    OPEN_BRACKET = 280,
    CLOSE_BRACKET = 281,
    START = 282,
    STOP = 283,
    PLAY = 284,
    NEW_LINE = 285,
    INT_NAME = 286,
    CHORD_NAME = 287,
    SET_NAME = 288,
    VAR = 289,
    NUMBER = 290,
    CHORD = 291,
    NOTE = 292
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define DO 260
#define WHILE 261
#define STAR 262
#define BAR 263
#define ADD 264
#define MINUS 265
#define ASSIGN 266
#define EQUAL_OP 267
#define NOT_EQUAL_OP 268
#define GT_OP 269
#define GTE_OP 270
#define LT_OP 271
#define LTE_OP 272
#define AND_OP 273
#define OR_OP 274
#define NOT_OP 275
#define OPEN_BRACES 276
#define CLOSE_BRACES 277
#define OPEN_PAREN 278
#define CLOSE_PAREN 279
#define OPEN_BRACKET 280
#define CLOSE_BRACKET 281
#define START 282
#define STOP 283
#define PLAY 284
#define NEW_LINE 285
#define INT_NAME 286
#define CHORD_NAME 287
#define SET_NAME 288
#define VAR 289
#define NUMBER 290
#define CHORD 291
#define NOTE 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "parser.y" /* yacc.c:355  */

    int int_type;
    int * number; 
    struct chord * chord;
    struct set * set;
    char * strVal;
    struct data dataVal;

#line 202 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 219 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   118

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  103

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    56,    56,    58,    60,    61,    62,    63,    64,    65,
      66,    67,    70,    73,    76,    79,    80,    83,    84,    88,
      89,    90,    93,    94,    98,    99,   102,   110,   111,   114,
     115,   116,   117,   118,   119,   122,   126,   129,   130,   131,
     134,   135,   136,   139,   140,   141,   144,   145,   146,   147,
     150,   151,   152
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "DO", "WHILE", "STAR",
  "BAR", "ADD", "MINUS", "ASSIGN", "EQUAL_OP", "NOT_EQUAL_OP", "GT_OP",
  "GTE_OP", "LT_OP", "LTE_OP", "AND_OP", "OR_OP", "NOT_OP", "OPEN_BRACES",
  "CLOSE_BRACES", "OPEN_PAREN", "CLOSE_PAREN", "OPEN_BRACKET",
  "CLOSE_BRACKET", "START", "STOP", "PLAY", "NEW_LINE", "INT_NAME",
  "CHORD_NAME", "SET_NAME", "VAR", "NUMBER", "CHORD", "NOTE", "$accept",
  "start", "stop", "program", "play", "do_sentence", "while_sentence",
  "if_sentence", "compare", "single_compare", "mult_compare", "any_op",
  "body", "add_op_logic", "op_compare", "declare", "assign", "var_type",
  "expression", "term", "factor", "constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

#define YYPACT_NINF -48

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-48)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -19,   -18,    14,   -48,   -48,     1,    -3,    -5,    -3,   -48,
       5,   -48,   -48,   -48,   -48,    40,    25,   -48,   -48,   -48,
     -48,   -48,   -48,    23,   -10,    -5,   -48,    67,    -5,    60,
      60,   -48,    46,    69,   -10,    60,   -48,   -48,   -48,   -48,
      54,    99,     8,    61,   -48,   -48,     7,    16,    -3,    50,
      60,    55,    33,   -48,   -10,   -48,    99,    57,    52,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -10,   -48,
     -48,    60,    60,    60,    60,    -5,   -48,   -48,    63,   -48,
      57,    76,   -48,    86,   -10,   -48,    30,    83,    61,    61,
     -48,   -48,    78,   -48,   -48,   -48,   -10,    85,   -48,   -48,
     -48,   -48,   -48
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    11,     1,     0,     0,     0,     0,     3,
       0,    10,    37,    38,    39,     0,     0,     9,     7,     8,
       6,     4,     5,     0,     0,     0,    11,     0,     0,     0,
       0,     2,     0,     0,     0,     0,    47,    51,    50,    52,
      23,     0,    21,    42,    45,    46,     0,     0,     0,     0,
       0,     0,     0,    35,     0,    23,     0,    21,     0,    18,
      33,    34,    29,    30,    31,    32,    27,    28,     0,    24,
      25,     0,     0,     0,     0,     0,    15,    26,     0,    14,
       0,     0,    36,     0,     0,    49,     0,    22,    40,    41,
      43,    44,     0,    13,    12,    20,     0,    22,    48,    17,
      16,    22,    19
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,   -48,    58,   -48,   -48,   -48,   -48,    -7,   -24,
     -31,   -47,   -23,   -48,   -48,   -48,   -48,   -48,    24,    -1,
      17,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    16,     5,    17,    18,    19,    20,    25,    55,
      41,    68,    27,    69,    70,    21,    22,    23,    42,    43,
      44,    45
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,    28,    46,    56,     6,    49,     7,     8,     1,    84,
      33,    75,     3,    34,     4,    35,    26,    71,    72,     6,
      24,     7,     8,    83,    36,    37,    38,    39,    29,     9,
      10,    11,    12,    13,    14,    15,    96,    76,    77,    71,
      72,    78,    71,    72,    87,    10,    11,    12,    13,    14,
      15,    30,    92,    51,    52,    31,    98,    32,    57,    58,
      97,    71,    72,    82,    71,    72,    71,    72,    73,    74,
      88,    89,   101,    48,    80,    50,    53,    35,    59,    81,
      79,    85,    86,    50,    47,    35,    36,    37,    38,    39,
      90,    91,    54,    93,    36,    37,    38,    39,    60,    61,
      62,    63,    64,    65,    66,    67,    94,    99,   100,   102,
      95,    60,    61,    62,    63,    64,    65,    66,    67
};

static const yytype_uint8 yycheck[] =
{
      24,     8,    25,    34,     3,    28,     5,     6,    27,    56,
      20,     4,    30,    23,     0,    25,    21,     9,    10,     3,
      23,     5,     6,    54,    34,    35,    36,    37,    23,    28,
      29,    30,    31,    32,    33,    34,    83,    30,    22,     9,
      10,    48,     9,    10,    68,    29,    30,    31,    32,    33,
      34,    11,    75,    29,    30,    30,    26,    34,    34,    35,
      84,     9,    10,    30,     9,    10,     9,    10,     7,     8,
      71,    72,    96,     6,    50,    23,    30,    25,    24,    24,
      30,    24,    58,    23,    26,    25,    34,    35,    36,    37,
      73,    74,    23,    30,    34,    35,    36,    37,    12,    13,
      14,    15,    16,    17,    18,    19,    30,    24,    30,    24,
      24,    12,    13,    14,    15,    16,    17,    18,    19
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    39,    30,     0,    41,     3,     5,     6,    28,
      29,    30,    31,    32,    33,    34,    40,    42,    43,    44,
      45,    53,    54,    55,    23,    46,    21,    50,    46,    23,
      11,    30,    34,    20,    23,    25,    34,    35,    36,    37,
      47,    48,    56,    57,    58,    59,    50,    41,     6,    50,
      23,    56,    56,    30,    23,    47,    48,    56,    56,    24,
      12,    13,    14,    15,    16,    17,    18,    19,    49,    51,
      52,     9,    10,     7,     8,     4,    30,    22,    46,    30,
      56,    24,    30,    48,    49,    24,    56,    47,    57,    57,
      58,    58,    50,    30,    30,    24,    49,    47,    26,    24,
      30,    47,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    41,    41,    41,    41,    41,    41,
      41,    41,    42,    43,    44,    45,    45,    46,    46,    47,
      47,    47,    48,    48,    49,    49,    50,    51,    51,    52,
      52,    52,    52,    52,    52,    53,    54,    55,    55,    55,
      56,    56,    56,    57,    57,    57,    58,    58,    58,    58,
      59,    59,    59
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     1,     2,     2,     2,     2,     2,     2,
       2,     0,     5,     5,     4,     4,     6,     5,     3,     5,
       4,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     1,     1,     1,
       3,     3,     1,     3,     3,     1,     1,     1,     4,     3,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 56 "parser.y" /* yacc.c:1646  */
    { printFullProgram((yyvsp[-2].strVal)); }
#line 1370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 58 "parser.y" /* yacc.c:1646  */
    { free_end(); exit(0); }
#line 1376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 60 "parser.y" /* yacc.c:1646  */
    { (yyval.strVal) = concatProgram((yyvsp[-1].strVal), (yyvsp[0].strVal)); }
#line 1382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 61 "parser.y" /* yacc.c:1646  */
    { (yyval.strVal) = concatProgram((yyvsp[-1].strVal), (yyvsp[0].strVal)); }
#line 1388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 62 "parser.y" /* yacc.c:1646  */
    { (yyval.strVal) = concatProgram((yyvsp[-1].strVal), (yyvsp[0].strVal)); }
#line 1394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 63 "parser.y" /* yacc.c:1646  */
    { (yyval.strVal) = concatProgram((yyvsp[-1].strVal), (yyvsp[0].strVal)); }
#line 1400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 64 "parser.y" /* yacc.c:1646  */
    { (yyval.strVal) = concatProgram((yyvsp[-1].strVal), (yyvsp[0].strVal)); }
#line 1406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 65 "parser.y" /* yacc.c:1646  */
    { (yyval.strVal) = concatProgram((yyvsp[-1].strVal), (yyvsp[0].strVal)); }
#line 1412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 66 "parser.y" /* yacc.c:1646  */
    { (yyval.strVal) = (yyvsp[-1].strVal); }
#line 1418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 67 "parser.y" /* yacc.c:1646  */
    { (yyval.strVal) = emptySentence(); }
#line 1424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 70 "parser.y" /* yacc.c:1646  */
    { (yyval.strVal) = playSet((yyvsp[-2].dataVal));   }
#line 1430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 73 "parser.y" /* yacc.c:1646  */
    { (yyval.strVal) = doWhileSentence((yyvsp[-3].strVal), (yyvsp[-1].dataVal)); }
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 76 "parser.y" /* yacc.c:1646  */
    { (yyval.strVal) = whileSentence((yyvsp[-1].strVal), (yyvsp[-2].dataVal)); }
#line 1442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 79 "parser.y" /* yacc.c:1646  */
    { (yyval.strVal) = ifSentence((yyvsp[-2].dataVal), (yyvsp[-1].strVal), NULL); }
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 80 "parser.y" /* yacc.c:1646  */
    { (yyval.strVal) = ifSentence((yyvsp[-4].dataVal), (yyvsp[-3].strVal), (yyvsp[-1].strVal)); }
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 83 "parser.y" /* yacc.c:1646  */
    { (yyval.dataVal) = addParen(condition_composed((yyvsp[-3].dataVal), (yyvsp[-2].int_type), (yyvsp[-1].dataVal))); /* print_boolean((int*)$$.value); */ }
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 84 "parser.y" /* yacc.c:1646  */
    { (yyval.dataVal) = addParen((yyvsp[-1].dataVal));  /* print_boolean((int*)$$.value);   */        }
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 88 "parser.y" /* yacc.c:1646  */
    { (yyval.dataVal) = addParen(condition_composed((yyvsp[-3].dataVal), (yyvsp[-2].int_type), (yyvsp[-1].dataVal)));  }
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 89 "parser.y" /* yacc.c:1646  */
    { (yyval.dataVal) = negate_condition((yyvsp[-1].dataVal));            }
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 90 "parser.y" /* yacc.c:1646  */
    { (yyval.dataVal) = data_boolean((yyvsp[0].dataVal));        }
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 93 "parser.y" /* yacc.c:1646  */
    { (yyval.dataVal) = condition_composed((yyvsp[-2].dataVal), (yyvsp[-1].int_type), (yyvsp[0].dataVal));  }
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 94 "parser.y" /* yacc.c:1646  */
    { (yyval.dataVal) = (yyvsp[0].dataVal); }
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 98 "parser.y" /* yacc.c:1646  */
    { (yyval.int_type) = (yyvsp[0].int_type); }
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 99 "parser.y" /* yacc.c:1646  */
    { (yyval.int_type) = (yyvsp[0].int_type); }
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 102 "parser.y" /* yacc.c:1646  */
    { (yyval.strVal) = addBraces((yyvsp[-1].strVal)); }
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 110 "parser.y" /* yacc.c:1646  */
    { (yyval.int_type) = and; }
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 111 "parser.y" /* yacc.c:1646  */
    { (yyval.int_type) = or;  }
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval.int_type) = gt;  }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval.int_type) = gte; }
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.int_type) = lt;  }
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.int_type) = lte; }
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 118 "parser.y" /* yacc.c:1646  */
    { (yyval.int_type) = eq;  }
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval.int_type) = neq; }
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 122 "parser.y" /* yacc.c:1646  */
    { (yyval.strVal) = createVar((yyvsp[-2].int_type),(yyvsp[-1].strVal)); }
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 126 "parser.y" /* yacc.c:1646  */
    { (yyval.strVal) = newVar((yyvsp[-3].strVal),(yyvsp[-1].dataVal)); }
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 129 "parser.y" /* yacc.c:1646  */
    { (yyval.int_type) = num_type;   }
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 130 "parser.y" /* yacc.c:1646  */
    { (yyval.int_type) = chord_type; }
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 131 "parser.y" /* yacc.c:1646  */
    { (yyval.int_type) = set_type;   }
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 134 "parser.y" /* yacc.c:1646  */
    { (yyval.dataVal) = addOperation((yyvsp[-2].dataVal),(yyvsp[0].dataVal));   }
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.dataVal) = minusOperation((yyvsp[-2].dataVal),(yyvsp[0].dataVal)); }
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyval.dataVal) = (yyvsp[0].dataVal); }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval.dataVal) = starOperation((yyvsp[-2].dataVal),(yyvsp[0].dataVal)); }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.dataVal) = barOperation ((yyvsp[-2].dataVal),(yyvsp[0].dataVal)); }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.dataVal) = (yyvsp[0].dataVal); }
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 144 "parser.y" /* yacc.c:1646  */
    { (yyval.dataVal) = (yyvsp[0].dataVal);}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.dataVal) = getDataByName((yyvsp[0].strVal));  }
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval.dataVal) = newSetData((yyvsp[-2].dataVal), (yyvsp[-1].dataVal)); /* print_set($$); */}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.dataVal) = addParen((yyvsp[-1].dataVal)); }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 150 "parser.y" /* yacc.c:1646  */
    { (yyval.dataVal) = getChordData((yyvsp[0].strVal)); /*print_chord($1); */ }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.dataVal) = getIntData((yyvsp[0].strVal));  /*  print_number($1); */ }
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.dataVal) = getNoteData((yyvsp[0].strVal)); /*print_chord($1);  */}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1674 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 155 "parser.y" /* yacc.c:1906  */


void yyerror(const char * format, ...){
    va_list argptr;
    va_start(argptr, format);
    vfprintf(stderr, format, argptr);
    va_end(argptr);
    fprintf(stderr," -> \033[1;31mError\033[0m in line %d\n\n", yylineno);
    exit(EXIT_FAILURE);
}

int yywrap(){
    return 1;
} 

void printHeaders();
void printFunctions();
void printWaveEndiannessFunctions();

int main() {
    init_list();
    // printf("\033[1;32mReady! Make your music!\033[0m\n\n");
    printHeaders();
    printWaveEndiannessFunctions();
    printFunctions();
    return yyparse();
} 

void printHeaders(){
    printf("#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include <math.h>\n\n");
    printf("#define BASE_FILENAME	\"out\"\n#define EXT_FILENAME	\".wav\"\n");
    printf("#define NOTE_COUNT  13\n#define CHORD_COUNT 14\n#define STD_CHORD_L 3\n\n");
    printf("#define M_PI           3.14159265358979323846\n#ifdef __linux__\n    #define SOUND_COMMAND  \"aplay -c 1 -q -t wav\"\n#endif\n#ifdef __APPLE__	\n    #define SOUND_COMMAND  \"afplay\"\n#endif\n");
    printf("#define SAMPLE_RATE     96000.0 // hertz\n#define MONO            1\n#define STEREO          2\n#define CHANNEL_NUM     MONO\n#define BITS_SAMPLE     16      // 8, 16 or 32\n\n");

    printf("\nstatic int fileNumber = 0;\n\n");
    printf("typedef enum { C=0, Cs, D, Ds=3, E, F, Fs=6, G, Gs, A=9, As, B, _ } notes_enum;\ntypedef enum { aC=0, aCm, aD, aDm=3, aE, aEm, aF=6, aFm, aG, aGm=9, aA, aAm, aB=12, aBm } chords_enum;\n\nstatic const char * noteName[NOTE_COUNT] = {\"C\", \"Cs\", \"D\", \"Ds\", \"E\", \"F\", \"Fs\", \"G\", \"Gs\", \"A\", \"As\", \"B\", \"_\"};\nstatic const char * chordName[CHORD_COUNT] = {\"aC\", \"aCm\", \"aD\", \"aDm\", \"aE\", \"aEm\", \"aF\", \"aFm\", \"aG\", \"aGm\", \"aA\", \"aAm\", \"aB\", \"aBm\"};\n\n");
    printf("static const float notes[] = { /*C*/ 65.41 * 8, 69.30* 8, 73.42* 8, 77.78* 8, 82.41* 8, 87.31* 8, 92.50* 8 , 98.00* 8, 103.83* 8, 110.00* 8, 116.54* 8, 123.47* 8 /*B*/ , 0};\n");
    printf("static notes_enum chordsNotes[CHORD_COUNT][STD_CHORD_L] = { {C,E, G}, {C,Ds,G}, {D,Fs,A}, {D,F, A}, {E,Gs,B}, {E,G, B}, {F,A, C}, {F,Gs,C}, {G,B, D}, {G,As,D}, {A,Cs,E}, {A,C, E}, {B,Ds,Fs}, {B,E, G}};\n\n");
    printf("struct NoteNode{\n\tnotes_enum note;\n\tstruct NoteNode * next;\n};\ntypedef struct chord{\n\tstruct NoteNode * notes;\n\tint quant;\n}Chord;\ntypedef struct block{\n\tChord * chords;\n\tint time;\n}Block;\ntypedef struct set{\n\tBlock * blocks;\n\tint quant;\n}Set;\n\n");
    /*Print wave prototipes */
    printf("typedef struct WaveHeader {\n\tchar chunkId[4];\n\tint  chunkSize;\n\tchar format[4];\n\tchar subChunk1Id[4];\n\tint  subChunk1Size;\n\tshort int audioFormat;\n\tshort int numChannels;\n\tint sampleRate;\n\tint byteRate;\n\tshort int blockAlign;\n\tshort int bitsPerSample;\n\tchar subChunk2Id[4];\n\tint  subChunk2Size;\n\t} WaveHeader;\ntypedef struct Wave {\n\tWaveHeader header;\n\tchar* data;\n\tlong long int index;\n\tlong long int size;\n\tlong long int nSamples;\n\t} Wave;\nWaveHeader makeWaveHeader(int const sampleRate, short int const numChannels, short int const bitsPerSample);\nWave makeWave(int const sampleRate, short int const numChannels, short int const bitsPerSample);\nvoid waveDestroy( Wave* wave);\nvoid waveSetDuration( Wave* wave, const long miliseconds );\nvoid waveAddSample( Wave* wave, const float* samples );\nvoid waveToFile( Wave* wave, const char* filename );\n\n");
    /* Print endianness prototipes */
    printf("int isBigEndian();\nvoid reverseEndianness(const long long int size, void* value);\nvoid toBigEndian(const long long int size, void* value);\nvoid toLittleEndian(const long long int size, void* value);\n\n");
    
    printf("Chord * atochord(const char *nptr);\n\
            Chord * atonote(const char *nptr);\n\
            Chord * newChord(char * constant);\n\
            Set * newSet(Chord * chord, int time);\n\
            Set * setRepeat(Set * set, int times);\n\
            Set * setConcat(Set * s1, Set * s2);\n\
            int containsNote(Chord * chord, notes_enum note);\n\
            Chord * chordSum(Chord * c1, Chord * c2);\n\
            Chord * chordSub(Chord * c1, Chord * c2);\n\
            int totalTime(Set * set);\n\
            int avgFreq(Chord * chord);\n\
            void playSet(Set * set);\n");
    printf("void generateWav(Set set, char * name);\n");
    printf("int playWav( char *filename );\n");

}



void printFunctions(){
    // /*Print new chord function */
    // printf("\n\nChord * newChord(char * constant){\n\tChord * new_chord = atonote(constant);\n\tif(new_chord != NULL){\n\t\treturn new_chord;\n\t}\n\telse {\n\t\tnew_chord = atochord(constant);\n\t}\n\treturn new_chord;\n}\n ");
    // /* Print New Set function */
    // printf("\n\nSet * newSet(Chord * chord, int time){\n\tSet * new_set = malloc(sizeof(struct set));\n\tif(new_set == NULL){\n\t\texit(1);\n\t}\n\tBlock * block = malloc(sizeof(struct block));\n\tif(block == NULL){\n\t\texit(1);\n\t}\n\tblock->chords = chord;\n\tblock->time = time;\n\tnew_set->blocks = block;\n\tnew_set->quant = 1;\n\treturn new_set;\n\t}\n");
    // /*Print contains note function */
    // printf("\n\nint containsNote(Chord * chord, notes_enum note){\n\tstruct NoteNode * node = chord->notes;\n\twhile(node != NULL){\n\t\tif(node->note == note)\n\t\t\treturn 1;\n\t\tnode = node->next;\n\t}\n\treturn 0;\n}\n");
    // /* Print avgFreq function */
    // printf("\n\nint avgFreq(Chord * chord){\n\tfloat sum_freq = 0;\n\tint quant = 0;\n\twhile (quant < chord->quant){\n\t\tsum_freq += notes[chord->notes[quant].note];\n\t\tquant++;\n\t}\n\treturn (quant == 0) ? 0 : (sum_freq/quant);\n} \n");
    // /* Print total time function */
    // printf("\n\nint totalTime(Set * set){\n\tint time = 0;\n\tfor(int i = 0; i < set->quant ; i++) {\n\t\ttime += set->blocks[i].time;\n\t}\n\treturn time;\n} \n");
    // /* Print Set Concat function */
    // printf("\n\nSet * setConcat(Set * s1, Set * s2){\n\tSet *new_set = malloc(sizeof(struct set));\n\tif(new_set == NULL){\n\t\texit(1);\n\t}\n\tint new_quant = s1->quant + s2->quant;\n\tfor(int i = s1->quant, j = 0; i < new_quant; i++, j++)\n\t\ts1->blocks[i] = s1->blocks[j];\n\tnew_set->quant = new_quant;\n\tnew_set->blocks = s1->blocks;\n\treturn new_set;\n} \n");
    // /* Print Set Repeat function */
    // printf("\n\nSet * setRepeat(Set * set, int times){\n\tint old_quant = set->quant;\n\tint new_quant = set->quant * times;\n\tBlock * old_block = set->blocks;\n\tBlock * new_block = malloc(sizeof(struct block) * new_quant);\n\tif(new_block == NULL){\n\t\t exit(1);\n\t}\n\tint i = 0, b_index = 0, j = 0;\n\tfor(i=0; i < times; i++){\n\t\tfor(j = 0; j < old_quant; j++){\n\t\t\tnew_block[b_index++] = old_block[j];\n\t\t}\n\t}\n\tSet *new_set = malloc(sizeof(struct set));\n\tif(new_set == NULL){\n\t\texit(1);\n\t}\n\tnew_set->quant = new_quant;\n\tnew_set->blocks = new_block;\n\treturn new_set;\n}\n");
    // /* Print Chord Sub function */
    // printf("\n\n Chord * chordSub(Chord * c1, Chord * c2){\n\tint q = 0;\n\twhile(q < c2->quant){\n\t\tif(containsNote(c1, c2->notes[q].note))\n\t\t\toutDeleteNote(c1, c2->notes[q].note);\n\t\tq++;\n\t}\n\tChord * new_chord = malloc(sizeof(struct chord));\n\tif(new_chord == NULL){\n\t\texit(1);\n\t}\n\tnew_chord->notes = c1->notes;\n\tnew_chord->quant = c1->quant;\n\treturn new_chord;\n}\n");
    // /* Print Chord Sum function */
    // printf("\n\nChord * chordSum(Chord * c1, Chord * c2){\n\tint q = 0;\n\twhile(q < c2->quant ){\n\t\tif(!containsNote(c1, c2->notes[q].note)){\n\t\t\toutAddNote(c1, c2->notes[q].note);\n\t\t}\n\t\tq++;\n\t}\n\tChord * new_chord = malloc(sizeof(struct chord));\n\tif(new_chord == NULL){\n\t\texit(1);\n\t}\n\tnew_chord->notes = c1->notes;\n\tnew_chord->quant = c1->quant;\n\treturn new_chord;\n} \n");
    // /* Print aToChord y aToNote functions */
    // printf("\n\nChord * atochord(const char *nptr){\n\tint stdChord;\n\tfor (stdChord = aC; stdChord < CHORD_COUNT; stdChord++) {\n\t\tif (strcmp(nptr, chordName[stdChord]) == 0) {\n\t\t\tbreak;\n\t\t}\n\t}\n\tif (stdChord == CHORD_COUNT){ \n\t\treturn NULL;\n\t}\n\tChord * chord = malloc(sizeof(*chord));\n\tif (chord == NULL) {\n\t\texit(1);\n\t}\n\tstruct NoteNode * node = (struct NoteNode *) malloc(sizeof(struct NoteNode));\n\tif (node == NULL){\n\t\texit(1);\n\t}\n\tnode->note = chordsNotes[stdChord][0];\n\tchord->notes = node;\n\tfor (int i = 1; i < STD_CHORD_L; i++) {\n\t\tnode->next = (struct NoteNode *) malloc(sizeof(struct NoteNode));\n\t\tif (node->next == NULL) {\n\t\t\texit(1);\n\t\t}\n\t\tnode->next->note = chordsNotes[stdChord][i];\n\t\tnode = node->next;\n\t}\n\tnode->next = NULL;\n\tchord->quant = STD_CHORD_L;\n\treturn chord;\n}\n\n\nChord * atonote(const char *nptr) {\n\tint note;\n\tfor (note = C; note < NOTE_COUNT; note++) {\n\t\t\tif (strcmp(nptr, noteName[note]) == 0) {\n\t\t\t\tbreak;\n\t\t}\n\t}\n\tif (note == NOTE_COUNT) {\n\t\treturn NULL;\n\t}\n\tChord * chord = malloc(sizeof(*chord));\n\tif (chord == NULL) { \n\t\texit(1);\n\t}\n\tchord->notes = malloc(sizeof(struct NoteNode));\n\tif (chord->notes == NULL) {\n\t\tfree(chord);\n\t}\n\tchord->notes->note = note;\n\tchord->notes->next = NULL;\n\tchord->quant = 1;\n\treturn chord;\n}\n");
    // /* Print addNote y deleteNote */
    // printf("\n\nvoid outAddNote(Chord * chord, notes_enum note){\n\tstruct NoteNode * node = chord->notes;\n\tstruct NoteNode * new = malloc(sizeof(struct NoteNode));\n\tif(new == NULL){\n\t\texit(1);\n\t}\n\tnew->note = note;\n\tnew->next = node;\n\tchord->notes = new;\n\tchord->quant++;\n\treturn;\n}\n\n\nvoid outDeleteNote(Chord * chord, notes_enum note){\n\tstruct NoteNode * node = chord->notes;\n\tif(node->note == note){\n\t\tstruct NoteNode * aux = node->next;\n\t\tnode->next = node->next->next;\n\t\tfree(aux);\n\t\tchord->quant--;\n\t\treturn;\n\t}\n\twhile (node->next != NULL){\n\t\tif(node->next->note == note){\n\t\t\tstruct NoteNode * aux = node->next;\n\t\t\tnode->next = node->next->next;\n\t\t\tfree(aux);\n\t\t\tchord->quant--;\n\t\t\treturn;\n\t\t}\n\t\tnode = node->next;\n\t}\n\treturn;\n}\n");
    /* Print playSet function */
    printf("\n\nvoid playSet(Set * set){\n\tchar buf[10];\n\tsnprintf(buf, 10, \"%%s%%d%%s\", BASE_FILENAME, fileNumber, EXT_FILENAME);\n\tgenerateWav(*set, buf);\n\tplayWav(buf);\n\tfileNumber++;\n}\n\n");
    /* Print soundSet.c functions */
    printf("\n\nint playWav( char *filename ) {\n    char command[256];\n    int status;\n    /* create command to execute */\n    sprintf (command, \"%%s %%s\", SOUND_COMMAND, filename);\n\n    /* play sound */\n    status = system( command );\n\n    return status;\n}\n\nvoid addSet (Wave * mySound, Set set);\n\nlong getSampleNumber(long miliseconds) {\n    return (long) ((miliseconds / 1000.0) * SAMPLE_RATE);\n}\n\n");
    printf("\n\nlong getTotalDuration(Set set) {\n    long rta = 0;\n    for (int i = 0; i < set.quant ; i++) {\n        rta += set.blocks[i].time;\n    }\n    return rta;\n}\n\nvoid generateWav(Set set, char * name) {\n    long duration = getTotalDuration(set);\n    long nSamples = getSampleNumber(duration);\n    \n    // Create a mono (1), 16-bit sound and set the duration\n    Wave mySound = makeWave((int)SAMPLE_RATE, CHANNEL_NUM, BITS_SAMPLE);\n    waveSetDuration(&mySound, duration);\n\n    // Add all of the data\n    addSet(&mySound, set);\n\n    // Write it to a file and clean up when done\n    waveToFile(&mySound, name);\n    waveDestroy(&mySound);\n}\n\nvoid resetArray(float * array, int size) {\n    for (int i = 0; i < size; i++) {\n        array[i] = 0.0;\n    }\n}\n\n");
    printf("\n\nvoid addChord(Wave * mySound, Chord * chord, long nSamples) {\n    float multiplier = M_PI * 2.0 / SAMPLE_RATE;\n    float frameData[CHANNEL_NUM];\n    int i, j, k;\n    for(i = 0; i < nSamples; i++){\n        resetArray(frameData, CHANNEL_NUM);\n        for (j = 0; j < chord->quant ; j++) {\n            for (k = 0; k < CHANNEL_NUM; k++) {\n                frameData[k] += sin(notes[chord->notes[j].note] * (float)i * multiplier) / chord->quant;\n            }\n        }\n        waveAddSample(mySound, frameData);\n    }\n}\n\nvoid addSet (Wave * mySound, Set set){\n    for (int i = 0; i < set.quant; i++) {\n        addChord(mySound, set.blocks[i].chords , getSampleNumber(set.blocks[i].time));\n    }\n}\n\n");


    /***** PRINT 2.0 ***/
    printf("Chord * atochord(const char *nptr) {\n\
            int stdChord;\n\
            for (stdChord = aC; stdChord < CHORD_COUNT; stdChord++) {\n\
                if (strcmp(nptr, chordName[stdChord]) == 0) {\n\
                    break;\n\
                }\n\
            }\n\
            if (stdChord == CHORD_COUNT){\n\
                return NULL;\n\
            }\n\
            Chord * chord = malloc(sizeof(*chord));\n\
            if (chord == NULL) { \n\
                exit(1);\n\
            }\n\
            chord->quant = STD_CHORD_L;\n\
            chord->notes = malloc(sizeof(*chord->notes) * chord->quant);\n\
            if (chord->notes == NULL) {\n\
                free(chord);\n\
                exit(1);\n\
            }\n\
            for (int i = 0; i < chord->quant; i++) {\n\
                chord->notes[i].note = chordsNotes[stdChord][i];\n\
            }\n\
            return chord;\n\
        }\n\
        Chord * atonote(const char *nptr) {\n\
            int note;\n\
            for (note = C; note < NOTE_COUNT; note++) {\n\
                if (strcmp(nptr, noteName[note]) == 0) {\n\
                    break;\n\
                }\n\
            }\n\
            if (note == NOTE_COUNT) {\n\
                return NULL;\n\
            }\n\
            Chord * chord = malloc(sizeof(*chord));\n\
            if (chord == NULL) { \n\
                exit(1);\n\
            }\n\
            chord->quant = 1;\n\
            chord->notes = malloc(sizeof(*chord->notes) * chord->quant);\n\
            if (chord->notes == NULL) {\n\
                free(chord);\n\
                exit(1);\n\
            }\n\
            chord->notes[0].note = note;\n\
            return chord;\n\
        }\n\
        Chord * newChord(char * constant){\n\
            Chord * new_chord = atonote(constant);\n\
            if(new_chord != NULL){\n\
                return new_chord;\n\
            }\n\
            else {\n\
                new_chord = atochord(constant);\n\
            }\n\
            return new_chord;\n\
        }\n\
        int containsNote(Chord * chord, notes_enum note){\n\
            for (int i = 0; i < chord->quant; i++) {\n\
                if (chord->notes[i].note == note) {\n\
                    return 1;\n\
                }\n\
            }\n\
            return 0;\n\
        }\n\
        Chord * chordSum(Chord * c1, Chord * c2){\n\
            Chord * new_chord = malloc(sizeof(struct chord));\n\
            if(new_chord == NULL){\n\
                exit(1);\n\
            }\n\
            new_chord->notes = malloc(sizeof(*new_chord->notes) * (c1->quant + c2->quant));\n\
            if (new_chord->notes == NULL) {\n\
                free(new_chord);\n\
                exit(1);\n\
            }\n\
            int index = 0;\n\
            for (index = 0; index < c1->quant; index++) {\n\
                new_chord->notes[index].note = c1->notes[index].note;\n\
            }\n\
            for (int j = 0; j < c2->quant; j++) {\n\
                if (!containsNote(c1, c2->notes[j].note)) {\n\
                    new_chord->notes[index].note = c2->notes[j].note;\n\
                    index++;\n\
                }\n\
            }\n\
            struct NoteNode * aux = new_chord->notes;\n\
            new_chord->notes = realloc(new_chord->notes, sizeof(*new_chord->notes) * index);\n\
            if (new_chord->notes == NULL) {\n\
                free(aux);\n\
                free(new_chord);\n\
                exit(1);\n\
            }\n\
            new_chord->quant = index;\n\
            return new_chord;\n\
        }\n\
        Chord * chordSub(Chord * c1, Chord * c2){\n\
            Chord * new_chord = malloc(sizeof(struct chord));\n\
            if(new_chord == NULL){\n\
                exit(1);\n\
            }\n\
            new_chord->notes = malloc(sizeof(*new_chord->notes) * c1->quant);\n\
            if (new_chord->notes == NULL) {\n\
                free(new_chord);\n\
                exit(1);\n\
            }\n\
            int index = 0;\n\
            for (int j = 0; j < c1->quant; j++) {\n\
                if (!containsNote(c2, c1->notes[j].note)) {\n\
                    new_chord->notes[index].note = c1->notes[j].note;\n\
                    index++;\n\
                }\n\
            }\n\
            struct NoteNode * aux = new_chord->notes;\n\
            new_chord->notes = realloc(new_chord->notes, sizeof(*new_chord->notes) * index);\n\
            if (new_chord->notes == NULL) {\n\
                free(aux);\n\
                free(new_chord);\n\
                exit(1);\n\
            }\n\
            new_chord->quant = index;\n\
            return new_chord;\n\
        }\n\
        Set * setRepeat(Set * set, int times){\n\
            int old_quant = set->quant;\n\
            int new_quant = set->quant * times;\n\
            Block * old_block = set->blocks;\n\
            Block * new_block = malloc(sizeof(struct block) * new_quant);\n\
            if(new_block == NULL){\n\
                exit(1);\n\
            }\n\
            int i = 0, b_index = 0, j = 0;\n\
            for(i=0; i < times; i++){\n\
                for(j = 0; j < old_quant; j++){\n\
                    new_block[b_index++] = old_block[j];\n\
                }\n\
            }\n\
            Set *new_set = malloc(sizeof(struct set));\n\
            if(new_set == NULL){\n\
                free(new_block);\n\
                exit(1);\n\
            }\n\
            new_set->quant = new_quant;\n\
            new_set->blocks = new_block;\n\
            return new_set;\n\
        }\n\
        Set * setConcat(Set * s1, Set * s2){\n\
            Set *new_set = malloc(sizeof(struct set));\n\
            if(new_set == NULL){\n\
                exit(1);\n\
            }\n\
            new_set->quant = s1->quant + s2->quant;\n\
            new_set->blocks = malloc(sizeof(*new_set->blocks) * new_set->quant);\n\
            if (new_set->blocks == NULL) {\n\
                free(new_set);\n\
                exit(1);\n\
            }\n\
            Chord emptyChord = {NULL, 0};\n\
            int index = 0;\n\
            for (index = 0; index < s1->quant; index++) {\n\
                new_set->blocks[index].chords = chordSum(s1->blocks[index].chords, &emptyChord);\n\
                if (new_set->blocks[index].chords == NULL) {\n\
                    free(new_set->blocks);\n\
                    free(new_set);\n\
                    exit(1);\n\
                }\n\
                new_set->blocks[index].time = s1->blocks[index].time;\n\
            }\n\
            for (int j = 0; j < s2->quant; j++, index++) {\n\
                new_set->blocks[index].chords = chordSum(s2->blocks[j].chords, &emptyChord);\n\
                if (new_set->blocks[index].chords == NULL) {\n\
                    free(new_set->blocks);\n\
                    free(new_set);\n\
                    exit(1);\n\
                }\n\
                new_set->blocks[index].time = s2->blocks[j].time;\n\
            }\n\
            return new_set;\n\
        }\n\
        Set * newSet(Chord * chord, int time){\n\
            Set * new_set = malloc(sizeof(struct set));\n\
            if(new_set == NULL){        //no habia espacio\n\
                exit(1);\n\
            }\n\
            Block * block = malloc(sizeof(struct block));\n\
            if(block == NULL){        //no habia espacio\n\
                exit(1);\n\
            }\n\
            Chord emptyChord = {NULL, 0};\n\
            block->chords = chordSum(chord, &emptyChord);\n\
            if (block->chords == NULL) {\n\
                free(block);\n\
                free(new_set);\n\
                exit(1);\n\
            }\n\
            block->time = time;\n\
            new_set->blocks = block;\n\
            new_set->quant = 1;\n\
            return new_set;\n\
        }\n\
        int totalTime(Set * set){\n\
            int time = 0;\n\
            for(int i = 0; i < set->quant ; i++) {\n\
                time += set->blocks[i].time;\n\
            }\n\
            return time;\n\
        }\n\
        int avgFreq(Chord * chord){\n\
            float sum_freq = 0;\n\
            int quant = 0;\n\
            while (quant < chord->quant){\n\
                sum_freq += notes[chord->notes[quant].note];\n\
                quant++;\n\
            }\n\
            return (quant == 0) ? 0 : (sum_freq/quant);\n\
        }\n");
}

void printWaveEndiannessFunctions(){
    /* Wave functions */
    printf("WaveHeader makeWaveHeader(int const sampleRate, short int const numChannels, short int const bitsPerSample ) {\n\
                WaveHeader myHeader;\n\
                myHeader.chunkId[0] = 'R';\n\
                myHeader.chunkId[1] = 'I';\n\
                myHeader.chunkId[2] = 'F';\n\
                myHeader.chunkId[3] = 'F';\n\
                myHeader.format[0] = 'W';\n\
                myHeader.format[1] = 'A';\n\
                myHeader.format[2] = 'V';\n\
                myHeader.format[3] = 'E';\n\
                myHeader.subChunk1Id[0] = 'f';\n\
                myHeader.subChunk1Id[1] = 'm';\n\
                myHeader.subChunk1Id[2] = 't';\n\
                myHeader.subChunk1Id[3] = ' ';\n\
                myHeader.audioFormat = 1;\n\
                myHeader.numChannels = numChannels;\n\
                myHeader.sampleRate = sampleRate; \n\
                myHeader.bitsPerSample = bitsPerSample; \n\
                myHeader.byteRate = myHeader.sampleRate * myHeader.numChannels * myHeader.bitsPerSample / 8;\n\
                myHeader.blockAlign = myHeader.numChannels * myHeader.bitsPerSample/8;\n\
                myHeader.subChunk2Id[0] = 'd';\n\
                myHeader.subChunk2Id[1] = 'a';\n\
                myHeader.subChunk2Id[2] = 't';\n\
                myHeader.subChunk2Id[3] = 'a';\n\
                myHeader.chunkSize = 4+8+16+8+0;\n\
                myHeader.subChunk1Size = 16;\n\
                myHeader.subChunk2Size = 0;\n\
                return myHeader;\n\
            }\n\
            Wave makeWave(int const sampleRate, short int const numChannels, short int const bitsPerSample) {\n\
                Wave myWave;\n\
                myWave.header = makeWaveHeader(sampleRate,numChannels,bitsPerSample);\n\
                return myWave;\n\
            }\n\
            void waveDestroy( Wave* wave) {\n\
                free( wave->data );\n\
            }\n\
            void waveSetDuration( Wave* wave, const long miliseconds ) {\n\
                const float seconds = miliseconds / 1000.0;\n\
                long long int totalBytes = (long long int)(wave->header.byteRate*seconds);\n\
                wave->data = (char*)malloc(totalBytes);\n\
                wave->index = 0;\n\
                wave->size = totalBytes;\n\
                wave->nSamples = (long long int) wave->header.numChannels * wave->header.sampleRate * seconds;\n\
                wave->header.chunkSize = 4+8+16+8+totalBytes;\n\
                wave->header.subChunk2Size = totalBytes;\n\
            }\n\
            void waveAddSample( Wave* wave, const float* samples ){\n\
                int i;\n\
                short int sample8bit;\n\
                int sample16bit;\n\
                long int sample32bit;\n\
                char* sample;\n\
                if( wave->header.bitsPerSample == 8 ){\n\
                    for( i=0; i<wave->header.numChannels; i+= 1){\n\
                        sample8bit = (short int) (127+127.0*samples[i]);\n\
                        toLittleEndian(1, (void*) &sample8bit);\n\
                        sample = (char*)&sample8bit;\n\
                        (wave->data)[ wave->index ] = sample[0];\n\
                        wave->index += 1;\n\
                    }\n\
                }\n\
                if( wave->header.bitsPerSample == 16 ){\n\
                    for( i=0; i<wave->header.numChannels; i+= 1){\n\
                        sample16bit = (int) (32767.0*samples[i]);\n\
                        toLittleEndian(2, (void*) &sample16bit);\n\
                        sample = (char*)&sample16bit;\n\
                        wave->data[ wave->index + 0 ] = sample[0];\n\
                        wave->data[ wave->index + 1 ] = sample[1];\n\
                        wave->index += 2;\n\
                    }\n\
                }\n\
                if( wave->header.bitsPerSample == 32 ){\n\
                    for( i=0; i<wave->header.numChannels; i+= 1){\n\
                        sample32bit = (long int) ((pow(2,32-1)-1)*samples[i]);\n\
                        toLittleEndian(4, (void*) &sample32bit);\n\
                        sample = (char*)&sample32bit;\n\
                        wave->data[ wave->index + 0 ] = sample[0];\n\
                        wave->data[ wave->index + 1 ] = sample[1];\n\
                        wave->data[ wave->index + 2 ] = sample[2];\n\
                        wave->data[ wave->index + 3 ] = sample[3];\n\
                        wave->index += 4;\n\
                    }\n\
                }\n\
            }\n\
            void waveToFile( Wave* wave, const char* filename ){\n\
                toLittleEndian(sizeof(int), (void*)&(wave->header.chunkSize));\n\
                toLittleEndian(sizeof(int), (void*)&(wave->header.subChunk1Size));\n\
                toLittleEndian(sizeof(short int), (void*)&(wave->header.audioFormat));\n\
                toLittleEndian(sizeof(short int), (void*)&(wave->header.numChannels));\n\
                toLittleEndian(sizeof(int), (void*)&(wave->header.sampleRate));\n\
                toLittleEndian(sizeof(int), (void*)&(wave->header.byteRate));\n\
                toLittleEndian(sizeof(short int), (void*)&(wave->header.blockAlign));\n\
                toLittleEndian(sizeof(short int), (void*)&(wave->header.bitsPerSample));\n\
                toLittleEndian(sizeof(int), (void*)&(wave->header.subChunk2Size));\n\
                FILE *file;\n\
                file = fopen(filename, \"wb\");\n\
                fwrite( &(wave->header), sizeof(WaveHeader), 1, file );\n\
                fwrite( (void*)(wave->data), sizeof(char), wave->size, file );\n\
                fclose( file );\n\
                toLittleEndian(sizeof(int), (void*)&(wave->header.chunkSize));\n\
                toLittleEndian(sizeof(int), (void*)&(wave->header.subChunk1Size));\n\
                toLittleEndian(sizeof(short int), (void*)&(wave->header.audioFormat));\n\
                toLittleEndian(sizeof(short int), (void*)&(wave->header.numChannels));\n\
                toLittleEndian(sizeof(int), (void*)&(wave->header.sampleRate));\n\
                toLittleEndian(sizeof(int), (void*)&(wave->header.byteRate));\n\
                toLittleEndian(sizeof(short int), (void*)&(wave->header.blockAlign));\n\
                toLittleEndian(sizeof(short int), (void*)&(wave->header.bitsPerSample));\n\
                toLittleEndian(sizeof(int), (void*)&(wave->header.subChunk2Size));\n\
            }\n");
        /* Endianness functions */
        printf("int isBigEndian() {\n\
                    int test = 1;\n\
                    char *p = (char*)&test;\n\
                    return p[0] == 0;\n\
                }\n\
                void reverseEndianness(const long long int size, void* value) {\n\
                    int i;\n\
                    char result[32];\n\
                    for( i=0; i<size; i+=1 ){\n\
                        result[i] = ((char*)value)[size-i-1];\n\
                    }\n\
                    for( i=0; i<size; i+=1 ){\n\
                        ((char*)value)[i] = result[i];\n\
                    }\n\
                }\n\
                void toBigEndian(const long long int size, void* value) {\n\
                    char needsFix = !( (1 && isBigEndian()) || (0 && !isBigEndian()) );\n\
                    if( needsFix ){\n\
                        reverseEndianness(size,value);\n\
                    }\n\
                }\n\
                void toLittleEndian(const long long int size, void* value) {\n\
                    char needsFix = !( (0 && isBigEndian()) || (1 && !isBigEndian()) );\n\
                    if( needsFix ){\n\
                        reverseEndianness(size,value);\n\
                    }\n\
                }\n");
}


/**
* *       yacc -d parser.y
* *       lex scanner.l
* *       gcc lex.yy.c y.tab.c -ly
**/
