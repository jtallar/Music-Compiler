#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typeUtil.h"

Chord * atochord(const char *nptr) {
    int stdChord;
    for (stdChord = aC; stdChord < CHORD_COUNT; stdChord++) {
        if (strcmp(nptr, chordName[stdChord]) == 0) {
            break;
        }
    }
    if (stdChord == CHORD_COUNT) {
        // ERROR --> Que hacemos?
        return NULL;
    }
    
    Chord * chord = malloc(sizeof(*chord));
    if (chord == NULL) {
        // ERROR --> Que hacemos?
        return NULL;
    }
    chord->note = malloc(sizeof(*chord->note) * STD_CHORD_L);
    if (chord->note == NULL) {
        // ERROR --> Que hacemos?
        free(chord);
        return NULL;
    }
    for (int i = 0; i < STD_CHORD_L; i++) {
        chord->note[i] = chordsNotes[stdChord][i];
    }
    chord->quant = STD_CHORD_L;
    return chord;
} 

Chord * atonote(const char *nptr) {
    int note;
    for (note = C; note < NOTE_COUNT; note++) {
        if (strcmp(nptr, noteName[note]) == 0) {
            break;
        }
    }
    if (note == NOTE_COUNT) {
        // ERROR --> Que hacemos?
        return NULL;
    }
    
    Chord * chord = malloc(sizeof(*chord));
    if (chord == NULL) {
        // ERROR --> Que hacemos?
        return NULL;
    }
    chord->note = malloc(sizeof(*chord->note));
    if (chord->note == NULL) {
        // ERROR --> Que hacemos?
        free(chord);
        return NULL;
    }
    chord->note[0] = note;
    chord->quant = 1;
    return chord;
}

void print_chord(struct chord * chord) {
    if (chord == NULL || chord->note == NULL) return;
    puts("\nVino un chord: \n");
    for (int i = 0; i < chord->quant; i++) {
        printf("\nNota %d: %d", i, chord->note[i]);
    }
    printf("\n\n");
}

bool createVar(types type, char * name, void * value){
    
    // averiguar si hay espacio y realloc de ser necesario usando CHUNK

    switch (type)
    {
        case num:
            variables[index]->type = type;
            variables[index]->name = calloc(strlen(name) + 1, sizeof(*name));
            if (variables[index]->name == NULL) {
                // ERROR
                return false;
            }
            strcpy(variables[index]->name, name);

            // el tema de void no me acuerdo un choto btw
            // Estoy viendo el codigo de flor
            // okok. ahora vuelvo
            // variables[index]->value = ;
            break;
        case chord:
            break;
        case set:
            break;
        default:
            break;
    }
    return true;
}

/* falopa no era la idea de la funcion */
struct variables * allocVars(){
    return malloc(sizeof(Var)*CHUNK);
}