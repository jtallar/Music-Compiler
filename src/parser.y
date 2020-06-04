%{
#include <stdio.h>
#include <stdlib.h>
#include "translator.h"

%}


/* ----------------- TOKENS ---------------------
 * Token that I'm expecting from the lexical 
 * analyzer (will save as defines in tab.h) */
%union {
    int number; 
    struct Chord * chord;
    struct Set * set;
    char * strVal;
}

%token IF ELSE DO WHILE ASSIGN STAR BAR ADD MINUS 
%token EQUAL_OP NOT_EQUAL_OP GT_OP GTE_OP LT_OP LTE_OP AND_OP OR_OP NOT_OP
%token OPEN_BRACES CLOSE_BRACES OPEN_PAREN CLOSE_PAREN OPEN_BRACKET CLOSE_BRACKET
%token PLAY NEW_LINE NOTE VAR
%token INT_NAME CHORD_NAME SET_NAME

%token <number> NUMBER 
%token <set> SET
%token <chord> CHORD

//%type <strVal> expression assign var_type term factor constant

%start program

%%

program         :  program declare 
                |  program assign
                |  program if_sentence
                |  program do_sentence
                |  program while_sentence
                |  program play
                |  /* empty */
                ;

play            : PLAY OPEN_PAREN set CLOSE_PAREN
                ;

do_sentence     : DO body WHILE compare
                ;

while_sentence  : WHILE compare body
                ;

if_sentence     : IF compare body else
                ;

compare         : OPEN_PAREN expression op_compare expression CLOSE_PAREN
                ;

body            : OPEN_BRACES program CLOSE_BRACES
                ;

else            : ELSE body 
                |
                ;

set             : set STAR factor 
                | set BAR set  
                | OPEN_BRACKET constant factor CLOSE_BRACKET
                | factor
                ;

op_compare      : GT_OP 
                | GTE_OP    
                | LT_OP 
                | LTE_OP 
                | EQUAL_OP 
                | NOT_EQUAL_OP
                ;

declare         : var_type VAR NEW_LINE
                ;

var_type        : INT_NAME
                | CHORD_NAME 
                | SET_NAME
                ;

assign          : VAR ASSIGN expression NEW_LINE        /* { $$ = $3; printf("Found %d\n", $$); } */
                ;

expression      : expression ADD term                   /* { $$ = $1 + $3; printf("Found %d\n", $$); } */
                | expression MINUS term                 /* { $$ = $1 - $3; printf("Found %d\n", $$); } */
                | term
                ;

term            : term STAR factor
                | term BAR factor
                | factor
                ;

factor          : CHORD 
                | VAR
                ;

constant        : CHORD 
                | NUMBER
                ;

%%

int yywrap(){
    return 1;
} 

int main() {
    printf("Make your music...\n");
    yyparse();
} 

/**
* *       yacc -d parser.y
* *       lex scanner.l
* *       gcc lex.yy.c y.tab.c -ly
**/