#include <stdio.h>
#include "lib/nn.h"
#include "lib/calculas.h"

#define inp_size 2

int main(){
    
    float inp[][inp_size] ={{0,0},
                    {1,0},
                    {0,1},
                    {1,1}}; 

    float output[4]={0,1,1,1};
    float bias;
    float weight[inp_size];

    LinearREG(LENS(inp),inp_size,inp,output,weight,&bias);

    printf("0 || 0 == %f\n",sigmoid(0*weight[0]+0*weight[1]+bias));
    printf("0 || 1 == %f\n",sigmoid(0*weight[0]+1*weight[1]+bias));
    printf("1 || 0 == %f\n",sigmoid(1*weight[0]+0*weight[1]+bias));
    printf("1 || 1 == %f\n",sigmoid(1*weight[0]+1*weight[1]+bias));

    return 0;
}