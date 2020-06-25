#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typeUtil.h"
#include "outPrinter.h"

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
    if (chord == NULL) yyerror("Not enough heap memory");

    /* chord->notes = malloc(sizeof(struct NoteNode));
    if (chord->notes == NULL) {
        free(chord);
        yyerror("Not enough heap memory");
    } */

    struct NoteNode * node = (struct NoteNode *) malloc(sizeof(struct NoteNode));
    if (node == NULL) yyerror("Not enough heap memory");
    node->note = chordsNotes[stdChord][0];
    chord->notes = node;
    for (int i = 1; i < STD_CHORD_L; i++) {
        node->next = (struct NoteNode *) malloc(sizeof(struct NoteNode));
        if (node->next == NULL) yyerror("Not enough heap memory");
        node->next->note = chordsNotes[stdChord][i];
        node = node->next;
    }
    node->next = NULL;    // o calloc
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
    if (chord == NULL) yyerror("Not enough heap memory");

    chord->notes = malloc(sizeof(struct NoteNode));
    if (chord->notes == NULL) {
        free(chord);
        yyerror("Not enough heap memory");
    }
    chord->notes->note = note;
    chord->notes->next = NULL;
    chord->quant = 1;
    return chord;
}

void print_chord(struct chord * chord) {
    if (chord == NULL || chord->notes == NULL) 
        yyerror("NULL pointer exception on chord or note");
    puts("\nChord: ");
    struct NoteNode * node = chord->notes;
    for (int i = 0; i < chord->quant; i++){
        printf("\tNota %d: %d\n", i, node->note);
        node = node->next;
    }
}

void print_chord_data(Data chord){
    print_chord(chord.value);
}

void init_list(){
    list = (List *) malloc(sizeof(struct list));
    list->header = NULL;
    list->tail = NULL;
    printf("Preparing our band...\n");
    // printf("Preparing our band...\nList: %d\t\tHeader: %d\tTail: %d\n", list, list->header, list->tail);
}

void createVar(types type, char * name){
    if(getVarByName(name) != NULL)
        yyerror("Variable named %s already exists.", name);
   // printf("Creating varible:  %s -> %s", getTypeByEnum(type), name);
    struct Node * node = (struct Node *) malloc(sizeof(struct Node));
    if(node == NULL) yyerror("Not enough heap memory");

    node->var = (struct var *) malloc(sizeof(struct var));
    if(node->var == NULL) yyerror("Not enough heap memory");
    node->var->data.type = type;
    node->var->data.value = NULL;
    node->next = NULL;

    node->var->name = (char *) malloc(sizeof(name));
    if(node->var->name == NULL) yyerror("Not enough heap memory");
    strcpy(node->var->name, name);

    if(list->header == NULL){
        list->header = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node; 
    }
    printCreateVar(type, name);
    
    // printf("\tDone!\n\n");

    /* while (node->next != NULL)      // hasta encontrar que el siguiente esta vacio
    node = node->next;
    Node * new = malloc(sizeof(struct Node *));
    new->var->data.type = type;
    strcpy(new->var->name, name);
    node->next = new; */
}

void putVar (size_t size, Var * variable, void * value){
    variable->data.value = malloc(size);
    if(variable->data.value == NULL)
        yyerror("Not enough heap memory");

    memcpy(variable->data.value, value, size);
}

void newVar (char * name, Data data){
    switch (data.type)
    {
        case num_type:
            putInt(name, (int *)data.value);
            break;
        case chord_type:
            putChord(name, (Chord *)data.value);
            break;
        case set_type:
            putSet(name, (Set *)data.value);
            break;
        default:
            yyerror("Undefined type of variable");
            break;
    }
    printPutVar(name, data);
}

void putInt(char * name, int * value){
    Var * variable = getVarByName(name);
    if(variable == NULL)
        yyerror("Variable '%s' doesn't exist", name);
    if(variable->data.type != num_type)
        yyerror("You are trying to assign %s to a %s variable", getTypeByEnum(variable->data.type), getTypeByEnum(num_type));
    putVar(sizeof(*value), variable, (void *) value);
}

void putChord(char * name, Chord * value){
    Var * variable = getVarByName(name);
    if(variable == NULL)
        yyerror("Variable '%s' doesn't exist", name);
    if(variable->data.type != chord_type)
        yyerror("You are trying to assign %s to a %s variable", getTypeByEnum(variable->data.type), getTypeByEnum(chord_type));
    putVar(sizeof(*value), variable, (void *) value);
}

void putSet(char * name, Set * value){
    Var * variable = getVarByName(name);
    if(variable == NULL)
        yyerror("Variable '%s' doesn't exist", name);
    if(variable->data.type != set_type)
        yyerror("You are trying to assign %s to a %s variable", getTypeByEnum(variable->data.type), getTypeByEnum(set_type));
    putVar(sizeof(* value), variable, (void *) value);
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
        yyerror("Variable '%s' undefined", name);
    }
    if(var->data.value == NULL){
        yyerror("Variable '%s' may not be initialized", name);
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

void print_number(int* num){
    printf("EL NUMERO ES %d", *num);
}

void addNote(Chord * chord, notes_enum note){
    /* struct NoteNode * node = chord->notes;
    while (node->next != NULL)
        node = node->next;
    struct NoteNode * new = (struct NoteNote *) malloc(sizeof(struct NoteNode));
    if(new == NULL) yyerror("Not enough heap memory");
    new->note = note;
    new->next = NULL;
    node->next = new;
    return; */
    struct NoteNode * node = chord->notes;
    struct NoteNode * new = (struct NoteNote *) malloc(sizeof(struct NoteNode));
    if(new == NULL) yyerror("Not enough heap memory");
    new->note = note;
    new->next = node;
    chord->notes = new;
    chord->quant++;
    return;
}

void deleteNote(Chord * chord, notes_enum note){
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

int containsNote(Chord * chord, notes_enum note){
    struct NoteNode * node = chord->notes;
    while(node != NULL){
        if(node->note == note)
            return 1;
        node = node->next;
    } 
    return 0;
}

Data addOperation(Data first, Data second){
    Data out;
    if(first.type == num_type && second.type == num_type){
        out.type = num_type;
        int result =  *((int *)(first.value)) + *((int *)(second.value));     // violacion de segmento aca
        out.value = malloc(sizeof(int *));
        *((int *) out.value) = result;
        printf("Result is %d", result);
        
        return out;
    }
    if(first.type == chord_type && second.type == chord_type){
        Chord * chord_one = (Chord *) first.value;
        Chord * chord_two = (Chord *) second.value;
        
        struct NoteNode * node = chord_two->notes;
        while(node != NULL){
            if(!containsNote(chord_one, node->note)){
                addNote(chord_one, node->note);
                // printf("NOT CONTAINS %d -> chord_one: ", node->note); 
            }
            node = node->next;
        }
        out.type = chord_type;
        out.value = chord_one;
        print_chord_data(out);

        return out;
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
        printf("Result is %d", result);

        return out;
    }
    if(first.type == chord_type && second.type == chord_type){
        Chord * chord_one = (Chord *) first.value;
        Chord * chord_two = (Chord *) second.value;
        
        struct NoteNode * node = chord_two->notes;
        while(node != NULL){
            if(containsNote(chord_one, node->note))
                deleteNote(chord_one, node->note);
            node = node->next;
        }
        out.type = chord_type;
        out.value = chord_one;
        print_chord_data(out);

        return out;
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
        printf("Result is %d", result);

        return out;
    }
    if(first.type == set_type && second.type == set_type){
        Set set_one = *((Set *) first.value);
        Set set_two = *((Set *) second.value);
        int new_quant = set_one.quant + set_two.quant;

        for(int i = set_one.quant, j = 0; i < new_quant; i++, j++)
            set_one.blocks[i] = set_two.blocks[j];

        out.type = set_type;
        out.value = malloc(sizeof(struct set));
        ((Set *)out.value)->quant = new_quant;
        ((Set *)out.value)->blocks = set_one.blocks;
        
        print_set(out);

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
        printf("Result is %d", result);

        return out;
    }
    if(first.type == set_type && second.type == num_type){
        int repeat = *((int *)second.value);

        Set set_old = *((Set *) first.value);
        int old_quant = set_old.quant;
        int new_quant = set_old.quant * repeat;
        
        Block * block_old = set_old.blocks;
        Block * block_new = malloc(sizeof(struct block)*new_quant);

        int i = 0, b_index = 0, j = 0;
        // printf("Repeat: %d \t Old Q: %d\n\n", repeat, old_quant);
        for(i; i < repeat; i++){
            for(j = 0; j < old_quant; j++){
                // printf("\nblock_new[%d] = block_old[%d]\n", b_index, j);
                block_new[b_index++] = block_old[j];              // luego en block_new tengo block_old repeat veces
            }
        }
        out.type = set_type;
        out.value = (Set *) malloc(sizeof(struct set));
        ((Set *)out.value)->quant = new_quant;
        ((Set *)out.value)->blocks = block_new;
        
        print_set(out);

        return out;
    }
    yyerror("Incompatible types. Can't operate (%s value) * (%s value)", getTypeByEnum(first.type), getTypeByEnum(second.type));
}

char * getTypeByEnum(types type){
    switch (type)
    {
        case num_type:   return "int";
            break;
        case chord_type: return "chord"; 
            break;
        case set_type:   return "set";
            break;
        default:
            break;
    }
    return "unknown";
}

Data newSetData(Data chord, Data time){
    // puts("new data set");
    Set * set = newSet(chord, time);
    Data data = {set_type, set};
    return data;
}

Set * newSet(Data chord, Data time){
    if(chord.type != chord_type || time.type != num_type)
        yyerror("You are creating a new set with incorrect variable types");
    Set * set = (Set *) malloc(sizeof(struct set));
    Block * block = (Block *) malloc(sizeof(struct block));
    block->chords = ((Chord *)chord.value);
    block->time = *((int*)time.value);
    set->blocks = block;
    set->quant = 1;
    return set;
}

void print_set(Data set){
    Set * realSet = (Set *)set.value;
    puts("---------------------------");
    printf("Set con:");
    for(int i=0; i < realSet->quant; i++){
        print_chord(realSet->blocks[i].chords);
        printf(" << durante %d segundos >>\n", realSet->blocks[i].time);
    }
    puts("---------------------------");
}


/* 
struct NoteNode{
  notes_enum note;
  struct NoteNode * next;
};

typedef struct chord{
  struct NoteNode * notes;
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