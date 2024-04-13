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

float cost(float weights[],float bias){

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
    float cost = 0.0f;
    for (int i=0;i<NOS;i++){
        summ = 0.0f;
        for(int j=0;j<NOI;j++){
            // printf("i1=%f w1=%f\n",inputs[i][j],weights[j]);
            summ += (inputs[i][j])*(weights[j]);
        }
        float y = sigmoid(summ+bias);
        // cost += ((y-output[i])*(y-output[i]));
        // cost = cost/NOS;
        // printf("predicted=%f,, actual==%f,,, cost == %f\n",y,output[i],cost);
        // // printf("sum=%f\n",summ+bias);
        // for(int it=0;it<10000;it++){

        // }
    }
}