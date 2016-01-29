/*    example.l
 
Example of a lex specification file.
     
      To create the lexical analyzer:

      flex mipl.l
      g++ lex.yy.c -o lexer
      lexer < inputFileName
*/

%{
/* 
Definitions of constants, variables, & function prototypes go here 
*/

#include <string.h>

int numLines = 0;

void printTokenInfo(const char* tokenType, char* lexeme);

%}

/* Defintions of regular expressions go here */

DIGIT [0-9]
CHAR '.'
LETTER [_a-zA-Z]
ID {LETTER}({LETTER}|{DIGIT})*

%%
\(\*([^*]|[\r\n]|(\*+([^*\)]|[\r\n])))*\*+\) {

}

[-+]?{DIGIT}+ {
    int i = 0;
    if(yytext[0] == '-') {
        printTokenInfo("T_MINUS", "-");
        ++yytext;
    } else if(yytext[0] == '+') {
        printTokenInfo("T_PLUS", "+");
        ++yytext;
    }

    while(yytext[i] == '0')
        ++i;

    int length = strlen(yytext) - i;
    if(length < 10)
        printTokenInfo("T_INTCONST", yytext);
    else if(length > 10)
        printf("**** Invalid integer constant: %s\n", yytext);
    else {
        bool flag = false;
        char* toMatch = "2147483647";
        for(int x=0; x<10; x++) {
            if(yytext[i] > toMatch[x])
                flag = true;
            ++i;
        }
        
        if(flag == true)
            printf("**** Invalid integer constant: %s\n", yytext);
        else
            printTokenInfo("T_INTCONST", yytext);
    }
    return 1;
}

{CHAR} {
    printTokenInfo("T_CHARCONST", yytext);
    return 1;
}

\+ {
    printTokenInfo("T_PLUS", yytext);
    return 1;
}

\- {
    printTokenInfo("T_MINUS", yytext);
    return 1;
}

":=" {
    printTokenInfo("T_ASSIGN", yytext);
    return 1;
}

\* {
    printTokenInfo("T_MULT", yytext);
    return 1;
}

[ \t\r]+ {

}

\n {
    numLines++;
}

"div" {
    printTokenInfo("T_DIV", yytext);
    return 1;
}

"if" {
    printTokenInfo("T_IF", yytext);
    return 1;
}

"else" {
    printTokenInfo("T_ELSE", yytext);
    return 1;
}

"begin" {
    printTokenInfo("T_BEGIN", yytext);
    return 1;
}

"end" {
    printTokenInfo("T_END", yytext);
    return 1;
}

"integer" {
    printTokenInfo("T_INT", yytext);
    return 1;
}

"char" {
    printTokenInfo("T_CHAR", yytext);
    return 1;
}

"boolean" {
    printTokenInfo("T_BOOL", yytext);
    return 1;
}

"and" {
    printTokenInfo("T_AND", yytext);
    return 1;
}

"or" {
    printTokenInfo("T_OR", yytext);
    return 1;
}

"true" {
    printTokenInfo("T_TRUE", yytext);
    return 1;
}

"false" {
    printTokenInfo("T_FALSE", yytext);
    return 1;
}

"var" {
    printTokenInfo("T_VAR", yytext);
    return 1;
}

"then" {
    printTokenInfo("T_THEN", yytext);
    return 1;
}

"do" {
    printTokenInfo("T_DO", yytext);
    return 1;
}

"while" {
    printTokenInfo("T_WHILE", yytext);
    return 1;
}

"not" {
    printTokenInfo("T_NOT", yytext);
    return 1;
}

"of" {
    printTokenInfo("T_OF", yytext);
    return 1;
}

"procedure" {
    printTokenInfo("T_PROC", yytext);
    return 1;
}

"program" {
    printTokenInfo("T_PROG", yytext);
    return 1;
}

"write" {
    printTokenInfo("T_WRITE", yytext);
    return 1;
}

"read" {
    printTokenInfo("T_READ", yytext);
    return 1;
}

"array" {
    printTokenInfo("T_ARRAY", yytext);
    return 1;
}

"(" {
    printTokenInfo("T_LPAREN", yytext);
    return 1;
}

")" {
    printTokenInfo("T_RPAREN", yytext);
    return 1;
}

"[" {
    printTokenInfo("T_LBRACK", yytext);
    return 1;
}

"]" {
    printTokenInfo("T_RBRACK", yytext);
    return 1;
}

"," {
    printTokenInfo("T_COMMA", yytext);
    return 1;
}

";" {
    printTokenInfo("T_SCOLON", yytext);
    return 1;
}

":" {
    printTokenInfo("T_COLON", yytext);
    return 1;
}

"<" {
    printTokenInfo("T_LT", yytext);
    return 1;
}

">" {
    printTokenInfo("T_GT", yytext);
    return 1;
}

"<>" {
    printTokenInfo("T_NE", yytext);
    return 1;
}

"<=" {
    printTokenInfo("T_LE", yytext);
    return 1;
}

">=" {
    printTokenInfo("T_GE", yytext);
    return 1;
}

"=" {
    printTokenInfo("T_EQ", yytext);
    return 1;
}

"." {
    printTokenInfo("T_DOT", yytext);
    return 1;
}

".." {
    printTokenInfo("T_DOTDOT", yytext);
    return 1;
}

{ID} {
    printTokenInfo("T_IDENT", yytext);
    return 1;
}

'' {
    printf("**** Invalid character constant: %s\n", yytext);
    return 1;
}

' {
    printf("**** Invalid character constant: %s\n", yytext);
    return 1;
}

. {
    printTokenInfo("T_UNKNOWN", yytext);
    return 1;
}

%%

// User-written code goes here

void printTokenInfo(const char* tokenType, char* lexeme) {
    printf("TOKEN: %s  LEXEME: %s\n", tokenType, lexeme);
}

// You should supply a yywrap function.
// Having it return 1 means only 1 input file will be scanned.
int yywrap(void) { return 1; }

int main(void) {
    while ( yylex() ) ;  // Keep processing tokens until 0 returned

    //printf("Processed %d lines\n", numLines);
    return 0;
}
