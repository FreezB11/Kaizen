#include <stdlib.h>
#include <stdio.h>
#include "lib/nn.h"

#define INPUT_SIZE 3 // Example input size
#define NUM_TRAINING_SETS 2 // Example number of training sets

int main() {
    int num_layers = 4;
    int num_neurons_per_layer[] = {INPUT_SIZE, 6,4, 2}; // Example network architecture
    network* net = create_network(num_layers, num_neurons_per_layer);
    link_layers(net);

    // Example training data
    double input_set1[INPUT_SIZE] = {0.5, 0.3, 0.8};
    double target_set1[2] = {0.7, 0.9};
    double input_set2[INPUT_SIZE] = {0.2, 0.6, 0.4};
    double target_set2[2] = {0.5, 0.8};

    double* inputs[NUM_TRAINING_SETS] = {input_set1, input_set2};
    double* targets[NUM_TRAINING_SETS] = {target_set1, target_set2};

    // Train the network
    train_network(net, inputs, targets, NUM_TRAINING_SETS);

    // Forward pass to get the output after training
    feed_forward(net, input_set1);

    // Accessing output of the last layer (assuming it's the output layer)
    printf("Output of the network after training with input set 1:\n");
    for (int i = 0; i < net->layers[num_layers - 1].num_neurons; i++) {
        printf("Neuron %d: %.4f\n", i, net->layers[num_layers - 1].neurons[i].output);
    }

    // Forward pass with input set 2
    feed_forward(net, input_set2);

    // Accessing output of the last layer (assuming it's the output layer)
    printf("\nOutput of the network after training with input set 2:\n");
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
