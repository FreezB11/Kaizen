// author:: hsay
#include <iostream>
#include <string.h>
#include <initializer_list>  // for std::initializer_list
#include <cstdlib>  // for malloc and free
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
    // Const version of element access
    // const T& operator[](std::size_t index) const {
        // if (index >= N) {
            // throw std::out_of_range("Index out of range");
        // }
        // return data[index];
    // }
    std::size_t size() const {return n;}

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
    vector<int,3> vec = {0,1,2};
    vector<int,3> vec2 = {0,1,3};
    vector<int,3> res = vec + vec2;
    for (auto it = res.begin(); it != res.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}