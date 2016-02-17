/*
 *  bison specifications for the MIPL language.
 *  Written to meet requirements for CS 5500, Spring 2016.
 */

/*
 *  Declaration section.
 */
%{

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

%}

%union {
  char* text;
  typeinfo info;
  idents ids;
  indexrange range;
}

   /*
    *  Token declaration. 'N_...' for rules, 'T_...' for tokens.
    *  Note: tokens are also used in the flex specification file.
    */
   %token      T_LPAREN    T_RPAREN    T_MULT     T_PLUS
   %token      T_COMMA     T_MINUS     T_DOT       T_DOTDOT
   %token      T_COLON     T_ASSIGN    T_SCOLON    T_LT
   %token      T_LE        T_NE        T_EQ        T_GT
   %token      T_GE        T_LBRACK    T_RBRACK    T_DO
   %token      T_AND       T_ARRAY     T_BEGIN     T_BOOL
   %token      T_CHAR      T_DIV       T_CHARCONST T_INTCONST
   %token      T_END       T_FALSE     T_IF        T_INT
   %token      T_NOT       T_OF        T_OR        T_PROC
   %token      T_PROG      T_READ      T_TRUE      T_IDENT
   %token      T_VAR       T_WHILE     T_WRITE     T_UNKNOWN

   %token      ST_EOF

   %type<text> T_IDENT T_INT T_INTCONST
   %type<ids> N_IDENT N_VARIDENT N_IDX N_SIGN N_INTCONST
   %type<info> N_TYPE N_ARRAY N_SIMPLE
   %type<range> N_IDXRANGE
   
      /*
       *  To eliminate ambiguities.
       */
   %nonassoc   T_THEN
   %nonassoc   T_ELSE

      /*
       *  Starting point.
       */
   %start      N_START

      /*
       *  Translation rules.
       */
%%

N_START         : N_PROG {
  prRule("N_START", "N_PROG");
  printf("\n---- Completed parsing ----\n\n");
  return 0;
 };
 
N_ADDOP         : T_PLUS {
  prRule("N_ADDOP", "T_PLUS");
 }
                | T_MINUS {
  prRule("N_ADDOP", "T_MINUS");
 }
                | T_OR {
  prRule("N_ADDOP", "T_OR");
 };

 N_ADDOPLST      : /* epsilon */
   {
  prRule("N_ADDOPLST", "epsilon");
 }
                | N_ADDOP N_TERM N_ADDOPLST
   {
  prRule("N_ADDOPLST", "N_ADDOP N_TERM N_ADDOPLST");
 };

 N_ARRAY         : T_ARRAY T_LBRACK N_IDXRANGE T_RBRACK T_OF N_SIMPLE
   {
     $$.type = "ARRAY";
     $$.startindex = $3.start;
     $$.startsign = $3.startsign;
     $$.endindex = $3.end;
     $$.endsign = $3.endsign;
     $$.basetype = $6.type;
     prRule("N_ARRAY",
     "T_ARRAY T_LBRACK N_IDXRANGE T_RBRACK T_OF N_SIMPLE");
 };

 N_ARRAYVAR      : N_ENTIREVAR
     {
  prRule("N_ARRAYVAR", "N_ENTIREVAR");
 };

 N_ASSIGN        : N_VARIABLE T_ASSIGN N_EXPR
   {
  prRule("N_ASSIGN", "N_VARIABLE T_ASSIGN N_EXPR");
 };

 N_BLOCK         : N_VARDECPART N_PROCDECPART N_STMTPART
   {
  prRule("N_BLOCK", "N_VARDECPART N_PROCDECPART N_STMTPART");
 };

 N_BOOLCONST     : T_TRUE
     {
  prRule("N_BOOLCONST", "T_TRUE");
 }
                | T_FALSE
                    {
  prRule("N_BOOLCONST", "T_FALSE");
 };

 N_COMPOUND      : T_BEGIN N_STMT N_STMTLST T_END
   {
  prRule("N_COMPOUND", "T_BEGIN N_STMT N_STMTLST T_END");
 };

 N_CONDITION     : T_IF N_EXPR T_THEN N_STMT
   {
  prRule("N_CONDITION", "T_IF N_EXPR T_THEN N_STMT");
 }
                | T_IF N_EXPR T_THEN N_STMT T_ELSE N_STMT
   {
  prRule("N_CONDITION",
     "T_IF N_EXPR T_THEN N_STMT T_ELSE N_STMT");
 };

 N_CONST         : N_INTCONST
     {
  prRule("N_CONST", "N_INTCONST");
 }
                | T_CHARCONST
                    {
  prRule("N_CONST", "T_CHARCONST");
 }
                | N_BOOLCONST
                    {
  prRule("N_CONST", "N_BOOLCONST");
 }
   ;
 N_ENTIREVAR     : N_VARIDENT
     {
  prRule("N_ENTIREVAR", "N_VARIDENT");
 }
   ;
 N_EXPR          : N_SIMPLEEXPR
     {
  prRule("N_EXPR", "N_SIMPLEEXPR");
 }
                | N_SIMPLEEXPR N_RELOP N_SIMPLEEXPR
   {
  prRule("N_EXPR", "N_SIMPLEEXPR N_RELOP N_SIMPLEEXPR");
 }
   ;
 N_FACTOR        : N_SIGN N_VARIABLE
   {
  prRule("N_FACTOR", "N_SIGN N_VARIABLE");
 }
                | N_CONST
                    {
  prRule("N_FACTOR", "N_CONST");
 }
                | T_LPAREN N_EXPR T_RPAREN
   {
  prRule("N_FACTOR", "T_LPAREN N_EXPR T_RPAREN");
 }
                | T_NOT N_FACTOR
   {
  prRule("N_FACTOR", "T_NOT N_FACTOR");
 };

 N_IDENT         : T_IDENT
     {
  $$.text = $1;
  prRule("N_IDENT", "T_IDENT");
 };

 N_IDENTLST      : /* epsilon */
                 {
		   prRule("N_IDENTLST", "epsilon");
		 }
                 | T_COMMA N_IDENT N_IDENTLST
		 {
		   lstidents.push_back($2.text);
		   prRule("N_IDENTLST", "T_COMMA N_IDENT N_IDENTLST");
		 };

 N_IDX           : N_INTCONST
     {
       $$.text = $1.text;
       $$.sign = $1.sign;
  prRule("N_IDX", "N_INTCONST");
 };

 N_IDXRANGE      : N_IDX T_DOTDOT N_IDX
   {
     $$.start = $1.text;
     $$.startsign = $1.sign;
     $$.end = $3.text;
     $$.endsign = $3.sign;
     prRule("N_IDXRANGE", "N_IDX T_DOTDOT N_IDX");
   };

 N_IDXVAR        : N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK
   {
  prRule("N_IDXVAR", "N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK");
 };

 N_INPUTLST      : /* epsilon */
   {
  prRule("N_INPUTLST", "epsilon");
 }
                | T_COMMA N_INPUTVAR N_INPUTLST
   {
  prRule("N_INPUTLST", "T_COMMA N_INPUTVAR N_INPUTLST");
 };

 N_INPUTVAR      : N_VARIABLE
     {
  prRule("N_INPUTVAR", "N_VARIABLE");
 };

 N_INTCONST      : N_SIGN T_INTCONST
   {
     $$.text = $2;
     $$.sign = $1.text;
     prRule("N_INTCONST", "N_SIGN T_INTCONST");
   };

 N_MULTOP        : T_MULT
     {
  prRule("N_MULTOP", "T_MULT");
 }
                | T_DIV
                    {
  prRule("N_MULTOP", "T_DIV");
 }
                | T_AND
                    {
  prRule("N_MULTOP", "T_AND");
		    };

 N_MULTOPLST     : /* epsilon */
   {
  prRule("N_MULTOPLST", "epsilon");
 }
                | N_MULTOP N_FACTOR N_MULTOPLST
   {
  prRule("N_MULTOPLST", "N_MULTOP N_FACTOR N_MULTOPLST");
 };

 N_OUTPUT        : N_EXPR
     {
  prRule("N_OUTPUT", "N_EXPR");
 };

 N_OUTPUTLST     : /* epsilon */
   {
  prRule("N_OUTPUTLST", "epsilon");
 }
                | T_COMMA N_OUTPUT N_OUTPUTLST
   {
  prRule("N_OUTPUTLST", "T_COMMA N_OUTPUT N_OUTPUTLST");
 };

 N_PROCDEC       : N_PROCHDR N_BLOCK
   {
     tables.pop_back();
     printf("\n___Exiting scope...\n\n");
     prRule("N_PROCDEC", "N_PROCHDR N_BLOCK");
   };

 N_PROCHDR       : T_PROC T_IDENT T_SCOLON
   {
     prRule("N_PROCHDR", "T_PROC T_IDENT T_SCOLON");
     if(search_tables($2)) {
       tables.back()[$2] = "PROCEDURE";
       printf("___Adding %s to symbol table with type PROCEDURE\n", $2);
       map<char*, char*> table;
       tables.push_back(table);
       printf("\n___Entering new scope...\n\n");
     }
     
     else {
       yyerror("Multiply defined identifier");
     }
   };

 N_PROCDECPART   : /* epsilon */
   {
     prRule("N_PROCDECPART", "epsilon");
   }
                | N_PROCDEC T_SCOLON N_PROCDECPART
   {
     prRule("N_PROCDECPART",
	    "N_PROCDEC T_SCOLON N_PROCDECPART");
   };

 N_PROCIDENT     : T_IDENT
     {
       prRule("N_PROCIDENT", "T_IDENT");
     };

 N_PROCSTMT      : N_PROCIDENT
     {
       prRule("N_PROCSTMT", "N_PROCIDENT");
     };

 N_PROG          : N_PROGLBL {
       //Add table to vector of tables
       //Print out Entering new Scope
       map<char*, char*> table;
       tables.push_back(table);
       printf("\n___Entering new scope...\n\n");
     }
     T_IDENT T_SCOLON
     {
       prRule("N_PROG", "N_PROGLBL T_IDENT T_SCOLON N_BLOCK T_DOT");
       if(search_tables($3)) {
	 tables.back()[$3] = "PROGRAM";
	 printf("___Adding %s to symbol table with type PROGRAM\n", $3);
       }
       else {
	 yyerror("Multiply defined identifier");
       }
     }N_BLOCK {
       printf("\n___Exiting scope...\n\n");
      } T_DOT{};

 N_PROGLBL       : T_PROG
     {
       prRule("N_PROGLBL", "T_PROG");
     };

 N_READ          : T_READ T_LPAREN N_INPUTVAR N_INPUTLST T_RPAREN
   {
     prRule("N_READ",
	    "T_READ T_LPAREN N_INPUTVAR N_INPUTLST T_RPAREN");
   };

 N_RELOP         : T_LT
     {
  prRule("N_RELOP", "T_LT");
 }
                | T_GT
                    {
  prRule("N_RELOP", "T_GT");
 }
                | T_LE
                    {
  prRule("N_RELOP", "T_LE");
 }
                | T_GE
                    {
  prRule("N_RELOP", "T_GE");
 }
                | T_EQ
                    {
  prRule("N_RELOP", "T_EQ");
 }
                | T_NE
                    {
  prRule("N_RELOP", "T_NE");
 }
   ;
 N_SIGN          : /* epsilon */
   {
     $$.text = "";
  prRule("N_SIGN", "epsilon");
 }
                | T_PLUS
                    {
		      $$.text = "";
  prRule("N_SIGN", "T_PLUS");
 }
                | T_MINUS
                    {
		      $$.text = "-";
  prRule("N_SIGN", "T_MINUS");
 };

 N_SIMPLE       : T_INT
                {
		  $$.type = "INTEGER";
  
		  prRule("N_SIMPLE", "T_INT");
		}
                | T_CHAR
		{
		  $$.type = "CHAR";    
		  prRule("N_SIMPLE", "T_CHAR");
		}
                | T_BOOL
                {
		  $$.type = "BOOLEAN";
		  prRule("N_SIMPLE", "T_BOOL");
		};

 N_SIMPLEEXPR    : N_TERM N_ADDOPLST
   {
  prRule("N_SIMPLEEXPR", "N_TERM N_ADDOPLST");
 }
   ;
 N_STMT          : N_ASSIGN
     {
  prRule("N_STMT", "N_ASSIGN");
 }
                | N_PROCSTMT
                    {
  prRule("N_STMT", "N_PROCSTMT");
 }
                | N_READ
                    {
  prRule("N_STMT", "N_READ");
 }
                | N_WRITE
                    {
  prRule("N_STMT", "N_WRITE");
 }
                | N_CONDITION
                    {
  prRule("N_STMT", "N_CONDITION");
 }
                | N_WHILE
                    {
  prRule("N_STMT", "N_WHILE");
 }
                | N_COMPOUND
                    {
  prRule("N_STMT", "N_COMPOUND");
 };

 N_STMTLST       : /* epsilon */
   {
  prRule("N_STMTLST", "epsilon");
 }
                | T_SCOLON N_STMT N_STMTLST
   {
  prRule("N_STMTLST", "T_SCOLON N_STMT N_STMTLST");
 };

 N_STMTPART      : N_COMPOUND
     {
  prRule("N_STMTPART", "N_COMPOUND");
 };

 N_TERM          : N_FACTOR N_MULTOPLST
   {
  prRule("N_TERM", "N_FACTOR N_MULTOPLST");
 };

 N_TYPE          : N_SIMPLE
                 {
		   $$.type = $1.type;
		   $$.startindex = "";
		   $$.endindex = "";
		   $$.basetype = "";
		   prRule("N_TYPE", "N_SIMPLE");
		 }
                 | N_ARRAY
                 { 
		   $$.type = $1.type; 
		   $$.startindex = $1.startindex;
		   $$.startsign = $1.startsign;
		   $$.endindex = $1.endindex;
		   $$.endsign = $1.endsign;
		   $$.basetype = $1.basetype;
		   prRule("N_TYPE", "N_ARRAY");
		 };

 N_VARDEC        : N_IDENT N_IDENTLST T_COLON N_TYPE
   {
     prRule("N_VARDEC", "N_IDENT N_IDENTLST T_COLON N_TYPE");
     
     //Add ident to table with type
     //Print out table addition
     if(search_tables($1.text)) {

       tables.back()[$1.text] = $4.type;
       if($4.startindex == "") {
	 printf("___Adding %s to symbol table with type %s\n", 
		$1.text, $4.type);
       }

       else {
	 printf("___Adding %s to symbol table with type %s %s%s .. %s%s OF %s\n"
		,$1.text ,$4.type, $4.startsign, $4.startindex
		, $4.endsign, $4.endindex, $4.basetype);
       }
     }
       
     else {
       yyerror("Multiply defined identifier");
     }
     
     while(lstidents.size() > 0) {
       char* a = lstidents.back();
       lstidents.pop_back();
       if(search_tables(a)) {

	 tables.back()[a] = $4.type;
	 if($4.startindex == "") {
	   printf("___Adding %s to symbol table with type %s\n", 
		  a, $4.type);
	 }

	 else {
	   printf("___Adding %s to symbol table with type %s %s%s .. %s%s OF %s\n"
		  ,a ,$4.type, $4.startsign, $4.startindex
		  , $4.endsign, $4.endindex, $4.basetype);
	 }
       }
       
       else {
	 yyerror("Multiply defined identifier");
       }  
     }
 };

 N_VARDECLST     : /* epsilon */
   {
  prRule("N_VARDECLST", "epsilon");
 }
                | N_VARDEC T_SCOLON N_VARDECLST
   {
  prRule("N_VARDECLST", "N_VARDEC T_SCOLON N_VARDECLST");
 };

 N_VARDECPART    : /* epsilon */
   {
  prRule("N_VARDECPART", "epsilon");
 }
                | T_VAR N_VARDEC T_SCOLON N_VARDECLST
   {
  prRule("N_VARDECPART",
     "T_VAR N_VARDEC T_SCOLON N_VARDECLST");
 };

 N_VARIABLE      : N_ENTIREVAR
     {
  prRule("N_VARIABLE", "N_ENTIREVAR");
 }
                | N_IDXVAR
                    {
  prRule("N_VARIABLE", "N_IDXVAR");
 };

 N_VARIDENT      : T_IDENT
     {
       if(search_all_tables($1)) {
	 yyerror("Undefined identifier");
       }
       prRule("N_VARIDENT", "T_IDENT");
 };

 N_WHILE         : T_WHILE N_EXPR T_DO N_STMT
   {
  prRule("N_WHILE", "T_WHILE N_EXPR T_DO N_STMT");
 };

 N_WRITE         : T_WRITE T_LPAREN N_OUTPUT N_OUTPUTLST T_RPAREN
   {
  prRule("N_WRITE",
     "T_WRITE T_LPAREN N_OUTPUT N_OUTPUTLST T_RPAREN");
 };

%%

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

