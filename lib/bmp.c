#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>

bmp bmp_write(char *filename,char data[],int width,int height){
    //identify the file as a BMP
    char tag[] = {'B','M'};

     int header[] = {
        0,                   // File size... update at the end.
        0, 0x36, 0x28,
        width, height,       // Image dimensions in pixels

        0x180001, 0, 0, 0x002e23, 0x002e23, 0, 0,
    };


    FILE *file = fopen(filename,"w+");

    fwrite(&tag,sizeof(tag),1,file);
    fwrite(&header, sizeof(header), 1, file);
    fwrite(&data,sizeof(data),1,file);
    fclose(file);
}