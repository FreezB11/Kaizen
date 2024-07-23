#include <iostream>
#ifndef mmax
#define mmax(a,b) (((a) > (b)) ? (a) : (b))
#endif
#define log(x) std::cout << x << std::endl;

int main(){
    int array[8] = {-1,2,4,-3,5,2,-5,2};
    int max = 0 ;
    int sum = 0;
    for (int i = 0; i <8; i++){
        sum = mmax(array[i], sum + array[i]);
        max = mmax(max,sum);
    }
    
    std::cout << max << std::endl;
}
