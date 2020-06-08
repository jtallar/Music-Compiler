%{
void yyerror(const char * format, ...);
int yylex();
extern int yylineno;

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "typeUtil.h"
/* Variable for the line count */

%}

/* ----------------- TOKENS ---------------------
 * Token that I'm expecting from the lexical 
 * analyzer (will save as defines in tab.h) */

/*  %code requires {
    struct data{
        types type;
        void * value;
    };
} */

%union {
    int int_type;
    int * number; 
    struct chord * chord;
    struct set * set;
    char * strVal;
    struct data dataVal;
}

%token IF ELSE DO WHILE STAR BAR ADD MINUS ASSIGN
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

%type <int_type> var_type
%type <strVal> assign
%type <dataVal> constant factor term expression

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

declare         : var_type VAR NEW_LINE                 { createVar($1,$2); }      // se me lleva NEW_LINE     
            /*  | var_type assign                       { createVar($1,$2); } */
                ;

assign          : VAR ASSIGN expression NEW_LINE        { newVar($1,$3); }
                ;

var_type        : INT_NAME                              { $$ = num_type;   }                              
                | CHORD_NAME                            { $$ = chord_type; }
                | SET_NAME                              { $$ = set_type;   }
                ;

expression      : expression ADD term                   { $$ = addOperation($1,$3);   }
                | expression MINUS term                 { $$ = minusOperation($1,$3); }
                | term                                  { $$ = $1; }
                ;

term            : term STAR factor                      { $$ = starOperation($1,$3); }
                | term BAR factor                       { $$ = barOperation ($1,$3); }
                | factor                                { $$ = $1; }
                ;

factor          : constant                                              { $$ = $1;}
                | VAR                                                   { $$ = getDataByName($1);  }
                | OPEN_BRACKET expression expression CLOSE_BRACKET      { $$ = newSetData($2, $3); print_set($$);}
                | OPEN_PAREN expression CLOSE_PAREN                     { $$ = $2; }
                ;

constant        : CHORD                                 { $$ = getChordData($1); /*print_chord($1); */ }
                | NUMBER                                { $$ = getIntData($1);   /*print_number($1);*/ }
                | NOTE                                  { $$ = getChordData($1); /*print_chord($1);  */}
                ;

%%

void yyerror(const char * format, ...){
    va_list argptr;
    va_start(argptr, format);
    vfprintf(stderr, format, argptr);
    va_end(argptr);
    fprintf(stderr," -> Error in line %d\n\n", yylineno);
    exit(1);
}

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