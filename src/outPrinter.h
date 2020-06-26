#ifndef _OUT_PRINTER_H_
#define _OUT_PRINTER_H_

#include "translator.h"

void printCreateVar(types type, char * name);

void printPutVar(char * name, Data data);


char * printChordConstant(char * chordStr);

#endif