#include "nn.h"
#include <stdio.h>


int main(){

    float input[4][2] = {{0,0},{0,1},{1,0},{1,1}};
    float output[4] = {0,0,0,1};

   neuron *n = createNeuron(5);

   printf("%f\n",n->input[0]);

    return 0;
}