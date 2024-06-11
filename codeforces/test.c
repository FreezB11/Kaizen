#include <stdio.h>

int main(){

    char a[6] ="10010";
    char b[6] ="10010"; 

    if( a[1] == b[1]){
        printf("same\n");
    }else{
        printf("not same\n");
    }

    return 0;
}