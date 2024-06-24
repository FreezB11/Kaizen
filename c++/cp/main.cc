// author:: hsay
#include <iostream>
#include <string.h>
// #include <cstdlib>  // for malloc and free
// #include <cstring>  // for memcpy
#define LOG(x) std::cout << x << std::endl;
#define len(x,y) (long long)sizeof(x)/sizeof(y)
#define f0r(a, b) for (long long i = a; i < (b); i++)
#define f1r(a, b) for (long long j = a; j < (b); j++)
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const ll mod1 = 1000000007;

template<typename T,std::size_t n>
class vector{
private:
    T* data;
public:
    vector(){
        data = (T*)malloc(n * sizeof(T));
        if (!data) {throw std::bad_alloc();}
        for (size_t i = 0; i < n; i++){new(&data[i]) T();}
    }
    ~vector() {
        for (std::size_t i = 0; i < n; ++i) {data[i].~T();}
        std::free(data);
    }
    //allows to access the elements with bound checkiing
    T& operator[](std::size_t index) {
        if (index >= n) {throw std::out_of_range("Index out of range");}
        return data[index];
    }
    // Const version of element access
    // const T& operator[](std::size_t index) const {
        // if (index >= N) {
            // throw std::out_of_range("Index out of range");
        // }
        // return data[index];
    // }
    std::size_t size() const {return n;}
};

void solve(int tc =1){
    
}


int main(){
    

    int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);

    // std::cin.get();
    return 0;
}




