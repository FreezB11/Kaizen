#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        int max_div = 0;
        for (int i = l; i <= r; ++i) {
            int count = 0;
            while (i > 0) {
                i /= 3;
                count++;
            }
            max_div = max(max_div, count);
        }

        cout << max_div - 1 << endl; // Subtract 1 because the last division doesn't count as an operation
    }
    return 0;
}
