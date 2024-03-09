#include <stdio.h>
 
double func(double x){
    return x*x;
}

int main(){
    int l =1;

    // double eps = 1.61011979e-4;
    double eps = 1.61012e-4;
    double rate =5e-1 ;
    double intg;
    printf("%f\n",rate);
    float out;
    for(float x = 0;x<10; x=x+rate){
        // printf("%f\n",x);
        out = out+ func(x)*eps;
        printf("%f = %f\n",x,out);
    };
    // for(int x=0;x<l;x=x+rate){
    //     intg = intg+ func(l)*eps;
    //     printf("%f\n",intg);
    // };
    

    return 0;
}