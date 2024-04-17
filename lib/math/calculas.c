#include <stdio.h>
#include "calculas.h"

float df(float (*func)(float),float x){
    // float eps = 1.61011979e-4;
    //float eps = 1.61012e-4;
    float df = (func(x+eps) -func(x-eps))/(2*eps);
    return df;
}

// float tanh(float x){
//     int y; 
//     return y;
// }

// float ex(float x){
//     int sum = 0;
//     for (size_t i = 0; i < 1000*1000; i++)
//     {
//         sum +=
//     }
    
// }

/*

float func(float x){
    return x*x;
}

int main(){

    float dff = df(func,3);

    printf("%f\n",dff);
    return 0;
}

*/