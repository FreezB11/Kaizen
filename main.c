#include <stdio.h>
#include "lib/nn.h"

int main(){
    
    float inp[][5] ={{1,2,3,4,5},
                    {2,3,4,5,6},
                    {3,4,5,6,7}}; 

    // float out[];

    float weight[5];

    printf("%ld\n",sizeof(inp)/sizeof(float));

    LinearREG(2,5,inp,weight);

    return 0;
}