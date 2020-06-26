#include <stdio.h>
#include <stdlib.h>
#include "outFunctions.h"

void printHeaders(){
    printf("#include <stdio.h>\n#include <stdlib.h>\n\n");
    printf("Chord * outNewChord(char * constant);\n");
    printf("Set * outNewSet(Chord * chord, int time);\n");
    printf("Chord * outChordSum(Chord * c1, Chord * c2);\n");
    printf("Chord * outChordSub(Chord * c1, Chord * c2);\n");
    printf("Set * outSetRepeat(Set * set, int times);\n");
    printf("Set * outSetConcat(Set * s1, Set * s2);\n");
    printf("int outTotalTime(Set * set);\n");
    printf("int outAvgFreq(Chord * chord);\n");
    printf("void outPlaySet(Set * set);\n");

    
}


printFunctions(){
    /*Print new chord function */
    printf("\n\nChord * outNewChord(char * constant){\n\tChord * new_chord = outAtonote(constant);\n\tif(new_chord != NULL){\n\t\treturn new_chord;\n\t}\n\telse {\n\t\tnew_chord = outAtochord(constant);\n\t}\n\treturn new_chord;\n}\n ");
    /* Print New Set function */
    printf("\n\nSet * outNewSet(Chord * chord, int time){\n\tSet * new_set = malloc(sizeof(struct set));\n\tif(new_set == NULL){\n\t\texit(1);\n\t}\n\tBlock * block = malloc(sizeof(struct block));\n\tif(block == NULL){\n\t\texit(1);\n\t}\n\tblock->chords = chord;\n\tblock->time = time;\n\tnew_set->blocks = block;\n\tnew_set->quant = 1;\n\treturn new_set;\n\t}\n");
    /*Print contains note function */
    printf("\n\nint outContainsNote(Chord * chord, notes_enum note){\n\tstruct NoteNode * node = chord->notes;\n\twhile(node != NULL){\n\t\tif(node->note == note)\n\t\t\treturn 1;\n\t\tnode = node->next;\n\t}\n\treturn 0;\n}\n");
    /* Print avgFreq function */
    printf("\n\nint outAvgFreq(Chord * chord){\n\tfloat sum_freq = 0;\n\tint quant = 0;\n\twhile (quant < chord->quant){\n\t\tsum_freq += notes[chord->notes[quant].note];\n\t\tquant++;\n\t}\n\treturn (quant == 0) ? 0 : (sum_freq/quant);\n} \n");
    /* Print total time function */
    printf("\n\nint outTotalTime(Set * set){\n\tint time = 0;\n\tfor(int i = 0; i < set->quant ; i++) {\n\t\ttime += set->blocks[i].time;\n\t}\n\treturn time;\n} \n");
    /* Print Set Concat function */
    printf("\n\nSet * outSetConcat(Set * s1, Set * s2){\n\tSet *new_set = malloc(sizeof(struct set));\n\tif(new_set == NULL){\n\t\texit(1);\n\t}\n\tint new_quant = s1->quant + s2->quant;\n\tfor(int i = s1->quant, j = 0; i < new_quant; i++, j++)\n\t\ts1->blocks[i] = s1->blocks[j];\n\tnew_set->quant = new_quant;\n\tnew_set->blocks = s1->blocks;\n\treturn new_set;\n} \n");
    /* Print Set Repeat function */
    printf("\n\nSet * outSetRepeat(Set * set, int times){\n\tint old_quant = set->quant;\n\tint new_quant = set->quant * times;\n\tBlock * old_block = set->blocks;\n\tBlock * new_block = malloc(sizeof(struct block) * new_quant);\n\tif(new_block == NULL){\n\t\t exit(1);\n\t}\n\tint i = 0, b_index = 0, j = 0;\n\tfor(i=0; i < times; i++){\n\t\tfor(j = 0; j < old_quant; j++){\n\t\t\tnew_block[b_index++] = old_block[j];\n\t\t}\n\t}\n\tSet *new_set = malloc(sizeof(struct set));\n\tif(new_set == NULL){\n\t\texit(1);\n\t}\n\tnew_set->quant = new_quant;\n\tnew_set->blocks = new_block;\n\treturn new_set;\n}\n");
    /* Print Chord Sub function */
    printf("\n\n Chord * outChordSub(Chord * c1, Chord * c2){\n\tint q = 0;\n\twhile(q < c2->quant){\n\t\tif(outContainsNote(c1, c2->notes[q].note))\n\t\t\toutDeleteNote(c1, c2->notes[q].note);\n\t\tq++;\n\t}\n\tChord * new_chord = malloc(sizeof(struct chord));\n\tif(new_chord == NULL){\n\t\texit(1);\n\t}\n\tnew_chord->notes = c1->notes;\n\tnew_chord->quant = c1->quant;\n\treturn new_chord;\n}\n");
    /* Print Chord Sum function */
    printf("\n\nChord * outChordSum(Chord * c1, Chord * c2){\n\tint q = 0;\n\twhile(q < c2->quant ){\n\t\tif(!outContainsNote(c1, c2->notes[q].note)){\n\t\t\toutAddNote(c1, c2->notes[q].note);\n\t\t}\n\t\tq++;\n\t}\n\tChord * new_chord = malloc(sizeof(struct chord));\n\tif(new_chord == NULL){\n\t\texit(1);\n\t}\n\tnew_chord->notes = c1->notes;\n\tnew_chord->quant = c1->quant;\n\treturn new_chord;\n} \n");
    /* Print aToChord y aToNote functions */
    printf("\n\nChord * outAtochord(const char *nptr){\n\tint stdChord;\n\tfor (stdChord = aC; stdChord < CHORD_COUNT; stdChord++) {\n\t\tif (strcmp(nptr, chordName[stdChord]) == 0) {\n\t\t\tbreak;\n\t\t}\n\t}\n\tif (stdChord == CHORD_COUNT){ \n\t\treturn NULL;\n\t}\n\tChord * chord = malloc(sizeof(*chord));\n\tif (chord == NULL) {\n\t\texit(1);\n\t}\n\tstruct NoteNode * node = (struct NoteNode *) malloc(sizeof(struct NoteNode));\n\tif (node == NULL){\n\t\texit(1);\n\t}\n\tnode->note = chordsNotes[stdChord][0];\n\tchord->notes = node;\n\tfor (int i = 1; i < STD_CHORD_L; i++) {\n\t\tnode->next = (struct NoteNode *) malloc(sizeof(struct NoteNode));\n\t\tif (node->next == NULL) {\n\t\t\texit(1);\n\t\t}\n\t\tnode->next->note = chordsNotes[stdChord][i];\n\t\tnode = node->next;\n\t}\n\tnode->next = NULL;\n\tchord->quant = STD_CHORD_L;\n\treturn chord;\n}\n\n\nChord * outAtonote(const char *nptr) {\n\tint note;\n\tfor (note = C; note < NOTE_COUNT; note++) {\n\t\t\tif (strcmp(nptr, noteName[note]) == 0) {\n\t\t\t\tbreak;\n\t\t}\n\t}\n\tif (note == NOTE_COUNT) {\n\t\treturn NULL;\n\t}\n\tChord * chord = malloc(sizeof(*chord));\n\tif (chord == NULL) { \n\t\texit(1);\n\t}\n\tchord->notes = malloc(sizeof(struct NoteNode));\n\tif (chord->notes == NULL) {\n\t\tfree(chord);\n\t}\n\tchord->notes->note = note;\n\tchord->notes->next = NULL;\n\tchord->quant = 1;\n\treturn chord;\n}\n");
    /* Print addNote y deleteNote */
    printf("\n\nvoid outAddNote(Chord * chord, notes_enum note){\n\tstruct NoteNode * node = chord->notes;\n\tstruct NoteNode * new = (struct NoteNote *) malloc(sizeof(struct NoteNode));\n\tif(new == NULL){\n\t\texit(1);\n\t}\n\tnew->note = note;\n\tnew->next = node;\n\tchord->notes = new;\n\tchord->quant++;\n\treturn;\n}\n\n\nvoid outDeleteNote(Chord * chord, notes_enum note){\n\tstruct NoteNode * node = chord->notes;\n\tif(node->note == note){\n\t\tstruct NoteNode * aux = node->next;\n\t\tnode->next = node->next->next;\n\t\tfree(aux);\n\t\tchord->quant--;\n\t\treturn;\n\t}\n\twhile (node->next != NULL){\n\t\tif(node->next->note == note){\n\t\t\tstruct NoteNode * aux = node->next;\n\t\t\tnode->next = node->next->next;\n\t\t\tfree(aux);\n\t\t\tchord->quant--;\n\t\t\treturn;\n\t\t}\n\t\tnode = node->next;\n\t}\n\treturn;\n}\n");

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
    Set* s=calloc(1,16);
    s=outSetConcat(outSetConcat(outSetConcat(outSetConcat(outSetConcat((outSetRepeat(outNewSet(outNewChord("aC"),500),2)),outNewSet(outNewChord("aD"),500)),outNewSet(outNewChord("aC"),500)),outNewSet(outNewChord("aF"),500)),outNewSet(outNewChord("aE"),500)),outNewSet(outNewChord("_"),1000));
// free(auxFree);
// auxFree=s;
// s=setConcat(setConcat(setConcat(setConcat(setConcat(setConcat(s,(setRepeat(newSet(newChord("aC"),500),2))),newSet(newChord("aD"),500)),newSet(newChord("aC"),500)),newSet(newChord("aG"),500)),newSet(newChord("aF"),500)),newSet(newChord("_"),1000));
// free(auxFree);
// auxFree=s;
// s=setConcat(setConcat(setConcat(setConcat(setConcat(setConcat(s,(setRepeat(newSet(newChord("aC"),500),3))),newSet(newChord("aA"),500)),newSet(newChord("aF"),500)),newSet(newChord("aE"),500)),newSet(newChord("aD"),800)),newSet(newChord("_"),1000));
// free(auxFree);
// auxFree=s;
// s=setConcat(setConcat(setConcat(setConcat(setConcat(s,(setRepeat(newSet(newChord("As"),500),2))),newSet(newChord("aA"),500)),newSet(newChord("aF"),500)),newSet(newChord("aG"),500)),newSet(newChord("aF"),800));
// free(auxFree);
    print_set2(s);


}


