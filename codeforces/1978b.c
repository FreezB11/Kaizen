#include <stdio.h>
#include <stdlib.h>

int main(){

    int n,a,b;
    int k =0;

    scanf("%d %d %d",&n,&a,&b);

    k = (2*(b-a) +1)/2;

    int profit  = (k*b - (k*(k-1))/2) + (n-k)*a;

    printf("%d",profit);

    return 0;
}