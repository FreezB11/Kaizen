#ifndef _NN 
#define _NN 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define nn float
#define nn_initialize float
#define LENS(arr) ((int) (sizeof (arr) / sizeof (arr)[0])) // no of sample sets


nn rand_float(void);
double sigmoid(double x);

void LinearREG(int NOS,int NOI,float inputs[NOS][NOI],float output[],float weights[]);

#endif