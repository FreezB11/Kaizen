#include <iostream>
#define log(x) std::cout << x << std::endl;

int main(){
    int t,a,b;
    int check;
    std::cin >> t;
    while(t--){
        std::cin >> a >> b;
        if((a%2 == 0) && (b%2 == 0)) {
            log("YES")
            }else if((a == 0) && (b%2 == 1)) {
                log("NO")}else if((a%2 == 1) && (b == 0)) {
                    log("NO")}else if((b*2 - a)%2 == 0){
                        log("YES")
        }else{
            log("NO")
        }

    }

    return 0;
}