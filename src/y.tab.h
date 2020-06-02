/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     ELSE = 259,
     DO = 260,
     WHILE = 261,
     ASSIGN = 262,
     STAR = 263,
     BAR = 264,
     ADD = 265,
     MINUS = 266,
     EQUAL_OP = 267,
     NOT_EQUAL_OP = 268,
     GT_OP = 269,
     GTE_OP = 270,
     LT_OP = 271,
     LTE_OP = 272,
     AND_OP = 273,
     OR_OP = 274,
     NOT_OP = 275,
     OPEN_BRACES = 276,
     CLOSE_BRACES = 277,
     OPEN_PAREN = 278,
     CLOSE_PAREN = 279,
     OPEN_BRACKET = 280,
     CLOSE_BRACKET = 281,
     NUMBER = 282,
     PLAY = 283,
     CHORD = 284,
     SET = 285,
     NEW_LINE = 286,
     NOTE = 287,
     INT = 288,
     VAR = 289
   };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define DO 260
#define WHILE 261
#define ASSIGN 262
#define STAR 263
#define BAR 264
#define ADD 265
#define MINUS 266
#define EQUAL_OP 267
#define NOT_EQUAL_OP 268
#define GT_OP 269
#define GTE_OP 270
#define LT_OP 271
#define LTE_OP 272
#define AND_OP 273
#define OR_OP 274
#define NOT_OP 275
#define OPEN_BRACES 276
#define CLOSE_BRACES 277
#define OPEN_PAREN 278
#define CLOSE_PAREN 279
#define OPEN_BRACKET 280
#define CLOSE_BRACKET 281
#define NUMBER 282
#define PLAY 283
#define CHORD 284
#define SET 285
#define NEW_LINE 286
#define NOTE 287
#define INT 288
#define VAR 289




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 11 "parser.y"
{
    int intVal; 
    char strVal[200];

    //struct Token *token;
}
/* Line 1529 of yacc.c.  */
#line 124 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

