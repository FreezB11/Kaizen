#ifndef _NN 
#define _NN 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define nn float
#define nn_initialize float


nn rand_float(void);
double sigmoid(double x);
void LinearREG(float input[],float *weight,int length);

#endif