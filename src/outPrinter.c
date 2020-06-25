#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "outPrinter.h"

static char * callocPrint(size_t size);
static void printNoteAssign(char * name, Chord * chord);
static void printBlockAssign(char * name, Set * set);

static void print_chord(struct chord * chord) {
    if (chord == NULL || chord->notes == NULL) 
        yyerror("NULL pointer exception on chord or note");
    puts("\nChord: ");
    struct NoteNode * node = chord->notes;
    for (int i = 0; i < chord->quant; i++){
        printf("\tNota %d: %d\n", i, node->note);
        node = node->next;
    }
}

void printCreateVar(types type, char * name) {
    switch (type)
    {
    case num_type:
        printf("int %s;\n", name);
        break;
    case chord_type:
        printf("Chord * %s = %s", name, callocPrint(sizeof(Chord)));
        break;
    case set_type:
        printf("Set * %s = %s", name, callocPrint(sizeof(Set)));
        break;
    default:
        perror("Unknown var type. Aborting...\n");
        abort();
        break;
    }   
}

void printPutVar(char * name, Data data) {
    switch (data.type)
    {
    case num_type:
        printf("%s = %d;\n", name, *((int *) data.value));
        break;
    case chord_type:
        printf("%s->quant = %d;\n", name, ((Chord *) data.value)->quant);
        char * buf = calloc(strlen(name) + strlen("->notes") + 1, sizeof(buf));
        if (buf == NULL) {
            abort(); /** TODO: Que hacemos aca?? */
        }
        sprintf(buf, "%s->notes", name);
        printNoteAssign(buf, (Chord *) data.value);
        free(buf);
        break;
    case set_type:
        printf("%s->quant = %d;\n", name, ((Set *) data.value)->quant);
        printBlockAssign(name, (Set *) data.value);
        break;
    default:
        perror("Unknown var type. Aborting...\n");
        abort();
        break;
    }   
}

static char * callocPrint(size_t size) {
    return "calloc(1, size);\n";
}

static void printNoteAssign(char * name, Chord * chord) {
    printf("%s = malloc(sizeof(*%s) * %d);\n", name, name, chord->quant);
    struct NoteNode * node = chord->notes;
    for (int i = 0; i < chord->quant; i++) {
        printf("%s[i].note = %d;\n", name, node->note);
        node = node->next;
    }
}

static void printBlockAssign(char * name, Set * set) {
    printf("%s->blocks = malloc(sizeof(*%s->blocks) * %d);\n", name, name, set->quant);
    for (int i = 0; i < set->quant; i++) {
        printf("%s->blocks[i].time = %d;\n", name, set->blocks[i].time);
        char * buf = calloc(strlen(name) + strlen("->blocks[i].chords") + 1, sizeof(buf));
        if (buf == NULL) {
            abort(); /** TODO: Que hacemos aca?? */
        }
        sprintf(buf, "%s->blocks[i].chords", name);
        printNoteAssign(buf, set->blocks[i].chords);
        free(buf);
    }
}