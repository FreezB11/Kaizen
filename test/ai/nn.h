// nn.h

#ifndef NN_H
#define NN_H

// Structure to hold the linear regression model parameters
typedef struct {
    double *coefficients; // Array to store coefficients for each input feature
    double intercept;
    int num_features;
} LinearRegressionModel;

// Function to train the linear regression model
LinearRegressionModel train_linear_regression(double **X, double *y, int num_samples, int num_features);

// Function to make predictions using the linear regression model
double predict_linear_regression(LinearRegressionModel model, double *x);

#endif // NN_H
