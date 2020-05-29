#include <stdio.h>
#include "sound.h"

int main(){
    // Define some variables for the sound
    float freq[4][2] = {{440.0, 880.0}, {550.0, 720.0}, {660.0, 550.0}, {440.0, 880.0}};
    float freq2[3] = {440.0, 480.0, 520.0};
    Chord chord[5] = {{freq[0], 2}, {freq[1], 2}, {freq[2], 2}, {freq[3], 2}, {freq2, 3}};
    Set set[5] = {{chord[0], 100}, {chord[1], 150}, {chord[2], 150}, {chord[3], 100}, {chord[4], 1500}};
    Score score = {set, 5};
    
    generateWav(score);

    return 0;
}


//