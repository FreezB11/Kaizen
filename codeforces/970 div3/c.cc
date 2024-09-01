#include <iostream>
#include <cmath>
#include <string>
#define log(x) std::cout << x << std::endl;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int l,r;
        std::cin >> l >> r;
        int prev=l;
        int count=0;
        int d = 1;
        while(prev <= r){
            prev = prev + d;
            count++;
            d++;
        }
        log(count)
    }
    return 0;
}
