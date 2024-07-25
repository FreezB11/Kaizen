/* toralize.h */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>



#define PROXY       "127.0.0.1"
#define PROXYPORT   8080

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
/*
		+----+----+----+----+----+----+----+----+----+----+....+----+
		| VN | CD | DSTPORT |      DSTIP        | USERID       |NULL|
		+----+----+----+----+----+----+----+----+----+----+....+----+
          1    1      2              4           variable       1
*/
struct proxy_request {
    int8 vn;
    int8 cd;
    int16 dsport;
    int32 dstip;
    unsigned char userid[8];
};
typedef struct proxy_request Req;

/*
		+----+----+----+----+----+----+----+----+
		| VN | CD | DSTPORT |      DSTIP        |
		+----+----+----+----+----+----+----+----+
    	   1    1      2              4
*/
struct proxy_response {
    int8 vn;
    int8 cd;
    int16 _; //dstport
    int32 __;//dstip
};
typedef struct proxy_response Res;