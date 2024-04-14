#include "nn.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define RAND_MAX 2147483647

float eps = 1.61012e-4;

float rand_float(void){
    return (float)rand()/(float)RAND_MAX;
}

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

float cost(int NOS,int NOI,float inputs[NOS][NOI],float output[],float weights[],float bias){
    float result = 0.0f;
     for (int i=0;i<NOS;i++){
        float summ = 0.0f;
        for(int j=0;j<NOI;j++){
            summ += (inputs[i][j])*(weights[j]);
        }
        float y = sigmoid(summ+bias);
        float d = y-output[i];
        result += y*y;
    }
    result /= NOS;
    return result;
}

void LinearREG(int NOS,int NOI,float inputs[NOS][NOI],float output[],float weights[]){
    // defining weights array based on the size of the input array..
    float summ = 0.0f;
    //srand(time(0));
    nn_initialize bias = rand_float();
    printf("bais == %f\n",bias);
    for(int i=0;i<NOI;i++){
        weights[i] = rand_float()*10.0f;
        printf("weight[%d]==%f\n",i,weights[i]);
    }
    float c1,c2;
    float dw1;
    float costt = cost(NOS,NOI,inputs,output,weights,bias);
    printf("%f\n",costt);
}