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

template<typename T,int n>
class vector{
private:
    T* data;
    T vMax = 0 ;
    long long vMin = MadMax;
public:
    vector(){
        data = (T*)malloc(n * sizeof(T));
        if (!data) {throw std::bad_alloc();}
        for (size_t i = 0; i < n; i++){new(&data[i]) T();}
    }
    vector(std::initializer_list<T> initList) {
        if (initList.size() > n) {
            throw std::out_of_range("Initializer list too large");
        }
        data = static_cast<T*>(std::malloc(n * sizeof(T)));
        if (!data) {
            throw std::bad_alloc();
        }
        std::size_t i = 0;
        for (const auto& item : initList) {
            new(&data[i++]) T(item);
            if(item > vMax){vMax = item;}
            if(item < vMin){vMin = item;}
            //LOG(item);
        }
        // Initialize remaining elements with default value
        for (; i < n; ++i) {
            new(&data[i]) T();
        }
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
    vector<T,n> operator+(vector<T,n> other){
        vector<T,n> result;
        for (size_t i = 0; i < n; ++i) {
            result[i] = data[i] + other[i];
        }
        return result;
    }
    vector<T, n> operator*(const T& scalar) const {
        vector<T, n> result;
        for (size_t i = 0; i < n; ++i) {
            result[i] = data[i] * scalar;
        }
        return result;
    }
    // Const version of element access
    // const T& operator[](std::size_t index) const {
        // if (index >= N) {
            // throw std::out_of_range("Index out of range");
        // }
        // return data[index];
    // }
    std::size_t size() const {return n;}
    T max(){ return vMax;}
    T min(){ return vMin;}
    class Iterator {
    private:
        T* ptr;
    public:
        explicit Iterator(T* p) : ptr(p) {}
        Iterator& operator++() { ++ptr; return *this; }
        Iterator operator++(int) { Iterator tmp = *this; ++ptr; return tmp; }
        T& operator*() { return *ptr; }
        T* operator->() { return ptr; }
        bool operator==(const Iterator& other) const { return ptr == other.ptr; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
    };
    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + n); }

    friend std::ostream& operator<<(std::ostream& os, const vector<T, n>& vec) {
        os << "[";
        for (size_t i = 0; i < n; ++i) {
            os << vec.data[i];
            if (i != n - 1) os << ", ";
        }
        os << "]";
        return os;
    }
  
};

void solve(int tc =1){
    int n;
    std::cin >> n;
    int *a = (int*)malloc(n*sizeof(int));
    int *b = (int*)malloc(n*sizeof(int));
    for (size_t i = 0; i < n; i++){
        std::cin >> a[i];
    }
    for (size_t i = 0; i < n; i++){
        std::cin >> b[i];
    }
    int mov_a = 0;
    int mov_b = 0;
    for (size_t i = 0; i < n; i++){
        if (a[i]>b[i]){
            mov_a = mov_a + a[i];
        }else if (b[i]>a[i]){
            mov_b = mov_b + b[i];
        }else{
            mov_b = mov_b + b[i];
        }
        
        
    }
    std::cout << mmin(mov_a,mov_b) << std::endl;
}

int main(){

    
    int tc = 1;
	std::cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);


    return 0;
}



