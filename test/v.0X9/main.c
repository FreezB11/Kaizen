#include "nn.h"
#include <stdio.h>


int main(){

    //float input[4][2] = {{0,0},{0,1},{1,0},{1,1}};
    float output[4] = {0,0,0,1};

    float input[5]={1,4,0,5,9};
    neuron *n = createNeuron(5,input);

    printf("%f\n",n->input[4]);

    return 0;
}