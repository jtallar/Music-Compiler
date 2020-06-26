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
%token START PLAY NEW_LINE
%token INT_NAME CHORD_NAME SET_NAME

%token <strVal> VAR
%token <strVal> NUMBER
/* %token <set> SET */
%token <strVal> CHORD
%token <strVal> NOTE

//%type <strVal> expression assign var_type term factor constant

%type <int_type> var_type any_op add_op_logic op_compare
%type <strVal> assign
%type <dataVal> constant factor term expression /**/ compare single_compare mult_compare

%start start

%%

start           :  START NEW_LINE program

program         :  program declare 
                |  program assign
                |  program if_sentence
                |  program do_sentence
                |  program while_sentence
                |  program play
                |  program NEW_LINE
                |  /* empty */
                ;

play            : PLAY OPEN_PAREN expression CLOSE_PAREN NEW_LINE       { playSet($3);   }
                ;

do_sentence     : DO body WHILE compare NEW_LINE
                ;

while_sentence  : WHILE compare body NEW_LINE
                ;

if_sentence     : IF compare body NEW_LINE
                | IF compare body ELSE body NEW_LINE
                ;

compare         : OPEN_PAREN mult_compare any_op single_compare CLOSE_PAREN         { $$ = addParen(condition_composed($2, $3, $4)); /* print_boolean((int*)$$.value); */ }
                | OPEN_PAREN single_compare CLOSE_PAREN                               { $$ = addParen($2);  /* print_boolean((int*)$$.value);   */        }
                /* | OPEN_PAREN expression CLOSE_PAREN                                 { $$ = condition_expression($2); print_boolean((int*)$$.value);       } */
                ;

single_compare  : OPEN_PAREN mult_compare any_op single_compare CLOSE_PAREN         { $$ = addParen(condition_composed($2, $3, $4));  }
                | NOT_OP OPEN_PAREN mult_compare CLOSE_PAREN                        { $$ = negate_condition($3);            }
                | expression                                                        { $$ = data_boolean($1);        }
                ;

mult_compare    : mult_compare any_op single_compare                                { $$ = condition_composed($1, $2, $3);  }                                
                | single_compare                                                    { $$ = $1; }
                ;

// Guarda lo que esta a la derecha $$ = $1
any_op          : add_op_logic                         { $$ = $1; }
                | op_compare                           { $$ = $1; }
                ;
                
body            : OPEN_BRACES program CLOSE_BRACES
                ;

else            : ELSE body 
                |
                ;

// Enum para todos los operadores que siguen
add_op_logic    : AND_OP                               { $$ = and; }
                | OR_OP                                { $$ = or;  }
                ;

op_compare      : GT_OP                                { $$ = gt;  }
                | GTE_OP                               { $$ = gte; }    
                | LT_OP                                { $$ = lt;  }
                | LTE_OP                               { $$ = lte; }
                | EQUAL_OP                             { $$ = eq;  }
                | NOT_EQUAL_OP                         { $$ = neq; }
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
                | OPEN_BRACKET expression expression CLOSE_BRACKET      { $$ = newSetData($2, $3); /* print_set($$); */}
                | OPEN_PAREN expression CLOSE_PAREN                     { $$ = addParen($2); }
                ;

constant        : CHORD                                 { $$ = getChordData($1); /*print_chord($1); */ }
                | NUMBER                                { $$ = getIntData($1);  /*  print_number($1); */ }
                | NOTE                                  { $$ = getNoteData($1); /*print_chord($1);  */}
                ;

%%

void yyerror(const char * format, ...){
    va_list argptr;
    va_start(argptr, format);
    vfprintf(stderr, format, argptr);
    va_end(argptr);
    fprintf(stderr," -> \033[1;31mError\033[0m in line %d\n\n", yylineno);
    exit(EXIT_FAILURE);
}

int yywrap(){
    return 1;
} 

int main() {
    init_list();
    // printf("\033[1;32mReady! Make your music!\033[0m\n\n");
    return yyparse();
} 

/**
* *       yacc -d parser.y
* *       lex scanner.l
* *       gcc lex.yy.c y.tab.c -ly
**/