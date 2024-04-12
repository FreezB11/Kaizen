#include <stdio.h>
#include "lib/nn.h"

int main(){
    
    float inp[][5] ={{1,2,3,4,5},
                    {2,3,4,5,6},
                    {3,4,5,6,7},
                    {4,5,6,7,8}}; 

    // float out[];

    float weight[5];

    // printf("%d\n",LEN(inp));

    LinearREG(LENS(inp),5,inp,weight);

    return 0;
}