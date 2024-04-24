#include <stdio.h>
#include "calculas.h"
#include <math.h>

float df(float (*func)(float),float x){
    // float eps = 1.61011979e-4;
    //float eps = 1.61012e-4;
    float df = (func(x+eps) -func(x-eps))/(2*eps);
    return df;
}

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double sigmoid_derivative(double x) {
    return x * (1.0 - x);
}