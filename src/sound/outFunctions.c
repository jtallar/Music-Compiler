#include <stdio.h>
#include <stdlib.h>
#define NOTE_COUNT  13
#define CHORD_COUNT 14
#define STD_CHORD_L 3
#define MAX_WAV_COUNT   10
#define BUF_SIZE		255
#ifndef INT_MAX
	#define INT_MAX 	2147483647
#endif

typedef enum { C=0, Cs, D, Ds=3, E, F, Fs=6, G, Gs, A=9, As, B, _ } notes_enum;
typedef enum { aC=0, aCm, aD, aDm=3, aE, aEm, aF=6, aFm, aG, aGm=9, aA, aAm, aB=12, aBm } chords_enum;

static const char * noteName[NOTE_COUNT] = {"C", "Cs", "D", "Ds", "E", "F", "Fs", "G", "Gs", "A", "As", "B", "_"};
static const char * chordName[CHORD_COUNT] = {"aC", "aCm", "aD", "aDm", "aE", "aEm", "aF", "aFm", "aG", "aGm", "aA", "aAm", "aB", "aBm"};

// float notes[] = { /*C*/ 65.41 * pow(2,3), 69.30* pow(2,3), 73.42* pow(2,3), 77.78* pow(2,3), 82.41* pow(2,3), 87.31* pow(2,3), 92.50* pow(2,3), 98.00* pow(2,3), 103.83* pow(2,3), 110.00* pow(2,3), 116.54* pow(2,3), 123.47* pow(2,3) /*B*/};
static const float notes[] = { /*C*/ 65.41 * 8, 69.30* 8, 73.42* 8, 77.78* 8, 82.41* 8, 87.31* 8, 92.50* 8 , 98.00* 8, 103.83* 8, 110.00* 8, 116.54* 8, 123.47* 8 /*B*/ , 0};

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

struct NoteNode{
  notes_enum note;          // Nota del nodo
  struct NoteNode * next;   // Queda en null
};

typedef struct chord{
  struct NoteNode * notes;  // Array de notas
  int quant;                // Cantidad de notas en array
}Chord;

typedef struct block{
  Chord * chords;   // Puntero a un chord (es uno solo)
  int time;         // Duracion del chord apuntado
}Block;

typedef struct set{
  Block * blocks;   // Array de blocks
  int quant;        // Cantidad de blocks
}Set;

#define BASE_FILENAME	"out"
#define EXT_FILENAME	".wav"

static int fileNumber = 0;

Chord * outAtochord(const char *nptr); 
Chord * outAtonote(const char *nptr);
Chord * outNewChord(char * constant);
Set * outNewSet(Chord * chord, int time);
Set * outSetRepeat(Set * set, int times);
Set * outSetConcat(Set * s1, Set * s2);
int outContainsNote(Chord * chord, notes_enum note);
Chord * outChordSum(Chord * c1, Chord * c2);
Chord * outChordSub(Chord * c1, Chord * c2);
int outTotalTime(Set * set);
int outAvgFreq(Chord * chord);
void outPlaySet(Set * set);

Chord * outAtochord(const char *nptr) {
    int stdChord;
    for (stdChord = aC; stdChord < CHORD_COUNT; stdChord++) {
        if (strcmp(nptr, chordName[stdChord]) == 0) {
            break;
        }
    }
    if (stdChord == CHORD_COUNT){
        return NULL;
    }
    
    Chord * chord = malloc(sizeof(*chord));
    if (chord == NULL) { 
        exit(1);
    }

    chord->quant = STD_CHORD_L;
    chord->notes = malloc(sizeof(*chord->notes) * chord->quant);
    if (chord->notes == NULL) {
        free(chord);
        exit(1);
    }
    for (int i = 0; i < chord->quant; i++) {
        chord->notes[i].note = chordsNotes[stdChord][i];
    }
    return chord;
} 

Chord * outAtonote(const char *nptr) {
    int note;
    for (note = C; note < NOTE_COUNT; note++) {
        if (strcmp(nptr, noteName[note]) == 0) {
            break;
        }
    }
    if (note == NOTE_COUNT) {
        return NULL;
    }
    
    Chord * chord = malloc(sizeof(*chord));
    if (chord == NULL) { 
        exit(1);
    }
    
    chord->quant = 1;
    chord->notes = malloc(sizeof(*chord->notes) * chord->quant);
    if (chord->notes == NULL) {
        free(chord);
        exit(1);
    }
    chord->notes[0].note = note;
    return chord;
}

Chord * outNewChord(char * constant){
    Chord * new_chord = outAtonote(constant);
    if(new_chord != NULL){
        return new_chord;
    }
    else {
        new_chord = outAtochord(constant);
    }
    return new_chord;
}

//muy parecida a typeUtil.c
Set * outNewSet(Chord * chord, int time){
    Set * new_set = malloc(sizeof(struct set));
    if(new_set == NULL){        //no habia espacio
        exit(1);
    }
    Block * block = malloc(sizeof(struct block));
    if(block == NULL){        //no habia espacio
        exit(1);
    }
    Chord emptyChord = {NULL, 0};
    block->chords = outChordSum(chord, &emptyChord);
    if (block->chords == NULL) {
        free(block);
        free(new_set);
        exit(1);
    }
    block->time = time;
    new_set->blocks = block;
    new_set->quant = 1;
    return new_set;
}

int outContainsNote(Chord * chord, notes_enum note){
    for (int i = 0; i < chord->quant; i++) {
        if (chord->notes[i].note == note) {
            return 1;
        }
    }
    return 0;
}

Chord * outChordSum(Chord * c1, Chord * c2){
    Chord * new_chord = malloc(sizeof(struct chord));
    if(new_chord == NULL){
        exit(1);
    }
    new_chord->notes = malloc(sizeof(*new_chord->notes) * (c1->quant + c2->quant));
    if (new_chord->notes == NULL) {
        free(new_chord);
        exit(1);
    }

    int index = 0;
    for (index = 0; index < c1->quant; index++) {
        new_chord->notes[index].note = c1->notes[index].note;
    }
    for (int j = 0; j < c2->quant; j++) {
        if (!outContainsNote(c1, c2->notes[j].note)) {
            new_chord->notes[index].note = c2->notes[j].note;
            index++;
        }
    }
    struct NoteNode * aux = new_chord->notes;
    new_chord->notes = realloc(new_chord->notes, sizeof(*new_chord->notes) * index);
    if (new_chord->notes == NULL) {
        free(aux);
        free(new_chord);
        exit(1);
    }
    new_chord->quant = index;

    return new_chord;
}

Chord * outChordSub(Chord * c1, Chord * c2){
    Chord * new_chord = malloc(sizeof(struct chord));
    if(new_chord == NULL){
        exit(1);
    }
    new_chord->notes = malloc(sizeof(*new_chord->notes) * c1->quant);
    if (new_chord->notes == NULL) {
        free(new_chord);
        exit(1);
    }
    int index = 0;
    for (int j = 0; j < c1->quant; j++) {
        if (!outContainsNote(c2, c1->notes[j].note)) {
            new_chord->notes[index].note = c1->notes[j].note;
            index++;
        }
    }
    struct NoteNode * aux = new_chord->notes;
    new_chord->notes = realloc(new_chord->notes, sizeof(*new_chord->notes) * index);
    if (new_chord->notes == NULL) {
        free(aux);
        free(new_chord);
        exit(1);
    }
    new_chord->quant = index;

    return new_chord;
}

Set * outSetRepeat(Set * set, int times){

    int old_quant = set->quant;
    int new_quant = set->quant * times;
    
    Block * old_block = set->blocks;
    Block * new_block = malloc(sizeof(struct block) * new_quant);
    if(new_block == NULL){
        exit(1);
    }

    int i = 0, b_index = 0, j = 0;
    for(i=0; i < times; i++){
        for(j = 0; j < old_quant; j++){
            new_block[b_index++] = old_block[j];
        }
    }

    Set *new_set = malloc(sizeof(struct set));
    if(new_set == NULL){
        free(new_block);
        exit(1);
    }
    new_set->quant = new_quant;
    new_set->blocks = new_block;

    return new_set;

}

Set * outSetConcat(Set * s1, Set * s2){
    Set *new_set = malloc(sizeof(struct set));
    if(new_set == NULL){
        exit(1);
    }
    new_set->quant = s1->quant + s2->quant;
    new_set->blocks = malloc(sizeof(*new_set->blocks) * new_set->quant);
    if (new_set->blocks == NULL) {
        free(new_set);
        exit(1);
    }
    Chord emptyChord = {NULL, 0};

    int index = 0;
    for (index = 0; index < s1->quant; index++) {
        new_set->blocks[index].chords = outChordSum(s1->blocks[index].chords, &emptyChord);
        if (new_set->blocks[index].chords == NULL) {
            free(new_set->blocks);
            free(new_set);
            exit(1);
        }
        new_set->blocks[index].time = s1->blocks[index].time;
    }
    for (int j = 0; j < s2->quant; j++, index++) {
        new_set->blocks[index].chords = outChordSum(s2->blocks[j].chords, &emptyChord);
        if (new_set->blocks[index].chords == NULL) {
            free(new_set->blocks);
            free(new_set);
            exit(1);
        }
        new_set->blocks[index].time = s2->blocks[j].time;
    }

    return new_set;
}

//igual a typeUtil.c
int outTotalTime(Set * set){
    int time = 0;
    for(int i = 0; i < set->quant ; i++) {
        time += set->blocks[i].time;
    }
    return time;
}

//esta quedo parecida a la de typeUtil.c
int outAvgFreq(Chord * chord){
    float sum_freq = 0;
    int quant = 0;
    while (quant < chord->quant){
        sum_freq += notes[chord->notes[quant].note];
        quant++;
    }
    return (quant == 0) ? 0 : (sum_freq/quant);
}

//igual a typeUtil.c sin validacion
void outPlaySet(Set * set){
    generateWav(*set);
    playWav(WAV_FILENAME(fileNumber));
    fileNumber++;
}

void playSet(Set * set){
    char buf[10];
    snprintf(buf, 10, "%s%d%s", BASE_FILENAME, fileNumber, EXT_FILENAME);
    fprintf(stderr," -> \033[1;36mGenerating\033[0m wav %s\n", buf);
    generateWav(*set, buf);
    fprintf(stderr," -> \033[1;36mPlaying\033[0m wav %s\n", buf);
    playWav(buf);
    fileNumber++;
    if(fileNumber >= MAX_WAV_COUNT) {
        fileNumber = 0;
    }
}
    
void printChord(Chord * chord) {
	if (chord == NULL) {
        puts("Empty chord\n");
        return;
	}
    printf("Chord has %d note%s: \n", chord->quant, (chord->quant <= 1) ? "" : "s");
    for (int i = 0; i < chord->quant; i++){
        printf("\t|~ Note %d: %s\n", i + 1, noteName[chord->notes[i].note]);
    }
}

void printSet(Set * set) {
	if (set == NULL) {
        puts("Empty set\n");
        return;
	}
    printf("Set has %d block%s: \n", set->quant, (set->quant <= 1) ? "" : "s");
    for(int i=0; i < set->quant; i++){
    	printf("\t|~ Block %d lasting %d ms: \n", i + 1, set->blocks[i].time);
        for (int j = 0; j < set->blocks[i].chords->quant; j++){
	        printf("\t\t|~ Note %d: %s\n", j + 1, noteName[set->blocks[i].chords->notes[j].note]);
	    }
    }
}

int getNumber(char * buffer) {
	long int aux = strtol(buffer, NULL, 10);
	if (aux > INT_MAX) {
		return INT_MAX;
	}
	return (int) aux;
}