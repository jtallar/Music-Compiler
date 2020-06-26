#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typeUtil.h"
#include "outPrinter.h"
#include "soundSet.h"


static int avg_freq(Chord * chord);
static int total_time(Set * set);

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
    printf("El numero es %d\n", *num);
}

void print_boolean(int* num){
    printf("--> %s\n", *num==1?"true":"false");
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
        int result =  *((int *)(first.value)) + *((int *)(second.value));
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
        for(i=0; i < repeat; i++){
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
        printf(" << durante %d milisegundos >>\n", realSet->blocks[i].time);
    }
    puts("---------------------------");
}

Data condition_composed(Data first, conditions cond, Data second){
    // printf("\nRecibo %d %d %d\n", *((int*)first.value), cond, *((int*)second.value));
    Data out;
    out.type = bool_type;
    out.value = malloc(sizeof(int *));
    switch (cond){
        case and: /* if(first.type != bool_type || second.type != bool_type)
                        yyerror("Incompatible types. Can't operate '(%s value) and (%s value)'", getTypeByEnum(first.type), getTypeByEnum(second.type)); */
                //   printf("Estoy evaluando %d and %d", *((int*)first.value), *((int*)second.value) );
                  *((int *) out.value) = (make_comparable(first) && make_comparable(second) ) ? 1:0;  
                //   *((int *) out.value) = (*((int*)first.value) && *((int*)second.value) ) ? 1:0;
                  return out;
                  break;
        case or:  /* if(first.type != bool_type || second.type != bool_type) */
                        // yyerror("Incompatible types. Can't operate '(%s value) or (%s value)'", getTypeByEnum(first.type), getTypeByEnum(second.type));
                  *((int *) out.value) = (make_comparable(first) || make_comparable(second) ) ? 1:0;  
                //   *((int *) out.value) = (*((int*)first.value) || *((int*)second.value) ) ? 1:0;
                  return out;
                  break;
        case gt:  /* printf("Estoy comparando %d > %d", make_comparable(first), make_comparable(second)); */
                  *((int *) out.value) = (make_comparable(first) > make_comparable(second))?1:0;
                  return out;
                  break;
        case gte: *((int *) out.value) = (make_comparable(first) >= make_comparable(second))?1:0;
                  return out;
                  break;
        case lt:  *((int *) out.value) = (make_comparable(first) < make_comparable(second))?1:0;
                  return out;
                  break;
        case lte: *((int *) out.value) = (make_comparable(first) <= make_comparable(second))?1:0;
                  return out;
                  break;
        case eq:  *((int *) out.value) = (make_comparable(first) == make_comparable(second))?1:0;
                  return out;
                  break;
        case neq: *((int *) out.value) = (make_comparable(first) != make_comparable(second))?1:0;
                  return out;
                  break;
        default:  free(out.value);
                  yyerror("Invalid binary logic operator.[Allowed: and or <= < > >= == != ]");
                  break;
    }
}

Data negate_condition(Data condition){
    Data out;
    out.type = bool_type;
    out.value = malloc(sizeof(int *));
    if(condition.type != bool_type){
        *((int *) out.value) = make_comparable(condition);
        return out;
    }
        // yyerror("Invalid parameter for condition. Cannot negate %s value", getTypeByEnum(condition.type));
    *((int *) out.value) = *((int*)condition.value) > 0 ? 0 : 1;
    return out;
}    

/* Data condition_expression(Data expression){
    Data out;
    out.type = bool_type;
    out.value = malloc(sizeof(int *));
    *((int *) out.value) = (expression.value != NULL);
    return out;
} */

int make_comparable(Data data){
    if(data.value == NULL) return 0;
    switch (data.type){
        case bool_type:
        case num_type:      
                return *((int*)data.value);
                break;
        case chord_type: 
                return avg_freq((Chord *)data.value);
                break;
        case set_type:
                return total_time((Set *) data.value);
                break;
        default:
            yyerror("Invalid comparable type");
            break;
    }
}

Data data_boolean(Data data){
    Data out;
    out.type = bool_type;
    out.value = malloc(sizeof(int *));
    switch (data.type){
        case bool_type:
        case num_type:      
                *((int *) out.value) = *((int*)data.value);
                break;
        case chord_type: 
                *((int *) out.value) = avg_freq((Chord *)data.value);
                break;
        case set_type:
                *((int *) out.value) = total_time((Set *) data.value);
                break;
        default:
            yyerror("Invalid comparable type");
            break;
    }
    return out;
}

/* RECURSO DE PRUEBA */
float getFreq(notes_enum note){
    float notes[] = { /*C*/ 65.41 * pow(2,3), 69.30* pow(2,3), 73.42* pow(2,3), 77.78* pow(2,3), 82.41* pow(2,3), 87.31* pow(2,3), 92.50* pow(2,3), 98.00* pow(2,3), 103.83* pow(2,3), 110.00* pow(2,3), 116.54* pow(2,3), 123.47* pow(2,3) /*B*/, 0};
    return notes[note];
}

static int avg_freq(Chord * chord){
    float sum_freq = 0;
    int quant = 0;
    struct NoteNode * node = chord->notes;
    while (node != NULL){
        sum_freq += getFreq(node->note);
        quant++;
        node = node->next;
    }
    return sum_freq/quant;
}

static int total_time(Set * set){
    int i,time = 0;
    for (i=0; i < set->quant; i++){
        time += set->blocks[i].time;
    }
    return time;
}


void playSet(Data set){
    if( set.type != set_type ){
        yyerror("\033[1;31mError\033[0m: Can't play %s type",getTypeByEnum(set.type));
    }
    print_set(set);
    Set * realSet = (Set *)set.value;
    generateWav(*realSet);
    playWav(WAV_FILE_NAME);
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