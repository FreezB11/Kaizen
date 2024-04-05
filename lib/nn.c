#include "nn.h"
#include <stdio.h>

nn LinearREG(float inputs[]){
    // defining weights array based on the size of the input array..
    int size = sizeof(inputs)/sizeof(inputs[0]);
    nn_initialize weights[size];
    nn_initialize bias;

    int summ = 0;

    for(size_t i=0;i<size;i++){
        summ += inputs[i]*weights[i];
    }

}