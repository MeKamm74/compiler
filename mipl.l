/*    mipl.l
      Author: Michael Kammeyer

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

%}

%option yylineno
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
    if(length < 10) {
        printTokenInfo("T_INTCONST", yytext);
        return T_INTCONST;
    }

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
        else {
            printTokenInfo("T_INTCONST", yytext);
            return T_INTCONST;
        }
    }
    return 1;
}

{CHAR} {
    printTokenInfo("T_CHARCONST", yytext);
    return T_CHARCONST;
}

\+ {
    printTokenInfo("T_PLUS", yytext);
    return T_PLUS;
}

\- {
    printTokenInfo("T_MINUS", yytext);
    return T_MINUS;
}

":=" {
    printTokenInfo("T_ASSIGN", yytext);
    return T_ASSIGN;
}

\* {
    printTokenInfo("T_MULT", yytext);
    return T_MULT;
}

[ \t\r]+ {

}

\n {
    numLines++;
}

"div" {
    printTokenInfo("T_DIV", yytext);
    return T_DIV;
}

"if" {
    printTokenInfo("T_IF", yytext);
    return T_IF;
}

"else" {
    printTokenInfo("T_ELSE", yytext);
    return T_ELSE;
}

"begin" {
    printTokenInfo("T_BEGIN", yytext);
    return T_BEGIN;
}

"end" {
    printTokenInfo("T_END", yytext);
    return T_END;
}

"integer" {
    printTokenInfo("T_INT", yytext);
    return T_INT;
}

"char" {
    printTokenInfo("T_CHAR", yytext);
    return T_CHAR;
}

"boolean" {
    printTokenInfo("T_BOOL", yytext);
    return T_BOOL;
}

"and" {
    printTokenInfo("T_AND", yytext);
    return T_AND;
}

"or" {
    printTokenInfo("T_OR", yytext);
    return T_OR;
}

"true" {
    printTokenInfo("T_TRUE", yytext);
    return T_TRUE;
}

"false" {
    printTokenInfo("T_FALSE", yytext);
    return T_FALSE;
}

"var" {
    printTokenInfo("T_VAR", yytext);
    return T_VAR;
}

"then" {
    printTokenInfo("T_THEN", yytext);
    return T_THEN;
}

"do" {
    printTokenInfo("T_DO", yytext);
    return T_DO;
}

"while" {
    printTokenInfo("T_WHILE", yytext);
    return T_WHILE;
}

"not" {
    printTokenInfo("T_NOT", yytext);
    return T_NOT;
}

"of" {
    printTokenInfo("T_OF", yytext);
    return T_OF;
}

"procedure" {
    printTokenInfo("T_PROC", yytext);
    return T_PROC;
}

"program" {
    printTokenInfo("T_PROG", yytext);
    return T_PROG;
}

"write" {
    printTokenInfo("T_WRITE", yytext);
    return T_WRITE;
}

"read" {
    printTokenInfo("T_READ", yytext);
    return T_READ;
}

"array" {
    printTokenInfo("T_ARRAY", yytext);
    return T_ARRAY;
}

"(" {
    printTokenInfo("T_LPAREN", yytext);
    return T_LPAREN;
}

")" {
    printTokenInfo("T_RPAREN", yytext);
    return T_RPAREN;
}

"[" {
    printTokenInfo("T_LBRACK", yytext);
    return T_LBRACK;
}

"]" {
    printTokenInfo("T_RBRACK", yytext);
    return T_RBRACK;
}

"," {
    printTokenInfo("T_COMMA", yytext);
    return T_COMMA;
}

";" {
    printTokenInfo("T_SCOLON", yytext);
    return T_SCOLON;
}

":" {
    printTokenInfo("T_COLON", yytext);
    return T_COLON;
}

"<" {
    printTokenInfo("T_LT", yytext);
    return T_LT;
}

">" {
    printTokenInfo("T_GT", yytext);
    return T_GT;
}

"<>" {
    printTokenInfo("T_NE", yytext);
    return T_NE;
}

"<=" {
    printTokenInfo("T_LE", yytext);
    return T_LE;
}

">=" {
    printTokenInfo("T_GE", yytext);
    return T_GE;
}

"=" {
    printTokenInfo("T_EQ", yytext);
    return T_EQ;
}

"." {
    printTokenInfo("T_DOT", yytext);
    return T_DOT;
}

".." {
    printTokenInfo("T_DOTDOT", yytext);
    return T_DOTDOT;
}

{ID} {
    printTokenInfo("T_IDENT", yytext);
    return T_IDENT;
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

