#include "nn.h"
#include "stdlib.h"


network* create_network(int num_layers, int* num_neurons_per_layer) {
    network* net = (network*)malloc(sizeof(network));
    net->num_layers = num_layers;
    net->layers = (layer*)malloc(num_layers * sizeof(layer));
    
    for (int i = 0; i < num_layers; i++) {
        net->layers[i].num_neurons = num_neurons_per_layer[i];
        net->layers[i].neurons = (neuron*)malloc(num_neurons_per_layer[i] * sizeof(neuron));
    }
    
    return net;
}

void link_layers(network* net) {
    for (int i = 0; i < net->num_layers - 1; i++) {
        for (int j = 0; j < net->layers[i].num_neurons; j++) {
            net->layers[i].neurons[j].output = 0.0; // Initialize output to zero for each neuron
            net->layers[i].neurons[j].bias = 0.0;   // Initialize bias to zero for each neuron
            for (int k = 0; k < net->layers[i + 1].num_neurons; k++) {
                // Establish connections between neurons in adjacent layers
                // Set the output of neurons in the current layer as the input of neurons in the next layer
                // For simplicity, let's assume each neuron in the next layer receives input from all neurons in the current layer
                net->layers[i + 1].neurons[k].input += net->layers[i].neurons[j].output;
            }
        }
    }
}
