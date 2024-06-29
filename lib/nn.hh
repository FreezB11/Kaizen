#ifndef NN
#define NN

#define ll long long
#define log(x) std::cout << x << std::endl;
#include <iostream>


template<typename T>
class network{
private:
    ll layers=0;
public:
    network(ll l){
        layers = l;
        log(layers)
    }
};


#endif