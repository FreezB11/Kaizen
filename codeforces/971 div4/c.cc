#include <iostream>
#include <cmath>
using namespace std;

int min_moves(int x, int y, int k) {
    int nx = (x + k - 1) / k;  // This is equivalent to ceil(x / k)
    int ny = (y + k - 1) / k;  // This is equivalent to ceil(y / k)
    if(nx <= ny){
        return 2*ny;
    }else{
        return 2*nx-1;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;
        cout << min_moves(x, y, k) << endl;
    }
    return 0;
}
