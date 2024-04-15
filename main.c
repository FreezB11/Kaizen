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

    for(size_t i=0;i<2;++i){
        for(size_t j=0;j<2;++j){
            printf("%zu | %zu == %f\n",i,j,sigmoid(i*weight[i]+j*weight[j]+bias));
        }
    }

    return 0;
}