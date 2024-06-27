#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif


int main(){
    int t;
    std::cin >> t;
    while(t--){
        int x,y;
        std::cin >> x >> y;
        int k=y/2;
        x-=min(x,7*k);
        
            if(y%2==1) {
                k=15-4*(y%2);
            x-=min(x,k);
            }
    
    
        
        std::cout << (y+1)/2+(x+14)/15<< std::endl;
    }

    return 0;
}