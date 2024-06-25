#include <stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    long long x,y,k;
    for(int i = 0; i<t; i++){
        scanf("%lld %lld %lld",&x,&y,&k);
        for (size_t i = 0; i < k; ++i) {
        x += 1;
        while (x % y == 0) {
            x /= y;
        }
    } 
    printf("%lld \n",x);
    }

}