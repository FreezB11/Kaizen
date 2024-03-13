#include <stdio.h>
 
double func(double x){
    return x*x; // intg = x^3/3
}

int main(){
    int l =1;

    // double eps = 1.61011979e-4;
    double eps = 1.61012e-4;
    double rate =1.6101e-4 ;
    double intg= 0;
    printf("rate:%f\n",rate);
    
    for (double i = 0; i < func(2);i = i+eps)
    {
        intg = intg + i*eps;
        printf("%f\n",intg);
        //printf("%f\n",i);
    }
    
    

    return 0;
}