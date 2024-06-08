#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define PNG_SIGNATURE_SIZE 8

const uint8_t png_signature[PNG_SIGNATURE_SIZE] = {
    0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A
};

int main () {

    FILE* fp;
    fp = fopen("out.png","ab");  

    fwrite(png_signature, 1, PNG_SIGNATURE_SIZE, fp);
    fclose(fp); 
    

    

    return 0;
}