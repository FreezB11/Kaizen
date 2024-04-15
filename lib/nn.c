#include "nn.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define RAND_MAX 2147483647

float eps = 1.61012e-2;

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
    float w1[NOI];
    float w2[NOI];
    //srand(time(0));
    nn_initialize bias = rand_float();
    printf("bais == %f\n",bias);
    for(int i=0;i<NOI;i++){
        weights[i] = rand_float()*10.0f;
        w1[i]=weights[i];
        printf("weight[%d]==%f\n",i,weights[i]);
    }
    float c1,c2;
    float costt = cost(NOS,NOI,inputs,output,weights,bias);
    printf("initial cost==%f\n",costt);
 
    for (int i = 0; i < NOI; i++)
    {
        w1[i] += eps;
        c1 = cost(NOS,NOI,inputs,output,w1,bias);
        w1[i] -= eps;
        printf("c1 == %f\n",c1);
        w2[i] -= eps;
        c2 = cost(NOS,NOI,inputs,output,w2,bias); 
        w2[i] += eps;
        printf("c2 == %f\n",c2);
    }
    










    // for (int i = 0; i < NOI; i++)
    // {
    //     weights[i] += eps;
    //     c1 = cost(NOS,NOI,inputs,output,weights,bias); 
    //     // weights[i] += 3*eps;
    //     printf("%f\n",c1);
    //     weights[i] -= 2*eps;
    //     c2 = cost(NOS,NOI,inputs,output,weights,bias);
    //     weights[i] += 2*eps;
    //     printf("%f\n",c2);
    // }
}