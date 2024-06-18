#include <iostream>

int main(){
    int t;
    std::cin >> t;

    while(t--){
        long long a,b,c;
        std::cin >>a>>b>>c;

        std::cout << a+b+c <<" "<< b+c <<" "<<c <<std::endl;
    }
}