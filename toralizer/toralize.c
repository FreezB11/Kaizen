/* toralize.c */
#include <stdio.h>
#include "toralize.h"

/**/

int main(int argc, char *argv[]){
    char *host;
    int port;

    int (argc < 3){
        printf("ERR::input missing!!\n");
        printf("Usage:: %s <host> <port>\n",argv[0]);

        return -1;
    }
    host = argv[1];
    port = atoi(argv[2]);
}