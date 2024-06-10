#include <stdio.h>

int mceil(int x,int y){
    return (x+y-1)/y;
}

int main (){

    int m,n,a;
    int nof;
    scanf("%d %d %d",&m,&n,&a);
    nof = mceil(m,a) * mceil(n,a);
    printf("%d",nof);

    return 0;
}