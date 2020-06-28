#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typeUtil.h"
#include "outPrinter.h"
// #include "soundSet.h"

static int make_comparable(Data * data);
static int avg_freq(Chord * chord);
static int total_time(Set * set);

Chord * atochord(const char *nptr) {
    int stdChord;
    for (stdChord = aC; stdChord < CHORD_COUNT; stdChord++) {
        if (strcmp(nptr, chordName[stdChord]) == 0) {
            break;
        }
    }
    if (stdChord == CHORD_COUNT) yyerror("Invalid chord constant");
    
    Chord * chord = malloc(sizeof(*chord));
    if (chord == NULL) yyerror("Not enough heap memory");

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
    // printf("Preparing our band...\n");
}

char * createVar(types type, char * name){
    if(getVarByName(name) != NULL)
        yyerror("Variable named %s already exists.", name);

    struct Node * node = (struct Node *) malloc(sizeof(struct Node));
    if(node == NULL) yyerror("Not enough heap memory");

    node->var = (struct var *) malloc(sizeof(struct var));
    if(node->var == NULL) yyerror("Not enough heap memory");
    node->var->data.type = type;
    node->var->data.value = NULL;
    node->next = NULL;

    node->var->name = (char *) calloc(strlen(name) + 1, sizeof(char));
    if(node->var->name == NULL) yyerror("Not enough heap memory");
    strcpy(node->var->name, name);

    node->var->data.print = node->var->name;

    if(list->header == NULL){
        list->header = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node; 
    }
    
    char * ret = printCreateVar(type, name);
    free(name);
    return ret;
}

void putVar (size_t size, Var * variable, void * value){
    variable->data.value = malloc(size);
    if(variable->data.value == NULL)
        yyerror("Not enough heap memory");

    memcpy(variable->data.value, value, size);
}

char * newVar (char * name, Data data){
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
    return printPutVar(name, data);
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

Data getNoteData(char * noteStr ){
    Chord * chord = atonote(noteStr);
    char * print = printChordConstant(noteStr);
    Data data = { chord_type, chord, print };
    free(noteStr);
    return data;
}

Data getChordData(char * chordStr ){
    Chord * chord = atochord(chordStr);
    char * print = printChordConstant(chordStr);
    Data data = { chord_type, chord, print };
    free(chordStr);
    return data;
}

Data getIntData(char * numStr){
    int * num = malloc(sizeof(*num));
    *num = atoi(numStr);
    Data data = { num_type, num, numStr };
    return data;
}

void print_number(int* num){
    printf("El numero es %d\n", *num);
}

void print_boolean(int* num){
    printf("--> %s\n", *num==1?"true":"false");
}

void addNote(Chord * chord, notes_enum note){
    struct NoteNode * node = chord->notes;
    struct NoteNode * new = malloc(sizeof(struct NoteNode));
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
        out.value = malloc(sizeof(int));
        *((int *) out.value) = result;
        out.print = printAddNumbers(first.print, second.print);
        return out;
    }
    if(first.type == chord_type && second.type == chord_type){
        Chord * chord_one = (Chord *) first.value;
        Chord * chord_two = (Chord *) second.value;
        
        struct NoteNode * node = chord_two->notes;
        while(node != NULL){
            if(!containsNote(chord_one, node->note))
                addNote(chord_one, node->note);
            node = node->next;
        }
        out.type = chord_type;
        out.value = chord_one;
        out.print = printAddChords(first.print, second.print);

        return out;
    }
    yyerror("Incompatible types. Can't operate %s value + %s value", getTypeByEnum(first.type), getTypeByEnum(second.type));
    abort();
}

Data minusOperation(Data first, Data second){
    Data out;
    if(first.type == num_type && second.type == num_type){
        out.type = num_type;
        int result =  *((int *) first.value) - *((int *) second.value);
        out.value = malloc(sizeof(int));
        *((int *) out.value) = result;
        out.print = printSubstractNumbers(first.print, second.print);
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
        out.print = printSubstractChords(first.print, second.print);

        return out;
    }
    yyerror("Incompatible types. Can't operate %s value - %s value", getTypeByEnum(first.type), getTypeByEnum(second.type));
    abort();
}

Data barOperation(Data first, Data second){
    Data out;
    if(first.type == num_type && second.type == num_type){
        out.type = num_type;
        int result =  *((int *) first.value) / *((int *) second.value);
        out.value = malloc(sizeof(int));
        *((int *) out.value) = result;
        out.print = printBarNumbers(first.print, second.print);
        return out;
    }
    if(first.type == set_type && second.type == set_type){
        Set set_one = *((Set *) first.value);
        Set set_two = *((Set *) second.value);
        int new_quant = set_one.quant + set_two.quant;

        out.type = set_type;
        out.value = malloc(sizeof(struct set));
        ((Set *)out.value)->quant = new_quant;
        // ((Set *)out.value)->blocks = set_one.blocks;
        Block * outBlocks = calloc(new_quant, sizeof(struct block));
        if(outBlocks == NULL) yyerror("Not enough heap memory");

        int i = 0, j = 0;
        for (i = 0; i < set_one.quant; i++)     // TODO: Ver si no conviene malloquear de nuevo
            outBlocks[i] = set_one.blocks[i];
        for (j = 0; j < set_two.quant; j++, i++)
            outBlocks[i] = set_two.blocks[j];

        ((Set *)out.value)->blocks = outBlocks;
        out.print = printBarSet(first.print, second.print);

        return out;
    }
    yyerror("Incompatible types. Can't operate %s value / %s value", getTypeByEnum(first.type), getTypeByEnum(second.type));
    abort();
}

Data starOperation(Data first, Data second){
    Data out;
    if(first.type == num_type && second.type == num_type){
        out.type = num_type;
        int result =  *((int *) first.value) * *((int *) second.value);
        out.value = malloc(sizeof(int));
        *((int *) out.value) = result;
        out.print = printStarNumbers(first.print, second.print);
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
        for(i=0; i < repeat; i++){
            for(j = 0; j < old_quant; j++){
                block_new[b_index++] = block_old[j];              // luego en block_new tengo block_old repeat veces
            }
        }
        out.type = set_type;
        out.value = (Set *) malloc(sizeof(struct set));
        ((Set *)out.value)->quant = new_quant;
        ((Set *)out.value)->blocks = block_new;
        
        out.print = printStarSet(first.print, second.print);

        return out;
    }
    yyerror("Incompatible types. Can't operate (%s value) * (%s value)", getTypeByEnum(first.type), getTypeByEnum(second.type));
    abort();
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
    char * print = printNewSet(chord.print, time.print);
    Data data = {set_type, set, print};
    return data;
}

Set * newSet(Data chord, Data time){
    if(chord.type != chord_type || time.type != num_type)
        yyerror("You are creating a new set with incorrect variable types");
    Set * set = (Set *) malloc(sizeof(struct set));
    Block * block = (Block *) malloc(sizeof(struct block));
    block->chords = ((Chord *)chord.value); // TODO: Ver si no conviene hacer malloc y memcpy
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
    out.value = malloc(sizeof(int));
    switch (cond){
        case and: *((int *) out.value) = (make_comparable(&first) && make_comparable(&second) ) ? 1:0;  
                  break;
        case or:  *((int *) out.value) = (make_comparable(&first) || make_comparable(&second) ) ? 1:0;  
                  break;
        case gt:  *((int *) out.value) = (make_comparable(&first) > make_comparable(&second) ) ? 1:0;
                  break;
        case gte: *((int *) out.value) = (make_comparable(&first) >= make_comparable(&second) ) ? 1:0;
                  break;
        case lt:  *((int *) out.value) = (make_comparable(&first) < make_comparable(&second) ) ? 1:0;
                  break;
        case lte: *((int *) out.value) = (make_comparable(&first) <= make_comparable(&second) ) ? 1:0;
                  break;
        case eq:  *((int *) out.value) = (make_comparable(&first) == make_comparable(&second) ) ? 1:0;
                  break;
        case neq: *((int *) out.value) = (make_comparable(&first) != make_comparable(&second) ) ? 1:0;
                  break;
        default:  free(out.value);
                  yyerror("Invalid binary logic operator.[Allowed: and or <= < > >= == != ]");
                  break;
    }
    out.print = printComparison(first.print, cond, second.print);
    return out;
}

Data negate_condition(Data condition){
    Data out;
    out.type = bool_type;
    out.value = malloc(sizeof(int));
    if(condition.type != bool_type){
        *((int *) out.value) = make_comparable(&condition);
    } else {
        // yyerror("Invalid parameter for condition. Cannot negate %s value", getTypeByEnum(condition.type));
        *((int *) out.value) = *((int*)condition.value) > 0 ? 0 : 1;
    }
    out.print = printNotComparison(condition.print);
    return out;
}    

/* Data condition_expression(Data expression){
    Data out;
    out.type = bool_type;
    out.value = malloc(sizeof(int));
    *((int *) out.value) = (expression.value != NULL);
    return out;
} */

static int make_comparable(Data * data){
    if(data->value == NULL) return 0;
    switch (data->type){
        case bool_type:
        case num_type:
                return *((int*)data->value);
                break;
        case chord_type: {
                char * aux = data->print;
                data->print = printMakeComparableChord(data->print);
                free(aux);
                return avg_freq((Chord *)data->value);
                break;
        } case set_type: {
                char * aux = data->print;
                data->print = printMakeComparableChord(data->print);
                free(aux);
                return total_time((Set *) data->value);
                break;
        } default:
            yyerror("Invalid comparable type");
            break;
    }
    abort();
}

Data data_boolean(Data data){
    Data out;
    out.type = bool_type;
    out.value = malloc(sizeof(int));
    switch (data.type){
        case bool_type:
        case num_type:      
                *((int *) out.value) = *((int*)data.value);
                out.print = calloc(strlen(data.print) + 1, sizeof(*out.print));
                if (out.print == NULL) yyerror("Not enough heap memory");
                strcpy(out.print, data.print);
                break;
        case chord_type: 
                *((int *) out.value) = avg_freq((Chord *)data.value);
                out.print = printMakeComparableChord(data.print);
                break;
        case set_type:
                *((int *) out.value) = total_time((Set *) data.value);
                out.print = printMakeComparableSet(data.print);
                break;
        default:
            yyerror("Invalid comparable type");
            break;
    }
    return out;
}

// /* RECURSO DE PRUEBA */
// float getFreq(notes_enum note){
//     float notes[] = { /*C*/ 65.41 * pow(2,3), 69.30* pow(2,3), 73.42* pow(2,3), 77.78* pow(2,3), 82.41* pow(2,3), 87.31* pow(2,3), 92.50* pow(2,3), 98.00* pow(2,3), 103.83* pow(2,3), 110.00* pow(2,3), 116.54* pow(2,3), 123.47* pow(2,3) /*B*/, 0};
//     return notes[note];
// }

static int avg_freq(Chord * chord){
    float sum_freq = 0;
    int quant = 0;
    struct NoteNode * node = chord->notes;
    while (node != NULL){
        sum_freq += notes[node->note];
        quant++;
        node = node->next;
    }
    return (quant == 0) ? 0 : (sum_freq/quant);
}

static int total_time(Set * set){
    int i,time = 0;
    for (i=0; i < set->quant; i++){
        time += set->blocks[i].time;
    }
    return time;
}

void free_end(){
    if(list==NULL) return;
    struct Node * node = list->header;
    struct Node * aux;
    while(node != NULL){
        aux = node;
        node = node->next;
        free(aux->var->name);
        free(aux->var);
        free(aux);
    }
    free(list);
}


char * playSet(Data set){
    if( set.type != set_type ){
        yyerror("\033[1;31mError\033[0m: Can't play %s type",getTypeByEnum(set.type));
    }
    // print_set(set);
    // Set * realSet = (Set *)set.value;
    // generateWav(*realSet, WAV_FILE_NAME);
    // playWav(WAV_FILE_NAME);
    return printPlaySet(set.print);
}

Data addParen(Data data) {
    char * aux = data.print;
    data.print = printAddParen(data.print);
    free(aux);
    return data;
}

char * addBraces(char * programStr) {
    char * ret = printAddBraces(programStr);
    free(programStr);
    return ret;
}

char * ifSentence(Data comp, char * ifBody, char * elseBody) {
    char * ret = printIfSentence(comp.print, ifBody, elseBody);
    free(ifBody);
    if (elseBody != NULL) free(elseBody);
    return ret;
}

char * doWhileSentence(char * body, Data comp) {
    char * ret = printDoWhileSentence(body, comp.print);
    free(body);
    return ret;
}

char * whileSentence(char * body, Data comp) {
    char * ret = printWhileSentence(body, comp.print);
    free(body);
    return ret;
}

char * emptySentence() {
    char * ret = calloc(1, sizeof(*ret));
    if (ret == NULL) yyerror("Not enough heap memory");
    return ret;
}

char * concatProgram(char * p1, char * p2) {
    char * ret = printConcatProgram(p1, p2);
    free(p1);
    free(p2);
    return ret;
}

char * printMessage(char * message) {
    char * ret = printStringLiteral(message);
    free(message);
    return ret;
}

char * printExpression(Data exp) {
    char * ret = printExpressionValue(exp);
    return ret;
}

char * getNumber(char * name) {
    Var * variable = getVarByName(name);
    if(variable == NULL)
        yyerror("Variable '%s' doesn't exist", name);
    if(variable->data.type != num_type)
        yyerror("You are trying to assign %s to a %s variable", getTypeByEnum(num_type), getTypeByEnum(variable->data.type));
    char * ret = printGetNumber(name);
    int mock = 0;
    putInt(name, &mock); // Initialize value
    free(name);
    return ret;
}

char * getChord(char * name) {
    Var * variable = getVarByName(name);
    if(variable == NULL)
        yyerror("Variable '%s' doesn't exist", name);
    if(variable->data.type != chord_type)
        yyerror("You are trying to assign %s to a %s variable", getTypeByEnum(num_type), getTypeByEnum(variable->data.type));
    char * ret = printGetChord(name);
    putChord(name, atonote("A")); // Initialize value
    free(name);
    return ret;
}

void generateFullProgram(char * program) {
    printFullProgram(program);
    free(program);
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