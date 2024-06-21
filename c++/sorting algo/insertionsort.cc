#include <iostream>
#include "lib.hh"
#define log(x) std::cout << x << std::endl;
#define len(x,y) sizeof(x)/sizeof(y)

float sq(float x){
    return x*x -2;
}

float NewM(float (*func)(float),int x,int S){
    float Xn;
    for (size_t i = 0; i < S; i++){
        Xn = x - func(x)/df(func,x);
        x = Xn;
    }
    return Xn;
}

int BS(long long arr[],int low,int high, int x){
    while (low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == x){
            return mid;
        }
        if (arr[mid] < x){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1;
}

void sort(int* arr){
    int size = sizeof(arr)/sizeof(int);
    std::cout << size << std::endl;
}

int main(){

    // int arr[10] = {2,9,8,4,3,1,6,7,5,10};
    // long long a[5] = {1,2,3,4,5};
    // int i = BS(a,0,len(a,int),4);
    // log(i)
    // sort(arr);
    log("=======================")
    float out = NewM(sq,1,1000);
    log(out);


    return 0;
}