#ifndef TRANSLATION_TOKENS_H
#define TRANSLATION_TOKENS_H

//#include <math.h>

typedef enum { C=0, Cs, D, Ds=3, E, F, Fs=6, G, Gs, A=9, As, B } notes_enum;
typedef enum { aC=0, aCm, aD, aDm=3, aE, aEm, aF=6, aFm, aG, aGm=9, aA, aAm, aB=12, aBm } chords_enum;

// float notes[] = { /*C*/ 65.41 * pow(2,3), 69.30* pow(2,3), 73.42* pow(2,3), 77.78* pow(2,3), 82.41* pow(2,3), 87.31* pow(2,3), 92.50* pow(2,3), 98.00* pow(2,3), 103.83* pow(2,3), 110.00* pow(2,3), 116.54* pow(2,3), 123.47* pow(2,3) /*B*/};

notes_enum chordsNotes[14][3] = {       {C,E, G},
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
                                              {B,E, G}       };

typedef struct chord{
  notes_enum * note;
  int quant;
}Chord;

typedef struct block{
  Chord *chords;
  int time;
}Block;

typedef struct set{
  Block blocks[200];
  int quant;
}Set;


// static const Chord ch[] = { { .note[0] = C, .quant = 3 } };

int a[] = {C, D, G};

const Chord ch[] = {  
      {chordsNotes[aC], 3},{chordsNotes[aCm], 3},{chordsNotes[aD],3},
      {chordsNotes[aDm], 3},{chordsNotes[aE], 3},{chordsNotes[aEm],3},
      {chordsNotes[aF], 3},{chordsNotes[aFm], 3},{chordsNotes[aG],3},
      {chordsNotes[aGm], 3},{chordsNotes[aA], 3},{chordsNotes[aAm],3},
      {chordsNotes[aB], 3},{chordsNotes[aBm], 3},
};

//ch[0]={ chordsNotes[0], 3};

#endif