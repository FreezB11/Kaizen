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

neuron *createNeuron(int noi,float inputs[]){

    neuron *n = (neuron*)malloc(sizeof(neuron));
    n->input = (float*)malloc(noi*sizeof(float));

    for (size_t i = 0; i < noi; i++)
    {
        n->input[i] = inputs[i];
    }

    n->bias = rand();

    return n;
}

nlayer *createLayer(int non,int non_prevLayer){
    nlayer *layer = (nlayer*)malloc(sizeof(nlayer));
    layer->neurons = (neuron**)malloc(non*sizeof(neuron));

    for (size_t i = 0; i < non; i++){
        layer->neurons[i] = createNeuron(non_prevLayer,0); // here i have to put smtg else in place of 0(ZERO)
    }
    return layer;
}