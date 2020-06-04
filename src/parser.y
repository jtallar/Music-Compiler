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
%token PLAY NEW_LINE NOTE
%token INT_NAME CHORD_NAME SET_NAME

%token <strVal> VAR
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

play            : PLAY OPEN_PAREN expression CLOSE_PAREN NEW_LINE
                ;

do_sentence     : DO body WHILE compare NEW_LINE
                ;

while_sentence  : WHILE compare body NEW_LINE
                ;

if_sentence     : IF compare body else NEW_LINE
                ;

compare         : simple_compare
                | not_op_logic OPEN_PAREN simple_compare add_op_logic mult_compare CLOSE_PAREN
                ;

simple_compare  : not_op_logic OPEN_PAREN expression op_compare expression CLOSE_PAREN
                ;

mult_compare    : simple_compare add_op_logic mult_compare
                | simple_compare
                ; 

body            : OPEN_BRACES program CLOSE_BRACES
                ;

else            : ELSE body 
                |
                ;

not_op_logic    : NOT_OP
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

factor          : constant 
                | VAR
                ;

constant        : CHORD     {print_chord($1);}
                | NUMBER
                ;

%%



int yywrap(){
    return 1;
} 

int main() {
    printf("Make your music...\n");
    return yyparse();
} 

void print_chord(struct chord * chord) {
    if (chord == NULL || chord->note == NULL) return;
    puts("\nVino un chord: \n");
    for (int i = 0; i < chord->quant; i++) {
        printf("\nNota %d: %d", i, chord->note[i]);
    }
}


/**
* *       yacc -d parser.y
* *       lex scanner.l
* *       gcc lex.yy.c y.tab.c -ly
**/