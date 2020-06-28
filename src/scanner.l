%{
#include "y.tab.h"
%}

digit		[0-9]
number		{digit}+
variable 	[a-z][a-z0-9_]*
new_line 	\n
note        (As|Cs|Ds|Fs|Gs|[A-G])
chord       a{note}m?


%%
"if"					return IF;
"else"					return ELSE;
"while"					return WHILE;
"do"                    return DO;
"=" 			  	 	return ASSIGN;
"*"                     return STAR;
"/"                     return BAR;
"+"                     return ADD;
"-"                     return MINUS;
"=="					return EQUAL_OP;
"!="					return NOT_EQUAL_OP;
">"						return GT_OP;
">="					return GTE_OP;
"<"						return LT_OP;
"<="					return LTE_OP;
"&&"					return AND_OP;
"||"					return OR_OP;
"!"						return NOT_OP;
"{"						return OPEN_BRACES;
"}"						return CLOSE_BRACES;
"("						return OPEN_PAREN;
")"						return CLOSE_PAREN;
"["                     return OPEN_BRACKET;
"]"                     return CLOSE_BRACKET;
"play"                  return PLAY;

"int"                   return INT;
"chord"                 return CHORD;
"set"                   return SET;


{number} 				{ yylval=atoi(yytext); return NUMBER; }
{variable} 				{ yylval= yytext; return VAR; }
{note} 				    { yylval= yytext; return NOTE; }
{chord} 				{ yylval= yytext; return CHORD; }
{new_line} 				{ yylineno++; return NEW_LINE; }		
.						;
	
%%
