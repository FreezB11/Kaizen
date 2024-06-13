#include <stdio.h>

int main(){
    int inp;
    scanf("%d",&inp);
    if(inp == 2){
        printf("NO");
    }else{
        if(inp%2 == 0){
            printf("YES");
        }else{
            printf("NO");
        }
    }
}