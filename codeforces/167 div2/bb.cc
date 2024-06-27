#include <iostream>
#include <string>



int main() {
    // int t;
    // std::cin >> t;
    std::string a;
    std::string b;
    std::cin >> a;
    std::cin >> b;
    int cnt = a.length() + b.length();

    for (size_t i = 0; i < a.length(); i++){
        for (size_t j = 0; j < b.length(); j++){
            if(a[i] == b[i]){
                cnt--;
            }
        }   
    }

    std::cout << cnt << std::endl;

    // if(a.length() > b.length()){
    //     for (size_t i = 0; i < a.length(); i++){
    //         for (size_t j = 0; j < b.length(); j++){
    //             if(a[i] != b[i]){
    //                 cnt++;
    //             }
    //         }   
    //     }
    // }else{
    //     for (size_t i = 0; i < b.length(); i++){
    //         for (size_t i = 0; i < a.length(); i++){
    //             if(a[i] != b[i]){
    //                 cnt++;
    //             }
    //         }   
    //     }
    // }

    // std::cout << a.length()<< std::endl;
    return 0;
}
