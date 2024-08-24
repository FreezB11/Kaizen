#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        if (n == 2) {
            cout << "-1\n";
        } else {
            for (int i = 1; i <= n; i++) {
                cout << (i % n) + 1 << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}
