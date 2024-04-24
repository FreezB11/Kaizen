#ifndef _NN_H
#define _NN_H

#include <stdlib.h>

struct neuron {
    double input;
    double bias;
    double output;
};

struct layer {
    int num_neurons;
    struct neuron *neurons;
};

struct network {
    int num_layers;
    struct layer *layers;
};

struct network* create_network(int num_layers, int* num_neurons_per_layer);
void link_layers(struct network* net);


#endif // !