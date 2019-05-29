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
#line 1 "./miniC.y" /* yacc.c:339  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>
#include "fonction.h"
#include "fonction.c"
#include "fonction_g_code.h"
#include "fonction_g_code.c"


Environnement env = {NULL, 0, NULL};
Environnement* p_env = &env;
Environnement envNull = {NULL, 0, NULL};

Pile_node pile_node = {NULL};  
Pile_node pile_node_case = {NULL};  
Node node_case[100]; 
int inc = 0;
Pile_str pile_str = {NULL};  
Pile_str pile_expr = {NULL}; 
Node* p_node = NULL;   
Pile_str tabPile_str[100];
int i_tabPile_str = 0;
Pile pile = {&env};
Pile pileFonction = {&envNull};
int op = 0;
int parms = 0;
int exprs = 0;
char* isTab = "";
char* tab ;
int n_error = 0;
int yylex();
int isVoid = 0;
int isSwitch = 0;
char* nodeCase;
int testRetour = 0;
int yylineno;
char* yytext;
void yyerror(char *s) {
    fprintf(stderr, "* Error \"%s\", ligne %d: \n", s, yylineno);
    n_error++;
     /* le programe s'arrete lors d'une erreur de syntaxe */
}

void warningError(char *s) {
    fprintf(stdout, "* Avertissement \"%s\", ligne %d: \n", s, yylineno);
     /* le programe s'arrete lors d'une erreur de syntaxe */
}

    

#line 120 "y.tab.c" /* yacc.c:339  */

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
    VOID = 258,
    INT = 259,
    FOR = 260,
    WHILE = 261,
    IF = 262,
    ELSE = 263,
    SWITCH = 264,
    CASE = 265,
    DEFAULT = 266,
    IDENTIFICATEUR = 267,
    CONSTANTE = 268,
    BREAK = 269,
    RETURN = 270,
    PLUS = 271,
    MOINS = 272,
    MUL = 273,
    DIV = 274,
    LSHIFT = 275,
    RSHIFT = 276,
    BAND = 277,
    BOR = 278,
    LAND = 279,
    LOR = 280,
    LT = 281,
    GT = 282,
    GEQ = 283,
    LEQ = 284,
    EQ = 285,
    NEQ = 286,
    NOT = 287,
    EXTERN = 288,
    THEN = 289,
    OP = 290,
    REL = 291
  };
#endif
/* Tokens.  */
#define VOID 258
#define INT 259
#define FOR 260
#define WHILE 261
#define IF 262
#define ELSE 263
#define SWITCH 264
#define CASE 265
#define DEFAULT 266
#define IDENTIFICATEUR 267
#define CONSTANTE 268
#define BREAK 269
#define RETURN 270
#define PLUS 271
#define MOINS 272
#define MUL 273
#define DIV 274
#define LSHIFT 275
#define RSHIFT 276
#define BAND 277
#define BOR 278
#define LAND 279
#define LOR 280
#define LT 281
#define GT 282
#define GEQ 283
#define LEQ 284
#define EQ 285
#define NEQ 286
#define NOT 287
#define EXTERN 288
#define THEN 289
#define OP 290
#define REL 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 74 "./miniC.y" /* yacc.c:355  */

    char* chaine; 
    int valnum;

#line 237 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 254 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   241

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

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
      41,    42,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    37,
       2,    46,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    81,    81,    88,    91,    99,   102,   105,   115,   116,
     119,   123,   126,   163,   173,   177,   183,   185,   186,   189,
     196,   201,   207,   208,   209,   216,   217,   218,   221,   230,
     239,   246,   255,   271,   282,   295,   300,   307,   322,   328,
     337,   349,   360,   367,   378,   381,   393,   405,   417,   429,
     441,   453,   465,   477,   484,   489,   492,   502,   512,   519,
     522,   528,   535,   536,   545,   546,   549,   550,   551,   552,
     553,   554
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "FOR", "WHILE", "IF",
  "ELSE", "SWITCH", "CASE", "DEFAULT", "IDENTIFICATEUR", "CONSTANTE",
  "BREAK", "RETURN", "PLUS", "MOINS", "MUL", "DIV", "LSHIFT", "RSHIFT",
  "BAND", "BOR", "LAND", "LOR", "LT", "GT", "GEQ", "LEQ", "EQ", "NEQ",
  "NOT", "EXTERN", "THEN", "OP", "REL", "';'", "','", "'['", "']'", "'('",
  "')'", "'{'", "'}'", "':'", "'='", "$accept", "programme",
  "liste_declarations", "liste_fonctions", "declaration",
  "liste_declarateurs", "declarateur", "fonction", "type", "liste_parms",
  "parm", "liste_instructions", "instruction", "iteration", "selection",
  "saut", "expression_switch", "affectation", "bloc", "appel", "variable",
  "expression", "liste_expressions", "condition", "binary_rel",
  "binary_comp", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,    59,    44,    91,
      93,    40,    41,   123,   125,    58,    61
};
# endif

#define YYPACT_NINF -66

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-66)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -66,    11,     0,   -66,   -66,   -66,    83,     0,   -66,   -66,
       9,    23,   -66,    30,    13,    92,    -2,    16,    13,    58,
     -66,    67,    68,    58,    81,    -4,   -66,   -66,    -2,    63,
       2,   -66,    58,    65,   -66,    77,   -66,   -66,   -66,    83,
      67,     3,    78,   105,   155,   170,   118,    79,   171,   126,
      72,   -66,   -66,   -66,   -66,   -66,   -66,   190,   -66,   -66,
     -20,   143,   115,   115,    94,   147,   111,    94,   -66,   189,
     -66,    94,   -66,    94,   192,   165,    83,   -66,    94,    94,
     -66,   191,   193,   115,   187,   -19,     7,   194,   203,   111,
     -66,   203,    25,    94,   139,   149,    94,    94,    94,    94,
      94,    94,    94,    94,   -66,    90,   157,   203,   115,   115,
     122,    36,   -66,   -66,   -66,   -66,   -66,   -66,    94,   -66,
     -66,   111,   115,   111,   111,   -66,    94,   195,   151,   -66,
     139,   139,   178,   178,   114,   114,   -66,   -66,   -66,   -66,
       4,    52,   -66,   203,   -66,   -66,   221,   -66,   203,   -66,
     -66,   143,   -66,   111,   196,   -66,   111,   -66
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,    14,    15,     0,     2,     3,     6,
       0,     0,     5,     0,    10,     0,     9,     0,     0,    18,
       7,     0,     0,    18,     0,     0,    16,    10,     8,     0,
       0,    19,     0,     0,    11,     0,    17,     4,    13,    21,
       0,     0,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     4,    12,    20,    22,    23,    24,     0,    26,    27,
       0,     0,     0,     0,     0,     0,     0,    59,    35,    42,
      54,     0,    36,     0,    55,     0,    21,    25,     0,     0,
      42,     0,     0,     0,     0,     0,     0,     0,    38,     0,
      34,    57,     0,    59,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,     0,    39,     0,     0,
       0,     0,    66,    67,    68,    69,    70,    71,     0,    64,
      65,     0,     0,     0,     0,    33,     0,     0,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    40,    43,
       0,     0,    62,    63,    29,    61,    30,    32,    58,    41,
      56,     0,    60,     0,     0,    31,     0,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,   -66,   -21,   -66,   -66,   -66,   212,   228,   188,   214,
     207,   164,   -65,   -66,   -66,   -66,   -66,   -59,   -66,   -66,
     -41,   -28,   148,   -56,   -66,   -66
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     7,     8,    15,    16,     9,    40,    25,
      26,    41,    53,    54,    55,    56,    87,    57,    58,    59,
      74,    84,    92,    85,   122,   118
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      60,    90,    81,     4,     5,   119,   120,    86,    42,    43,
      44,     3,    45,    46,    47,    48,    39,    49,    50,    78,
      60,    14,    75,   121,   125,    60,    79,   111,   119,   120,
      76,   119,   120,     6,    32,    17,    88,    22,    33,    91,
      32,   151,    18,    94,    35,    95,    51,    52,    60,   123,
     106,   107,   140,   141,    19,   110,   144,    23,   146,   147,
     119,   120,    24,   126,    60,    91,   145,   127,   130,   131,
     132,   133,   134,   135,   136,   137,   119,   120,   142,    27,
      60,    29,    60,    60,    69,    70,     4,     5,   155,    71,
     143,   157,   154,    31,   152,    42,    43,    44,   148,    45,
      46,    47,    48,    34,    49,    50,    69,    70,    37,    72,
      60,    71,    60,    73,    38,    60,    42,    43,    44,    61,
      45,    46,    47,    48,    66,    49,    50,    69,    70,    20,
      21,    65,    71,    51,   138,    73,   102,   103,    96,    97,
      98,    99,   100,   101,   102,   103,    62,    82,   112,   113,
     114,   115,   116,   117,    51,    80,    83,    98,    99,   100,
     101,   102,   103,    68,   129,    96,    97,    98,    99,   100,
     101,   102,   103,    96,    97,    98,    99,   100,   101,   102,
     103,    96,    97,    98,    99,   100,   101,   102,   103,   126,
      10,   129,    89,   150,    11,    13,    63,   139,   100,   101,
     102,   103,   104,    96,    97,    98,    99,   100,   101,   102,
     103,    64,    67,   112,   113,   114,   115,   116,   117,    96,
      97,    98,    99,   100,   101,   102,   103,    77,   108,   153,
      93,    78,   149,    28,   109,    12,   124,    30,   156,    36,
     105,   128
};

static const yytype_uint8 yycheck[] =
{
      41,    66,    61,     3,     4,    24,    25,    63,     5,     6,
       7,     0,     9,    10,    11,    12,    37,    14,    15,    39,
      61,    12,    50,    42,    89,    66,    46,    83,    24,    25,
      51,    24,    25,    33,    38,    12,    64,    39,    42,    67,
      38,    37,    12,    71,    42,    73,    43,    44,    89,    42,
      78,    79,   108,   109,    41,    83,   121,    41,   123,   124,
      24,    25,     4,    38,   105,    93,   122,    42,    96,    97,
      98,    99,   100,   101,   102,   103,    24,    25,    42,    12,
     121,    13,   123,   124,    12,    13,     3,     4,   153,    17,
     118,   156,   151,    12,    42,     5,     6,     7,   126,     9,
      10,    11,    12,    40,    14,    15,    12,    13,    43,    37,
     151,    17,   153,    41,    37,   156,     5,     6,     7,    41,
       9,    10,    11,    12,    45,    14,    15,    12,    13,    37,
      38,    13,    17,    43,    44,    41,    22,    23,    16,    17,
      18,    19,    20,    21,    22,    23,    41,    32,    26,    27,
      28,    29,    30,    31,    43,    12,    41,    18,    19,    20,
      21,    22,    23,    37,    42,    16,    17,    18,    19,    20,
      21,    22,    23,    16,    17,    18,    19,    20,    21,    22,
      23,    16,    17,    18,    19,    20,    21,    22,    23,    38,
       2,    42,    45,    42,     6,     7,    41,    40,    20,    21,
      22,    23,    37,    16,    17,    18,    19,    20,    21,    22,
      23,    41,    41,    26,    27,    28,    29,    30,    31,    16,
      17,    18,    19,    20,    21,    22,    23,    37,    37,     8,
      41,    39,    37,    21,    41,     7,    42,    23,    42,    32,
      76,    93
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    49,     0,     3,     4,    33,    50,    51,    54,
      55,    55,    54,    55,    12,    52,    53,    12,    12,    41,
      37,    38,    39,    41,     4,    56,    57,    12,    53,    13,
      56,    12,    38,    42,    40,    42,    57,    43,    37,    49,
      55,    58,     5,     6,     7,     9,    10,    11,    12,    14,
      15,    43,    44,    59,    60,    61,    62,    64,    65,    66,
      67,    41,    41,    41,    41,    13,    45,    41,    37,    12,
      13,    17,    37,    41,    67,    68,    49,    37,    39,    46,
      12,    64,    32,    41,    68,    70,    70,    63,    68,    45,
      59,    68,    69,    41,    68,    68,    16,    17,    18,    19,
      20,    21,    22,    23,    37,    58,    68,    68,    37,    41,
      68,    70,    26,    27,    28,    29,    30,    31,    72,    24,
      25,    42,    71,    42,    42,    59,    38,    42,    69,    42,
      68,    68,    68,    68,    68,    68,    68,    68,    44,    40,
      70,    70,    42,    68,    59,    70,    59,    59,    68,    37,
      42,    37,    42,     8,    64,    59,    42,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    56,    57,
      58,    58,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    61,    61,    61,    61,    62,    62,    62,    63,    64,
      65,    66,    67,    67,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    69,    69,    69,
      70,    70,    70,    70,    71,    71,    72,    72,    72,    72,
      72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     1,     3,     3,     1,
       1,     4,     9,     7,     1,     1,     1,     3,     0,     2,
       2,     0,     1,     1,     1,     2,     1,     1,     9,     5,
       5,     7,     5,     4,     3,     2,     2,     3,     1,     3,
       4,     5,     1,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     4,     1,     3,     0,
       4,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1
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
#line 81 "./miniC.y" /* yacc.c:1646  */
    {
            
            printf("Fin du programme: %d erreur(s) generee(s).\n",n_error);
                
        }
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 88 "./miniC.y" /* yacc.c:1646  */
    {
            (yyval.chaine) = concat(2, (yyvsp[-1].chaine), (yyvsp[0].chaine));
        }
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 91 "./miniC.y" /* yacc.c:1646  */
    {
            Pile_str pile_str = {NULL};
            tabPile_str[++i_tabPile_str] = pile_str;
            semantiqueEmpiler(&pile); 
            (yyval.chaine) = "";
        }
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 99 "./miniC.y" /* yacc.c:1646  */
    {
            (yyval.chaine) = concat(2, (yyvsp[-1].chaine), (yyvsp[0].chaine));
    }
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 102 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = (yyvsp[0].chaine);}
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 105 "./miniC.y" /* yacc.c:1646  */
    {
             if(isVoid == 1){
                yyerror("declaration avec void");
                printf("Le type void ne peut etre utiliser pour la declaration de variable\n");
            }
            (yyval.chaine) = concat(4, (yyvsp[-2].chaine), " ", (yyvsp[-1].chaine), ";\n");
            
        }
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 115 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = concat(3, (yyvsp[-2].chaine), ",", (yyvsp[0].chaine));}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 116 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = (yyvsp[0].chaine);}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 119 "./miniC.y" /* yacc.c:1646  */
    {
            (yyval.chaine) = (yyvsp[0].chaine);
            sementiqueDeclaration2((yyvsp[0].chaine),&pile,&pileFonction,0,&yylineno);
            }
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 123 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = concat(4, (yyvsp[-3].chaine), "[",(yyvsp[-1].chaine), "]");}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 126 "./miniC.y" /* yacc.c:1646  */
    {
            (yyval.chaine) = (yyvsp[-7].chaine);
            depiler(&pile);
            sementiqueDeclaration((yyvsp[-7].chaine),&pile,parms,&yylineno);
            for(int cpt = 0; cpt < cpt_lva ; cpt++){
                Variable var = listeValeur_appel[cpt];
                Variable varPile = trouverVar_pile(var.nom,&pile);
                rechercheVarDansPile(var.nom , &pile ,&yylineno);
                if(var.valeur != varPile.valeur){
                    yyerror("nombre parametre");
                    printf("\til faut %d parametres a la fonction \" %s(int ...) \" , vous en avez mis %d !!!\n",varPile.valeur, var.nom , var.valeur);
                }
            }
            empiler(&pileFonction);
            parms = 0;
            cpt_lva = 0;
            if(strcmp((yyvsp[-8].chaine),"int")==0 && testRetour == 0){
                warningError("Absence de retour d'expression");
                printf("La fonction int n'a pas de retour d'expression.\n\n");

            }
            testRetour = 0;
            
            
            char* bloc = myNodeName();
            char* fonction = myNodeName();
            char* label_fonction = concat(3,(yyvsp[-8].chaine)," , ",(yyvsp[-7].chaine));
            modifParentNode_str(&pile_node,&tabPile_str[i_tabPile_str--],bloc);
            empiler_node(&pile_node,bloc,"BLOC",2,fonction);
            
            empiler_node(&pile_node,fonction,label_fonction,1,"");
            
            
            (yyval.chaine) = fonction;
            }
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 163 "./miniC.y" /* yacc.c:1646  */
    {
            
            sementiqueDeclaration((yyvsp[-4].chaine),&pile,parms,&yylineno);
            empiler(&pileFonction);
            parms = 0;
            (yyval.chaine) = "";
    
    }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 173 "./miniC.y" /* yacc.c:1646  */
    {
            (yyval.chaine) = "void";
            isVoid = 1;
        }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 177 "./miniC.y" /* yacc.c:1646  */
    {
        (yyval.chaine) = "int";
        isVoid = 0;
    }
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 183 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = (yyvsp[0].chaine);}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 185 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = concat(3,(yyvsp[-2].chaine),",",(yyvsp[0].chaine));}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 186 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine)="";}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 189 "./miniC.y" /* yacc.c:1646  */
    {
            (yyval.chaine) = concat(2,"int ",(yyvsp[0].chaine));
            sementiqueDeclaration((yyvsp[0].chaine),&pileFonction,parms,&yylineno);
            parms++;
        }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 196 "./miniC.y" /* yacc.c:1646  */
    {
            empiler_str(&tabPile_str[i_tabPile_str],(yyvsp[0].chaine));
            p_node = pile_node.premier;
            (yyval.chaine) = (yyvsp[0].chaine);
        }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 201 "./miniC.y" /* yacc.c:1646  */
    {
        (yyval.chaine) = "";
        
    }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 207 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = (yyvsp[0].chaine);}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 208 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = (yyvsp[0].chaine);}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 209 "./miniC.y" /* yacc.c:1646  */
    {
        (yyval.chaine) = (yyvsp[0].chaine);
        if(isSwitch>0){
            modifParentNode(&pile_node,(yyval.chaine),nodeCase);
            isSwitch = 0;
        }
    }
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 216 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = concat(2,(yyvsp[-1].chaine),"");}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 217 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = (yyvsp[0].chaine);}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 218 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = (yyvsp[0].chaine);}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 221 "./miniC.y" /* yacc.c:1646  */
    {
            char* parent = myNodeName();        
            modifParentNode(&pile_node,(yyvsp[-6].chaine),parent);
            modifParentNode(&pile_node,(yyvsp[-4].chaine),parent);
            modifParentNode(&pile_node,(yyvsp[-2].chaine),parent);
            modifParentNode(&pile_node,(yyvsp[0].chaine),parent);
            empiler_node(&pile_node,parent,"FOR",2,""); 
            (yyval.chaine) = parent;
        }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 230 "./miniC.y" /* yacc.c:1646  */
    {
            char* parent = myNodeName();        
            modifParentNode(&pile_node,(yyvsp[-2].chaine),parent);
            modifParentNode(&pile_node,(yyvsp[0].chaine),parent);
            empiler_node(&pile_node,parent,"WHILE",2,""); 
            (yyval.chaine) = parent;
    }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 239 "./miniC.y" /* yacc.c:1646  */
    {
            char* parent = myNodeName();        
            modifParentNode(&pile_node,(yyvsp[-2].chaine),parent);
            modifParentNode(&pile_node,(yyvsp[0].chaine),parent);
            empiler_node(&pile_node,parent,"IF",6,""); 
            (yyval.chaine) = parent;
        }
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 246 "./miniC.y" /* yacc.c:1646  */
    {
            char* parent = myNodeName();        
            modifParentNode(&pile_node,(yyvsp[-4].chaine),parent);
            modifParentNode(&pile_node,(yyvsp[-2].chaine),parent);
            modifParentNode(&pile_node,(yyvsp[0].chaine),parent);
            empiler_node(&pile_node,parent,"IF",6,""); 
            (yyval.chaine) = parent;
        
        }
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 255 "./miniC.y" /* yacc.c:1646  */
    {
            isSwitch = 0;
            /*pile_node.premier = p_node;
            depiler_node(&pile_node);*/
            pile_node.premier->label = "SWITCH";
            char* parent = pile_node.premier->nom;
            
           
            /*int i = 0;
            while(i<inc){
                Node n = node_case[i++];
                empiler_node(&pile_node,n.nom,n.label,2,parent); 
            }
            inc = 0;*/
            (yyval.chaine) = parent;
        }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 271 "./miniC.y" /* yacc.c:1646  */
    {
            isSwitch = 1;
            char* myCase = myNodeName();        
            char* case_label = concat(2,"case",(yyvsp[-2].chaine));
            modifParentNode(&pile_node,(yyvsp[0].chaine),myCase);
            empiler_node(&pile_node,myCase,case_label,2,"");
            Node n = {myCase,case_label,2,NULL,""};
            node_case[inc++] = n;
            nodeCase = myCase;
            (yyval.chaine) = myCase;
        }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 282 "./miniC.y" /* yacc.c:1646  */
    {
            isSwitch = 1;
            char* myCase = myNodeName();        
            char* case_label = "case_default";
            modifParentNode(&pile_node,(yyvsp[0].chaine),myCase);
            empiler_node(&pile_node,myCase,case_label,2,"");
            Node n = {myCase,case_label,2,NULL,""};
            node_case[inc++] = n;
            nodeCase = myCase;
            (yyval.chaine) = myCase;
        }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 295 "./miniC.y" /* yacc.c:1646  */
    {
            char* nom = myNodeName();
            empiler_node(&pile_node,nom,"BREAK",5,""); 
            (yyval.chaine) = nom;
        }
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 300 "./miniC.y" /* yacc.c:1646  */
    {
        
            char* parent = myNodeName();
            empiler_node(&pile_node,parent,"RETURN",3,""); 
            (yyval.chaine) = parent;
        
        }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 307 "./miniC.y" /* yacc.c:1646  */
    {
             testRetour = 1;
             char* parent = myNodeName();        
             modifParentNode(&pile_node,(yyvsp[-1].chaine),parent);
             empiler_node(&pile_node,parent,"RETURN",3,""); 
             (yyval.chaine) = parent;
        
             if(isVoid == 1){
                yyerror("retour d'un void");
                printf("Une fonction de type void ne peut pas avoir de retour\n");
            }
    }
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 322 "./miniC.y" /* yacc.c:1646  */
    {
            pile_node.premier = p_node;
            (yyval.chaine) = (yyvsp[0].chaine);
        }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 328 "./miniC.y" /* yacc.c:1646  */
    {
        char* parent = myNodeName();        
        modifParentNode(&pile_node,(yyvsp[-2].chaine),parent);
        modifParentNode(&pile_node,(yyvsp[0].chaine),parent);
        empiler_node(&pile_node,parent,":=",2,""); 
        (yyval.chaine) = parent;
        }
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 337 "./miniC.y" /* yacc.c:1646  */
    {
            char* bloc = myNodeName();
            
            modifParentNode_str(&pile_node,&tabPile_str[i_tabPile_str--],bloc);
            empiler_node(&pile_node,bloc,"BLOC",2,"");
            (yyval.chaine) = bloc;
            
            depiler(&pile);            
           
        }
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 349 "./miniC.y" /* yacc.c:1646  */
    {
            
            char* parent = myNodeName();
            modifParentNode_str(&pile_node,&tabPile_str[i_tabPile_str--],parent);
            empiler_node(&pile_node,parent,(yyvsp[-4].chaine),4,"");
            (yyval.chaine)= parent;
            semantiqueAppel((yyvsp[-4].chaine),&pile,&exprs,&yylineno);
            exprs = 0;
        }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 360 "./miniC.y" /* yacc.c:1646  */
    {
            char* nom = myNodeName();
            (yyval.chaine) = nom;
            tab = myNodeName();
            empiler_node(&pile_node,nom,(yyvsp[0].chaine),2,"");
            rechercheVarDansPile2((yyvsp[0].chaine) , &pile, &pileFonction ,&yylineno);
        }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 367 "./miniC.y" /* yacc.c:1646  */
    { 
            if(strcmp(isTab,tab)!=0){
                isTab = tab;
                empiler_node(&pile_node,tab,"TAB",2,"");
                modifParentNode(&pile_node,(yyvsp[-3].chaine),tab);
            }
            modifParentNode(&pile_node,(yyvsp[-1].chaine),tab);
            (yyval.chaine) = tab;
        }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 378 "./miniC.y" /* yacc.c:1646  */
    {
            (yyval.chaine) = (yyvsp[-1].chaine);
        }
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 381 "./miniC.y" /* yacc.c:1646  */
    {
        
            char* parent = myNodeName();        
            modifParentNode(&pile_node,(yyvsp[-2].chaine),parent);
            modifParentNode(&pile_node,(yyvsp[0].chaine),parent);
            empiler_node(&pile_node,parent,"+",2,"");
            /*if(condition_trois_adresses(&pile_node,$2,parent)){
                printf("->>>%s\n",$2);
                code_trois_adresses(&pile_node);
            }*/
            (yyval.chaine) = parent;
    }
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 393 "./miniC.y" /* yacc.c:1646  */
    {
        
            char* parent = myNodeName();        
            modifParentNode(&pile_node,(yyvsp[-2].chaine),parent);
            modifParentNode(&pile_node,(yyvsp[0].chaine),parent);
            empiler_node(&pile_node,parent,"-",2,"");
            /*if(condition_trois_adresses(&pile_node,$2,parent)){
                printf("->>>%s\n",$2);
                code_trois_adresses(&pile_node);
            }*/
            (yyval.chaine) = parent;
    }
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 405 "./miniC.y" /* yacc.c:1646  */
    {
        
            char* parent = myNodeName();        
            modifParentNode(&pile_node,(yyvsp[-2].chaine),parent);
            modifParentNode(&pile_node,(yyvsp[0].chaine),parent);
            empiler_node(&pile_node,parent,"*",2,"");
            /*if(condition_trois_adresses(&pile_node,$2,parent)){
                printf("->>>%s\n",$2);
                code_trois_adresses(&pile_node);
            }*/
            (yyval.chaine) = parent;
    }
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 417 "./miniC.y" /* yacc.c:1646  */
    {
        
            char* parent = myNodeName();        
            modifParentNode(&pile_node,(yyvsp[-2].chaine),parent);
            modifParentNode(&pile_node,(yyvsp[0].chaine),parent);
            empiler_node(&pile_node,parent,"/",2,"");
            /*if(condition_trois_adresses(&pile_node,$2,parent)){
                printf("->>>%s\n",$2);
                code_trois_adresses(&pile_node);
            }*/
            (yyval.chaine) = parent;
    }
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 429 "./miniC.y" /* yacc.c:1646  */
    {
        
            char* parent = myNodeName();        
            modifParentNode(&pile_node,(yyvsp[-2].chaine),parent);
            modifParentNode(&pile_node,(yyvsp[0].chaine),parent);
            empiler_node(&pile_node,parent,"<<",2,"");
            /*if(condition_trois_adresses(&pile_node,$2,parent)){
                printf("->>>%s\n",$2);
                code_trois_adresses(&pile_node);
            }*/
            (yyval.chaine) = parent;
    }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 441 "./miniC.y" /* yacc.c:1646  */
    {
        
            char* parent = myNodeName();        
            modifParentNode(&pile_node,(yyvsp[-2].chaine),parent);
            modifParentNode(&pile_node,(yyvsp[0].chaine),parent);
            empiler_node(&pile_node,parent,">>",2,"");
            /*if(condition_trois_adresses(&pile_node,$2,parent)){
                printf("->>>%s\n",$2);
                code_trois_adresses(&pile_node);
            }*/
            (yyval.chaine) = parent;
    }
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 453 "./miniC.y" /* yacc.c:1646  */
    {
        
            char* parent = myNodeName();        
            modifParentNode(&pile_node,(yyvsp[-2].chaine),parent);
            modifParentNode(&pile_node,(yyvsp[0].chaine),parent);
            empiler_node(&pile_node,parent,"&",2,"");
            /*if(condition_trois_adresses(&pile_node,$2,parent)){
                printf("->>>%s\n",$2);
                code_trois_adresses(&pile_node);
            }*/
            (yyval.chaine) = parent;
    }
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 465 "./miniC.y" /* yacc.c:1646  */
    {
        
            char* parent = myNodeName();        
            modifParentNode(&pile_node,(yyvsp[-2].chaine),parent);
            modifParentNode(&pile_node,(yyvsp[0].chaine),parent);
            empiler_node(&pile_node,parent,"|",2,"");
            /*if(condition_trois_adresses(&pile_node,$2,parent)){
                printf("->>>%s\n",$2);
                code_trois_adresses(&pile_node);
            }*/
            (yyval.chaine) = parent;
    }
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 477 "./miniC.y" /* yacc.c:1646  */
    {
        
        char* parent = myNodeName();        
        modifParentNode(&pile_node,(yyvsp[0].chaine),parent);
        empiler_node(&pile_node,parent,":-",2,""); 
        (yyval.chaine) = parent;
    }
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 484 "./miniC.y" /* yacc.c:1646  */
    {
            char* nom = myNodeName();
            empiler_node(&pile_node,nom,(yyvsp[0].chaine),2,"");
            (yyval.chaine) = nom;
    }
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 489 "./miniC.y" /* yacc.c:1646  */
    {
            (yyval.chaine) = (yyvsp[0].chaine);
    }
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 492 "./miniC.y" /* yacc.c:1646  */
    {
            char* parent = myNodeName();
            modifParentNode_str(&pile_node,&tabPile_str[i_tabPile_str--],parent);
            empiler_node(&pile_node,parent,(yyvsp[-3].chaine),2,"");
            (yyval.chaine)= parent;
            semantiqueAppel((yyvsp[-3].chaine),&pile,&exprs,&yylineno);
            exprs = 0;
    }
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 502 "./miniC.y" /* yacc.c:1646  */
    {
            exprs++;
            /*empiler_str(&pile_expr,$1);*/
            Pile_str pile_str = {NULL};
            tabPile_str[++i_tabPile_str] = pile_str;
            empiler_str(&tabPile_str[i_tabPile_str],(yyvsp[0].chaine));
            (yyval.chaine) = (yyvsp[0].chaine);
            
        }
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 512 "./miniC.y" /* yacc.c:1646  */
    {
            exprs++;
            empiler_str(&tabPile_str[i_tabPile_str],(yyvsp[0].chaine));
            /*empiler_str(&pile_expr,$3);*/
            (yyval.chaine) = (yyvsp[0].chaine);

    }
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 519 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = "";}
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 522 "./miniC.y" /* yacc.c:1646  */
    {
            char* parent = myNodeName();        
            modifParentNode(&pile_node,(yyvsp[-1].chaine),parent);
            empiler_node(&pile_node,parent,"NOT",2,""); 
            (yyval.chaine) = parent;
        }
#line 2142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 528 "./miniC.y" /* yacc.c:1646  */
    {
            char* parent = myNodeName();        
            modifParentNode(&pile_node,(yyvsp[-2].chaine),parent);
            modifParentNode(&pile_node,(yyvsp[0].chaine),parent);
            empiler_node(&pile_node,parent,(yyvsp[-1].chaine),2,""); 
            (yyval.chaine) = parent;
    }
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 535 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = (yyvsp[-1].chaine);}
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 536 "./miniC.y" /* yacc.c:1646  */
    {
            char* parent = myNodeName();        
            modifParentNode(&pile_node,(yyvsp[-2].chaine),parent);
            modifParentNode(&pile_node,(yyvsp[0].chaine),parent);
            empiler_node(&pile_node,parent,(yyvsp[-1].chaine),2,""); 
            (yyval.chaine) = parent;
        }
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 545 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = "&&";}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 546 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = "||";}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 549 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = "<";}
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 550 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = ">";}
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 551 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = ">=";}
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 552 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = "<=";}
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 553 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = "==";}
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 554 "./miniC.y" /* yacc.c:1646  */
    {(yyval.chaine) = "!=";}
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2224 "y.tab.c" /* yacc.c:1646  */
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
#line 556 "./miniC.y" /* yacc.c:1906  */


int main(int argc, char *argv[]){    
     yyparse();
    if(n_error>0){
                printf("%d erreur(s) de semantique. Aucun fichier n'a ete genere. \n",n_error);
                exit(1);
            }
            
            char* node_reste = "";
            char* node_liaison = "";
            char* contenu = "";
            while(pile_node.premier != NULL){
                Node ins = depiler_node(&pile_node);
                if(strlen(ins.suivant) == 0){
                    node_reste = concat(2,newNode(ins.nom,ins.label,ins.id_label),node_reste);
                    
                        
                }
                else{
                    node_liaison = concat(4,ins.suivant,"->",ins.nom,"\n");
                    node_reste = concat(3,newNode(ins.nom,ins.label,ins.id_label),node_reste,node_liaison);
                }
            }
        
            
            
            
            contenu = concat(3 , "digraph mon_programme {\n",node_reste,"\n}");
            
            char* nomFichier;
            if(argv[1] != NULL)
            {
                nomFichier = argv[1];
                nomFichier = concat(3,"DOT/",argv[1],".dot");
            }
            else
            {
                nomFichier = "DOT/out.dot";

            }
            FILE* fichier = fopen(nomFichier,"w");
            fprintf(fichier, "%s\n", contenu);
            fclose(fichier);
            printf("Un fichier \"%s\" a ete genere.\n",nomFichier);
 }


