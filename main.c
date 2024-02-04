#include <stdio.h>
#include <stdlib.h>
#include "lib/color.h"

int main (){
    printf("\a");
    printf("hello\n");
    
    int i = 0;
    do {
        printf("%d",i);
        i++;
    }while(i<5);

    return 0;
}