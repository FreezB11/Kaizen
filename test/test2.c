#include <stdio.h>
 
double func(double x){
    return x*x; // intg = x^3/3
}

int main(){
    int l =1;

    // double eps = 1.61011979e-4;
    double eps = 1.61012e-4;
    double rate =5e-2 ;
    double intg;
    printf("rate:%f\n",rate);
    float out;
    for (double i = 0; i < 10;i = i+rate)
    {
        printf("%f\n",i);
    }
    
    

    return 0;
}