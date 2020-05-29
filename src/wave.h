#ifndef _WAVE_H_
#define _WAVE_H_

typedef struct WaveHeader {
    // Riff Wave Header
    char chunkId[4];
    int  chunkSize;
    char format[4];

    // Format Subchunk
    char subChunk1Id[4];
    int  subChunk1Size;
    short int audioFormat;
    short int numChannels;
    int sampleRate;
    int byteRate;
    short int blockAlign;
    short int bitsPerSample;
    //short int extraParamSize;

    // Data Subchunk
    char subChunk2Id[4];
    int  subChunk2Size;

} WaveHeader;

typedef struct Wave {
    WaveHeader header;
    char* data;
    long long int index;
    long long int size;
    long long int nSamples;
} Wave;

WaveHeader makeWaveHeader(int const sampleRate, short int const numChannels, short int const bitsPerSample);
Wave makeWave(int const sampleRate, short int const numChannels, short int const bitsPerSample);
void waveDestroy( Wave* wave);
void waveSetDuration( Wave* wave, const long miliseconds );
void waveAddSample( Wave* wave, const float* samples );
void waveToFile( Wave* wave, const char* filename );

#endif /* _WAVE_H_ */