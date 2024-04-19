// Sure, here's a simple implementation of a neural network in C to solve the XOR gate problem using a single hidden layer with two neurons:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 2
#define HIDDEN_SIZE 2
#define OUTPUT_SIZE 1
#define LEARNING_RATE 0.01
#define EPOCHS 100000

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double sigmoid_derivative(double x) {
    return x * (1 - x);
}

void forward(double input[], double hidden[], double output[], double weights_ih[][HIDDEN_SIZE], double weights_ho[]) {
    // Forward pass from input to hidden layer
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        double sum = 0;
        for (int j = 0; j < INPUT_SIZE; j++) {
            sum += input[j] * weights_ih[j][i];
        }
        hidden[i] = sigmoid(sum);
    }
    
    // Forward pass from hidden layer to output
    double sum = 0;
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        sum += hidden[i] * weights_ho[i];
    }
    output[0] = sigmoid(sum);
}

void train(double inputs[][INPUT_SIZE], double labels[], double weights_ih[][HIDDEN_SIZE], double weights_ho[]) {
    for (int epoch = 0; epoch < EPOCHS; epoch++) {
        double input[INPUT_SIZE];
        double hidden[HIDDEN_SIZE];
        double output[OUTPUT_SIZE];
        
        int idx = epoch % 4;
        for (int i = 0; i < INPUT_SIZE; i++) {
            input[i] = inputs[idx][i];
        }
        
        forward(input, hidden, output, weights_ih, weights_ho);
        
        // Backpropagation
        double error = labels[idx] - output[0];
        
        // Update weights from hidden to output
        for (int i = 0; i < HIDDEN_SIZE; i++) {
            double delta_ho = error * sigmoid_derivative(output[0]);
            weights_ho[i] += LEARNING_RATE * hidden[i] * delta_ho;
        }
        
        // Update weights from input to hidden
        for (int i = 0; i < HIDDEN_SIZE; i++) {
            double sum = 0;
            for (int j = 0; j < HIDDEN_SIZE; j++) {
                sum += weights_ho[j] * sigmoid_derivative(hidden[j]);
            }
            for (int j = 0; j < INPUT_SIZE; j++) {
                double delta_ih = sum * sigmoid_derivative(hidden[i]) * inputs[idx][j];
                weights_ih[j][i] += LEARNING_RATE * delta_ih;
            }
        }
    }
}

int main() {
    double inputs[4][INPUT_SIZE] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    double labels[4] = {0, 1, 1, 0};
    
    double weights_ih[INPUT_SIZE][HIDDEN_SIZE];
    double weights_ho[HIDDEN_SIZE];
    
    // Initialize weights randomly
    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            weights_ih[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
    }
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        weights_ho[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }
    
    train(inputs, labels, weights_ih, weights_ho);
    
    // Test the trained network
    printf("Testing the trained XOR network:\n");
    for (int i = 0; i < 4; i++) {
        double input[INPUT_SIZE];
        double hidden[HIDDEN_SIZE];
        double output[OUTPUT_SIZE];
        
        for (int j = 0; j < INPUT_SIZE; j++) {
            input[j] = inputs[i][j];
        }
        
        forward(input, hidden, output, weights_ih, weights_ho);
        
        printf("Input: %d %d, Output: %.2f\n", (int)input[0], (int)input[1], output[0]);
    }
    
    return 0;
}


// This code trains a neural network with one hidden layer to learn the XOR function. It uses a sigmoid activation function and backpropagation for training. The weights are initialized randomly, and the network is trained for a fixed number of epochs. Finally, it tests the trained network on all possible inputs to verify its performance.