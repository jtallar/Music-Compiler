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
    puts("\n");
}

void init_list(){
    list = (List *) malloc(sizeof(struct list));
    list->header = NULL;
    list->tail = NULL;
    printf("Preparing our band...\n");
    // printf("Preparing our band...\nList: %d\t\tHeader: %d\tTail: %d\n", list, list->header, list->tail);
}

bool createVar(types type, char * name){
    if(getVarByName(name) != NULL)
        yyerror("Variable named %s already exists.", name);
    printf("Creating varible:  %s -> %s", getTypeByEnum(type), name);
    struct Node * node = (struct Node *) malloc(sizeof(struct Node));
    if(node == NULL) return false;

    if(list->header == NULL){
        node->var = (struct var *) malloc(sizeof(struct var));
        if(node->var == NULL) return false;
        if(node == NULL) return false;
        node->var->data.type = type;
        node->var->name = (char *) malloc(sizeof(name));
        if(node->var->name == NULL) return false;
        strcpy(node->var->name, name);
        list->header = node;
        list->tail = node;
        printf("\nDone!\n\n");
        return true;
    }

    node->var = (struct var *) malloc(sizeof(struct var));
    if(node->var == NULL) return false;
    node->var->data.type = type;
    node->next = NULL;

    node->var->name = (char *) malloc(sizeof(name));
    if(node->var->name == NULL) return false;
    strcpy(node->var->name, name);
    
    list->tail->next = node;
    list->tail = node;  
    
    printf("\nDone!\n\n");

    return true;

    /* while (node->next != NULL)      // hasta encontrar que el siguiente esta vacio
    node = node->next;
    Node * new = malloc(sizeof(struct Node *));
    new->var->data.type = type;
    strcpy(new->var->name, name);
    node->next = new; */
}

bool putInt(char * name, int * value){
    Var * variable = getVarByName(name);
    if(variable == NULL || variable->data.type != num_type)
        return false;
    return putVar(sizeof(*value), variable, (void *) value);
}

bool putChord(char * name, Chord * value){
    Var * variable = getVarByName(name);
    if(variable == NULL || variable->data.type != chord_type)
        return false;
    return putVar(sizeof(*value), variable, (void *) value);
}

bool putSet(char * name, Set * value){
    Var * variable = getVarByName(name);
    if(variable == NULL || variable->data.type != set_type)
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

Data getDataByName(char * name){
    Var * var = getVarByName(name);
    if(var == NULL){
        yyerror("Variable %s undefined", name);
        exit(EXIT_FAILURE); 
    }
    return var->data;
}

Data getChordData(Chord * chord ){
    Data data = { chord_type, chord };
    return data;
}

Data getIntData(int * num){
    Data data = { num_type, num };
    return data;
}

Data addOperation(Data first, Data second){
    Data out;
    if(first.type == num_type && second.type == num_type){
        out.type = num_type;
        int result =  *((int *) first.value) + *((int *) second.value);
        out.value = malloc(sizeof(int *));
        *((int *) out.value) = result;
        return out;
    }
    if(first.type == chord_type && second.type == chord_type){
        
    }
    yyerror("Incompatible types. Can't operate %s value + %s value", getTypeByEnum(first.type), getTypeByEnum(second.type));
}

Data minusOperation(Data first, Data second){
    Data out;
    if(first.type == num_type && second.type == num_type){
        out.type = num_type;
        int result =  *((int *) first.value) - *((int *) second.value);
        out.value = malloc(sizeof(int *));
        *((int *) out.value) = result;
        return out;
    }
    if(first.type == chord_type && second.type == chord_type){
        
    }
    yyerror("Incompatible types. Can't operate %s value - %s value", getTypeByEnum(first.type), getTypeByEnum(second.type));
}

Data barOperation(Data first, Data second){
    Data out;
    if(first.type == num_type && second.type == num_type){
        out.type = num_type;
        int result =  *((int *) first.value) / *((int *) second.value);
        out.value = malloc(sizeof(int *));
        *((int *) out.value) = result;
        return out;
    }
    if(first.type == set_type && second.type == set_type){
        Set set_one = *((Set *) first.value);
        Set set_two = *((Set *) second.value);
        int new_quant = set_one.quant + set_two.quant;

        for(int i = set_one.quant, j = 0; i < new_quant; i++, j++)
            set_one.blocks[i] = set_two.blocks[j];

        out.type = set_type;
        out.value = malloc(sizeof(Set *));
        ((Set *)out.value)->quant = new_quant;
        ((Set *)out.value)->blocks = set_one.blocks;
        
        return out;
    }
    yyerror("Incompatible types. Can't operate %s value / %s value", getTypeByEnum(first.type), getTypeByEnum(second.type));
}

Data starOperation(Data first, Data second){
    Data out;
    if(first.type == num_type && second.type == num_type){
        out.type = num_type;
        int result =  *((int *) first.value) * *((int *) second.value);
        out.value = malloc(sizeof(int *));
        *((int *) out.value) = result;

        return out;
    }
    if(first.type == set_type && second.type == num_type){
        int repeat = *((int *)second.value);
        Set set_old = *((Set *) first.value);
        int old_quant = set_old.quant;
        int new_quant = set_old.quant * repeat;
        
        Block * block_old = set_old.blocks;
        Block * block_new = malloc(sizeof(struct block));

        for(int i = 0, j, index = 0; i < repeat; i++)
            for(j = 0; j < old_quant; j++)
                block_new[index++] = block_old[j];              // luego en block_new tengo block_old repeat veces

        out.type = set_type;
        out.value = malloc(sizeof(Set *));
        ((Set *)out.value)->quant = new_quant;
        ((Set *)out.value)->blocks = block_new;
        
        return out;
    }
    yyerror("Incompatible types. Can't operate %s value * %s value", getTypeByEnum(first.type), getTypeByEnum(second.type));
}


/* 
typedef struct chord{
  notes_enum * note;
  int quant;
}Chord;

typedef struct set{
  Block * blocks;
  int quant;
}Set; 

typedef struct block{
  Chord * chords;
  int time;
}Block;

typedef struct data{
  types type;
  void * value;
}Data;

*/

char * getTypeByEnum(types type){
    switch (type)
    {
        case num_type:   return "int";
            break;
        case chord_type: return "chord"; 
            break;
        case set_type:   return "set";
            break;
        default:         return "unknown";
            break;
    }
    return "unknown";
}

Data newSetData(Data chord, Data time){
    Set * set = newSet(chord, time);
    Data data = {set_type, set};
    return data;
}

Set * newSet(Data chord, Data time){

    if(chord.type != chord_type || time.type != num_type) {
        // yyerror
        return NULL;
    }
    Set * set = malloc(sizeof(struct set));
    Block * block = malloc(sizeof(struct block));
    block->chords = ((Chord *)chord.value);
    block->time = *((int*)time.value);
    set->blocks[0] = *block;
    set->quant = 1;

    return set;
}

bool putVar (unsigned long size, Var * variable, void * value){
    variable->data.value = malloc(size);
    if(variable->data.value == NULL)
        return false;
    memcpy(variable->data.value, value, size);
    return true;
}
