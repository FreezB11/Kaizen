#include <stdlib.h>
#include <stdio.h>
#include "lib/nn.h"

#define INPUT_SIZE 2 // Example input size
#define NUM_TRAINING_SETS 4 // Example number of training sets

int main() {
    int num_layers = 3;
    int num_neurons_per_layer[] = {INPUT_SIZE,2,1}; // Example network architecture
    network* net = create_network(num_layers, num_neurons_per_layer);
    //link_layers(net);

    // Example training data
    double input_set1[INPUT_SIZE] = {0,0};
    double target_set1[1] = {0};
    double input_set2[INPUT_SIZE] = {0,1};
    double target_set2[1] = {1};
    double input_set3[INPUT_SIZE] = {1,0};
    double target_set3[1] = {1};
    double input_set4[INPUT_SIZE] = {1,1};
    double target_set4[1] = {0};

    double* inputs[NUM_TRAINING_SETS] = {input_set1, input_set2,input_set3,input_set4};
    double* targets[NUM_TRAINING_SETS] = {target_set1, target_set2,target_set3,target_set4};

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
    feed_forward(net, input_set3);

    // Accessing output of the last layer (assuming it's the output layer)
    printf("\nOutput of the network after training with input set 3:\n");
    for (int i = 0; i < net->layers[num_layers - 1].num_neurons; i++) {
        printf("Neuron %d: %.4f\n", i, net->layers[num_layers - 1].neurons[i].output);
    }
    feed_forward(net, input_set4);

    // Accessing output of the last layer (assuming it's the output layer)
    printf("\nOutput of the network after training with input set 4:\n");
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
