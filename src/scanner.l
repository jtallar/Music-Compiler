%{
#include "typeUtil.h"
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void yyerror (const char * format, ...);
int yylex();
%}

string      \"[^\"]*\"
number		([1-9][0-9]*|(0))
variable 	[a-z][a-z0-9_]* 
new_line 	\n
note        (As|Cs|Ds|Fs|Gs|[_A-G])
chord       a{note}m?


%%
"if"			    return IF;
"else"		        return ELSE;
"while"			    return WHILE;
"do"                return DO;
"=" 	  	 	    return ASSIGN;
"*"                 return STAR;
"/"                 return BAR;
"+"                 return ADD;
"-"                 return MINUS;
"=="		        return EQUAL_OP;
"!="			    return NOT_EQUAL_OP;
">"			        return GT_OP;
">="			    return GTE_OP;
"<"			        return LT_OP;
"<="			    return LTE_OP;
"and"			    return AND_OP;
"or"			    return OR_OP;
"!"			        return NOT_OP;
"{"			        return OPEN_BRACES;
"}"			        return CLOSE_BRACES;
"("			        return OPEN_PAREN;
")"			        return CLOSE_PAREN;
"["                 return OPEN_BRACKET;
"]"                 return CLOSE_BRACKET;
"play"              return PLAY;
"print"             return PRINT;
"getnum"            return GET_NUM;
"getchord"          return GET_CHORD;
"start"             return START;
"stop"              return STOP;

"int"               return INT_NAME;
"chord"             return CHORD_NAME;
"set"               return SET_NAME;

{number} 			{ /* puts(yytext); */ yylval.strVal = malloc(yyleng+1); strcpy(yylval.strVal,yytext); return NUMBER; }
{note} 		        { /* puts(yytext); */ yylval.strVal = malloc(yyleng+1); strcpy(yylval.strVal,yytext); return NOTE; }
{chord} 			{ /* puts(yytext); */ yylval.strVal = malloc(yyleng+1); strcpy(yylval.strVal,yytext); return CHORD; }
{variable} 			{ /* puts(yytext); */ yylval.strVal = malloc(yyleng+1); strcpy(yylval.strVal,yytext); return VAR; }
{string}            { /* puts(yytext); */ yylval.strVal = malloc(yyleng+1); strcpy(yylval.strVal,yytext); return STRING; }
{new_line} 			{ yylineno++; return NEW_LINE; }		
.				    { /* yyerror("Syntax Error! No match found for %s %d", yytext, yyleng); */ }
	
%%

/* int yyerror(char *s){
    fprintf(stderr, "\nERROR ON LINE %d : $s\n", yylineno, s);
} */