#include <stdio.h>
#include <stdlib.h>

int main(){

    unsigned long long n,a,b;
    int k =0;
    unsigned long long profit =0;
    scanf("%d %d %d",&n,&a,&b);

    k = (2*(b-a) +1)/2;

    if(((2*(b-a) +1)/2)<0){
        profit = n*a; 
    }else{
        profit  = (k*b - (k*(k-1))/2) + (n-k)*a;
    }
    printf("%lld",profit);

    return 0;
}