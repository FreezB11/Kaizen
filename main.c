#include <stdio.h>
#include <stdlib.h>
#include "lib/color.h"

int main (int argc,char* argv[]){
    printf(RED);
    printf("hello\n");
    printf("%d\n",argc);
    printf("%s\n",argv[1]);

    return 0;
}