#ifndef _OUT_FUNCTIONS_H_
#define _OUT_FUNCTIONS_H_

#include "translator.h"

Chord * outNewChord(char * constant);
Set * outNewSet(Chord * chord, int time);

Chord * outChordSum(Chord * c1, Chord * c2);
Chord * outChordSub(Chord * c1, Chord * c2);

Set * outSetRepeat(Set * set, int times);
Set * outSetConcat(Set * s1, Set * s2);

int outTotalTime(Set * set);
int outAvgFreq(Chord * chord);

void outPlaySet(Set * set);

#endif