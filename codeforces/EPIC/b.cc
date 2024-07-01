// author:: hsay
#include <iostream>
#include <string.h>
#include <initializer_list>  // for std::initializer_list
#include <cstdlib>  // for malloc and free
#include <queue>
#include <vector>
#include <utility>
// #include <chrono> // use when time is required
//  #include <cstring>  // for memcpy
#define MadMax 0x7fffffffffffffffLL
#define LOG(x) std::cout << x << std::endl;
#define len(x,y) (long long)sizeof(x)/sizeof(y)
#define f0r(a, b) for (long long i = a; i < (b); i++)
#define f1r(a, b) for (long long j = a; j <= (b); j++)
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

bool isin(std::string a,std::string b){ // tell if a is in b
    if (b.find(a) != std::string::npos) {return true;} else{return false;}
}

template<typename T> T max(T &a, T &b) { return a > b ? a : b; }

void solve(int tc =1){
    int *arr,*k;
    int n;
    int coins = 0;
    std::cin >> n;
    arr = (int*)malloc(n*sizeof(int));
    k = (int*)malloc(n*sizeof(int));

    f0r(0,n){
        std::cin >> arr[i];
        k[i] = 0;
    }
    bool inc;
    f0r(1,n){
        if (arr[i] >= arr[i-1]){
            inc = true;
        }else{
            inc = false;
            break;
        }
    }

    while (!inc){
        f0r(1,n){
            if (arr[i] >= arr[i-1]){
                inc = true;
            }else{
                coins = coins + (arr[i-1] - arr[i]) + 1;
                // k[i] = i;
                // arr[k[i]]++;
                inc = false;
            }
        }
        LOG("check")
        // coins++;
    }

    // f0r(0,n){
    //     std::cout << k[i] << " ";
    // }

    LOG(coins)
}


int main(){

    
    int tc = 1;
	// std::cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
    return 0;
}