#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "translator.h"
#include "soundSet.h"


#define M_PI           3.14159265358979323846

static double outVolume = BASE_VOLUME;

int playWav( char *filename ) {
    char command[256];
    int status;
    /* create command to execute */
    sprintf (command, "%s %s", SOUND_COMMAND, filename);

    /* play sound */
    status = system( command );
     
    return status;
}


void addSet (Wave * mySound, Set set);

long getSampleNumber(long miliseconds) {
    return (long) ((miliseconds / 1000.0) * SAMPLE_RATE);
}


long getTotalDuration(Set set) {
    long rta = 0;
    for (int i = 0; i < set.quant ; i++) {
        rta += set.blocks[i].time;
    }
    return rta;
}

void generateWav(Set set, char * name) {
    long duration = getTotalDuration(set);
    long nSamples = getSampleNumber(duration);
    
    // Create a mono (1), 16-bit sound and set the duration
    Wave mySound = makeWave((int)SAMPLE_RATE, CHANNEL_NUM, BITS_SAMPLE);
    waveSetDuration(&mySound, duration);

    // Add all of the data
    addSet(&mySound, set);

    // Write it to a file and clean up when done
    waveToFile(&mySound, name);
    waveDestroy(&mySound);
}


/*
    struct NoteNode * node = chord->notes;
    for (int i = 0; i < chord->quant; i++){
        printf("\tNota %d: %d\n", i, node->note);
        node = node->next;
    }

*/

void resetArray(float * array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 0.0;
    }
}


void addChord(Wave * mySound, Chord * chord, long nSamples) {
    float multiplier = M_PI * 2.0 / SAMPLE_RATE;
    float frameData[CHANNEL_NUM];
    int i, j, k;
    for(i = 0; i < nSamples; i++){
        resetArray(frameData, CHANNEL_NUM);
        for (j = 0; j < chord->quant ; j++) {
            for (k = 0; k < CHANNEL_NUM; k++) {
                frameData[k] += outVolume * sin(notes[chord->notes[j].note] * (float)i * multiplier) / chord->quant;
            }
        }
        waveAddSample(mySound, frameData);
    }
}



void addSet (Wave * mySound, Set set){
    for (int i = 0; i < set.quant; i++) {
        addChord(mySound, set.blocks[i].chords , getSampleNumber(set.blocks[i].time));
    }
}



