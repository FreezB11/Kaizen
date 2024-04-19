// main.c
#include <stdlib.h>
#include <stdio.h>
#include "nn.h"

int main() {
    // Sample data
    double X[][2] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
    double y[] = {2, 4, 5, 4, 5};
    int num_samples = sizeof(X) / sizeof(X[0]);
    int num_features = sizeof(X[0]) / sizeof(X[0][0]);

    // Train the linear regression model
    LinearRegressionModel model = train_linear_regression((double **)X, y, num_samples, num_features);

    // Make predictions
    printf("Linear Regression Model:\n");
    printf("Intercept: %.2f\n", model.intercept);
    printf("Coefficients: ");
    for (int i = 0; i < model.num_features; i++) {
        printf("%.2f ", model.coefficients[i]);
    }
    printf("\n");

    // Test input
    double test_input[] = {6, 7}; // Adjust this array to match the number of features

    // Ensure that test_input matches the number of features
    if (sizeof(test_input) / sizeof(test_input[0]) != num_features) {
        printf("Test input does not match the number of features.\n");
        return 1; // Return with an error code
    }

    // Make prediction for the test input
    printf("Predicted value for test input: %.2f\n", predict_linear_regression(model, test_input));

    // Free allocated memory
    //free(model.coefficients);

    return 0;
}
