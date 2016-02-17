/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 9 "kammeyerm.y" /* yacc.c:339  */


#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <map>
#include <string>
#include <string.h>

  using namespace std;

  void ignoreComment();
  int ckInt();
  void  prRule(const char*, const char*);
  void printTokenInfo(const char* tokenType, 
		      const char* lexeme);

  int yyerror(const char*);

  extern "C" {
    int yyparse(void);
    int yylex(void);
    int yywrap() {return 1;}
 }

#define MAX_INT "2147483647"

#define OUTPUT_TOKENS     1
#define OUTPUT_PRODUCTIONS 1

int lineNum = 1;                   // source line number

 vector< map<char*, char*> > tables;
 vector<char*> lstidents;
 struct typeinfo {
   char* type;
   char* startindex;
   char* startsign;
   char* endindex;
   char* endsign;
   char* basetype;
 };
 
 struct idents {
   char* sign;
   char* text;
 };
 
 struct indexrange {
   char* start;
   char* startsign;
   char* end;
   char* endsign;
 };

 bool search_tables(char* ident) {
   map<char*, char*>::const_iterator it = tables.back().begin();
   for(; it != tables.back().end(); ++it) {
     if(!strcmp(it -> first, ident))
       return false;
   }  
   return true;
 }
 
 bool search_all_tables(char* ident) {
   vector< map<char*, char*> >::reverse_iterator rit = tables.rbegin();
   for(; rit != tables.rend(); ++rit) {
     map<char*, char*>::const_iterator it = (*rit).begin();
     for(; it != (*rit).end(); ++it) {
       if(!strcmp(it -> first, ident))
	 return false;
     }  
   }
   return true;
 }


#line 144 "kammeyerm.tab.c" /* yacc.c:339  */

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
    T_LPAREN = 258,
    T_RPAREN = 259,
    T_MULT = 260,
    T_PLUS = 261,
    T_COMMA = 262,
    T_MINUS = 263,
    T_DOT = 264,
    T_DOTDOT = 265,
    T_COLON = 266,
    T_ASSIGN = 267,
    T_SCOLON = 268,
    T_LT = 269,
    T_LE = 270,
    T_NE = 271,
    T_EQ = 272,
    T_GT = 273,
    T_GE = 274,
    T_LBRACK = 275,
    T_RBRACK = 276,
    T_DO = 277,
    T_AND = 278,
    T_ARRAY = 279,
    T_BEGIN = 280,
    T_BOOL = 281,
    T_CHAR = 282,
    T_DIV = 283,
    T_CHARCONST = 284,
    T_INTCONST = 285,
    T_END = 286,
    T_FALSE = 287,
    T_IF = 288,
    T_INT = 289,
    T_NOT = 290,
    T_OF = 291,
    T_OR = 292,
    T_PROC = 293,
    T_PROG = 294,
    T_READ = 295,
    T_TRUE = 296,
    T_IDENT = 297,
    T_VAR = 298,
    T_WHILE = 299,
    T_WRITE = 300,
    T_UNKNOWN = 301,
    ST_EOF = 302,
    T_THEN = 303,
    T_ELSE = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 87 "kammeyerm.y" /* yacc.c:355  */

  char* text;
  typeinfo info;
  idents ids;
  indexrange range;

#line 238 "kammeyerm.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 253 "kammeyerm.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   112

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   133,   133,   139,   142,   145,   150,   153,   158,   170,
     175,   180,   185,   189,   194,   199,   203,   209,   213,   217,
     222,   227,   231,   236,   240,   244,   248,   253,   260,   263,
     269,   276,   285,   291,   294,   299,   304,   311,   315,   319,
     325,   328,   333,   339,   342,   347,   354,   371,   374,   380,
     385,   390,   398,   407,   390,   411,   416,   422,   426,   430,
     434,   438,   442,   448,   452,   457,   463,   469,   474,   480,
     485,   489,   493,   497,   501,   505,   509,   515,   518,   523,
     528,   533,   541,   552,   602,   605,   611,   614,   620,   624,
     629,   637,   642
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_LPAREN", "T_RPAREN", "T_MULT",
  "T_PLUS", "T_COMMA", "T_MINUS", "T_DOT", "T_DOTDOT", "T_COLON",
  "T_ASSIGN", "T_SCOLON", "T_LT", "T_LE", "T_NE", "T_EQ", "T_GT", "T_GE",
  "T_LBRACK", "T_RBRACK", "T_DO", "T_AND", "T_ARRAY", "T_BEGIN", "T_BOOL",
  "T_CHAR", "T_DIV", "T_CHARCONST", "T_INTCONST", "T_END", "T_FALSE",
  "T_IF", "T_INT", "T_NOT", "T_OF", "T_OR", "T_PROC", "T_PROG", "T_READ",
  "T_TRUE", "T_IDENT", "T_VAR", "T_WHILE", "T_WRITE", "T_UNKNOWN",
  "ST_EOF", "T_THEN", "T_ELSE", "$accept", "N_START", "N_ADDOP",
  "N_ADDOPLST", "N_ARRAY", "N_ARRAYVAR", "N_ASSIGN", "N_BLOCK",
  "N_BOOLCONST", "N_COMPOUND", "N_CONDITION", "N_CONST", "N_ENTIREVAR",
  "N_EXPR", "N_FACTOR", "N_IDENT", "N_IDENTLST", "N_IDX", "N_IDXRANGE",
  "N_IDXVAR", "N_INPUTLST", "N_INPUTVAR", "N_INTCONST", "N_MULTOP",
  "N_MULTOPLST", "N_OUTPUT", "N_OUTPUTLST", "N_PROCDEC", "N_PROCHDR",
  "N_PROCDECPART", "N_PROCIDENT", "N_PROCSTMT", "N_PROG", "$@1", "$@2",
  "$@3", "N_PROGLBL", "N_READ", "N_RELOP", "N_SIGN", "N_SIMPLE",
  "N_SIMPLEEXPR", "N_STMT", "N_STMTLST", "N_STMTPART", "N_TERM", "N_TYPE",
  "N_VARDEC", "N_VARDECLST", "N_VARDECPART", "N_VARIABLE", "N_VARIDENT",
  "N_WHILE", "N_WRITE", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -86

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-86)))

#define YYTABLE_NINF -91

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -16,   -86,    33,   -86,   -86,   -86,    -7,    29,   -86,     6,
       8,   -86,     9,   -86,    41,    38,    49,    17,    54,     6,
      43,     8,    58,     8,   -86,    57,     9,   -86,    -4,   -86,
     -86,    41,    -8,    59,   -86,   -86,   -86,     2,    68,     5,
       2,    70,    55,   -86,   -86,   -86,    56,   -86,   -86,   -86,
     -86,    61,    65,   -86,   -86,   -86,   -86,    60,   -86,   -86,
     -86,   -86,   -86,   -86,     8,     2,   -86,   -86,   -86,   -86,
       2,   -86,   -86,   -86,    30,     4,   -86,   -18,    47,     7,
      37,    62,     2,     2,    -4,    50,     2,    14,   -86,    78,
     -86,    -4,   -86,   -86,   -86,     2,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,     2,   -86,   -86,   -86,
       2,   -86,    76,   -86,    -4,   -86,    79,    64,    61,   -86,
     -86,    77,    67,   -86,    63,   -86,    40,     4,   -86,     7,
      37,    86,   -86,     2,    87,   -86,   -86,    14,    66,    -4,
     -86,   -86,    76,   -86,    79,   -86,   -86,    19,   -86,   -86,
     -86,   -86
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    55,     0,     2,    51,     1,     0,     0,    52,    86,
       0,    53,    47,    27,    28,     0,     0,     0,     0,    86,
       0,     0,     0,    84,    54,     0,    47,    45,     0,    79,
      11,    28,     0,     0,    87,    46,    48,    63,     0,    49,
      63,     0,     0,    70,    76,    74,    88,    89,    50,    71,
      72,    77,     0,    20,    75,    73,    29,     0,    68,    67,
      66,    82,    81,    83,    84,    63,    64,    65,    18,    13,
      63,    12,    19,    24,     0,    40,    17,     0,    21,     6,
       0,     0,    63,    63,     0,     0,    63,    63,    85,     0,
      26,     0,    37,    39,    38,    63,    80,    36,    90,    23,
      57,    59,    62,    61,    58,    60,    63,     3,     4,     5,
      63,    69,    33,    35,     0,    42,    43,     0,    77,    14,
      10,     0,     0,    30,     0,    25,    15,    40,    22,     6,
       0,     0,    91,    63,     0,    32,    78,    63,     0,     0,
      41,     7,    33,    56,    43,    92,    31,     0,    16,    34,
      44,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -86,   -86,   -86,   -37,   -86,   -86,   -86,    75,   -86,    80,
     -86,   -86,   -86,   -26,   -67,    74,    72,   -41,   -86,   -86,
     -45,   -32,   -85,   -86,   -28,   -29,   -43,   -86,   -86,    81,
     -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -81,
     -42,     0,   -84,   -10,   -86,    -1,   -86,   100,    48,   -86,
     -76,   -86,   -86,   -86
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   110,   111,    61,    42,    43,    11,    72,    44,
      45,    73,    46,   115,    75,    14,    22,   121,   122,    47,
     131,   112,    76,    95,    96,   116,   134,    18,    19,    20,
      48,    49,     3,     6,     9,    16,     4,    50,   106,    77,
      62,    78,    51,    85,    30,    79,    63,    33,    34,    12,
      52,    53,    54,    55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     118,    99,   123,    90,   113,    65,   124,   126,    66,    92,
      67,    74,    97,   107,    81,   108,    57,   -90,    58,    59,
      66,    28,    67,     1,    98,   -90,    60,    93,   127,    37,
     132,    68,    94,     5,    69,     7,    38,    70,    39,    89,
      40,    41,     8,    71,   109,    58,    59,    17,    21,    10,
      13,    23,   123,    60,   113,   148,   124,   117,    24,    25,
     120,   100,   101,   102,   103,   104,   105,    26,    28,    32,
      35,    80,    64,    82,    84,    83,    -9,    86,    91,    98,
      87,   119,   125,   130,   114,   135,   133,   137,   138,   139,
     143,   145,   141,    97,    27,    31,   146,   149,   142,   140,
      29,   150,   147,    56,   144,   151,   128,    36,   136,   129,
      15,     0,    88
};

static const yytype_int16 yycheck[] =
{
      84,    77,    87,    70,    80,     3,    87,    91,     6,     5,
       8,    37,    30,     6,    40,     8,    24,    12,    26,    27,
       6,    25,     8,    39,    42,    20,    34,    23,    95,    33,
     114,    29,    28,     0,    32,    42,    40,    35,    42,    65,
      44,    45,    13,    41,    37,    26,    27,    38,     7,    43,
      42,    13,   137,    34,   130,   139,   137,    83,     9,    42,
      86,    14,    15,    16,    17,    18,    19,    13,    25,    11,
      13,     3,    13,     3,    13,    20,    20,    12,    48,    42,
      20,    31,     4,     7,    22,    21,     7,    10,    21,    49,
       4,     4,   129,    30,    19,    21,   137,   142,   130,   127,
      20,   144,    36,    31,   133,   147,   106,    26,   118,   110,
      10,    -1,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    51,    82,    86,     0,    83,    42,    13,    84,
      43,    57,    99,    42,    65,    97,    85,    38,    77,    78,
      79,     7,    66,    13,     9,    42,    13,    57,    25,    59,
      94,    65,    11,    97,    98,    13,    79,    33,    40,    42,
      44,    45,    55,    56,    59,    60,    62,    69,    80,    81,
      87,    92,   100,   101,   102,   103,    66,    24,    26,    27,
      34,    54,    90,    96,    13,     3,     6,     8,    29,    32,
      35,    41,    58,    61,    63,    64,    72,    89,    91,    95,
       3,    63,     3,    20,    13,    93,    12,    20,    98,    63,
      64,    48,     5,    23,    28,    73,    74,    30,    42,   100,
      14,    15,    16,    17,    18,    19,    88,     6,     8,    37,
      52,    53,    71,   100,    22,    63,    75,    63,    92,    31,
      63,    67,    68,    72,    89,     4,    92,    64,    91,    95,
       7,    70,    92,     7,    76,    21,    93,    10,    21,    49,
      74,    53,    71,     4,    75,     4,    67,    36,    92,    70,
      76,    90
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    52,    53,    53,    54,    55,
      56,    57,    58,    58,    59,    60,    60,    61,    61,    61,
      62,    63,    63,    64,    64,    64,    64,    65,    66,    66,
      67,    68,    69,    70,    70,    71,    72,    73,    73,    73,
      74,    74,    75,    76,    76,    77,    78,    79,    79,    80,
      81,    83,    84,    85,    82,    86,    87,    88,    88,    88,
      88,    88,    88,    89,    89,    89,    90,    90,    90,    91,
      92,    92,    92,    92,    92,    92,    92,    93,    93,    94,
      95,    96,    96,    97,    98,    98,    99,    99,   100,   100,
     101,   102,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     0,     3,     6,     1,
       3,     3,     1,     1,     4,     4,     6,     1,     1,     1,
       1,     1,     3,     2,     1,     3,     2,     1,     0,     3,
       1,     3,     4,     0,     3,     1,     2,     1,     1,     1,
       0,     3,     1,     0,     3,     2,     3,     0,     3,     1,
       1,     0,     0,     0,     8,     1,     5,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     1,
       2,     1,     1,     4,     0,     3,     0,     4,     1,     1,
       1,     4,     5
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
#line 133 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_START", "N_PROG");
  printf("\n---- Completed parsing ----\n\n");
  return 0;
 }
#line 1451 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 139 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_ADDOP", "T_PLUS");
 }
#line 1459 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 142 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_ADDOP", "T_MINUS");
 }
#line 1467 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 145 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_ADDOP", "T_OR");
 }
#line 1475 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 150 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_ADDOPLST", "epsilon");
 }
#line 1483 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 154 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_ADDOPLST", "N_ADDOP N_TERM N_ADDOPLST");
 }
#line 1491 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 159 "kammeyerm.y" /* yacc.c:1646  */
    {
     (yyval.info).type = "ARRAY";
     (yyval.info).startindex = (yyvsp[-3].range).start;
     (yyval.info).startsign = (yyvsp[-3].range).startsign;
     (yyval.info).endindex = (yyvsp[-3].range).end;
     (yyval.info).endsign = (yyvsp[-3].range).endsign;
     (yyval.info).basetype = (yyvsp[0].info).type;
     prRule("N_ARRAY",
     "T_ARRAY T_LBRACK N_IDXRANGE T_RBRACK T_OF N_SIMPLE");
 }
#line 1506 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 171 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_ARRAYVAR", "N_ENTIREVAR");
 }
#line 1514 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 176 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_ASSIGN", "N_VARIABLE T_ASSIGN N_EXPR");
 }
#line 1522 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 181 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_BLOCK", "N_VARDECPART N_PROCDECPART N_STMTPART");
 }
#line 1530 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 186 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_BOOLCONST", "T_TRUE");
 }
#line 1538 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 190 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_BOOLCONST", "T_FALSE");
 }
#line 1546 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 195 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_COMPOUND", "T_BEGIN N_STMT N_STMTLST T_END");
 }
#line 1554 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 200 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_CONDITION", "T_IF N_EXPR T_THEN N_STMT");
 }
#line 1562 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 204 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_CONDITION",
     "T_IF N_EXPR T_THEN N_STMT T_ELSE N_STMT");
 }
#line 1571 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 210 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_CONST", "N_INTCONST");
 }
#line 1579 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 214 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_CONST", "T_CHARCONST");
 }
#line 1587 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 218 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_CONST", "N_BOOLCONST");
 }
#line 1595 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 223 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_ENTIREVAR", "N_VARIDENT");
 }
#line 1603 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 228 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_EXPR", "N_SIMPLEEXPR");
 }
#line 1611 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 232 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_EXPR", "N_SIMPLEEXPR N_RELOP N_SIMPLEEXPR");
 }
#line 1619 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 237 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_FACTOR", "N_SIGN N_VARIABLE");
 }
#line 1627 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 241 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_FACTOR", "N_CONST");
 }
#line 1635 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 245 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_FACTOR", "T_LPAREN N_EXPR T_RPAREN");
 }
#line 1643 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 249 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_FACTOR", "T_NOT N_FACTOR");
 }
#line 1651 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 254 "kammeyerm.y" /* yacc.c:1646  */
    {
  (yyval.ids).text = (yyvsp[0].text);
  prRule("N_IDENT", "T_IDENT");
 }
#line 1660 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 260 "kammeyerm.y" /* yacc.c:1646  */
    {
		   prRule("N_IDENTLST", "epsilon");
		 }
#line 1668 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 264 "kammeyerm.y" /* yacc.c:1646  */
    {
		   lstidents.push_back((yyvsp[-1].ids).text);
		   prRule("N_IDENTLST", "T_COMMA N_IDENT N_IDENTLST");
		 }
#line 1677 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 270 "kammeyerm.y" /* yacc.c:1646  */
    {
       (yyval.ids).text = (yyvsp[0].ids).text;
       (yyval.ids).sign = (yyvsp[0].ids).sign;
  prRule("N_IDX", "N_INTCONST");
 }
#line 1687 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 277 "kammeyerm.y" /* yacc.c:1646  */
    {
     (yyval.range).start = (yyvsp[-2].ids).text;
     (yyval.range).startsign = (yyvsp[-2].ids).sign;
     (yyval.range).end = (yyvsp[0].ids).text;
     (yyval.range).endsign = (yyvsp[0].ids).sign;
     prRule("N_IDXRANGE", "N_IDX T_DOTDOT N_IDX");
   }
#line 1699 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 286 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_IDXVAR", "N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK");
 }
#line 1707 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 291 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_INPUTLST", "epsilon");
 }
#line 1715 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 295 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_INPUTLST", "T_COMMA N_INPUTVAR N_INPUTLST");
 }
#line 1723 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 300 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_INPUTVAR", "N_VARIABLE");
 }
#line 1731 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 305 "kammeyerm.y" /* yacc.c:1646  */
    {
     (yyval.ids).text = (yyvsp[0].text);
     (yyval.ids).sign = (yyvsp[-1].ids).text;
     prRule("N_INTCONST", "N_SIGN T_INTCONST");
   }
#line 1741 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 312 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_MULTOP", "T_MULT");
 }
#line 1749 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 316 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_MULTOP", "T_DIV");
 }
#line 1757 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 320 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_MULTOP", "T_AND");
		    }
#line 1765 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 325 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_MULTOPLST", "epsilon");
 }
#line 1773 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 329 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_MULTOPLST", "N_MULTOP N_FACTOR N_MULTOPLST");
 }
#line 1781 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 334 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_OUTPUT", "N_EXPR");
 }
#line 1789 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 339 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_OUTPUTLST", "epsilon");
 }
#line 1797 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 343 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_OUTPUTLST", "T_COMMA N_OUTPUT N_OUTPUTLST");
 }
#line 1805 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 348 "kammeyerm.y" /* yacc.c:1646  */
    {
     tables.pop_back();
     printf("\n___Exiting scope...\n\n");
     prRule("N_PROCDEC", "N_PROCHDR N_BLOCK");
   }
#line 1815 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 355 "kammeyerm.y" /* yacc.c:1646  */
    {
     prRule("N_PROCHDR", "T_PROC T_IDENT T_SCOLON");
     if(search_tables((yyvsp[-1].text))) {
       tables.back()[(yyvsp[-1].text)] = "PROCEDURE";
       printf("___Adding %s to symbol table with type PROCEDURE\n", (yyvsp[-1].text));
       map<char*, char*> table;
       tables.push_back(table);
       printf("\n___Entering new scope...\n\n");
     }
     
     else {
       yyerror("Multiply defined identifier");
     }
   }
#line 1834 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 371 "kammeyerm.y" /* yacc.c:1646  */
    {
     prRule("N_PROCDECPART", "epsilon");
   }
#line 1842 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 375 "kammeyerm.y" /* yacc.c:1646  */
    {
     prRule("N_PROCDECPART",
	    "N_PROCDEC T_SCOLON N_PROCDECPART");
   }
#line 1851 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 381 "kammeyerm.y" /* yacc.c:1646  */
    {
       prRule("N_PROCIDENT", "T_IDENT");
     }
#line 1859 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 386 "kammeyerm.y" /* yacc.c:1646  */
    {
       prRule("N_PROCSTMT", "N_PROCIDENT");
     }
#line 1867 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 390 "kammeyerm.y" /* yacc.c:1646  */
    {
       //Add table to vector of tables
       //Print out Entering new Scope
       map<char*, char*> table;
       tables.push_back(table);
       printf("\n___Entering new scope...\n\n");
     }
#line 1879 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 398 "kammeyerm.y" /* yacc.c:1646  */
    {
       prRule("N_PROG", "N_PROGLBL T_IDENT T_SCOLON N_BLOCK T_DOT");
       if(search_tables((yyvsp[-1].text))) {
	 tables.back()[(yyvsp[-1].text)] = "PROGRAM";
	 printf("___Adding %s to symbol table with type PROGRAM\n", (yyvsp[-1].text));
       }
       else {
	 yyerror("Multiply defined identifier");
       }
     }
#line 1894 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 407 "kammeyerm.y" /* yacc.c:1646  */
    {
       printf("\n___Exiting scope...\n\n");
      }
#line 1902 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 409 "kammeyerm.y" /* yacc.c:1646  */
    {}
#line 1908 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 412 "kammeyerm.y" /* yacc.c:1646  */
    {
       prRule("N_PROGLBL", "T_PROG");
     }
#line 1916 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 417 "kammeyerm.y" /* yacc.c:1646  */
    {
     prRule("N_READ",
	    "T_READ T_LPAREN N_INPUTVAR N_INPUTLST T_RPAREN");
   }
#line 1925 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 423 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_RELOP", "T_LT");
 }
#line 1933 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 427 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_RELOP", "T_GT");
 }
#line 1941 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 431 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_RELOP", "T_LE");
 }
#line 1949 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 435 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_RELOP", "T_GE");
 }
#line 1957 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 439 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_RELOP", "T_EQ");
 }
#line 1965 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 443 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_RELOP", "T_NE");
 }
#line 1973 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 448 "kammeyerm.y" /* yacc.c:1646  */
    {
     (yyval.ids).text = "";
  prRule("N_SIGN", "epsilon");
 }
#line 1982 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 453 "kammeyerm.y" /* yacc.c:1646  */
    {
		      (yyval.ids).text = "";
  prRule("N_SIGN", "T_PLUS");
 }
#line 1991 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 458 "kammeyerm.y" /* yacc.c:1646  */
    {
		      (yyval.ids).text = "-";
  prRule("N_SIGN", "T_MINUS");
 }
#line 2000 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 464 "kammeyerm.y" /* yacc.c:1646  */
    {
		  (yyval.info).type = "INTEGER";
  
		  prRule("N_SIMPLE", "T_INT");
		}
#line 2010 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 470 "kammeyerm.y" /* yacc.c:1646  */
    {
		  (yyval.info).type = "CHAR";    
		  prRule("N_SIMPLE", "T_CHAR");
		}
#line 2019 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 475 "kammeyerm.y" /* yacc.c:1646  */
    {
		  (yyval.info).type = "BOOLEAN";
		  prRule("N_SIMPLE", "T_BOOL");
		}
#line 2028 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 481 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_SIMPLEEXPR", "N_TERM N_ADDOPLST");
 }
#line 2036 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 486 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_STMT", "N_ASSIGN");
 }
#line 2044 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 490 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_STMT", "N_PROCSTMT");
 }
#line 2052 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 494 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_STMT", "N_READ");
 }
#line 2060 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 498 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_STMT", "N_WRITE");
 }
#line 2068 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 502 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_STMT", "N_CONDITION");
 }
#line 2076 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 506 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_STMT", "N_WHILE");
 }
#line 2084 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 510 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_STMT", "N_COMPOUND");
 }
#line 2092 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 515 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_STMTLST", "epsilon");
 }
#line 2100 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 519 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_STMTLST", "T_SCOLON N_STMT N_STMTLST");
 }
#line 2108 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 524 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_STMTPART", "N_COMPOUND");
 }
#line 2116 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 529 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_TERM", "N_FACTOR N_MULTOPLST");
 }
#line 2124 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 534 "kammeyerm.y" /* yacc.c:1646  */
    {
		   (yyval.info).type = (yyvsp[0].info).type;
		   (yyval.info).startindex = "";
		   (yyval.info).endindex = "";
		   (yyval.info).basetype = "";
		   prRule("N_TYPE", "N_SIMPLE");
		 }
#line 2136 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 542 "kammeyerm.y" /* yacc.c:1646  */
    { 
		   (yyval.info).type = (yyvsp[0].info).type; 
		   (yyval.info).startindex = (yyvsp[0].info).startindex;
		   (yyval.info).startsign = (yyvsp[0].info).startsign;
		   (yyval.info).endindex = (yyvsp[0].info).endindex;
		   (yyval.info).endsign = (yyvsp[0].info).endsign;
		   (yyval.info).basetype = (yyvsp[0].info).basetype;
		   prRule("N_TYPE", "N_ARRAY");
		 }
#line 2150 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 553 "kammeyerm.y" /* yacc.c:1646  */
    {
     prRule("N_VARDEC", "N_IDENT N_IDENTLST T_COLON N_TYPE");
     
     //Add ident to table with type
     //Print out table addition
     if(search_tables((yyvsp[-3].ids).text)) {

       tables.back()[(yyvsp[-3].ids).text] = (yyvsp[0].info).type;
       if((yyvsp[0].info).startindex == "") {
	 printf("___Adding %s to symbol table with type %s\n", 
		(yyvsp[-3].ids).text, (yyvsp[0].info).type);
       }

       else {
	 printf("___Adding %s to symbol table with type %s %s%s .. %s%s OF %s\n"
		,(yyvsp[-3].ids).text ,(yyvsp[0].info).type, (yyvsp[0].info).startsign, (yyvsp[0].info).startindex
		, (yyvsp[0].info).endsign, (yyvsp[0].info).endindex, (yyvsp[0].info).basetype);
       }
     }
       
     else {
       yyerror("Multiply defined identifier");
     }
     
     while(lstidents.size() > 0) {
       char* a = lstidents.back();
       lstidents.pop_back();
       if(search_tables(a)) {

	 tables.back()[a] = (yyvsp[0].info).type;
	 if((yyvsp[0].info).startindex == "") {
	   printf("___Adding %s to symbol table with type %s\n", 
		  a, (yyvsp[0].info).type);
	 }

	 else {
	   printf("___Adding %s to symbol table with type %s %s%s .. %s%s OF %s\n"
		  ,a ,(yyvsp[0].info).type, (yyvsp[0].info).startsign, (yyvsp[0].info).startindex
		  , (yyvsp[0].info).endsign, (yyvsp[0].info).endindex, (yyvsp[0].info).basetype);
	 }
       }
       
       else {
	 yyerror("Multiply defined identifier");
       }  
     }
 }
#line 2202 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 602 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_VARDECLST", "epsilon");
 }
#line 2210 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 606 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_VARDECLST", "N_VARDEC T_SCOLON N_VARDECLST");
 }
#line 2218 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 611 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_VARDECPART", "epsilon");
 }
#line 2226 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 615 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_VARDECPART",
     "T_VAR N_VARDEC T_SCOLON N_VARDECLST");
 }
#line 2235 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 621 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_VARIABLE", "N_ENTIREVAR");
 }
#line 2243 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 625 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_VARIABLE", "N_IDXVAR");
 }
#line 2251 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 630 "kammeyerm.y" /* yacc.c:1646  */
    {
       if(search_all_tables((yyvsp[0].text))) {
	 yyerror("Undefined identifier");
       }
       prRule("N_VARIDENT", "T_IDENT");
 }
#line 2262 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 638 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_WHILE", "T_WHILE N_EXPR T_DO N_STMT");
 }
#line 2270 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 643 "kammeyerm.y" /* yacc.c:1646  */
    {
  prRule("N_WRITE",
     "T_WRITE T_LPAREN N_OUTPUT N_OUTPUTLST T_RPAREN");
 }
#line 2279 "kammeyerm.tab.c" /* yacc.c:1646  */
    break;


#line 2283 "kammeyerm.tab.c" /* yacc.c:1646  */
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
#line 648 "kammeyerm.y" /* yacc.c:1906  */


#include "lex.yy.c"
     extern FILE *yyin;


     void prRule(const char *lhs, const char *rhs) 
     {
       if (OUTPUT_PRODUCTIONS)
	 printf("%s -> %s\n", lhs, rhs);
       return;
     }

     int yyerror(const char *s) 
     {
       printf("Line %d: %s\n", lineNum, s);
       exit(1);
     }

     int ckInt() 
     {
       char *ptr;
       int rc = 0;
       ptr = yytext;

       /* ignore sign and leading zeroes */
       if (*ptr == '-' || *ptr == '+')
	 ++ptr;
       while (*ptr == '0')
	 ++ptr;

       switch (*ptr) {
       case '1':/* ALL are valid */
	 break;

       case '2':/* it depends */
	 if (strcmp(MAX_INT, ptr) < 0)
	   rc = 1;
	 break;

       default:     /* ALL are invalid */
	 rc = 1;
	 break;
       }
       return rc;
     }

     void ignoreComment() 
     {
       char c, pc = 0;

       /* read and ignore the input until you get an ending token */
       while (((c = yyinput()) != ')' || pc != '*') && c != 0) {
	 pc = c;
	 if (c == '\n') lineNum++;
       }

       return;
     }

     void printTokenInfo(const char* tokenType, const char* lexeme) 
     {
       if (OUTPUT_TOKENS)
	 printf("TOKEN: %-15s  LEXEME: %s\n", tokenType, lexeme);
     }

/*     bool search_tables(char* ident) {
       vector< map<char*, char*> >::reverse_iterator rit = tables.rbegin();
       for(; rit != tables.rend(); ++rit)
	 if((*rit[ident])
	   return false;

       return true;
       }  */

     int main()
     {
       // loop as long as there is anything to parse
       do {
	 yyparse();
       } while (!feof(yyin));

       return 0;
     }

