#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/color.h"
#include "lib/bmp.h"


int main (int argc,char* argv[]){
   

    char *input = argv[1];
    
    char bitmap[] = {
        0x36,
        0x39,
        0x3C,
        0x3E,
        0x41,
        0x44
    };

    bmp_write(input,0,2,2);

    return 0;
}