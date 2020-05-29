#include <stdio.h>
#include <stdlib.h>
#include "sound.h"

enum notes_enum{ C=0, Cs, D, Ds=3, E, F, Fs=6, G, Gs, A=9, As, B };
enum chords_enum{ aC=0, aCm, aD, aDm=3, aE, aEm, aF=6, aFm, aG, aGm=9, aA, aAm, aB=12, aBm };

float notes[] = { /*C*/ 65.41, 69.30, 73.42, 77.78, 82.41, 87.31, 92.50, 98.00, 103.83, 110.00, 116.54, 123.47 /*B*/};

// Cada nota tiene 8 registros, para obtener el registro n de la nota A -> notesFreq[A] * 2^(n-1)

int main(){

    float chordsFreqs[14][3] = {{notes[C],notes[E],notes[G]}, {notes[C],notes[Ds],notes[G]}, {notes[D],notes[Fs],notes[A]}, {notes[D],notes[F],notes[A]},
                                {notes[E],notes[Gs],notes[B]}, {notes[E],notes[G],notes[B]}, {notes[F],notes[A],notes[C]}, {notes[F],notes[Gs],notes[C]},
                                 {notes[G],notes[B],notes[D]}, {notes[G],notes[As],notes[A]}, {notes[A],notes[Cs],notes[E]}, {notes[A],notes[C],notes[E]},
                                  {notes[B],notes[Ds],notes[Fs]}, {notes[B],notes[E],notes[G]} };

    Chord realChords[14] = {   /*C */{ chordsFreqs[aC],3  },
                               /*Cm*/{ chordsFreqs[aCm],3 },
                                     { chordsFreqs[aD],3  },
                                     { chordsFreqs[aDm],3 },
                                     { chordsFreqs[aE],3  },
                                     { chordsFreqs[aEm],3 },
                                     { chordsFreqs[aF],3  },
                                     { chordsFreqs[aFm],3 },
                                     { chordsFreqs[aG],3  },
                                     { chordsFreqs[aGm],3 },
                                     { chordsFreqs[aA],3  },
                                     { chordsFreqs[aAm],3 },
                               /*B */{ chordsFreqs[aB],3  },
                               /*Bm*/{ chordsFreqs[aBm],3 }     };

    // Define some variables for the sound
    //float freqs[4][2] = {{440.0, 880.0}, {550.0, 720.0}, {660.0, 550.0}, {440.0, 880.0}};
    //float freqs2[3] = {440.0, 480.0, 520.0};
    //Chord chord[5] = {{freqs[0], 2}, {freqs[1], 2}, {freqs[2], 2}, {freqs[3], 2}, {freqs2, 3}};
    //Set set[5] = {{chord[0], 500}, {chord[1], 150}, {chord[2], 150}, {chord[3], 100}, {chord[4], 1500}};
    Set set[7] = {{realChords[aC], 500}, {realChords[aD], 500}, {realChords[aE], 500},{realChords[aFm], 500}, {realChords[aG], 500}, {realChords[aA], 500}, {realChords[aB], 1000}};
    Set setfc[12] = {{realChords[aC], 500}, {realChords[aC], 500}, {realChords[aD], 500},{realChords[aC], 500}, {realChords[aF], 500}, {realChords[aE], 800},
        {realChords[aC], 500}, {realChords[aC], 500}, {realChords[aD], 500},{realChords[aC], 500}, {realChords[aG], 500}, {realChords[aF], 800}};

    Score score = {setfc, 12};
    
    generateWav(score);

    playWav(WAV_FILE_NAME);

    return 0;
}

int playWav( char *filename ) {
    char command[256];
    int status;
    /* create command to execute */
    sprintf (command, "%s %s", SOUND_COMMAND, filename);

    /* play sound */
    status = system( command );
     
    return status;
}

// Needed function that return freq from given note 
/*Chord newChord( float * freq, int size ){
    Chord chord[size];
    for (int i = 0; i < size; i++){
        chord[i] = freq
    }    return chord;
}

Set newSet( Chord c, long time ){

}

Score newScore( Set * s, int size ){

}*/


/*      
**      Ejemplo: 
**		chord a = A + B + C
**		set s = [a 30]
**		set h = [G 1]
**      set f = [_ 5]
**		set d = (h / f) * 10
**		set b = ( s * 4 / [G 10] / s * 1 ) * 20
*/
