#ifndef TRANSLATION_TOKENS_H
#define TRANSLATION_TOKENS_H

#include <stdbool.h>
//#include <math.h>
#define NOTE_COUNT  13
#define CHORD_COUNT 14
#define STD_CHORD_L 3

typedef enum { num_type, chord_type, set_type, var_type } types;
typedef enum { C=0, Cs, D, Ds=3, E, F, Fs=6, G, Gs, A=9, As, B, _ } notes_enum;
static const char * noteName[NOTE_COUNT] = {"C", "Cs", "D", "Ds", "E", "F", "Fs", "G", "Gs", "A", "As", "B", "_"};
typedef enum { aC=0, aCm, aD, aDm=3, aE, aEm, aF=6, aFm, aG, aGm=9, aA, aAm, aB=12, aBm } chords_enum;
static const char * chordName[CHORD_COUNT] = {"aC", "aCm", "aD", "aDm", "aE", "aEm", "aF", "aFm", "aG", "aGm", "aA", "aAm", "aB", "aBm"};

// float notes[] = { /*C*/ 65.41 * pow(2,3), 69.30* pow(2,3), 73.42* pow(2,3), 77.78* pow(2,3), 82.41* pow(2,3), 87.31* pow(2,3), 92.50* pow(2,3), 98.00* pow(2,3), 103.83* pow(2,3), 110.00* pow(2,3), 116.54* pow(2,3), 123.47* pow(2,3) /*B*/};

static notes_enum chordsNotes[CHORD_COUNT][STD_CHORD_L] = { {C,E, G},
                                                            {C,Ds,G}, 
                                                            {D,Fs,A}, 
                                                            {D,F, A},
                                                            {E,Gs,B}, 
                                                            {E,G, B}, 
                                                            {F,A, C}, 
                                                            {F,Gs,C},
                                                            {G,B, D}, 
                                                            {G,As,D}, 
                                                            {A,Cs,E}, 
                                                            {A,C, E},
                                                            {B,Ds,Fs}, 
                                                            {B,E, G}};

/* struct var * variables[CHUNK];
int index = 0; */

typedef struct data{
  types type;
  void * value;
}Data;

typedef struct var{
  char * name;
  Data data;
}Var;

struct Node{
  Var * var;
  struct Node * next;
};

typedef struct list{
  struct Node * header;
  struct Node * tail;
}List;

List * list;

typedef struct chord{
  notes_enum * note;
  int quant;
}Chord;

typedef struct block{
  Chord * chords;
  int time;
}Block;

typedef struct set{
  Block * blocks;
  int quant;
}Set;

static const Chord ch[] = {  
      {chordsNotes[aC],  STD_CHORD_L}, {chordsNotes[aCm], STD_CHORD_L}, {chordsNotes[aD], STD_CHORD_L},
      {chordsNotes[aDm], STD_CHORD_L}, {chordsNotes[aE],  STD_CHORD_L}, {chordsNotes[aEm],STD_CHORD_L},
      {chordsNotes[aF],  STD_CHORD_L}, {chordsNotes[aFm], STD_CHORD_L}, {chordsNotes[aG], STD_CHORD_L},
      {chordsNotes[aGm], STD_CHORD_L}, {chordsNotes[aA],  STD_CHORD_L}, {chordsNotes[aAm],STD_CHORD_L},
      {chordsNotes[aB],  STD_CHORD_L}, {chordsNotes[aBm], STD_CHORD_L},
};

extern void yyerror (char *s);

#endif