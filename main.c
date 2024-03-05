#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/color.h"
#include "lib/bmp.h"


int main (int argc,char* argv[]){
   

    char *input = argv[1];
    
    char bitmap[] = {
        0xa4, // Blue
    0x55, // Green
    0x00, // Red
    0x00  // Padding
    };

    bmp_write(input,bitmap,1,1);

    return 0;
}