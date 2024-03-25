#include <stdio.h>

double df(double (*func)(int),double x){
    // double eps = 1.61011979e-4;
    double eps = 1.61012e-4;
    double df = (func(x+eps) -func(x-eps))/(2*eps);
    return df;
}



/*

double func(double x){
    return x*x;
}

int main(){

    double dff = df(func,3);

    printf("%f\n",dff);
    return 0;
}

*/