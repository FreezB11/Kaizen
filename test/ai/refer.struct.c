#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 2
#define HIDDEN_SIZE 3
#define OUTPUT_SIZE 1
#define LEARNING_RATE 0.1
#define EPOCHS 10000

// Sigmoid activation function
double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

// Derivative of the sigmoid function
double sigmoid_derivative(double x) {
    return x * (1 - x);
}

// Neuron structure
typedef struct {
    double output;
    double *weights;
    double bias;
} Neuron;

// Layer structure
typedef struct {
    int num_neurons;
    Neuron *neurons;
} Layer;

// Create a neuron
Neuron create_neuron(int num_inputs) {
    Neuron neuron;
    neuron.output = 0;
    neuron.bias = ((double)rand() / RAND_MAX) * 2 - 1; // Random bias between -1 and 1
    neuron.weights = (double *)malloc(num_inputs * sizeof(double));
    for (int i = 0; i < num_inputs; i++) {
        neuron.weights[i] = ((double)rand() / RAND_MAX) * 2 - 1; // Random weight between -1 and 1
    }
    return neuron;
}

// Create a layer
Layer create_layer(int num_neurons, int num_inputs_per_neuron) {
    Layer layer;
    layer.num_neurons = num_neurons;
    layer.neurons = (Neuron *)malloc(num_neurons * sizeof(Neuron));
    for (int i = 0; i < num_neurons; i++) {
        layer.neurons[i] = create_neuron(num_inputs_per_neuron);
    }
    return layer;
}

int main() {
    // Example of creating a layer with 3 neurons, each having 2 inputs
    Layer input_layer = create_layer(INPUT_SIZE, 1);
    Layer hidden_layer = create_layer(HIDDEN_SIZE, INPUT_SIZE);
    Layer output_layer = create_layer(OUTPUT_SIZE, HIDDEN_SIZE);

    // Accessing individual neurons
    printf("Bias of neuron 0 in the hidden layer: %lf\n", hidden_layer.neurons[1].bias);

    // Freeing memory
    for (int i = 0; i < input_layer.num_neurons; i++) {
        free(input_layer.neurons[i].weights);
    }
    free(input_layer.neurons);
    
    for (int i = 0; i < hidden_layer.num_neurons; i++) {
        free(hidden_layer.neurons[i].weights);
    }
    free(hidden_layer.neurons);
    
    for (int i = 0; i < output_layer.num_neurons; i++) {
        free(output_layer.neurons[i].weights);
    }
    free(output_layer.neurons);

    return 0;
}
