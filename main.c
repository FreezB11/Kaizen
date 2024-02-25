#include <stdio.h>
#include <stdlib.h>
#include "lib/color.h"

// enum png {
//     sign = '89 50 4E 47 0D 0A 1A 0A',
//     IHDR = '00 00 00 0D 49 48 44 52 00 00 00 01 00 00 00 01 08 02 00 00 00 90 77 53 DE'
//     IDATA = '',
// };

int main (int argc,char* argv[]){
    printf(RED);
    printf("hello\n");
    printf("%d\n",argc);
    printf("%s\n",argv[1]);

    return 0;
}