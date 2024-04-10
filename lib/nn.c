#include "nn.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define RAND_MAX 2147483647
// nn normalization(float input[]){

// }

int NOS;// no of samples 
int NOI;// no of inputs

float rand_float(void){
    return (float)rand()/(float)RAND_MAX;
}

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}


void LinearREG(float inputs[NOS][NOI],float weights[],int length){
    // defining weights array based on the size of the input array..
    int size = length;// sizeof(inputs)/sizeof(inputs[0]);
    srand(time(0));
    nn_initialize bias = rand_float();

    int summ = 0;

    for(size_t i=0;i<size;i++){
        //printf("%f\n",inputs[i]);
        weights[i] = rand_float()*10.0f;
    }

    for (size_t j;j<NOS;j++ ){

        for(size_t i=0;i<NOI;i++){
            printf("%f",inputs[i][j]);
            summ += (inputs[i][j])*weights[i];
        }
        summ += bias;
    }
}