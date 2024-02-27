#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/color.h"
#include "lib/bmp.h"


int main (int argc,char* argv[]){
   

    char *input = argv[1];
    
    char bitmap[] = {
        0x35, // Blue
        0x41, // Green
        0xef, // Red
        0x00  // Padding
    };

    bmp_write(input,bitmap,1,1);

    return 0;
}