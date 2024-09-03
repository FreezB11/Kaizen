#include <iostream>
#include <string>
#include <vector>
#define log(x) std::cout << x << std::endl;

void solve(){
    int a,b;
    std::cin >> a >> b;
    log(b-a);
}


int main(){
    int t;
    std::cin >> t;
    while(t--){
        solve();
    }
    return 0;
}