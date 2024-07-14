#include <iostream>
#ifndef mmax
#define mmax(a,b) (((a) > (b)) ? (a) : (b))
#endif
#define log(x) std::cout << x << std::endl;

int main(){
    int array[8] = {-1,2,4,-3,5,2,-5,2};
    int max = 0 ;
    for (int i = 0; i <8; i++){
        for (int j = i; j < 8; j++){
            int sum = 0;
            for (int k = i; k <= j; k++){
                sum += array[k];
            }
            max = mmax(max,sum);
        }
    }
    
    std::cout << max << std::endl;
}
