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



template<typename T> T max(T &a, T &b) { return a > b ? a : b; }

template<typename T,long long n>
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
void test();
void solve(int tc =1){
    
}


int main(){

    
    int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
    test();

    return 0;
}



/*
this how to use the itrator
Vector<int, 5> vec = {0, 1, 2, 3, 4};

    // Print values using iterators
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

        /// the implementation is hard but i shall try it again

    // vector<vector<int,4>,2> vec = {{0,0,0,0},{1,1,1,1}};
    
    // for (std::size_t i = 0; i <2; ++i) {
    //     for (std::size_t j = 0; j < 4; ++j) {
    //         std::cout << vec[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // vector<int,4> vec = {0,0,0,1};
    // f0r(0,4){LOG(vec[i])}
    // std::cin.get();




*/

void test(){
    vector<int,10> vec = {1,9,3,5,6,2,8,4,7,11};
    // std::cout << vec[0] << std::endl;
    std::cout << vec.max() << std::endl;
    std::cout << vec.min() << std::endl;

    // vector<vector<int,4>,4> vec2d = {
    //     {1, 0, 0, 0},
    //     {0, 2, 0, 0},
    //     {0, 0, 3, 0},
    //     {0, 0, 0, 4}
    // };
    // for (size_t i = 0; i < vec2d.size(); ++i) {
    //     std::cout << vec2d[i] << std::endl;
    // }
    // vector<int,4> vec = {0,1,2};
    // for (auto it = vec.begin(); it != vec.end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // vector<int,3> vec = {0,1,2};
    // vector<int,3> vec2 = vec * 2;
    // LOG(vec2)
    // vector<int,3> res = vec + vec2;
    // LOG(vec)
    // for (auto it = res.begin(); it != res.end(); ++it) {
    //     std::cout << *it << " ";
    // }
    std::cout << std::endl;
}