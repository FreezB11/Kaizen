#include <stdio.h>
#include <stdlib.h>


int main(){

    char a[5] = "01101";
    char c[5] = "01101";

    int b = (int)a;
    int d = (int)b;

    printf("%d\n",b);
    printf("%d\n",d);

    return 0;
}