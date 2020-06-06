%{
void yyerror (char *s);
int yylex();
#include <stdio.h>
#include <stdlib.h>
#include "typeUtil.h"

%}


/* ----------------- TOKENS ---------------------
 * Token that I'm expecting from the lexical 
 * analyzer (will save as defines in tab.h) */
%union {
    int number; 
    struct chord * chord;
    struct set * set;
    char * strVal;
}

%token IF ELSE DO WHILE ASSIGN STAR BAR ADD MINUS 
%token EQUAL_OP NOT_EQUAL_OP GT_OP GTE_OP LT_OP LTE_OP AND_OP OR_OP NOT_OP
%token OPEN_BRACES CLOSE_BRACES OPEN_PAREN CLOSE_PAREN OPEN_BRACKET CLOSE_BRACKET
%token PLAY NEW_LINE
%token INT_NAME CHORD_NAME SET_NAME

%token <strVal> VAR 
%token <number> NUMBER
%token <set> SET
%token <chord> CHORD
%token <chord> NOTE

//%type <strVal> expression assign var_type term factor constant

%type <number> var_type

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

play            : PLAY OPEN_PAREN expression CLOSE_PAREN NEW_LINE
                ;

do_sentence     : DO body WHILE compare NEW_LINE
                ;

while_sentence  : WHILE compare body NEW_LINE
                ;

if_sentence     : IF compare body else NEW_LINE
                ;

compare         : OPEN_PAREN mult_compare any_op single_compare CLOSE_PAREN
                | NOT_OP OPEN_PAREN mult_compare CLOSE_PAREN
                | OPEN_PAREN expression CLOSE_PAREN
                ;

single_compare  : OPEN_PAREN mult_compare any_op single_compare CLOSE_PAREN
                | NOT_OP OPEN_PAREN mult_compare CLOSE_PAREN
                | expression
                ;

mult_compare    : mult_compare any_op single_compare
                | single_compare
                ;

any_op          : add_op_logic
                | op_compare
                ;
                
body            : OPEN_BRACES program CLOSE_BRACES
                ;

else            : ELSE body 
                |
                ;

add_op_logic    : AND_OP
                | OR_OP
                ;

op_compare      : GT_OP 
                | GTE_OP    
                | LT_OP 
                | LTE_OP 
                | EQUAL_OP 
                | NOT_EQUAL_OP
                ;

declare         : var_type VAR NEW_LINE                 { createVar($1,$2); }           
                | var_type assign                       /* { createVar($1,$2); } */
                ;

var_type        : INT_NAME                              { $$ = 0; }                              
                | CHORD_NAME                            { $$ = 1; }
                | SET_NAME                              { $$ = 2; }
                ;

assign          : VAR ASSIGN expression NEW_LINE        { $$ = $1; }
                ;

expression      : expression ADD term                   /*{ $$ = $1 + $3; printf("Found %d\n", $$); } */
                | expression MINUS term                 /* { $$ = $1 - $3; printf("Found %d\n", $$); } */
                | term
                ;

term            : term STAR factor
                | term BAR factor
                | factor
                ;

factor          : constant 
                | VAR
                | OPEN_BRACKET expression expression CLOSE_BRACKET
                | OPEN_PAREN expression CLOSE_PAREN
                ;

constant        : CHORD     {print_chord($1);}
                | NUMBER
                | NOTE      {print_chord($1);}
                ;

%%

int yywrap(){
    return 1;
} 

int main() {
    init_list();
    printf("Ready! Make your music!\n\n");
    return yyparse();
} 

/**
* *       yacc -d parser.y
* *       lex scanner.l
* *       gcc lex.yy.c y.tab.c -ly
**/