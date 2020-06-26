#ifndef _OUT_FUNCTIONS_H_
#define _OUT_FUNCTIONS_H_

#include "translator.h"

Chord * newChord(char * constant);
Set * newSet(Chord * chord, int time);

Chord * chordSum(Chord * c1, Chord * c2);
Chord * chordSub(Chord * c1, Chord * c2);

Set * setRepeat(Set * set, int times);
Set * setConcat(Set * s1, Set * s2);

int totalTime(Set * set);
int avgFreq(Chord * chord);

void playSet(Set * set);

#endif