#ifdef __linux__
    #define SOUND_COMMAND  "aplay -c"
#endif

#ifdef __APPLE__	
    #define SOUND_COMMAND  "afplay"
#endif

#ifndef _SOUND_H_
#define _SOUND_H_

#include "wave.h"

#define WAV_FILE_NAME   "output.wav"

#define SAMPLE_RATE     96000.0 // hertz
#define MONO            1
#define STEREO          2
#define CHANNEL_NUM     MONO
#define BITS_SAMPLE     16      // 8, 16 or 32

typedef struct Chord {
    float * freq;   // Frequency array [hz]
    int size;       // Number of freq in array
} Chord;

typedef struct Set {
    Chord chord;    // Chord to play
    long time;      // Time to play chord [ms]
} Set;

typedef struct Score {
    Set * sets;    // Sets to play
    int size;      // Number of sets in array
} Score;

void addChord(Wave * mySound, Chord chord, long nSamples);
void addScore(Wave * mySound, Score score);
void generateWav(Score score);

int playSound( char *filename );

// Score is an array of Sets
long getTotalDuration(Score score);
// time in ms
long getSampleNumber(long miliseconds);

#endif /* _SOUND_H_ */