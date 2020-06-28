CC=gcc
YACC=yacc
YACCFLAGS=-d
LEX=lex
CFLAGS=-Wall -pedantic -std=c99 -g -Wno-unused-variable -Wno-unused-function
#CFLAGS=-Wall -pedantic -std=c99 -g
SOURCES= lex.yy.c y.tab.c typeUtil.c outPrinter.c
OBJECTS=$(SOURCES:.c=.o)
LIB=-ly -lm