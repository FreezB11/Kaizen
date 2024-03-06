#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/color.h"
#include "lib/bmp.h"

#define white 255,255,255
#define black 0,0,0

#define height 3
#define width 3

int main (int argc,char* argv[]){
   

    char *input = argv[1];
    
    char bitmap[] = {
    // 255,255,255, //white
    white,
    0,255,0, // green
    0,0,255, //red
    255,255,255,
    255,0,0,// blue in coder term
    255,255,0, //cyan
    0,255,255, // yellow
    255,255,255,
    255,255,255, //white
    0,255,0, // green
    0,0,255, //red
    255,255,255,
    };

    int img_data[height][width] = {};

    bmp_write(input,bitmap,width,height); // width then height

    return 0;
}