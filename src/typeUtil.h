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

Data getDataByName(char * name);

Data getChordData(Chord * chord );

Data getIntData(int * num);

Data newSetData(Data chord, Data time);

/**     Operations    **/

Data addOperation(Data first, Data second);

Data minusOperation(Data first, Data second);

Data barOperation(Data first, Data second);

Data starOperation(Data first, Data second);

/***********************/

char * getTypeByEnum(types type);

Set * newSet(Data chord, Data time);

bool putInt(char * name, int * value);

bool putChord(char * name, Chord * value);

bool putSet(char * name, Set * value);

#endif