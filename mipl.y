/*
      example.y

 	Example of a yacc specification file.

      Grammar is:

        <expr> -> intconst | ident | foo <identList> <intconstList>
        <identList> -> epsilon | <identList> ident
        <intconstList> -> intconst | <intconstList> intconst

      To create the syntax analyzer:

        flex example.l
        bison example.y
        g++ example.tab.c -o parser
        parser < inputFileName
 */

%{
#include <stdio.h>

int numLines = 0; 

void printRule(const char *, const char *);
int yyerror(const char *s);
void printTokenInfo(const char* tokenType, const char* lexeme);

extern "C" {
    int yyparse(void);
    int yylex(void);
    int yywrap() { return 1; }
}

%}

/* Token declarations */
%token  T_IDENT T_INTCONST T_CHARCONST T_TRUE T_FALSE 
%token  T_LT T_GT T_LE T_GE T_EQ T_NE T_DOT T_DOTDOT 
%token  T_LPAREN T_RPAREN T_LBRACK T_RBRACK T_PLUS 
%token  T_MINUS T_MULT T_DIV T_OR T_AND T_IF T_PROG 
%token  T_PROC T_VAR T_DO T_WHILE T_READ T_WRITE T_NOT
%token  T_BEGIN T_END T_COLON T_SCOLON T_COMMA T_ASSIGN 
%token  T_INT T_CHAR T_BOOL T_ARRAY T_OF T_UNKNOWN
%nonassoc  T_THEN T_ELSE

/* Starting point */
%start		N_START

/* Translation rules */
%%
N_START                 : N_PROG
                        {
			    printRule("N_START", "N_PROG");
			    printf("---- Completed parsing ----\n\n");
			}


N_PROGLBL		: T_PROG
		     	{
			    printRule("N_PROGLBL", "T_PROG");
	       		}
       			;

N_PROG			: N_PROGLBL T_IDENT T_SCOLON N_BLOCK T_DOT
		 	{
			    printRule("N_PROG", "N_PROGLBL T_IDENT T_SCOLON N_BLOCK T_DOT");
		     	}
		        ;
N_BLOCK       	        : N_VARDECPART N_PROCDECPART N_STMTPART
			{
		      	    printRule("N_BLOCK", "N_VARDECPART N_PROCDECPART N_STMTPART");
		       	}
                        ;
N_VARDECPART            : /* epsilon */
			{
		       	    printRule("N_VARDECPART", "epsilon");
		       	}
                        | T_VAR N_VARDEC T_SCOLON N_VARDECLST
			{
			    printRule("N_VARDEVPART", "var N_VARDEC T_SCOLON N_VARDECLST");
		        }
		        ;

N_VARDECLST             : N_VARDEC T_SCOLON N_VARDECLST
                        {
	           	    printRule("N_VARDECKST", "N_VARDEC T_SCOLON N_VARDECLST");
                        }
                        | /* epsilon */
			{
			   printRule("N_VARDEVLST", "epsilon"); 
			}
                        ;
N_VARDEC                : N_IDENT N_IDENTLST T_COLON N_TYPE
                        {
			   printRule("N_VARDEC", "N_IDENT N_IDENTLST T_COLON N_TYPE");
			}                 
                        ;
N_IDENT                 : T_IDENT
                        {
			   printRule("N_IDENT", "T_IDENT");
                        } 
                        ;
N_IDENTLST              : T_COMMA N_IDENT N_IDENTLST
                        {
			   printRule("N_IDENTLST", "T_COMMA N_IDENT N_IDNTLST"); 
			}
                        | /* epsilon */
			{
 			   printRule("N_IDENTLST", "epsilon");
			}
                        ;
N_TYPE                  : N_SIMPLE
                        {
			   printRule("N_TYPE", "N_SIMPLE");
			} 
                        | N_ARRAY
			{
			   printRule("N_TYPE", "N_ARRAY");
			}
                        ;
N_ARRAY                 : T_ARRAY T_LBRACK N_IDXRANGE T_RBRACK T_OF N_SIMPLE
                        {
			   printRule("N_ARRAY", "T_ARRAY T_LBRACK N_IDXRANGE T_RBRACK T_OF N_SIMPLE");
			}
                        ;
N_IDX                   : N_INTCONST
                        {
			  printRule("N_IDX", "N_INTCONST");
			}
                        ;
N_IDXRANGE              : N_IDX T_DOTDOT N_IDX
                        {
			   printRule("N_IDXRANGE", "N_IDX T_DOTDOT N_IDX");
			}
N_SIMPLE                : T_INT
                        {
			   printRule("N_SIMPLE", "T_INT");
			}
                        | T_CHAR
			{
			   printRule("N_SIMPLE", "T_CHAR");
			}
                        | T_BOOL
			{
			   printRule("N_SIMPLE", "T_BOOL");
			}
                        ;
N_PROCDECPART           : N_PROCDEC T_SCOLON N_PROCDECPART
                        {
			   printRule("N_PROCDECPART", "N_PROCDEC T_SCOLON N_PROCDECPART");
			}
                        | /* epsilon */
                        {
			   printRule("N_PROCDECPART", "epsilon");
			};

N_PROCDEC               : N_PROCHDR N_BLOCK
                        {
			   printRule("N_PROCDEC", "N_PROCHDR N_BLOCK");
			};

N_PROCHDR               : T_PROC T_IDENT T_SCOLON
                        {
			   printRule("N_PROCHDR", "T_PROC T_IDENT T_SCOLON");
			};

N_STMTPART              : N_COMPOUND
                        {
			   printRule("N_STMTPART", "N_COMPOUND");
			};

N_COMPOUND              : T_BEGIN N_STMT N_STMTLST T_END
                        {
			   printRule("N_COMPOUND", "T_BEGIN N_STMT N_STMTLST T_END");
			};

N_STMTLST               : T_SCOLON N_STMT N_STMTLST
                        {
			   printRule("N_STMTLST", "T_SCOLON N_STMT N_STMTLST");
			}
                        | /*epsilon*/
                        {
			   printRule("N_STMTLST", "epsilon");
			};

N_STMT                  : N_ASSIGN
                        {
			   printRule("N_STMT", "N_ASSIGN");
			}
                        | N_PROCSTMT
			{
			   printRule("N_STMT", "N_PROCSTMT");
			}
                        | N_READ
                        {
			   printRule("N_STMT", "N_READ");
			}
                        | N_WRITE
                        {
			   printRule("N_STMT", "N_WRITE");
			}
                        | N_CONDITION
                        {
			   printRule("N_STMT", "N_CONDITION");
			}
                        | N_WHILE
                        {
			   printRule("N_STMT", "N_WHILE");
			}
                        | N_COMPOUND
                        {
			   printRule("N_STMT", "N_COMPOUND");
			};

N_ASSIGN                : N_VARIABLE T_ASSIGN N_EXPR
                        {
			   printRule("N_ASSIGN", "N_VARIABLE T_ASSIGN N_EXPR");
			};

N_PROCSTMT              : N_PROCIDENT
                        {
			   printRule("N_PROCSTMT", "N_PROCIDENT");
			};

N_PROCIDENT             : T_IDENT
                        {
			   printRule("N_PROCIDENT", "T_IDENT");
			};

N_READ                  : T_READ T_LPAREN N_INPUTVAR N_INPUTLST T_RPAREN
                        {
			   printRule("N_READ", "T_READ T_LPAREN N_INPUTVAR N_INPUTLST T_RPAREN");
			};

N_INPUTLST              : T_COMMA N_INPUTVAR N_INPUTLST
                        {
			   printRule("N_INPUTLST", "T_COMMA N_INPUTVAR N_INPUTLST");
			}
                        | /*epsilon*/
                        { 
			   printRule("N_INPUTLST", "epsilon");
			};

N_INPUTVAR              : N_VARIABLE
                        {
			   printRule("N_INPUTVAR", "N_VARIABLE");
			};

N_WRITE                 : T_WRITE T_LPAREN N_OUTPUT N_OUTPUTLST T_RPAREN
                        {
			   printRule("N_WRITE", "T_WRITE T_LPAREN N_OUTPUT N_OUTPUTLST T_RPAREN");
			};

N_OUTPUTLST             : T_COMMA N_OUTPUT N_OUTPUTLST 
                        {
			   printRule("N_OUTPUTLST", "T_COMMA N_OUTPUT N_OUTPUTLST");
			}
                        | /*epsilon*/
                        {
			   printRule("N_OUTPUTLST", "epsilon");
			};

N_OUTPUT                : N_EXPR
                        {
			   printRule("N_OUTPUT", "N_EXPR");
			};

N_CONDITION             : T_IF N_EXPR T_THEN N_STMT
                        {
			   printRule("N_CONDITION", "T_IF N_EXPR T_THEN N_STMT");
			}
                        | T_IF N_EXPR T_THEN N_STMT T_ELSE N_STMT 
                        {
			   printRule("N_CONDITION", "T_IF N_EXPR T_THEN N_STMT T_ELSE N_STMT");
			};

N_WHILE                 : T_WHILE N_EXPR T_DO N_STMT
                        {
			   printRule("N_WHILE", "T_WHILE N_EXPR T_DO N_STMT");
			};

N_EXPR                  : N_SIMPLEEXPR
                        {
			   printRule("N_EXPR", "N_SIMPLEEXPR");
			}
                        | N_SIMPLEEXPR N_RELOP N_SIMPLEEXPR
                        {
			   printRule("N_EXPR", "N_SIMPLEEXP N_RELOP N_SIMPLEEXPR");
			};

N_SIMPLEEXPR            : N_TERM N_ADDOPLST
                        {
			   printRule("N_SIMPLEEXPR", "N_TERM N_ADDOPLST");
			};

N_ADDOPLST              : N_ADDOP N_TERM N_ADDOPLST
                        {
			   printRule("N_ADDOPLST", "N_ADDOP N_TERM N_ADDOPLST");
			}
                        | /*epsilon*/
                        {
			   printRule("N_ADDOPLST", "epsilon");
			};

N_TERM                  : N_FACTOR N_MULTOPLST
                        {
			   printRule("N_TERM", "N_FACTOR N_MULTOPLST");
			};

N_MULTOPLST             : N_MULTOP N_FACTOR N_MULTOPLST
                        {
			   printRule("N_MULTOPLST", "N_MULTOP N_FACTOR N_MULTOP");
			}
                        | /*epsilon*/
                        {
			   printRule("N_MULTOPLST", "epsilon");
			};

N_FACTOR                : N_SIGN N_VARIABLE
                        {
			   printRule("N_FACTOR", "N_SIGN N_VARIABLE");
			}
                        | N_CONST
                        {
			   printRule("N_FACTOR", "N_CONST");
			}
                        | T_LPAREN N_EXPR T_RPAREN
                        {
			   printRule("N_FACTOR", "T_LPAREN N_EXPR T_RPAREN");
			}
                        | T_NOT N_FACTOR
                        {
			   printRule("N_FACTOR", "T_NOT N_FACTOR");
			};

N_SIGN                  : T_PLUS
                        {
			   printRule("N_SIGN", "T_PLUS");
			}
                        | T_MINUS
                        {
			   printRule("N_SIGN", "T_MINUS");
			}
                        | /*epsilon*/
                        {
			   printRule("N_SIGN", "epsilon");
			};

N_ADDOP                 : T_PLUS
                        {
			   printRule("N_ADDOP", "T_PLUS");
			}
                        | T_MINUS
                        {
			   printRule("N_ADDOP", "T_MINUS");
			}
                        | T_OR
                        { 
			   printRule("N_ADDOP", "T_OR");
			};

N_MULTOP                : T_MULT
                        {
			   printRule("N_MULTOP", "T_MULT");
			}
                        | T_DIV
                        {
			   printRule("N_MULTOP", "T_DIV");
			}
                        | T_AND
                        {
			   printRule("N_MULTOP", "T_AND");
			};

N_RELOP                 : T_LT
                        {
			   printRule("N_RELOP", "T_LT");
			}
                        | T_GT
                        {
			   printRule("N_RELOP", "T_GT");
			}
                        | T_LE
                        {
			   printRule("N_RELOP", "T_LE");
			}
                        | T_GE
                        {
			   printRule("N_RELOP", "T_GE");
			}
                        | T_EQ
                        {
			   printRule("N_RELOP", "T_EQ");
			}
                        | T_NE
                        {
			   printRule("N_RELOP", "T_NE");
			};

N_VARIABLE              : N_ENTIREVAR
                        {
			   printRule("N_VARIABLE", "N_ENTIREVAR");
			} 
                        | N_IDXVAR
                        {
			   printRule("N_VARIABLE", "N_IDXVAR");
			};

N_IDXVAR                : N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK
                        {
			   printRule("N_IDXVAR", "N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK");
			};

N_ARRAYVAR              : N_ENTIREVAR
                        {
			   printRule("N_ARRAYVAR", "ENTIREVAR");
			};

N_ENTIREVAR             : N_VARIDENT
                        {
			   printRule("N_ENTIREVAR", "N_VARIDENT");
			};

N_VARIDENT              : T_IDENT
                        {
			   printRule("N_VARIDENT", "T_IDENT");
			};

N_CONST                 : N_INTCONST
                        {
			   printRule("N_CONST", "N_INTCONST");
			}
                        | T_CHARCONST
                        {
			   printRule("N_CONST", "T_CHARCONST");
			}
                        | N_BOOLCONST
                        {
			   printRule("N_CONST", "N_BOOLCONST");
			};

N_INTCONST              : N_SIGN T_INTCONST
                        {
			   printRule("N_INTCONST", "N_SIGN T_INTCONST");
			};

N_BOOLCONST             : T_TRUE
                        {
			   printRule("N_BOOLCONST", "T_TRUE");
			}
                        | T_FALSE
                        {
			   printRule("N_BOOLCONST", "T_FALSE");
			};


%%

#include "lex.yy.c"
extern FILE *yyin;

void printRule(const char *lhs, const char *rhs) {
  printf("%s -> %s\n", lhs, rhs);
  return;
}

int yyerror(const char *s) {
  printf("Line %d: %s\n", yylineno, s);
  return(1);
}

void printTokenInfo(const char* tokenType, const char* lexeme) {
  printf("TOKEN: %s  LEXEME: %s\n", tokenType, lexeme);
}

int main() {
  do {
	yyparse();
  } while (!feof(yyin));

  return 0;
}
