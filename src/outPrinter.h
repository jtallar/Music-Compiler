#ifndef _OUT_PRINTER_H_
#define _OUT_PRINTER_H_

#include "translator.h"

void printCreateVar(types type, char * name);

void printPutVar(char * name, Data data);


char * printChordConstant(char * chordStr);

char * printNewSet(char * chordPrint, char * timePrint);

char * printAddParen(char * expPrint);

char * printStarNumbers(char * print1, char * print2);
char * printStarSet(char * setPrint, char * timesPrint);

char * printBarNumbers(char * print1, char * print2);
char * printBarSet(char * print1, char * print2);

char * printAddNumbers(char * print1, char * print2);
char * printAddChords(char * print1, char * print2);

char * printSubstractNumbers(char * print1, char * print2);
char * printSubstractChords(char * print1, char * print2);

char * printMakeComparableChord(char * print);
char * printMakeComparableSet(char * print);

char * printComparison(char * print1, conditions cond, char * print2);
char * printNotComparison(char * print);


void printIfSentence(char * cond, char * ifBody, char * elseBody);

#endif