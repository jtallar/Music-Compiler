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
    puts("\nVino un chord: ");
    for (int i = 0; i < chord->quant; i++) {
        printf("\nNota %d: %d", i, chord->note[i]);
    }
    printf("\n");
}

void init_list(){
    list = (List *) malloc(sizeof(struct list));
    list->header = NULL;
    list->tail = NULL;
    printf("Preparing our band...\n");
    // printf("Preparing our band...\nList: %d\t\tHeader: %d\tTail: %d\n", list, list->header, list->tail);
}

bool createVar(types type, char * name){
    if(getVarByName(name) != NULL){
        printf("ERROR. Variable with that name already exists.\n\n");
        return false;
    }
    printf("Creating varible:  %s -> %s", type==0?"int":"chord", name);
    struct Node * node = (struct Node *) malloc(sizeof(struct Node));
    if(node == NULL) return false;

    if(list->header == NULL){
        node->var = (struct Var *) malloc(sizeof(struct Var));
        if(node->var == NULL) return false;
        if(node == NULL) return false;
        node->var->type = type;
        node->var->name = (char *) malloc(sizeof(name));
        if(node->var->name == NULL) return false;
        strcpy(node->var->name, name);
        list->header = node;
        list->tail = node;
        printf("Done!\n\n");
        return true;
    }

    node->var = (struct Var *) malloc(sizeof(struct Var));
    if(node->var == NULL) return false;
    node->var->type = type;
    node->next = NULL;

    node->var->name = (char *) malloc(sizeof(name));
    if(node->var->name == NULL) return false;
    strcpy(node->var->name, name);
    
    list->tail->next = node;
    list->tail = node;  
    
    printf("Done!\n\n");

    return true;

    /* while (node->next != NULL)      // hasta encontrar que el siguiente esta vacio
    node = node->next;
    Node * new = malloc(sizeof(struct Node *));
    new->var->type = type;
    strcpy(new->var->name, name);
    node->next = new; */
}

bool putInt(char * name, int * value){
    Var * variable = getVarByName(name);
    if(variable == NULL || variable->type != num)
        return false;
    return putVar(sizeof(*value), variable, (void *) value);
}

bool putChord(char * name, Chord * value){
    Var * variable = getVarByName(name);
    if(variable == NULL || variable->type != chord)
        return false;
    return putVar(sizeof(*value), variable, (void *) value);
}

bool putSet(char * name, Set * value){
    Var * variable = getVarByName(name);
    if(variable == NULL || variable->type != set)
        return false;
    return putVar(sizeof(*value), variable, (void *) value);
}

Var * getVarByName(char * name){
    struct Node * node = list->header;
    while(node != NULL){
        if(strcmp(node->var->name, name) == 0)
            return node->var;
        node = node->next;
    }
    return NULL;
}

bool putVar (unsigned long size, Var * variable, void * value){
    variable->value = malloc(size);
    if(variable->value == NULL)
        return false;
    memcpy(variable->value, value, size);
    return true;
}
