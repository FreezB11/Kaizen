#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 3 // Example input size
#define NUM_TRAINING_SETS 2 // Example number of training sets
#define LEARNING_RATE 0.1 // Example learning rate
#define NUM_EPOCHS 1000 // Example number of training epochs

struct neuron {
    double input;
    double bias;
    double output;
    double delta; // Delta value used for backpropagation
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

double sigmoid_derivative(double x) {
    return x * (1.0 - x);
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

void backpropagation(struct network* net, double* target) {
    // Backpropagate the error from the output layer to the previous layers
    for (int i = net->num_layers - 1; i > 0; i--) {
        for (int j = 0; j < net->layers[i].num_neurons; j++) {
            struct neuron* neuron = &net->layers[i].neurons[j];
            // Calculate the error for the output layer
            if (i == net->num_layers - 1) {
                neuron->delta = (target[j] - neuron->output) * sigmoid_derivative(neuron->output);
            } else {
                // Calculate the error for hidden layers
                neuron->delta = 0.0;
                for (int k = 0; k < net->layers[i + 1].num_neurons; k++) {
                    neuron->delta += net->layers[i + 1].neurons[k].delta * 1.0; // Assuming all neurons are connected
                }
                neuron->delta *= sigmoid_derivative(neuron->output);
            }
        }
    }
}

void update_weights(struct network* net) {
    // Update weights and biases using the calculated deltas
    for (int i = 1; i < net->num_layers; i++) {
        for (int j = 0; j < net->layers[i].num_neurons; j++) {
            struct neuron* neuron = &net->layers[i].neurons[j];
            for (int k = 0; k < net->layers[i - 1].num_neurons; k++) {
                // Update weights
                // Example of weight update using gradient descent
                // Adjust the weight by adding the product of the input, delta, and learning rate
                neuron->input += net->layers[i - 1].neurons[k].output * neuron->delta * LEARNING_RATE;
            }
            // Update bias
            neuron->bias += neuron->delta * LEARNING_RATE;
        }
    }
}

void train_network(struct network* net, double** inputs, double** targets, int num_training_sets) {
    for (int epoch = 0; epoch < NUM_EPOCHS; epoch++) {
        for (int set = 0; set < num_training_sets; set++) {
            // Forward propagation
            feed_forward(net, inputs[set]);
            // Backpropagation
            backpropagation(net, targets[set]);
            // Update weights and biases
            update_weights(net);
        }
    }
}

int main() {
    int num_layers = 3;
    int num_neurons_per_layer[] = {INPUT_SIZE, 4, 2}; // Example network architecture
    struct network* net = create_network(num_layers, num_neurons_per_layer);
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
