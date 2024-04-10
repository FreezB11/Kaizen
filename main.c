#include <stdio.h>
#include "lib/nn.h"

int main(){
    
    float inp[2][5] ={{1,2,3,4,5},
                    {2,3,4,5,6}}; 

    float weight[5];


    LinearREG(inp,weight,5);

    // for (size_t i = 0; i < 5; i++)
    // {
        // printf("%f\n",weight[i]);
    // }
    

    //printf("hello\n");

    return 0;
}