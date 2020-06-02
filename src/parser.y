%{
#include <stdio.h>
#include <stdlib.h>
%}


/* ----------------- TOKENS ---------------------
 * Token that I'm expecting from the lexical 
 * analyzer (will save as defines in tab.h) */

%union {
    int INT; 
    char* CHORD; 
    char set; 
}

%token IF ELSE DO WHILE ASSIGN STAR BAR ADD MINUS 
%token EQUAL_OP NOT_EQUAL_OP GT_OP GTE_OP LT_OP LTE_OP AND_OP OR_OP NOT_OP
%token OPEN_BRACES CLOSE_BRACES OPEN_PAREN CLOSE_PAREN
%token OPEN_BRACKET CLOSE_BRACKET
%token NUMBER VAR PLAY INT CHORD SET NEW_LINE NOTE 

%type <num> INT expression assign
%type <chord> CHORD
%type <set> SET
%type <char> NOTE VAR 

%start program

%%

program     : declare program 
            | assign program 
            |  /* empty */
            ;

var_type    : INT 
            | CHORD 
            | SET
            ;

declare     : var_type VAR NEW_LINE
            ;
assign      : VAR ASSIGN expression NEW_LINE          { $$ = $3; printf("Found %d\n", $$); }
            ;

expression  : expression ADD expression               { $$ = $1 + $3; printf("Found %d\n", $$); }
            | expression MINUS expression             { $$ = $1 - $3; printf("Found %d\n", $$); }
            | factor
            ;

term        : term STAR factor 
            | term BAR factor 
            ;

factor      : constant 
            | VAR
            ;

constant    : NOTE 
            | CHORD 
            | NUMBER

%%

int yywrap(){
        return 1;
} 

main() {
    printf("Enter the expression:\n");
    yyparse();
} 

/*
**       yacc -d parser.y
**       lex scanner.l
**       gcc lex.yy.c y.tab.c -ly
*/