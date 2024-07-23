#include <iostream>

using namespace std;



int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        if(k == 0){
            std::cout << 0 << std::endl;
        }else if (k == n*n){
            std::cout << 2*n - 1 << std::endl;
        }else if (k == n ){
            std::cout << 1 << std::endl;
        }else if (k > n){
            int l = k/n;
            std::cout << l +1 << std::endl;
        }
        
        

    }

    return 0;
}
