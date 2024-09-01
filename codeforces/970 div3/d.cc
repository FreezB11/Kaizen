#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#define log(x) std::cout << x << std::endl;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> p(n);
        std::vector<int> bw(n);
        for (int i = 0; i < n; i++){
            std::cin >> p[i];
        }
        for (int i = 0; i < n; i++){
            std::cin >> bw[i];
        }
        for(int j = 0; j<n; j++){
            int hops = 0;
            int count = 0;
            int i = j;
            while(hops <= n){
                i = p[j];
                if(bw[i] != 1 ){
                    count++;
                }
                i = p[i];
                hops++;
            }
            log(count)
            }
        }
        return 0;        
}

