%{
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
// #include "translator.h"
#include "typeUtil.h"
struct chord * atochord(const char *nptr);
void yyerror (char *s);
int yylex();
%}

number		[1-9][0-9]*
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
"&&"			    return AND_OP;
"||"			    return OR_OP;
"!"			        return NOT_OP;
"{"			        return OPEN_BRACES;
"}"			        return CLOSE_BRACES;
"("			        return OPEN_PAREN;
")"			        return CLOSE_PAREN;
"["                 return OPEN_BRACKET;
"]"                 return CLOSE_BRACKET;
"play"              return PLAY;

"int"               return INT_NAME;
"chord"             return CHORD_NAME;
"set"               return SET_NAME;


{number} 			{ /* puts(yytext); */ yylval.number = atoi(yytext); return NUMBER; }
{note} 		        { /* puts(yytext); */ yylval.chord = atonote(yytext); return NOTE; }
{chord} 			{ /* puts(yytext); */ yylval.chord = atochord(yytext); return CHORD; }
{variable} 			{ /* puts(yytext); */ yylval.strVal = yytext; return VAR; }
{new_line} 			{ yylineno++; return NEW_LINE; }		
.				    ;
	
%%

/* int yyerror(char *s){
    fprintf(stderr, "\nERROR ON LINE %d : $s\n", yylineno, s);
} */