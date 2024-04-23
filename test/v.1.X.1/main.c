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

struct network* create_network(int num_layers, int* num_neurons_per_layer) {
    struct network* net = (struct network*)malloc(sizeof(struct network));
    net->num_layers = num_layers;
    net->layers = (struct layer*)malloc(num_layers * sizeof(struct layer));
    
    for (int i = 0; i < num_layers; i++) {
        net->layers[i].num_neurons = num_neurons_per_layer[i];
        net->layers[i].neurons = (struct neuron*)malloc(num_neurons_per_layer[i] * sizeof(struct neuron));
    }
    
    return net;
}

int main() {
    int num_layers = 3;
    int num_neurons_per_layer[] = {5, 3, 2};
    
    struct network* net = create_network(num_layers, num_neurons_per_layer);
    
    // Now net contains the initialized network with the respective number of layers and neurons
    
    // Don't forget to free memory when done
    for (int i = 0; i < num_layers; i++) {
        free(net->layers[i].neurons);
    }
    free(net->layers);
    free(net);
    
    return 0;
}