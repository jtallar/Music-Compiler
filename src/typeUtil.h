#ifndef TYPE_UTIL_H
#define TYPE_UTIL_H

#include "translator.h"

struct chord * atochord(const char *nptr);

struct chord * atonote(const char *nptr);          

void print_chord(struct chord * chord);

void init_list();

bool createVar(types type, char * name);

bool putVar (unsigned long size, Var * variable, void * value);

Var * getVarByName(char * name);

bool putInt(char * name, int * value);

bool putChord(char * name, Chord * value);

bool putSet(char * name, Set * value);

#endif