#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



int main() {
    int n;
    cin >> n;
    int x,y; 

    for (size_t i = 0; i < n; i++){
        cin >> x >> y;
        if(y >= -1 ){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    


    return 0;
}
