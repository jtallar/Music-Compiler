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
     STAR = 262,
     BAR = 263,
     ADD = 264,
     MINUS = 265,
     ASSIGN = 266,
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
     START = 282,
     PLAY = 283,
     NEW_LINE = 284,
     PRINT = 285,
     INT_NAME = 286,
     CHORD_NAME = 287,
     SET_NAME = 288,
     VAR = 289,
     NUMBER = 290,
     CHORD = 291,
     NOTE = 292,
     STRING = 293
   };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define DO 260
#define WHILE 261
#define STAR 262
#define BAR 263
#define ADD 264
#define MINUS 265
#define ASSIGN 266
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
#define START 282
#define PLAY 283
#define NEW_LINE 284
#define PRINT 285
#define INT_NAME 286
#define CHORD_NAME 287
#define SET_NAME 288
#define VAR 289
#define NUMBER 290
#define CHORD 291
#define NOTE 292
#define STRING 293




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 25 "parser.y"
{
    int int_type;
    int * number; 
    struct chord * chord;
    struct set * set;
    char * strVal;
    struct data dataVal;
}
/* Line 1529 of yacc.c.  */
#line 134 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

