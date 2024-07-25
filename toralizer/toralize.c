/* toralize.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include "toralize.h"

/**/

int main(int argc, char *argv[]){
    char *host;
    int port,s;

    struct sockaddr_in sock;

    if(argc < 3){
        printf("ERR::input missing!!\n");
        printf("Usage:: %s <host> <port>\n",argv[0]);

        return -1;
    }
    host = argv[1];
    port = atoi(argv[2]);
    s = socket(AF_INET,SOCK_STREAM,0);

    if (s<0){
        perror("socket");
        return -1;
    }
    memset(&sock, 0, sizeof(sock));  // Initialize the sock structure
    sock.sin_family = AF_INET;
    sock.sin_port = htons(PROXYPORT);
    sock.sin_addr.s_addr = inet_addr(PROXY);

    if(connect(s,(struct sockaddr *)&sock,sizeof(sock)) < 0){
        perror("connect");
        return -1;
    }
    printf("connected to proxy\n");
    close(s);

    return 0;
}