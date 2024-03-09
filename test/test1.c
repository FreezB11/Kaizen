#include <stdio.h>
 
double func(float x){
    return x*x*x*x;
}

 int main(){
    printf("hello\n");
    double x =2;
    double eps = 1.61011979e-4;
    printf("%f\n",eps);
    printf("%f\n",func(x));
  
    double df = (func(x+eps) -func(x))/eps;
    printf("%f\n",df);  

    return 0;
 }