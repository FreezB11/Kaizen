#include "nn.h"
#include <stdio.h>


int main(){

    //float input[4][2] = {{0,0},{0,1},{1,0},{1,1}};
    float output[4] = {0,0,0,1};

    int nns[5]={3,1,0,5,9};

    //Matrix inp = create_matrix(4,2);

    Nnetwrk *testnet = createNetwork(5,0,nns);
    






















    // neuron *n = createNeuron(5,input);
    // printf("%f\n",n->input[4]);

    return 0;
}