#ifndef _OUT_PRINTER_H_
#define _OUT_PRINTER_H_

#include "translator.h"

void printCreateVar(types type, char * name);

void printPutVar(char * name, Data data);


char * printChordConstant(char * chordStr);

char * printNewSet(char * chordPrint, char * timePrint);

char * printAddParen(char * expPrint);

#endif