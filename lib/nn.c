#include "nn.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define RAND_MAX 2147483647

float rand_float(void){
    return (float)rand()/(float)RAND_MAX;
}

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

float cost(float weight[],float bias){

}

void LinearREG(int NOS,int NOI,float inputs[NOS][NOI],float output[],float weights[]){
    // defining weights array based on the size of the input array..
    float summ = 0;  
    srand(time(0));
    nn_initialize bias = rand_float();
  
    for(size_t i=0;i<NOI;i++){
        weights[i] = rand_float()*10.0f;
    }
    for (int i=0;i<NOS;i++){
        for(int j=0;j<NOI;j++){
            summ += (inputs[i][j])*weights[i];
        }
        summ += bias;
        // printf("%f, %f\n",summ,bias);
    }
}