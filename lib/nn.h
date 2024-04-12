#ifndef _NN 
#define _NN 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define nn float
#define nn_initialize float

// int NOS;// no of samples 
// int NOI;// no of inputs


nn rand_float(void);
double sigmoid(double x);

void LinearREG(int NOS,int NOI,float inputs[NOS][NOI],float weights[]);

#endif