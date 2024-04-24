#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 4 // Example input size

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

void link_layers(struct network* net) {
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

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

void feed_forward(struct network* net, double* input) {
    // Set input values for the input layer
    for (int i = 0; i < net->layers[0].num_neurons; i++) {
        net->layers[0].neurons[i].output = input[i];
    }

    // Forward propagation through the network
    for (int i = 1; i < net->num_layers; i++) {
        for (int j = 0; j < net->layers[i].num_neurons; j++) {
            double sum = 0.0;
            // Calculate the weighted sum of inputs
            for (int k = 0; k < net->layers[i - 1].num_neurons; k++) {
                sum += net->layers[i - 1].neurons[k].output; // Input from the previous layer's neurons
            }
            sum += net->layers[i].neurons[j].bias; // Add bias
            // Apply activation function (sigmoid in this case)
            net->layers[i].neurons[j].output = sigmoid(sum);
        }
    }
}

int main() {
    int num_layers = 3;
    int num_neurons_per_layer[] = {INPUT_SIZE, 4, 2}; // Example network architecture
    struct network* net = create_network(num_layers, num_neurons_per_layer);
    link_layers(net);

    // Example input
    double input[INPUT_SIZE] = {0.5, 0.3, 0.8, 0.9};
    feed_forward(net, input);

    // Accessing output of the last layer (assuming it's the output layer)
    printf("Output of the network:\n");
    for (int i = 0; i < net->layers[num_layers - 1].num_neurons; i++) {
        printf("Neuron %d: %.4f\n", i, net->layers[num_layers - 1].neurons[i].output);
    }

    // Free memory
    for (int i = 0; i < num_layers; i++) {
        free(net->layers[i].neurons);
    }
    free(net->layers);
    free(net);

    return 0;
}
