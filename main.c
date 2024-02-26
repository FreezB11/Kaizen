#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/color.h"

// enum png {
//     sign = '89 50 4E 47 0D 0A 1A 0A',
//     IHDR = '00 00 00 0D 49 48 44 52 00 00 00 01 00 00 00 01 08 02 00 00 00 90 77 53 DE',
//     // IDATA = '',
//     IEND = '00 00 00 00 49 45 4E 44 AE 42 60 82'
// };

int main (int argc,char* argv[]){
   

    unsigned char sign[100] = "89 50 4E 47 0D 0A 1A 0A";

    char *input = argv[1];
    FILE *file = fopen(input,"ab+");

    fwrite(&sign,sizeof(sign),1,file);

    fclose(file);

    return 0;
}