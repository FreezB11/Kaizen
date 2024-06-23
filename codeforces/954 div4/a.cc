#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;
        
        int min_distance = INT_MAX;
        
        for (int a = 1; a <= 10; ++a) {
            int current_distance = abs(a - x1) + abs(a - x2) + abs(a - x3);
            min_distance = min(min_distance, current_distance);
        }
        
        cout << min_distance << endl;
    }
    return 0;
}
