#include "nn.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define RAND_MAX 2147483647
#define rate 0.001f
float eps = 1.61012e-3;

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

void LinearREG(int NOS,int NOI,float inputs[NOS][NOI],float output[],float weights[],float *bias){
    // defining weights array based on the size of the input array..
    float summ = 0.0f;
    float w1[NOI];
    float w2[NOI];
    float dw[NOI];
    //srand(time(0));
    *bias = rand_float();
    printf("bais == %f\n",*bias);
    for(int i=0;i<NOI;i++){
        weights[i] = rand_float()*10.0f;
        w1[i]=weights[i];
        printf("weight[%d]==%f\n",i,weights[i]);
    }
    float c1,c2;
    float costt = cost(NOS,NOI,inputs,output,weights,*bias);
    printf("initial cost==%f\n",costt);
 
    
    for(int k=0;k<1000*1000;k++){
        for (int i = 0; i < NOI; i++)
        {
            w1[i] += eps;
            w2[i] -= eps;
            dw[i] = (cost(NOS,NOI,inputs,output,w1,*bias)-cost(NOS,NOI,inputs,output,w2,*bias))/(2*eps);
            w1[i] -= eps;
            w2[i] += eps;
            float db = (cost(NOS,NOI,inputs,output,w1,*bias+eps)-cost(NOS,NOI,inputs,output,w2,*bias-eps))/(2*eps);
            weights[i] -= rate*(dw[i]);
            *bias -= rate*db;
            w1[i] = weights[i];
            w2[i] = weights[i];
        }
        float costRUNT = cost(NOS,NOI,inputs,output,weights,*bias);
        //printf("cost == %f\n",costRUNT);
    }

    float costAFT = cost(NOS,NOI,inputs,output,weights,*bias);
    printf("AFTER cost==%f\n",costAFT);
    
    for(int i=0;i<NOI;i++){
        printf("after train weight[%d]==%f\n",i,weights[i]);
    }
    printf("after train bias == %f\n",*bias);


}