#include "nn.h"
#include <stdlib.h>

/*

typedef struct{
    int NOS;
    int NOI;
    double *inputs;
    double *weights;
    float bias;
}NN;

*/

neuron *createNeuron(int noi){

    neuron *n = (neuron*)malloc(sizeof(neuron));
    n->input = (float*)malloc(noi*sizeof(float));
    n->input[0]=69;
    n->bias = rand();

    return n;
}
