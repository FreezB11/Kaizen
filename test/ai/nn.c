#include "nn.h"
#include <stdlib.h>

// Function to train the linear regression model
LinearRegressionModel train_linear_regression(double **X, double *y, int num_samples, int num_features) {
    // Allocate memory for coefficients
    double *coefficients = (double *)malloc(num_features * sizeof(double));

    // Initialize variables
    double *sum_x = (double *)calloc(num_features, sizeof(double));
    double sum_y = 0;
    double *sum_xy = (double *)calloc(num_features, sizeof(double));
    double *sum_x_squared = (double *)calloc(num_features, sizeof(double));

    // Calculate sums
    for (int i = 0; i < num_samples; i++) {
        sum_y += y[i];
        for (int j = 0; j < num_features; j++) {
            sum_x[j] += X[i][j];
            sum_xy[j] += X[i][j] * y[i];
            sum_x_squared[j] += X[i][j] * X[i][j];
        }
    }

    // Calculate coefficients
    for (int j = 0; j < num_features; j++) {
        coefficients[j] = (num_samples * sum_xy[j] - sum_x[j] * sum_y) / (num_samples * sum_x_squared[j] - sum_x[j] * sum_x[j]);
    }

    // Calculate intercept
    double intercept = sum_y / num_samples;
    for (int j = 0; j < num_features; j++) {
        intercept -= coefficients[j] * (sum_x[j] / num_samples);
    }

    // Create linear regression model
    LinearRegressionModel model;
    model.coefficients = coefficients;
    model.intercept = intercept;
    model.num_features = num_features;

    return model;
}

// Function to make predictions using the linear regression model
double predict_linear_regression(LinearRegressionModel model, double *x) {
    double prediction = model.intercept;
    for (int j = 0; j < model.num_features; j++) {
        prediction += model.coefficients[j] * x[j];
    }
    return prediction;
}
