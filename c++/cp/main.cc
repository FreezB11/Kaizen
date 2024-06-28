// author:: hsay
#include <iostream>
#include <string.h>
#include <initializer_list>  // for std::initializer_list
#include <cstdlib>  // for malloc and free
// #include <chrono> // use when time is required
//  #include <cstring>  // for memcpy
#define MadMax 0x7fffffffffffffffLL
#define LOG(x) std::cout << x << std::endl;
#define len(x,y) (long long)sizeof(x)/sizeof(y)
#define f0r(a, b) for (long long i = a; i < (b); i++)
#define f1r(a, b) for (long long j = a; j < (b); j++)
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const ll mod1 = 1000000007;

#ifndef mmax
#define mmax(a,b) (((a) > (b)) ? (a) : (b))
#endif
#ifndef mmin
#define mmin(a,b) (((a) < (b)) ? (a) : (b))
#endif

template<typename T> T max(T &a, T &b) { return a > b ? a : b; }

template<typename T>
class vector{
private:
    T *data;
    ll size;
    ll max =0;
    ll min = MadMax;
public:
    vector(ll n){
        size = n;
        data = (T*)malloc(n*sizeof(T));
        if (!data) {throw std::bad_alloc();}
        for (size_t i = 0; i < n; i++){new(&data[i]) T();}
    }
    T& operator[](std::size_t index) {
        if (index >= size) {throw std::out_of_range("Index out of range");}
        return data[index];
    }
};

void solve(int tc =1){
       
}

int main(){

    
    int tc = 1;
	// std::cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
    return 0;
}