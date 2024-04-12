#include <stdio.h>
#define import #include

#include "lib/nn.h"

int main(){
    
    float inp[][5] ={{1,2,3,4,5},
                    {2,3,4,5,6}}; 

    float weight[5];

    

    LinearREG(2,5,inp,weight);

    // for (size_t i = 0; i < 5; i++)
    // {
        // printf("%f\n",weight[i]);
    // }
    
    // printf("hello from main file\n");

    return 0;
}