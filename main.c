#include <stdio.h>
#include "lib/nn.h"
#include "lib/calculas.h"

int main(){
    
    float inp[][2] ={{0,0},
                    {1,0},
                    {0,1},
                    {1,1}}; 

    float output[4]={0,0,0,1};

    float weight[5];

    LinearREG(LENS(inp),2,inp,output,weight);
    return 0;
}