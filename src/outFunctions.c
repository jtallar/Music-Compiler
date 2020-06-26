#include <stdlib.h>
#include "outFunctions.h"

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

    struct NoteNode * node = (struct NoteNode *) malloc(sizeof(struct NoteNode));
    if (node == NULL){ 
        exit(1);
    }
    node->note = chordsNotes[stdChord][0];
    chord->notes = node;
    for (int i = 1; i < STD_CHORD_L; i++) {
        node->next = (struct NoteNode *) malloc(sizeof(struct NoteNode));
        if (node->next == NULL) { 
            exit(1);
        }
        node->next->note = chordsNotes[stdChord][i];
        node = node->next;
    }
    node->next = NULL;   
    chord->quant = STD_CHORD_L;
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
    chord->notes = malloc(sizeof(struct NoteNode));
    if (chord->notes == NULL) {
        free(chord);
    }
    chord->notes->note = note;
    chord->notes->next = NULL;
    chord->quant = 1;
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
    block->chords = chord;
    block->time = time;
    new_set->blocks = block;
    new_set->quant = 1;
    return new_set;
}


/******* Funciones que estan en typeUtil.c tal cual********************/

void outAddNote(Chord * chord, notes_enum note){
    struct NoteNode * node = chord->notes;
    struct NoteNode * new = (struct NoteNote *) malloc(sizeof(struct NoteNode));
    if(new == NULL){
        exit(1);
    }
    new->note = note;
    new->next = node;
    chord->notes = new;
    chord->quant++;
    return;
}

void outDeleteNote(Chord * chord, notes_enum note){
    struct NoteNode * node = chord->notes;
    if(node->note == note){
        struct NoteNode * aux = node->next;
        node->next = node->next->next;
        free(aux);
        chord->quant--;
        return;
    }    
    while (node->next != NULL){
        if(node->next->note == note){
            struct NoteNode * aux = node->next;
            node->next = node->next->next;
            free(aux);
            chord->quant--;
            return;
        }
        node = node->next;
    }
    return;
}

int outContainsNote(Chord * chord, notes_enum note){
    struct NoteNode * node = chord->notes;
    while(node != NULL){
        if(node->note == note)
            return 1;
        node = node->next;
    } 
    return 0;
}
/***************************/



Chord * outChordSum(Chord * c1, Chord * c2){

    int q = 0;
    while(q < c2->quant ){
        if(!outContainsNote(c1, c2->notes[q].note)){
            outAddNote(c1, c2->notes[q].note);
        }
        q++;
    }

    //Podria devolver directamente c1 creo, check
    Chord * new_chord = malloc(sizeof(struct chord));
    if(new_chord == NULL){
        exit(1);
    }
    new_chord->notes = c1->notes;
    new_chord->quant = c1->quant;

    return new_chord;
}


Chord * outChordSub(Chord * c1, Chord * c2){
        
    int q = 0;
    while(q < c2->quant){
        if(outContainsNote(c1, c2->notes[q].note))
            outDeleteNote(c1, c2->notes[q].note);
        q++;
    }
    
    //Podria devolver directamente c1 creo, check
    Chord * new_chord = malloc(sizeof(struct chord));
    if(new_chord == NULL){
        exit(1);
    }
    new_chord->notes = c1->notes;
    new_chord->quant = c1->quant;

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
    int new_quant = s1->quant + s2->quant;

    for(int i = s1->quant, j = 0; i < new_quant; i++, j++)
       s1->blocks[i] = s1->blocks[j];


    new_set->quant = new_quant;
    new_set->blocks = s1->blocks;

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
        sum_freq += notes[chord->notes[quant].note]; //vector de frequencias que esta en translator.h
        quant++;
    }
    return (quant == 0) ? 0 : (sum_freq/quant);
}



//igual a typeUtil.c sin validacion
// void outPlaySet(Set * set){
     /** TODO: **/
//     // generateWav(*set);
//     // playWav("output.wav");
// }


