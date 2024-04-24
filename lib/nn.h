#ifndef _NN_H
#define _NN_H

#include <stdlib.h>

typedef struct {
    double input;
    double bias;
    double output;
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