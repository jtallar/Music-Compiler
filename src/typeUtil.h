#ifndef TYPE_UTIL_H
#define TYPE_UTIL_H

#include "translator.h"

struct chord * atochord(const char *nptr);
struct chord * atonote(const char *nptr);          

/*      Printing       */
void print_chord(struct chord * chord);
void print_number(int* num);
void print_set(Data set);
void print_boolean(int* num);
void print_chord_data(Data chord);
/***********************/

void addNote(Chord * chord, notes_enum note);

void deleteNote(Chord * chord, notes_enum note);

int containsNote(Chord * chord, notes_enum note);

void init_list();

void createVar(types type, char * name);

void putVar (size_t size, Var * variable, void * value);

Var * getVarByName(char * name);

Data getDataByName(char * name);

Data getChordData(Chord * chord );

Data getIntData(int * num);

Data newSetData(Data chord, Data time);

/**      Operations     **/
Data addOperation(Data first, Data second);
Data minusOperation(Data first, Data second);
Data barOperation(Data first, Data second);
Data starOperation(Data first, Data second);
/***********************/

/**     Conditions      **/
Data condition_composed(Data first, conditions cond, Data second);
Data negate_condition(Data condition);        
Data condition_expression(Data exp); 
/***********************/

char * getTypeByEnum(types type);

Set * newSet(Data chord, Data time);

void putInt(char * name, int * value);

void putChord(char * name, Chord * value);

void putSet(char * name, Set * value);

Data data_boolean(Data data);

#endif