CC=gcc
CFLAGS=-Wall -pedantic -std=c99
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
LIB=-ly -lm