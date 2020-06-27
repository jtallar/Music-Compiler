%{
void yyerror(const char * format, ...);
int yylex();
extern int yylineno;

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "typeUtil.h"
/* Variable for the line count */

%}

/* ----------------- TOKENS ---------------------
 * Token that I'm expecting from the lexical 
 * analyzer (will save as defines in tab.h) */

/*  %code requires {
    struct data{
        types type;
        void * value;
    };
} */

%union {
    int int_type;
    int * number; 
    struct chord * chord;
    struct set * set;
    char * strVal;
    struct data dataVal;
}

%token IF ELSE DO WHILE STAR BAR ADD MINUS ASSIGN
%token EQUAL_OP NOT_EQUAL_OP GT_OP GTE_OP LT_OP LTE_OP AND_OP OR_OP NOT_OP
%token OPEN_BRACES CLOSE_BRACES OPEN_PAREN CLOSE_PAREN OPEN_BRACKET CLOSE_BRACKET
%token START PLAY NEW_LINE
%token INT_NAME CHORD_NAME SET_NAME

%token <strVal> VAR
%token <strVal> NUMBER
/* %token <set> SET */
%token <strVal> CHORD
%token <strVal> NOTE

//%type <strVal> expression assign var_type term factor constant

%type <int_type> var_type any_op add_op_logic op_compare
%type <strVal> assign declare if_sentence do_sentence while_sentence play body program
%type <dataVal> constant factor term expression /**/ compare single_compare mult_compare

%start start

%%

start           :  START NEW_LINE program                                           { printFullProgram($3); }

program         :  program declare                                                  { $$ = concatProgram($1, $2); }   
                |  program assign                                                   { $$ = concatProgram($1, $2); }
                |  program if_sentence                                              { $$ = concatProgram($1, $2); }
                |  program do_sentence                                              { $$ = concatProgram($1, $2); }
                |  program while_sentence                                           { $$ = concatProgram($1, $2); }
                |  program play                                                     { $$ = concatProgram($1, $2); }
                |  program NEW_LINE                                                 { $$ = $1; }
                |  /* empty */                                                      { $$ = emptySentence(); }
                ;

play            : PLAY OPEN_PAREN expression CLOSE_PAREN NEW_LINE                   { $$ = playSet($3);   }
                ;

do_sentence     : DO body WHILE compare NEW_LINE                                    { $$ = doWhileSentence($2, $4); }
                ;

while_sentence  : WHILE compare body NEW_LINE                                       { $$ = whileSentence($3, $2); }
                ;

if_sentence     : IF compare body NEW_LINE                                          { $$ = ifSentence($2, $3, NULL); }
                | IF compare body ELSE body NEW_LINE                                { $$ = ifSentence($2, $3, $5); }
                ;

compare         : OPEN_PAREN mult_compare any_op single_compare CLOSE_PAREN         { $$ = addParen(condition_composed($2, $3, $4)); /* print_boolean((int*)$$.value); */ }
                | OPEN_PAREN single_compare CLOSE_PAREN                             { $$ = addParen($2);  /* print_boolean((int*)$$.value);   */        }
                /* | OPEN_PAREN expression CLOSE_PAREN                                 { $$ = condition_expression($2); print_boolean((int*)$$.value);       } */
                ;

single_compare  : OPEN_PAREN mult_compare any_op single_compare CLOSE_PAREN         { $$ = addParen(condition_composed($2, $3, $4));  }
                | NOT_OP OPEN_PAREN mult_compare CLOSE_PAREN                        { $$ = negate_condition($3);            }
                | expression                                                        { $$ = data_boolean($1);        }
                ;

mult_compare    : mult_compare any_op single_compare                                { $$ = condition_composed($1, $2, $3);  }                                
                | single_compare                                                    { $$ = $1; }
                ;

// Guarda lo que esta a la derecha $$ = $1
any_op          : add_op_logic                         { $$ = $1; }
                | op_compare                           { $$ = $1; }
                ;
                
body            : OPEN_BRACES program CLOSE_BRACES     { $$ = addBraces($2); }
                ;

else            : ELSE body 
                |
                ;

// Enum para todos los operadores que siguen
add_op_logic    : AND_OP                               { $$ = and; }
                | OR_OP                                { $$ = or;  }
                ;

op_compare      : GT_OP                                { $$ = gt;  }
                | GTE_OP                               { $$ = gte; }    
                | LT_OP                                { $$ = lt;  }
                | LTE_OP                               { $$ = lte; }
                | EQUAL_OP                             { $$ = eq;  }
                | NOT_EQUAL_OP                         { $$ = neq; }
                ;

declare         : var_type VAR NEW_LINE                 { $$ = createVar($1,$2); }      // se me lleva NEW_LINE     
            /*  | var_type assign                       { $$ = createVar($1,$2); } */
                ;

assign          : VAR ASSIGN expression NEW_LINE        { $$ = newVar($1,$3); }
                ;

var_type        : INT_NAME                              { $$ = num_type;   }                              
                | CHORD_NAME                            { $$ = chord_type; }
                | SET_NAME                              { $$ = set_type;   }
                ;

expression      : expression ADD term                   { $$ = addOperation($1,$3);   }
                | expression MINUS term                 { $$ = minusOperation($1,$3); }
                | term                                  { $$ = $1; }
                ;

term            : term STAR factor                      { $$ = starOperation($1,$3); }
                | term BAR factor                       { $$ = barOperation ($1,$3); }
                | factor                                { $$ = $1; }
                ;

factor          : constant                                              { $$ = $1;}
                | VAR                                                   { $$ = getDataByName($1);  }
                | OPEN_BRACKET expression expression CLOSE_BRACKET      { $$ = newSetData($2, $3); /* print_set($$); */}
                | OPEN_PAREN expression CLOSE_PAREN                     { $$ = addParen($2); }
                ;

constant        : CHORD                                 { $$ = getChordData($1); /*print_chord($1); */ }
                | NUMBER                                { $$ = getIntData($1);  /*  print_number($1); */ }
                | NOTE                                  { $$ = getNoteData($1); /*print_chord($1);  */}
                ;

%%

void yyerror(const char * format, ...){
    va_list argptr;
    va_start(argptr, format);
    vfprintf(stderr, format, argptr);
    va_end(argptr);
    fprintf(stderr," -> \033[1;31mError\033[0m in line %d\n\n", yylineno);
    exit(EXIT_FAILURE);
}

int yywrap(){
    return 1;
} 

void printHeaders();
void printFunctions();

int main() {
    init_list();
    // printf("\033[1;32mReady! Make your music!\033[0m\n\n");
    printHeaders();
    printFunctions();
    return yyparse();
} 

void printHeaders(){
    printf("#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include <math.h>\n\n");
    printf("#define BASE_FILENAME	\"out\"\n#define EXT_FILENAME	\".wav\"\n");
    printf("#define NOTE_COUNT  13\n#define CHORD_COUNT 14\n#define STD_CHORD_L 3\n\n");
    printf("#define M_PI           3.14159265358979323846\n#ifdef __linux__\n    #define SOUND_COMMAND  \"aplay -c 1 -q -t wav\"\n#endif\n#ifdef __APPLE__	\n    #define SOUND_COMMAND  \"afplay\"\n#endif\n");
    printf("#define SAMPLE_RATE     96000.0 // hertz\n#define MONO            1\n#define STEREO          2\n#define CHANNEL_NUM     MONO\n#define BITS_SAMPLE     16      // 8, 16 or 32\n\n");

    printf("\nstatic int fileNumber = 0;\n\n");
    printf("typedef enum { C=0, Cs, D, Ds=3, E, F, Fs=6, G, Gs, A=9, As, B, _ } notes_enum;\ntypedef enum { aC=0, aCm, aD, aDm=3, aE, aEm, aF=6, aFm, aG, aGm=9, aA, aAm, aB=12, aBm } chords_enum;\n\nstatic const char * noteName[NOTE_COUNT] = {\"C\", \"Cs\", \"D\", \"Ds\", \"E\", \"F\", \"Fs\", \"G\", \"Gs\", \"A\", \"As\", \"B\", \"_\"};\nstatic const char * chordName[CHORD_COUNT] = {\"aC\", \"aCm\", \"aD\", \"aDm\", \"aE\", \"aEm\", \"aF\", \"aFm\", \"aG\", \"aGm\", \"aA\", \"aAm\", \"aB\", \"aBm\"};\n\n");
    printf("static const float notes[] = { /*C*/ 65.41 * 8, 69.30* 8, 73.42* 8, 77.78* 8, 82.41* 8, 87.31* 8, 92.50* 8 , 98.00* 8, 103.83* 8, 110.00* 8, 116.54* 8, 123.47* 8 /*B*/ , 0};\n");
    printf("static notes_enum chordsNotes[CHORD_COUNT][STD_CHORD_L] = { {C,E, G}, {C,Ds,G}, {D,Fs,A}, {D,F, A}, {E,Gs,B}, {E,G, B}, {F,A, C}, {F,Gs,C}, {G,B, D}, {G,As,D}, {A,Cs,E}, {A,C, E}, {B,Ds,Fs}, {B,E, G}};\n\n");
    printf("struct NoteNode{\n\tnotes_enum note;\n\tstruct NoteNode * next;\n};\ntypedef struct chord{\n\tstruct NoteNode * notes;\n\tint quant;\n}Chord;\ntypedef struct block{\n\tChord * chords;\n\tint time;\n}Block;\ntypedef struct set{\n\tBlock * blocks;\n\tint quant;\n}Set;\n\n");
    printf("Chord * outAtochord(const char *nptr);\n");
    printf("Chord * outAtonote(const char *nptr);\n");
    printf("void outAddNote(Chord * chord, notes_enum note);\n");
    printf("void outDeleteNote(Chord * chord, notes_enum note);\n");
    printf("int outContainsNote(Chord * chord, notes_enum note);\n");
    printf("Chord * newChord(char * constant);\n");
    printf("Set * newSet(Chord * chord, int time);\n");
    printf("Chord * chordSum(Chord * c1, Chord * c2);\n");
    printf("Chord * chordSub(Chord * c1, Chord * c2);\n");
    printf("Set * setRepeat(Set * set, int times);\n");
    printf("Set * setConcat(Set * s1, Set * s2);\n");
    printf("int totalTime(Set * set);\n");
    printf("int avgFreq(Chord * chord);\n");
    printf("void playSet(Set * set);\n\n");
    printf("void generateWav(Set set, char * name);\n");
    printf("int playWav( char *filename );\n");
}


void printFunctions(){
    /*Print new chord function */
    printf("\n\nChord * newChord(char * constant){\n\tChord * new_chord = outAtonote(constant);\n\tif(new_chord != NULL){\n\t\treturn new_chord;\n\t}\n\telse {\n\t\tnew_chord = outAtochord(constant);\n\t}\n\treturn new_chord;\n}\n ");
    /* Print New Set function */
    printf("\n\nSet * newSet(Chord * chord, int time){\n\tSet * new_set = malloc(sizeof(struct set));\n\tif(new_set == NULL){\n\t\texit(1);\n\t}\n\tBlock * block = malloc(sizeof(struct block));\n\tif(block == NULL){\n\t\texit(1);\n\t}\n\tblock->chords = chord;\n\tblock->time = time;\n\tnew_set->blocks = block;\n\tnew_set->quant = 1;\n\treturn new_set;\n\t}\n");
    /*Print contains note function */
    printf("\n\nint outContainsNote(Chord * chord, notes_enum note){\n\tstruct NoteNode * node = chord->notes;\n\twhile(node != NULL){\n\t\tif(node->note == note)\n\t\t\treturn 1;\n\t\tnode = node->next;\n\t}\n\treturn 0;\n}\n");
    /* Print avgFreq function */
    printf("\n\nint avgFreq(Chord * chord){\n\tfloat sum_freq = 0;\n\tint quant = 0;\n\twhile (quant < chord->quant){\n\t\tsum_freq += notes[chord->notes[quant].note];\n\t\tquant++;\n\t}\n\treturn (quant == 0) ? 0 : (sum_freq/quant);\n} \n");
    /* Print total time function */
    printf("\n\nint totalTime(Set * set){\n\tint time = 0;\n\tfor(int i = 0; i < set->quant ; i++) {\n\t\ttime += set->blocks[i].time;\n\t}\n\treturn time;\n} \n");
    /* Print Set Concat function */
    printf("\n\nSet * setConcat(Set * s1, Set * s2){\n\tSet *new_set = malloc(sizeof(struct set));\n\tif(new_set == NULL){\n\t\texit(1);\n\t}\n\tint new_quant = s1->quant + s2->quant;\n\tfor(int i = s1->quant, j = 0; i < new_quant; i++, j++)\n\t\ts1->blocks[i] = s1->blocks[j];\n\tnew_set->quant = new_quant;\n\tnew_set->blocks = s1->blocks;\n\treturn new_set;\n} \n");
    /* Print Set Repeat function */
    printf("\n\nSet * setRepeat(Set * set, int times){\n\tint old_quant = set->quant;\n\tint new_quant = set->quant * times;\n\tBlock * old_block = set->blocks;\n\tBlock * new_block = malloc(sizeof(struct block) * new_quant);\n\tif(new_block == NULL){\n\t\t exit(1);\n\t}\n\tint i = 0, b_index = 0, j = 0;\n\tfor(i=0; i < times; i++){\n\t\tfor(j = 0; j < old_quant; j++){\n\t\t\tnew_block[b_index++] = old_block[j];\n\t\t}\n\t}\n\tSet *new_set = malloc(sizeof(struct set));\n\tif(new_set == NULL){\n\t\texit(1);\n\t}\n\tnew_set->quant = new_quant;\n\tnew_set->blocks = new_block;\n\treturn new_set;\n}\n");
    /* Print Chord Sub function */
    printf("\n\n Chord * chordSub(Chord * c1, Chord * c2){\n\tint q = 0;\n\twhile(q < c2->quant){\n\t\tif(outContainsNote(c1, c2->notes[q].note))\n\t\t\toutDeleteNote(c1, c2->notes[q].note);\n\t\tq++;\n\t}\n\tChord * new_chord = malloc(sizeof(struct chord));\n\tif(new_chord == NULL){\n\t\texit(1);\n\t}\n\tnew_chord->notes = c1->notes;\n\tnew_chord->quant = c1->quant;\n\treturn new_chord;\n}\n");
    /* Print Chord Sum function */
    printf("\n\nChord * chordSum(Chord * c1, Chord * c2){\n\tint q = 0;\n\twhile(q < c2->quant ){\n\t\tif(!outContainsNote(c1, c2->notes[q].note)){\n\t\t\toutAddNote(c1, c2->notes[q].note);\n\t\t}\n\t\tq++;\n\t}\n\tChord * new_chord = malloc(sizeof(struct chord));\n\tif(new_chord == NULL){\n\t\texit(1);\n\t}\n\tnew_chord->notes = c1->notes;\n\tnew_chord->quant = c1->quant;\n\treturn new_chord;\n} \n");
    /* Print aToChord y aToNote functions */
    printf("\n\nChord * outAtochord(const char *nptr){\n\tint stdChord;\n\tfor (stdChord = aC; stdChord < CHORD_COUNT; stdChord++) {\n\t\tif (strcmp(nptr, chordName[stdChord]) == 0) {\n\t\t\tbreak;\n\t\t}\n\t}\n\tif (stdChord == CHORD_COUNT){ \n\t\treturn NULL;\n\t}\n\tChord * chord = malloc(sizeof(*chord));\n\tif (chord == NULL) {\n\t\texit(1);\n\t}\n\tstruct NoteNode * node = (struct NoteNode *) malloc(sizeof(struct NoteNode));\n\tif (node == NULL){\n\t\texit(1);\n\t}\n\tnode->note = chordsNotes[stdChord][0];\n\tchord->notes = node;\n\tfor (int i = 1; i < STD_CHORD_L; i++) {\n\t\tnode->next = (struct NoteNode *) malloc(sizeof(struct NoteNode));\n\t\tif (node->next == NULL) {\n\t\t\texit(1);\n\t\t}\n\t\tnode->next->note = chordsNotes[stdChord][i];\n\t\tnode = node->next;\n\t}\n\tnode->next = NULL;\n\tchord->quant = STD_CHORD_L;\n\treturn chord;\n}\n\n\nChord * outAtonote(const char *nptr) {\n\tint note;\n\tfor (note = C; note < NOTE_COUNT; note++) {\n\t\t\tif (strcmp(nptr, noteName[note]) == 0) {\n\t\t\t\tbreak;\n\t\t}\n\t}\n\tif (note == NOTE_COUNT) {\n\t\treturn NULL;\n\t}\n\tChord * chord = malloc(sizeof(*chord));\n\tif (chord == NULL) { \n\t\texit(1);\n\t}\n\tchord->notes = malloc(sizeof(struct NoteNode));\n\tif (chord->notes == NULL) {\n\t\tfree(chord);\n\t}\n\tchord->notes->note = note;\n\tchord->notes->next = NULL;\n\tchord->quant = 1;\n\treturn chord;\n}\n");
    /* Print addNote y deleteNote */
    printf("\n\nvoid outAddNote(Chord * chord, notes_enum note){\n\tstruct NoteNode * node = chord->notes;\n\tstruct NoteNode * new = malloc(sizeof(struct NoteNode));\n\tif(new == NULL){\n\t\texit(1);\n\t}\n\tnew->note = note;\n\tnew->next = node;\n\tchord->notes = new;\n\tchord->quant++;\n\treturn;\n}\n\n\nvoid outDeleteNote(Chord * chord, notes_enum note){\n\tstruct NoteNode * node = chord->notes;\n\tif(node->note == note){\n\t\tstruct NoteNode * aux = node->next;\n\t\tnode->next = node->next->next;\n\t\tfree(aux);\n\t\tchord->quant--;\n\t\treturn;\n\t}\n\twhile (node->next != NULL){\n\t\tif(node->next->note == note){\n\t\t\tstruct NoteNode * aux = node->next;\n\t\t\tnode->next = node->next->next;\n\t\t\tfree(aux);\n\t\t\tchord->quant--;\n\t\t\treturn;\n\t\t}\n\t\tnode = node->next;\n\t}\n\treturn;\n}\n");
    /* Print playSet function */
    printf("\n\nvoid playSet(Set * set){\n\tchar buf[10];\n\tsnprintf(buf, 10, \"%%s%%d%%s\", BASE_FILENAME, fileNumber, EXT_FILENAME);\n\tgenerateWav(*set, buf);\n\tplayWav(buf);\n\tfileNumber++;\n}\n\n");
    /* Print soundSet.c functions */
    printf("\n\nint playWav( char *filename ) {\n    char command[256];\n    int status;\n    /* create command to execute */\n    sprintf (command, \"%%s %%s\", SOUND_COMMAND, filename);\n\n    /* play sound */\n    status = system( command );\n\n    return status;\n}\n\nvoid addSet (Wave * mySound, Set set);\n\nlong getSampleNumber(long miliseconds) {\n    return (long) ((miliseconds / 1000.0) * SAMPLE_RATE);\n}\n\n");
    printf("\n\nlong getTotalDuration(Set set) {\n    long rta = 0;\n    for (int i = 0; i < set.quant ; i++) {\n        rta += set.blocks[i].time;\n    }\n    return rta;\n}\n\nvoid generateWav(Set set, char * name) {\n    long duration = getTotalDuration(set);\n    long nSamples = getSampleNumber(duration);\n    \n    // Create a mono (1), 16-bit sound and set the duration\n    Wave mySound = makeWave((int)SAMPLE_RATE, CHANNEL_NUM, BITS_SAMPLE);\n    waveSetDuration(&mySound, duration);\n\n    // Add all of the data\n    addSet(&mySound, set);\n\n    // Write it to a file and clean up when done\n    waveToFile(&mySound, name);\n    waveDestroy(&mySound);\n}\n\nvoid resetArray(float * array, int size) {\n    for (int i = 0; i < size; i++) {\n        array[i] = 0.0;\n    }\n}\n\n");
    printf("\n\nvoid addChord(Wave * mySound, Chord * chord, long nSamples) {\n    float multiplier = M_PI * 2.0 / SAMPLE_RATE;\n    float frameData[CHANNEL_NUM];\n    int i, j, k;\n    for(i = 0; i < nSamples; i++){\n        resetArray(frameData, CHANNEL_NUM);\n        struct NoteNode * node = chord->notes;\n        for (j = 0; j < chord->quant ; j++) {\n            for (k = 0; k < CHANNEL_NUM; k++) {\n                frameData[k] += sin(notes[node->note] * (float)i * multiplier) / chord->quant;\n            }\n            node->next;\n        }\n        waveAddSample(mySound, frameData);\n    }\n}\n\nvoid addSet (Wave * mySound, Set set){\n    for (int i = 0; i < set.quant; i++) {\n        addChord(mySound, set.blocks[i].chords , getSampleNumber(set.blocks[i].time));\n    }\n}\n\n");
}

/**
* *       yacc -d parser.y
* *       lex scanner.l
* *       gcc lex.yy.c y.tab.c -ly
**/