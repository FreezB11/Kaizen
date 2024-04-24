#ifndef _NN_H
#define _NN_H

#include <stdlib.h>
#include "math/calculas.h"

#define LEARNING_RATE 0.1 // Example learning rate
#define NUM_EPOCHS 100*100 // Example number of training epochs

typedef struct {
    double input;
    double bias;
    double output;
    double delta;
} neuron;

typedef struct {
    int num_neurons;
    neuron *neurons;
} layer;

typedef struct {
    int num_layers;
    layer *layers;
}network;

network* create_network(int num_layers, int* num_neurons_per_layer);
void link_layers(network* net);


#endif // !