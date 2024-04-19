#ifndef _NN_H_
#define _NN_H_

#include <stdlib.h>

#define LENS(arr) ((int) (sizeof (arr) / sizeof (arr)[0])) // no of sample sets


// non => no of neuron
//noi => no of input
//nos => no of samples
//nol => no of layers

typedef struct{
    int noi;
    float *input;
    float bias;
    float output;
}neuron;

typedef struct{
    int non;
    neuron *neurons;
}nlayer;


typedef struct{
    int NOS;
    int NOI;
    nlayer *nol;
}Nnetwrk;

neuron *createNeuron(int noi);
nlayer *createLayer(int non,int non_prevLayer);


Nnetwrk *initialize(int nol);
Nnetwrk forward(Nnetwrk neural);


 
#endif