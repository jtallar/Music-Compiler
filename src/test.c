#include <stdio.h>
#include <stdlib.h>
#include "outFunctions.h"

void printHeaders(){
    printf("#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include <math.h>\n\n");
    printf("#define BASE_FILENAME	\"out\"\n#define EXT_FILENAME	\".wav\"\n");
    printf("#define NOTE_COUNT  13\n#define CHORD_COUNT 14\n#define STD_CHORD_L 3\n\n");
    printf("#define M_PI           3.14159265358979323846\n#ifdef __linux__\n    #define SOUND_COMMAND  \"aplay -c 1 -q -t wav\"\n#endif\n#ifdef __APPLE__	\n    #define SOUND_COMMAND  \"afplay\"\n#endif\n");
    printf("#define SAMPLE_RATE     96000.0 // hertz\n#define MONO            1\n#define STEREO          2\n#define CHANNEL_NUM     MONO\n#define BITS_SAMPLE     16      // 8, 16 or 32\n\n");

    printf("\nstatic int fileNumber = 0;\n\n");
    printf("typedef enum { C=0, Cs, D, Ds=3, E, F, Fs=6, G, Gs, A=9, As, B, _ } notes_enum;\ntypedef enum { aC=0, aCm, aD, aDm=3, aE, aEm, aF=6, aFm, aG, aGm=9, aA, aAm, aB=12, aBm } chords_enum;\n\nstatic const char * noteName[NOTE_COUNT] = {\"C\", \"Cs\", \"D\", \"Ds\", \"E\", \"F\", \"Fs\", \"G\", \"Gs\", \"A\", \"As\", \"B\", \"_\"};\nstatic const char * chordName[CHORD_COUNT] = {\"aC\", \"aCm\", \"aD\", \"aDm\", \"aE\", \"aEm\", \"aF\", \"aFm\", \"aG\", \"aGm\", \"aA\", \"aAm\", \"aB\", \"aBm\"};\n\n");
    printf("static const float notes[] = { /*C*/ 65.41 * 8, 69.30* 8, 73.42* 8, 77.78* 8, 82.41* 8, 87.31* 8, 92.50* 8 , 98.00* 8, 103.83* 8, 110.00* 8, 116.54* 8, 123.47* 8 /*B*/ , 0};\n");
    printf("static notes_enum chordsNotes[CHORD_COUNT][STD_CHORD_L] = { {C,E, G}, {C,Ds,G}, {D,Fs,A}, {D,F, A}, {E,Gs,B}, {E,G, B}, {F,A, C}, {F,Gs,C}, {G,B, D}, {G,As,D}, {A,Cs,E}, {A,C, E}, {B,Ds,Fs}, {B,E, G}};\n\n");
    printf("struct NoteNode{\n\tnotes_enum note;\n\tstruct NoteNode * next;\n};\ntypedef struct chord{\n\tstruct NoteNode * notes;\n\tint quant;\n}Chord;\ntypedef struct block{\n\tChord * chords;\n\tint time;\n}Block;\ntypedef struct set{\n\tBlock * blocks;\n\tint quant;\n}Set;\n\n");
    /*Print wave prototipes */
    printf("typedef struct WaveHeader {\n\tchar chunkId[4];\n\tint  chunkSize;\n\tchar format[4];\n\tchar subChunk1Id[4];\n\tint  subChunk1Size;\n\tshort int audioFormat;\n\tshort int numChannels;\n\tint sampleRate;\n\tint byteRate;\n\tshort int blockAlign;\n\tshort int bitsPerSample;\n\tchar subChunk2Id[4];\n\tint  subChunk2Size;\n\t} WaveHeader;\ntypedef struct Wave {\n\tWaveHeader header;\n\tchar* data;\n\tlong long int index;\n\tlong long int size;\n\tlong long int nSamples;\n\t} Wave;\nWaveHeader makeWaveHeader(int const sampleRate, short int const numChannels, short int const bitsPerSample);\nWave makeWave(int const sampleRate, short int const numChannels, short int const bitsPerSample);\nvoid waveDestroy( Wave* wave);\nvoid waveSetDuration( Wave* wave, const long miliseconds );\nvoid waveAddSample( Wave* wave, const float* samples );\nvoid waveToFile( Wave* wave, const char* filename );\n\n");
    /* Print endianness prototipes */
    printf("int isBigEndian();\nvoid reverseEndianness(const long long int size, void* value);\nvoid toBigEndian(const long long int size, void* value);\nvoid toLittleEndian(const long long int size, void* value);\n\n");
    
    printf("Chord * atochord(const char *nptr);\n\
            Chord * atonote(const char *nptr);\n\
            Chord * newChord(char * constant);\n\
            Set * newSet(Chord * chord, int time);\n\
            Set * setRepeat(Set * set, int times);\n\
            Set * setConcat(Set * s1, Set * s2);\n\
            int containsNote(Chord * chord, notes_enum note);\n\
            Chord * chordSum(Chord * c1, Chord * c2);\n\
            Chord * chordSub(Chord * c1, Chord * c2);\n\
            int totalTime(Set * set);\n\
            int avgFreq(Chord * chord);\n\
            void playSet(Set * set);\n");
    printf("void generateWav(Set set, char * name);\n");
    printf("int playWav( char *filename );\n");

}



void printFunctions(){
    // /*Print new chord function */
    // printf("\n\nChord * newChord(char * constant){\n\tChord * new_chord = atonote(constant);\n\tif(new_chord != NULL){\n\t\treturn new_chord;\n\t}\n\telse {\n\t\tnew_chord = atochord(constant);\n\t}\n\treturn new_chord;\n}\n ");
    // /* Print New Set function */
    // printf("\n\nSet * newSet(Chord * chord, int time){\n\tSet * new_set = malloc(sizeof(struct set));\n\tif(new_set == NULL){\n\t\texit(1);\n\t}\n\tBlock * block = malloc(sizeof(struct block));\n\tif(block == NULL){\n\t\texit(1);\n\t}\n\tblock->chords = chord;\n\tblock->time = time;\n\tnew_set->blocks = block;\n\tnew_set->quant = 1;\n\treturn new_set;\n\t}\n");
    // /*Print contains note function */
    // printf("\n\nint containsNote(Chord * chord, notes_enum note){\n\tstruct NoteNode * node = chord->notes;\n\twhile(node != NULL){\n\t\tif(node->note == note)\n\t\t\treturn 1;\n\t\tnode = node->next;\n\t}\n\treturn 0;\n}\n");
    // /* Print avgFreq function */
    // printf("\n\nint avgFreq(Chord * chord){\n\tfloat sum_freq = 0;\n\tint quant = 0;\n\twhile (quant < chord->quant){\n\t\tsum_freq += notes[chord->notes[quant].note];\n\t\tquant++;\n\t}\n\treturn (quant == 0) ? 0 : (sum_freq/quant);\n} \n");
    // /* Print total time function */
    // printf("\n\nint totalTime(Set * set){\n\tint time = 0;\n\tfor(int i = 0; i < set->quant ; i++) {\n\t\ttime += set->blocks[i].time;\n\t}\n\treturn time;\n} \n");
    // /* Print Set Concat function */
    // printf("\n\nSet * setConcat(Set * s1, Set * s2){\n\tSet *new_set = malloc(sizeof(struct set));\n\tif(new_set == NULL){\n\t\texit(1);\n\t}\n\tint new_quant = s1->quant + s2->quant;\n\tfor(int i = s1->quant, j = 0; i < new_quant; i++, j++)\n\t\ts1->blocks[i] = s1->blocks[j];\n\tnew_set->quant = new_quant;\n\tnew_set->blocks = s1->blocks;\n\treturn new_set;\n} \n");
    // /* Print Set Repeat function */
    // printf("\n\nSet * setRepeat(Set * set, int times){\n\tint old_quant = set->quant;\n\tint new_quant = set->quant * times;\n\tBlock * old_block = set->blocks;\n\tBlock * new_block = malloc(sizeof(struct block) * new_quant);\n\tif(new_block == NULL){\n\t\t exit(1);\n\t}\n\tint i = 0, b_index = 0, j = 0;\n\tfor(i=0; i < times; i++){\n\t\tfor(j = 0; j < old_quant; j++){\n\t\t\tnew_block[b_index++] = old_block[j];\n\t\t}\n\t}\n\tSet *new_set = malloc(sizeof(struct set));\n\tif(new_set == NULL){\n\t\texit(1);\n\t}\n\tnew_set->quant = new_quant;\n\tnew_set->blocks = new_block;\n\treturn new_set;\n}\n");
    // /* Print Chord Sub function */
    // printf("\n\n Chord * chordSub(Chord * c1, Chord * c2){\n\tint q = 0;\n\twhile(q < c2->quant){\n\t\tif(containsNote(c1, c2->notes[q].note))\n\t\t\toutDeleteNote(c1, c2->notes[q].note);\n\t\tq++;\n\t}\n\tChord * new_chord = malloc(sizeof(struct chord));\n\tif(new_chord == NULL){\n\t\texit(1);\n\t}\n\tnew_chord->notes = c1->notes;\n\tnew_chord->quant = c1->quant;\n\treturn new_chord;\n}\n");
    // /* Print Chord Sum function */
    // printf("\n\nChord * chordSum(Chord * c1, Chord * c2){\n\tint q = 0;\n\twhile(q < c2->quant ){\n\t\tif(!containsNote(c1, c2->notes[q].note)){\n\t\t\toutAddNote(c1, c2->notes[q].note);\n\t\t}\n\t\tq++;\n\t}\n\tChord * new_chord = malloc(sizeof(struct chord));\n\tif(new_chord == NULL){\n\t\texit(1);\n\t}\n\tnew_chord->notes = c1->notes;\n\tnew_chord->quant = c1->quant;\n\treturn new_chord;\n} \n");
    // /* Print aToChord y aToNote functions */
    // printf("\n\nChord * atochord(const char *nptr){\n\tint stdChord;\n\tfor (stdChord = aC; stdChord < CHORD_COUNT; stdChord++) {\n\t\tif (strcmp(nptr, chordName[stdChord]) == 0) {\n\t\t\tbreak;\n\t\t}\n\t}\n\tif (stdChord == CHORD_COUNT){ \n\t\treturn NULL;\n\t}\n\tChord * chord = malloc(sizeof(*chord));\n\tif (chord == NULL) {\n\t\texit(1);\n\t}\n\tstruct NoteNode * node = (struct NoteNode *) malloc(sizeof(struct NoteNode));\n\tif (node == NULL){\n\t\texit(1);\n\t}\n\tnode->note = chordsNotes[stdChord][0];\n\tchord->notes = node;\n\tfor (int i = 1; i < STD_CHORD_L; i++) {\n\t\tnode->next = (struct NoteNode *) malloc(sizeof(struct NoteNode));\n\t\tif (node->next == NULL) {\n\t\t\texit(1);\n\t\t}\n\t\tnode->next->note = chordsNotes[stdChord][i];\n\t\tnode = node->next;\n\t}\n\tnode->next = NULL;\n\tchord->quant = STD_CHORD_L;\n\treturn chord;\n}\n\n\nChord * atonote(const char *nptr) {\n\tint note;\n\tfor (note = C; note < NOTE_COUNT; note++) {\n\t\t\tif (strcmp(nptr, noteName[note]) == 0) {\n\t\t\t\tbreak;\n\t\t}\n\t}\n\tif (note == NOTE_COUNT) {\n\t\treturn NULL;\n\t}\n\tChord * chord = malloc(sizeof(*chord));\n\tif (chord == NULL) { \n\t\texit(1);\n\t}\n\tchord->notes = malloc(sizeof(struct NoteNode));\n\tif (chord->notes == NULL) {\n\t\tfree(chord);\n\t}\n\tchord->notes->note = note;\n\tchord->notes->next = NULL;\n\tchord->quant = 1;\n\treturn chord;\n}\n");
    // /* Print addNote y deleteNote */
    // printf("\n\nvoid outAddNote(Chord * chord, notes_enum note){\n\tstruct NoteNode * node = chord->notes;\n\tstruct NoteNode * new = malloc(sizeof(struct NoteNode));\n\tif(new == NULL){\n\t\texit(1);\n\t}\n\tnew->note = note;\n\tnew->next = node;\n\tchord->notes = new;\n\tchord->quant++;\n\treturn;\n}\n\n\nvoid outDeleteNote(Chord * chord, notes_enum note){\n\tstruct NoteNode * node = chord->notes;\n\tif(node->note == note){\n\t\tstruct NoteNode * aux = node->next;\n\t\tnode->next = node->next->next;\n\t\tfree(aux);\n\t\tchord->quant--;\n\t\treturn;\n\t}\n\twhile (node->next != NULL){\n\t\tif(node->next->note == note){\n\t\t\tstruct NoteNode * aux = node->next;\n\t\t\tnode->next = node->next->next;\n\t\t\tfree(aux);\n\t\t\tchord->quant--;\n\t\t\treturn;\n\t\t}\n\t\tnode = node->next;\n\t}\n\treturn;\n}\n");
    /* Print playSet function */
    printf("\n\nvoid playSet(Set * set){\n\tchar buf[10];\n\tsnprintf(buf, 10, \"%%s%%d%%s\", BASE_FILENAME, fileNumber, EXT_FILENAME);\n\tgenerateWav(*set, buf);\n\tplayWav(buf);\n\tfileNumber++;\n}\n\n");
    /* Print soundSet.c functions */
    printf("\n\nint playWav( char *filename ) {\n    char command[256];\n    int status;\n    /* create command to execute */\n    sprintf (command, \"%%s %%s\", SOUND_COMMAND, filename);\n\n    /* play sound */\n    status = system( command );\n\n    return status;\n}\n\nvoid addSet (Wave * mySound, Set set);\n\nlong getSampleNumber(long miliseconds) {\n    return (long) ((miliseconds / 1000.0) * SAMPLE_RATE);\n}\n\n");
    printf("\n\nlong getTotalDuration(Set set) {\n    long rta = 0;\n    for (int i = 0; i < set.quant ; i++) {\n        rta += set.blocks[i].time;\n    }\n    return rta;\n}\n\nvoid generateWav(Set set, char * name) {\n    long duration = getTotalDuration(set);\n    long nSamples = getSampleNumber(duration);\n    \n    // Create a mono (1), 16-bit sound and set the duration\n    Wave mySound = makeWave((int)SAMPLE_RATE, CHANNEL_NUM, BITS_SAMPLE);\n    waveSetDuration(&mySound, duration);\n\n    // Add all of the data\n    addSet(&mySound, set);\n\n    // Write it to a file and clean up when done\n    waveToFile(&mySound, name);\n    waveDestroy(&mySound);\n}\n\nvoid resetArray(float * array, int size) {\n    for (int i = 0; i < size; i++) {\n        array[i] = 0.0;\n    }\n}\n\n");
    printf("\n\nvoid addChord(Wave * mySound, Chord * chord, long nSamples) {\n    float multiplier = M_PI * 2.0 / SAMPLE_RATE;\n    float frameData[CHANNEL_NUM];\n    int i, j, k;\n    for(i = 0; i < nSamples; i++){\n        resetArray(frameData, CHANNEL_NUM);\n        for (j = 0; j < chord->quant ; j++) {\n            for (k = 0; k < CHANNEL_NUM; k++) {\n                frameData[k] += sin(notes[chord->notes[j].note] * (float)i * multiplier) / chord->quant;\n            }\n        }\n        waveAddSample(mySound, frameData);\n    }\n}\n\nvoid addSet (Wave * mySound, Set set){\n    for (int i = 0; i < set.quant; i++) {\n        addChord(mySound, set.blocks[i].chords , getSampleNumber(set.blocks[i].time));\n    }\n}\n\n");


    /***** PRINT 2.0 ***/
    printf("Chord * atochord(const char *nptr) {\n\
            int stdChord;\n\
            for (stdChord = aC; stdChord < CHORD_COUNT; stdChord++) {\n\
                if (strcmp(nptr, chordName[stdChord]) == 0) {\n\
                    break;\n\
                }\n\
            }\n\
            if (stdChord == CHORD_COUNT){\n\
                return NULL;\n\
            }\n\
            Chord * chord = malloc(sizeof(*chord));\n\
            if (chord == NULL) { \n\
                exit(1);\n\
            }\n\
            chord->quant = STD_CHORD_L;\n\
            chord->notes = malloc(sizeof(*chord->notes) * chord->quant);\n\
            if (chord->notes == NULL) {\n\
                free(chord);\n\
                exit(1);\n\
            }\n\
            for (int i = 0; i < chord->quant; i++) {\n\
                chord->notes[i].note = chordsNotes[stdChord][i];\n\
            }\n\
            return chord;\n\
        }\n\
        Chord * atonote(const char *nptr) {\n\
            int note;\n\
            for (note = C; note < NOTE_COUNT; note++) {\n\
                if (strcmp(nptr, noteName[note]) == 0) {\n\
                    break;\n\
                }\n\
            }\n\
            if (note == NOTE_COUNT) {\n\
                return NULL;\n\
            }\n\
            Chord * chord = malloc(sizeof(*chord));\n\
            if (chord == NULL) { \n\
                exit(1);\n\
            }\n\
            chord->quant = 1;\n\
            chord->notes = malloc(sizeof(*chord->notes) * chord->quant);\n\
            if (chord->notes == NULL) {\n\
                free(chord);\n\
                exit(1);\n\
            }\n\
            chord->notes[0].note = note;\n\
            return chord;\n\
        }\n\
        Chord * newChord(char * constant){\n\
            Chord * new_chord = atonote(constant);\n\
            if(new_chord != NULL){\n\
                return new_chord;\n\
            }\n\
            else {\n\
                new_chord = atochord(constant);\n\
            }\n\
            return new_chord;\n\
        }\n\
        int containsNote(Chord * chord, notes_enum note){\n\
            for (int i = 0; i < chord->quant; i++) {\n\
                if (chord->notes[i].note == note) {\n\
                    return 1;\n\
                }\n\
            }\n\
            return 0;\n\
        }\n\
        Chord * chordSum(Chord * c1, Chord * c2){\n\
            Chord * new_chord = malloc(sizeof(struct chord));\n\
            if(new_chord == NULL){\n\
                exit(1);\n\
            }\n\
            new_chord->notes = malloc(sizeof(*new_chord->notes) * (c1->quant + c2->quant));\n\
            if (new_chord->notes == NULL) {\n\
                free(new_chord);\n\
                exit(1);\n\
            }\n\
            int index = 0;\n\
            for (index = 0; index < c1->quant; index++) {\n\
                new_chord->notes[index].note = c1->notes[index].note;\n\
            }\n\
            for (int j = 0; j < c2->quant; j++) {\n\
                if (!containsNote(c1, c2->notes[j].note)) {\n\
                    new_chord->notes[index].note = c2->notes[j].note;\n\
                    index++;\n\
                }\n\
            }\n\
            struct NoteNode * aux = new_chord->notes;\n\
            new_chord->notes = realloc(new_chord->notes, sizeof(*new_chord->notes) * index);\n\
            if (new_chord->notes == NULL) {\n\
                free(aux);\n\
                free(new_chord);\n\
                exit(1);\n\
            }\n\
            new_chord->quant = index;\n\
            return new_chord;\n\
        }\n\
        Chord * chordSub(Chord * c1, Chord * c2){\n\
            Chord * new_chord = malloc(sizeof(struct chord));\n\
            if(new_chord == NULL){\n\
                exit(1);\n\
            }\n\
            new_chord->notes = malloc(sizeof(*new_chord->notes) * c1->quant);\n\
            if (new_chord->notes == NULL) {\n\
                free(new_chord);\n\
                exit(1);\n\
            }\n\
            int index = 0;\n\
            for (int j = 0; j < c1->quant; j++) {\n\
                if (!containsNote(c2, c1->notes[j].note)) {\n\
                    new_chord->notes[index].note = c1->notes[j].note;\n\
                    index++;\n\
                }\n\
            }\n\
            struct NoteNode * aux = new_chord->notes;\n\
            new_chord->notes = realloc(new_chord->notes, sizeof(*new_chord->notes) * index);\n\
            if (new_chord->notes == NULL) {\n\
                free(aux);\n\
                free(new_chord);\n\
                exit(1);\n\
            }\n\
            new_chord->quant = index;\n\
            return new_chord;\n\
        }\n\
        Set * setRepeat(Set * set, int times){\n\
            int old_quant = set->quant;\n\
            int new_quant = set->quant * times;\n\
            Block * old_block = set->blocks;\n\
            Block * new_block = malloc(sizeof(struct block) * new_quant);\n\
            if(new_block == NULL){\n\
                exit(1);\n\
            }\n\
            int i = 0, b_index = 0, j = 0;\n\
            for(i=0; i < times; i++){\n\
                for(j = 0; j < old_quant; j++){\n\
                    new_block[b_index++] = old_block[j];\n\
                }\n\
            }\n\
            Set *new_set = malloc(sizeof(struct set));\n\
            if(new_set == NULL){\n\
                free(new_block);\n\
                exit(1);\n\
            }\n\
            new_set->quant = new_quant;\n\
            new_set->blocks = new_block;\n\
            return new_set;\n\
        }\n\
        Set * setConcat(Set * s1, Set * s2){\n\
            Set *new_set = malloc(sizeof(struct set));\n\
            if(new_set == NULL){\n\
                exit(1);\n\
            }\n\
            new_set->quant = s1->quant + s2->quant;\n\
            new_set->blocks = malloc(sizeof(*new_set->blocks) * new_set->quant);\n\
            if (new_set->blocks == NULL) {\n\
                free(new_set);\n\
                exit(1);\n\
            }\n\
            Chord emptyChord = {NULL, 0};\n\
            int index = 0;\n\
            for (index = 0; index < s1->quant; index++) {\n\
                new_set->blocks[index].chords = chordSum(s1->blocks[index].chords, &emptyChord);\n\
                if (new_set->blocks[index].chords == NULL) {\n\
                    free(new_set->blocks);\n\
                    free(new_set);\n\
                    exit(1);\n\
                }\n\
                new_set->blocks[index].time = s1->blocks[index].time;\n\
            }\n\
            for (int j = 0; j < s2->quant; j++, index++) {\n\
                new_set->blocks[index].chords = chordSum(s2->blocks[j].chords, &emptyChord);\n\
                if (new_set->blocks[index].chords == NULL) {\n\
                    free(new_set->blocks);\n\
                    free(new_set);\n\
                    exit(1);\n\
                }\n\
                new_set->blocks[index].time = s2->blocks[j].time;\n\
            }\n\
            return new_set;\n\
        }\n\
        Set * newSet(Chord * chord, int time){\n\
            Set * new_set = malloc(sizeof(struct set));\n\
            if(new_set == NULL){        //no habia espacio\n\
                exit(1);\n\
            }\n\
            Block * block = malloc(sizeof(struct block));\n\
            if(block == NULL){        //no habia espacio\n\
                exit(1);\n\
            }\n\
            Chord emptyChord = {NULL, 0};\n\
            block->chords = chordSum(chord, &emptyChord);\n\
            if (block->chords == NULL) {\n\
                free(block);\n\
                free(new_set);\n\
                exit(1);\n\
            }\n\
            block->time = time;\n\
            new_set->blocks = block;\n\
            new_set->quant = 1;\n\
            return new_set;\n\
        }\n\
        int totalTime(Set * set){\n\
            int time = 0;\n\
            for(int i = 0; i < set->quant ; i++) {\n\
                time += set->blocks[i].time;\n\
            }\n\
            return time;\n\
        }\n\
        int avgFreq(Chord * chord){\n\
            float sum_freq = 0;\n\
            int quant = 0;\n\
            while (quant < chord->quant){\n\
                sum_freq += notes[chord->notes[quant].note];\n\
                quant++;\n\
            }\n\
            return (quant == 0) ? 0 : (sum_freq/quant);\n\
        }\n");
}

void printWaveEndiannessFunctions(){
    /* Wave functions */
    printf("WaveHeader makeWaveHeader(int const sampleRate, short int const numChannels, short int const bitsPerSample ) {\n\
                WaveHeader myHeader;\n\
                myHeader.chunkId[0] = 'R';\n\
                myHeader.chunkId[1] = 'I';\n\
                myHeader.chunkId[2] = 'F';\n\
                myHeader.chunkId[3] = 'F';\n\
                myHeader.format[0] = 'W';\n\
                myHeader.format[1] = 'A';\n\
                myHeader.format[2] = 'V';\n\
                myHeader.format[3] = 'E';\n\
                myHeader.subChunk1Id[0] = 'f';\n\
                myHeader.subChunk1Id[1] = 'm';\n\
                myHeader.subChunk1Id[2] = 't';\n\
                myHeader.subChunk1Id[3] = ' ';\n\
                myHeader.audioFormat = 1;\n\
                myHeader.numChannels = numChannels;\n\
                myHeader.sampleRate = sampleRate; \n\
                myHeader.bitsPerSample = bitsPerSample; \n\
                myHeader.byteRate = myHeader.sampleRate * myHeader.numChannels * myHeader.bitsPerSample / 8;\n\
                myHeader.blockAlign = myHeader.numChannels * myHeader.bitsPerSample/8;\n\
                myHeader.subChunk2Id[0] = 'd';\n\
                myHeader.subChunk2Id[1] = 'a';\n\
                myHeader.subChunk2Id[2] = 't';\n\
                myHeader.subChunk2Id[3] = 'a';\n\
                myHeader.chunkSize = 4+8+16+8+0;\n\
                myHeader.subChunk1Size = 16;\n\
                myHeader.subChunk2Size = 0;\n\
                return myHeader;\n\
            }\n\
            Wave makeWave(int const sampleRate, short int const numChannels, short int const bitsPerSample) {\n\
                Wave myWave;\n\
                myWave.header = makeWaveHeader(sampleRate,numChannels,bitsPerSample);\n\
                return myWave;\n\
            }\n\
            void waveDestroy( Wave* wave) {\n\
                free( wave->data );\n\
            }\n\
            void waveSetDuration( Wave* wave, const long miliseconds ) {\n\
                const float seconds = miliseconds / 1000.0;\n\
                long long int totalBytes = (long long int)(wave->header.byteRate*seconds);\n\
                wave->data = (char*)malloc(totalBytes);\n\
                wave->index = 0;\n\
                wave->size = totalBytes;\n\
                wave->nSamples = (long long int) wave->header.numChannels * wave->header.sampleRate * seconds;\n\
                wave->header.chunkSize = 4+8+16+8+totalBytes;\n\
                wave->header.subChunk2Size = totalBytes;\n\
            }\n\
            void waveAddSample( Wave* wave, const float* samples ){\n\
                int i;\n\
                short int sample8bit;\n\
                int sample16bit;\n\
                long int sample32bit;\n\
                char* sample;\n\
                if( wave->header.bitsPerSample == 8 ){\n\
                    for( i=0; i<wave->header.numChannels; i+= 1){\n\
                        sample8bit = (short int) (127+127.0*samples[i]);\n\
                        toLittleEndian(1, (void*) &sample8bit);\n\
                        sample = (char*)&sample8bit;\n\
                        (wave->data)[ wave->index ] = sample[0];\n\
                        wave->index += 1;\n\
                    }\n\
                }\n\
                if( wave->header.bitsPerSample == 16 ){\n\
                    for( i=0; i<wave->header.numChannels; i+= 1){\n\
                        sample16bit = (int) (32767.0*samples[i]);\n\
                        toLittleEndian(2, (void*) &sample16bit);\n\
                        sample = (char*)&sample16bit;\n\
                        wave->data[ wave->index + 0 ] = sample[0];\n\
                        wave->data[ wave->index + 1 ] = sample[1];\n\
                        wave->index += 2;\n\
                    }\n\
                }\n\
                if( wave->header.bitsPerSample == 32 ){\n\
                    for( i=0; i<wave->header.numChannels; i+= 1){\n\
                        sample32bit = (long int) ((pow(2,32-1)-1)*samples[i]);\n\
                        toLittleEndian(4, (void*) &sample32bit);\n\
                        sample = (char*)&sample32bit;\n\
                        wave->data[ wave->index + 0 ] = sample[0];\n\
                        wave->data[ wave->index + 1 ] = sample[1];\n\
                        wave->data[ wave->index + 2 ] = sample[2];\n\
                        wave->data[ wave->index + 3 ] = sample[3];\n\
                        wave->index += 4;\n\
                    }\n\
                }\n\
            }\n\
            void waveToFile( Wave* wave, const char* filename ){\n\
                toLittleEndian(sizeof(int), (void*)&(wave->header.chunkSize));\n\
                toLittleEndian(sizeof(int), (void*)&(wave->header.subChunk1Size));\n\
                toLittleEndian(sizeof(short int), (void*)&(wave->header.audioFormat));\n\
                toLittleEndian(sizeof(short int), (void*)&(wave->header.numChannels));\n\
                toLittleEndian(sizeof(int), (void*)&(wave->header.sampleRate));\n\
                toLittleEndian(sizeof(int), (void*)&(wave->header.byteRate));\n\
                toLittleEndian(sizeof(short int), (void*)&(wave->header.blockAlign));\n\
                toLittleEndian(sizeof(short int), (void*)&(wave->header.bitsPerSample));\n\
                toLittleEndian(sizeof(int), (void*)&(wave->header.subChunk2Size));\n\
                FILE *file;\n\
                file = fopen(filename, \"wb\");\n\
                fwrite( &(wave->header), sizeof(WaveHeader), 1, file );\n\
                fwrite( (void*)(wave->data), sizeof(char), wave->size, file );\n\
                fclose( file );\n\
                toLittleEndian(sizeof(int), (void*)&(wave->header.chunkSize));\n\
                toLittleEndian(sizeof(int), (void*)&(wave->header.subChunk1Size));\n\
                toLittleEndian(sizeof(short int), (void*)&(wave->header.audioFormat));\n\
                toLittleEndian(sizeof(short int), (void*)&(wave->header.numChannels));\n\
                toLittleEndian(sizeof(int), (void*)&(wave->header.sampleRate));\n\
                toLittleEndian(sizeof(int), (void*)&(wave->header.byteRate));\n\
                toLittleEndian(sizeof(short int), (void*)&(wave->header.blockAlign));\n\
                toLittleEndian(sizeof(short int), (void*)&(wave->header.bitsPerSample));\n\
                toLittleEndian(sizeof(int), (void*)&(wave->header.subChunk2Size));\n\
            }\n");
        /* Endianness functions */
        printf("int isBigEndian() {\n\
                    int test = 1;\n\
                    char *p = (char*)&test;\n\
                    return p[0] == 0;\n\
                }\n\
                void reverseEndianness(const long long int size, void* value) {\n\
                    int i;\n\
                    char result[32];\n\
                    for( i=0; i<size; i+=1 ){\n\
                        result[i] = ((char*)value)[size-i-1];\n\
                    }\n\
                    for( i=0; i<size; i+=1 ){\n\
                        ((char*)value)[i] = result[i];\n\
                    }\n\
                }\n\
                void toBigEndian(const long long int size, void* value) {\n\
                    char needsFix = !( (1 && isBigEndian()) || (0 && !isBigEndian()) );\n\
                    if( needsFix ){\n\
                        reverseEndianness(size,value);\n\
                    }\n\
                }\n\
                void toLittleEndian(const long long int size, void* value) {\n\
                    char needsFix = !( (0 && isBigEndian()) || (1 && !isBigEndian()) );\n\
                    if( needsFix ){\n\
                        reverseEndianness(size,value);\n\
                    }\n\
                }\n");
}

void print_chord2(Chord * chord) {
    if (chord == NULL || chord->notes == NULL){
        printf("ERROR");
        return;
    }
    puts("\nChord: ");
    printf("c quant: %d", chord->quant);
    struct NoteNode * node = chord->notes;
    for (int i = 0; i < chord->quant; i++){
        printf("\tNota %d: %d\n", i, node->note);
        node = node->next;
    }
}

void print_set2(Set * realSet){
    puts("---------------------------");
    printf("Set con:");
    printf("%d \n",realSet->quant);
    for(int i=0; i < realSet->quant; i++){
        printf("i: %d \n",i);
        print_chord2(realSet->blocks[i].chords);
        printf(" << durante %d milisegundos >>\n", realSet->blocks[i].time);
    }
    puts("---------------------------");
}




int main(){
    printHeaders();
    printFunctions();
    printf("\n\n\nint main(int argc, char** argv){\n");
}


