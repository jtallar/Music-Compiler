#include <stdio.h>
#include <stdlib.h>
#include "sound.h"


int main(){
    // Define some variables for the sound
    float freq[4][2] = {{440.0, 880.0}, {550.0, 720.0}, {660.0, 550.0}, {440.0, 880.0}};
    float freq2[3] = {440.0, 480.0, 520.0};
    Chord chord[5] = {{freq[0], 2}, {freq[1], 2}, {freq[2], 2}, {freq[3], 2}, {freq2, 3}};
    Set set[5] = {{chord[0], 100}, {chord[1], 150}, {chord[2], 150}, {chord[3], 100}, {chord[4], 1500}};
    Score score = {set, 5};
    
    generateWav(score);

    playSound(WAV_FILE_NAME);

    return 0;
}

int playSound( char *filename ) {
    char command[256];
    int status;
    /* create command to execute */
    sprintf (command, "%s 1 -q -t wav %s", SOUND_COMMAND, filename);

    /* play sound */
    status = system( command );
     
    return status;
}

// Needed function that return freq from given note 
/*Chord newChord( float * freq, int size ){
    Chord chord[size];
    for (int i = 0; i < size; i++){
        chord[i] = freq
    }
    return chord;
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
