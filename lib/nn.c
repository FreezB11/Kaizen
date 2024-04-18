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
        //float y = summ +bias;
        float d = y-output[i];
        result += y*y;
    }
    result /= NOS;
    return result;
}

void Ntest(double *x){
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%f\n",*((x + i * 2) + j));
        }
        
    }
    
}

NN *create(int NOS,int NOI){
    NN *neural = (NN*)malloc(sizeof(NN));
    if (neural == NULL){
        printf("Memory allocation failed.\n");
        exit(1); // Exit program if memory allocation fails
    }
    neural->nos = NOS;
    neural->noi = NOI;
    
}

void LinearREG(int NOS,int NOI,float inputs[NOS][NOI],float output[NOS],float weights[NOI],float *bias){
    // defining weights array based on the size of the input array..
    float summ = 0.0f;
    float w1[NOI];
    float w2[NOI];
    float dw[NOI];
    srand(time(0));
    *bias = rand_float();
    printf("bais == %f\n",*bias);
    for(int i=0;i<NOI;i++){
        weights[i] = rand_float()*10.0f;
        w2[i]=w1[i]=weights[i];
        printf("weight[%d]==%f\n",i,weights[i]);
    }
    
    float costt = cost(NOS,NOI,inputs,output,weights,*bias);
    printf("initial cost==%f\n",costt);
 
    for(int k=0;k<1100;k++){
        for (int i = 0; i < NOI; i++)
        {
            w1[i] += eps;
            dw[i] = (cost(NOS,NOI,inputs,output,w1,*bias)-costt)/(eps);
            weights[i] -= rate*dw[i];
            w1[i] = weights[i];
            //w1[i] -= eps;

        }
        float db = (cost(NOS,NOI,inputs,output,w2,*bias+eps)-costt)/(eps);
        *bias -= rate*db;
        // float costRUNT = cost(NOS,NOI,inputs,output,weights,*bias);
        //printf("cost == %f\n",costRUNT);
    }

    float costAFT = cost(NOS,NOI,inputs,output,weights,*bias);
    printf("AFTER cost==%f\n",costAFT);
    
    for(int i=0;i<NOI;i++){
       printf("after train weight[%d]==%f\n",i,weights[i]);
    }
    printf("after train bias == %f\n",*bias);


}