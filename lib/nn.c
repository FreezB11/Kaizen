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

void LinearREG(int NOS,int NOI,float inputs[NOS][NOI],float output[],float weights[]){
    // defining weights array based on the size of the input array..
    float summ = 0.0f;  
    srand(time(0));
    nn_initialize bias = rand_float();
    printf("bais == %f\n",bias);
    for(int i=0;i<NOI;i++){
        weights[i] = rand_float()*10.0f;
        printf("weight[%d]==%f\n",i,weights[i]);
    }

    for (int i=0;i<NOS;i++){
        for(int j=0;j<NOI;j++){
            printf("%f\n",inputs[i][j]);
            summ += (inputs[i][j])*weights[i];
        }
        summ += bias;
        printf("sum = %f\n",summ);
    }
}