#ifdef __linux__
    #define SOUND_COMMAND  "aplay -c 1 -q -t wav"
#endif

#ifdef __APPLE__	
    #define SOUND_COMMAND  "afplay"
#endif

#ifndef _SOUND_SET_H_
#define _SOUND_SET_H_

#include "translator.h"
#include "wave.h"

#define WAV_FILE_NAME   "output.wav"

#define SAMPLE_RATE     96000.0 // hertz
#define MONO            1
#define STEREO          2
#define CHANNEL_NUM     MONO
#define BITS_SAMPLE     16      // 8, 16 or 32


void generateWav(Set set, char * name);

int playWav( char *filename );


#endif