#include <stdio.h>
#include "lib/calculas.h"

double func(double x){
    return x*x;
}

int main(){

    double dff = df(func,3);

    printf("%f\n",dff);
    return 0;
}