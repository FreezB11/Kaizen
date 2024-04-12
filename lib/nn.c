#include "nn.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define RAND_MAX 2147483647
// nn normalization(float input[]){

// }

// int NOS;// no of samples 
// int NOI;// no of inputs

float rand_float(void){
    return (float)rand()/(float)RAND_MAX;
}

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}
// int NOS = 0;
// int NOI = 0;

void LinearREG(int NOS,int NOI,float inputs[NOS][NOI],float weights[]){
    // defining weights array based on the size of the input array..
    int size = NOI;// sizeof(inputs)/sizeof(inputs[0]);
    int summ = 0;  
    srand(time(0));
    nn_initialize bias = rand_float();
  
    for(size_t i=0;i<size;i++){
        weights[i] = rand_float()*10.0f;
    }
    printf("%d %d\n",NOS,NOI);
    
   
    
    for (int i=0;i<NOS;i++){
        for(int j=0;j<NOI;j++){
            // printf("%d %d\n",j,i);
            printf("%f\n",inputs[i][j]);
            summ += (inputs[i][j])*weights[i];
        }
        summ += bias;
    }
}