#include <stdio.h>
#include "lib/nn.h"

int main(){
    
    float inputs[5]={1,2,3,4,4};
    int size = sizeof(inputs)/sizeof(inputs[0]);

    //printf("from main %d === %lu\n",size,sizeof(inputs[0]));

    nn_initialize weights[size];

    LinearREG(inputs,weights);

    // for(int i=0;i<size;i++){
        // printf("%f\n",weights[i]);
    // }

    return 0;
}