#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "outPrinter.h"

// static char * callocPrint(size_t size);
// static void printNoteAssign(char * name, Chord * chord);
// static void printBlockAssign(char * name, Set * set);
static char * getCompareSymbol(conditions cond);

#define BASE_INT_DECL_LEN   7
#define BASE_CHORD_DECL_LEN 23
#define BASE_SET_DECL_LEN   21
#define BASE_ASSIGN_LEN     29

char * printCreateVar(types type, char * name) {
    char * ret;
    switch (type)
    {
    case num_type:
        ret = calloc(BASE_INT_DECL_LEN + strlen(name), sizeof(*ret));
        if (ret == NULL) {
            yyerror("Not enough heap memory");
            abort();
        }
        sprintf(ret, "int %s;\n", name);
        break;
    case chord_type:
        ret = calloc(BASE_CHORD_DECL_LEN + strlen(name), sizeof(*ret));
        if (ret == NULL) {
            yyerror("Not enough heap memory");
            abort(); 
        }
        sprintf(ret, "Chord* %s=calloc(1,%lu);\n", name, sizeof(Chord));
        break;
    case set_type:
        ret = calloc(BASE_SET_DECL_LEN + strlen(name), sizeof(*ret));
        if (ret == NULL) {
            yyerror("Not enough heap memory");
            abort(); 
        }
        sprintf(ret, "Set* %s=calloc(1,%lu);\n", name, sizeof(Set));
        break;
    default:
        perror("Unknown var type. Aborting...\n");
        abort();
        break;
    }
    return ret;
}

// static char * callocPrint(size_t size) {
//     return "calloc(1,size);\n";
// }

char * printPutVar(char * name, Data data) {
    // switch (data.type)
    // {
    // case num_type:
    //     printf("%s=%d;\n", name, *((int *) data.value));
    //     break;
    // case chord_type:
    //     printf("%s->quant=%d;\n", name, ((Chord *) data.value)->quant);
    //     char * buf = calloc(strlen(name) + strlen("->notes") + 1, sizeof(buf));
    //     if (buf == NULL) {
    //         yyerror("Not enough heap memory");
    //         abort(); 
    //     }
    //     sprintf(buf, "%s->notes", name);
    //     printNoteAssign(buf, (Chord *) data.value);
    //     free(buf);
    //     break;
    // case set_type:
    //     printf("%s->quant=%d;\n", name, ((Set *) data.value)->quant);
    //     printBlockAssign(name, (Set *) data.value);
    //     break;
    // default:
    //     perror("Unknown var type. Aborting...\n");
    //     abort();
    //     break;
    // }
    char * ret;
    if (data.type == num_type) {
        ret = calloc(4 + strlen(name) + strlen(data.print), sizeof(*ret));
        if (ret == NULL) {
            yyerror("Not enough heap memory");
            abort(); 
        }
        sprintf(ret, "%s=%s;\n", name, data.print);
        return ret;
    }
    ret = calloc(BASE_ASSIGN_LEN + strlen(name) * 2 + strlen(data.print), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "auxFree=%s;\n%s=%s;\nfree(auxFree);\n", name, name, data.print);
    return ret;
}

// static void printNoteAssign(char * name, Chord * chord) {
//     printf("%s=malloc(sizeof(*%s)*%d);\n", name, name, chord->quant);
//     struct NoteNode * node = chord->notes;
//     for (int i = 0; i < chord->quant; i++) {
//         printf("%s[i].note=%d;\n", name, node->note);
//         node = node->next;
//     }
// }

// static void printBlockAssign(char * name, Set * set) {
//     printf("%s->blocks=malloc(sizeof(*%s->blocks)*%d);\n", name, name, set->quant);
//     for (int i = 0; i < set->quant; i++) {
//         printf("%s->blocks[i].time=%d;\n", name, set->blocks[i].time);
//         char * buf = calloc(strlen(name) + strlen("->blocks[i].chords") + 1, sizeof(buf));
//         if (buf == NULL) {
//             yyerror("Not enough heap memory");
//             abort(); 
//         }
//         sprintf(buf, "%s->blocks[i].chords", name);
//         printNoteAssign(buf, set->blocks[i].chords);
//         free(buf);
//     }
// }

#define NEW_CHORD_LEN       16
#define BASE_NEW_SET_LEN    10
#define BASE_SET_STAR_LEN   13
#define BASE_SET_BAR_LEN    13
#define BASE_CHORD_ADD_LEN  12
#define BASE_CHORD_SUB_LEN  12
#define BASE_CHORD_CMP_LEN  10
#define BASE_SET_CMP_LEN    12
#define BASE_IF_ELSE_LEN    7
#define BASE_DO_WHILE_LEN   10
#define BASE_WHILE_LEN      6
#define BASE_PLAY_SET_LEN   12


char * printChordConstant(char * chordStr) {
    char * ret = calloc(NEW_CHORD_LEN, sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    int note;
    for (note = C; note < NOTE_COUNT; note++) {
        if (strcmp(chordStr, noteName[note]) == 0) {
            snprintf(ret, NEW_CHORD_LEN, "newChord(\"%s\")", chordStr);
            return ret;
        }
    }

    int stdChord;
    for (stdChord = aC; stdChord < CHORD_COUNT; stdChord++) {
        if (strcmp(chordStr, chordName[stdChord]) == 0) {
            snprintf(ret, NEW_CHORD_LEN, "newChord(\"%s\")", chordStr);
            return ret;
        }
    }
    free(ret);
    yyerror("Not enough heap memory");
    abort(); 
}

char * printNewSet(char * chordPrint, char * timePrint) {
    char * ret = calloc(BASE_NEW_SET_LEN + strlen(chordPrint) + strlen(timePrint), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "newSet(%s,%s)", chordPrint, timePrint);
    return ret;
}

char * printAddParen(char * expPrint) {
    char * ret = calloc(3 + strlen(expPrint), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "(%s)", expPrint);
    return ret;
}

char * printAddBraces(char * print) {
    char * ret = calloc(5 + strlen(print), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "{\n%s}\n", print);
    return ret;
}

/** TODO: Optimizar si ambos NO son variables */
char * printStarNumbers(char * print1, char * print2){
    char * ret = calloc(2 + strlen(print1) + strlen(print2), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "%s*%s", print1, print2);
    return ret;
}

char * printStarSet(char * setPrint, char * timesPrint){
    char * ret = calloc(BASE_SET_STAR_LEN + strlen(setPrint) + strlen(timesPrint), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "setRepeat(%s,%s)", setPrint, timesPrint);
    return ret;
}

/** TODO: Optimizar si ambos NO son variables */
char * printBarNumbers(char * print1, char * print2){
    char * ret = calloc(2 + strlen(print1) + strlen(print2), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "%s/%s", print1, print2);
    return ret;
}

char * printBarSet(char * print1, char * print2){
    char * ret = calloc(BASE_SET_BAR_LEN + strlen(print1) + strlen(print2), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "setConcat(%s,%s)", print1, print2);
    return ret;
}

/** TODO: Optimizar si ambos NO son variables */
char * printAddNumbers(char * print1, char * print2) {
    char * ret = calloc(2 + strlen(print1) + strlen(print2), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "%s+%s", print1, print2);
    return ret;
}

char * printAddChords(char * print1, char * print2) {
    char * ret = calloc(BASE_CHORD_ADD_LEN + strlen(print1) + strlen(print2), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "chordSum(%s,%s)", print1, print2);
    return ret;
}

/** TODO: Optimizar si ambos NO son variables */
char * printSubstractNumbers(char * print1, char * print2) {
    char * ret = calloc(2 + strlen(print1) + strlen(print2), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "%s-%s", print1, print2);
    return ret;
}

char * printSubstractChords(char * print1, char * print2) {
    char * ret = calloc(BASE_CHORD_SUB_LEN + strlen(print1) + strlen(print2), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "chordSub(%s,%s)", print1, print2);
    return ret;
}

char * printMakeComparableChord(char * print) {
    char * ret = calloc(BASE_CHORD_CMP_LEN + strlen(print), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "avgFreq(%s)", print);
    return ret;
}

char * printMakeComparableSet(char * print) {
    char * ret = calloc(BASE_SET_CMP_LEN + strlen(print), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "totalTime(%s)", print);
    return ret;
}

char * printComparison(char * print1, conditions cond, char * print2) {
    char * ret = calloc(3 + strlen(print1) + strlen(print2), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "%s%s%s", print1, getCompareSymbol(cond), print2);
    return ret;
}

char * printNotComparison(char * print) {
    char * ret = calloc(4 + strlen(print), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "!(%s)", print);
    return ret;
}

static char * getCompareSymbol(conditions cond) {
    char * ret;
    switch (cond)
    {
        case and:
            ret = "&&";
            break;
        case or:
            ret = "||";
            break;
        case gt:
            ret = ">";
            break;
        case gte:
            ret = ">=";
            break;
        case lt:
            ret = "<";
            break;
        case lte:
            ret = "<=";
            break;
        case eq:
            ret = "==";
            break;
        case neq:
            ret = "!=";
            break;
        default:
            abort();
    }
    return ret;
}

char * printIfSentence(char * cond, char * ifBody, char * elseBody) {
    bool elsePresent = true;
    if (ifBody == NULL)     ifBody = "";
    if (elseBody == NULL) {
        elseBody = "";
        elsePresent = false;
    }
    char * ret = calloc(BASE_IF_ELSE_LEN + strlen(cond) + strlen(ifBody) + strlen(elseBody), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    if (elsePresent) {
        sprintf(ret, "if%s%selse%s", cond, ifBody, elseBody);
        // printf("if%s%selse%s", cond, ifBody, elseBody);
    } else {
        sprintf(ret, "if%s%s", cond, ifBody);
        // printf("if%s%s", cond, ifBody);
    }
    return ret;
}

char * printDoWhileSentence(char * body, char * cond) {
    char * ret = calloc(BASE_DO_WHILE_LEN + strlen(body) + strlen(cond), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "do%swhile%s;\n", body, cond);
    return ret;
}

char * printWhileSentence(char * body, char * cond) {
    char * ret = calloc(BASE_WHILE_LEN + strlen(body) + strlen(cond), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "while%s%s", cond, body);
    return ret;
}

char * printPlaySet(char * print) {
    char * ret = calloc(BASE_PLAY_SET_LEN + strlen(print), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "playSet(%s);\n", print);
    return ret;
}

char * printConcatProgram(char * p1, char * p2) {
    char * ret = calloc(1 + strlen(p1) + strlen(p2), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "%s%s", p1, p2);
    return ret;
}

void printFullProgram(char * program) {
    printf("int main (const int argc, const char **argv) {\nvoid * auxFree;\nchar auxBuf[BUF_SIZE];\n\n");
    printf("if (argc >= 2) {\n\tchar * auxPtr;\n\tlong int volumePercent = strtol(argv[1], &auxPtr, 10);\n\tif (auxPtr != argv[1]) {\n\t\toutVolume = (volumePercent >= 100) ? 1.0 : (volumePercent / 100.0);\n\t}\n}\n\n");
    printf("%s", program);
    printf("}\n");
}

#define BASE_PRINT_STR_LEN      11
#define BASE_PRINT_NUM_LEN      18
#define BASE_PRINT_CHORD_LEN    15
#define BASE_PRINT_SET_LEN      13
#define BASE_GET_NUM_LEN        45
#define BASE_GET_CHORD_LEN      148

char * printStringLiteral(char * message) {
    char * ret = calloc(BASE_PRINT_STR_LEN + strlen(message), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "printf(%s);\n", message);
    return ret;
}

char * printExpressionValue(Data exp) {
    char * ret;
    switch (exp.type)
    {
    case num_type:
        ret = calloc(BASE_PRINT_NUM_LEN + strlen(exp.print), sizeof(*ret));
        if (ret == NULL) {
            yyerror("Not enough heap memory");
            abort(); 
        }
        sprintf(ret, "printf(\"%%d\\n\",%s);\n", exp.print);
        return ret;
    case chord_type:
        ret = calloc(BASE_PRINT_CHORD_LEN + strlen(exp.print), sizeof(*ret));
        if (ret == NULL) {
            yyerror("Not enough heap memory");
            abort(); 
        }
        sprintf(ret, "printChord(%s);\n", exp.print);
        return ret;
    case set_type:
        ret = calloc(BASE_PRINT_SET_LEN + strlen(exp.print), sizeof(*ret));
        if (ret == NULL) {
            yyerror("Not enough heap memory");
            abort(); 
        }
        sprintf(ret, "printSet(%s);\n", exp.print);
        return ret;
    default:
        abort();
    }
}

char * printGetNumber(char * name) {
    char * ret = calloc(BASE_GET_NUM_LEN + strlen(name), sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "fgets(auxBuf,BUF_SIZE,stdin);\n%s=getNumber(auxBuf);\n", name);
    return ret;
}

char * printGetChord(char * name) {
    char * ret = calloc(BASE_GET_CHORD_LEN + strlen(name) * 3, sizeof(*ret));
    if (ret == NULL) {
        yyerror("Not enough heap memory");
        abort(); 
    }
    sprintf(ret, "fgets(auxBuf,BUF_SIZE,stdin);\nauxBuf[strlen(auxBuf)-1]=\'\\0\';\nauxFree=%s;\n%s=newChord(auxBuf);\nfree(auxFree);\nif(%s==NULL){\nputs(\"Invalid note/chord\\n\");\nexit(1);\n}\n", name, name, name);
    return ret;
}