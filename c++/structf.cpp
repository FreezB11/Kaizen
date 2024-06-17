#include <iostream>

struct tests
{
    int x;
    int sq(int x){
        return x*x;
    };
};


int main(){

    struct tests t;
    t.x = 5;
    t.sq(5);
    std::cout << t.sq(5) << std::endl;
    return 0;
}