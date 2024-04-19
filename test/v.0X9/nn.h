#ifndef _NN_H_
#define _NN_H_

typedef struct{
    int NOS;
    int NOI;
    double *inputs;
    float bias;
}NN;


NN forward(NN neural);


#endif