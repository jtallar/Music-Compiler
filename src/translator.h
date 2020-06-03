#ifndef TRANSLATION_TOKENS_H
#define TRANSLATION_TOKENS_H

enum notes_enum{ C=0, Cs, D, Ds=3, E, F, Fs=6, G, Gs, A=9, As, B };
enum chords_enum{ aC=0, aCm, aD, aDm=3, aE, aEm, aF=6, aFm, aG, aGm=9, aA, aAm, aB=12, aBm };


const notes_enum chordsFreqs[14][3] = {{C,E,G},
                                      {C,Ds,G}, 
                                      {D,Fs,A}, 
                                      {D,F,A},
                                      {E,Gs,B}, 
                                      {E,G,B}, 
                                      {F,A,C}, 
                                      {F,Gs,C},
                                      {G,B,D}, 
                                      {G,As,D}, 
                                      {A,Cs,E}, 
                                      {A,C,E},
                                      {B,Ds,Fs}, 
                                      {B,E,G}
                                  };

static const Chord ch[] = {{ .note = chordsFreqs[0], .quant =  3},
                           {}
                          
                          };

typedef enum {  
} TokenType;

typedef enum {  
            
} DataType;

/* Token structures that hold the token information */

/* Shared struct */
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


#endif