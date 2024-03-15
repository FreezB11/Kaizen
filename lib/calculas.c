#include <stdio.h>

int df(int (*func)(int),int x){
    // double eps = 1.61011979e-4;
    double eps = 1.61012e-4;
    double df = (func(x+eps) -func(x-eps))/(2*eps);
    return 0;
}