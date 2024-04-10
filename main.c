#include <stdio.h>
#include "lib/nn.h"

int main(){
    
    float inp[] ={1,2,3,4,5}; 

    float weight[5];


    LinearREG(inp,weight,5);

    for (size_t i = 0; i < 5; i++)
    {
        printf("%f\n",weight[i]);
    }
    

    printf("hello\n");

    return 0;
}