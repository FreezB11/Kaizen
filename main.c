#include <stdio.h>
#include "lib/nn.h"
#include "lib/calculas.h"

#define inp_size 2

int main(){
    
    float inp[][inp_size] ={{0,0,},
                    {1,0},
                    {0,1},
                    {1,1}}; 

    float output[4]={0,0,0,1};

    float weight[5];

    LinearREG(LENS(inp),inp_size,inp,output,weight);
    return 0;
}