#include <stdio.h>
#define pi 3.14

long double mpow(long double base,int p){
    if (p == 0){return 1;}
    return base * mpow(base,p-1);
    
}

int mfact(int x){
    if(x == 0){return 1;}
    return x* mfact(x-1);
}

long double msin(long double x){

    if(x == 0){return 0.0f;}

    long double result = 0.0f;
    for (size_t i = 0; i < 100; i++){
        result = result + (mpow(-1,i) * (mpow(x,2*i + 1) / mfact(2*i +1))) ;
    }
    return result;
}

int main(){
    printf("%lf",msin(1.0f));
    return 0;
}
