#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int count = 0;
        for (int a = 1; a <= x; ++a) {
            for (int b = 1; b <= x - a; ++b) {
                for (int c = 1; c <= x - a - b; ++c) {
                    if (a + b + c <= x && a * b + a * c + b * c <= n) {
                        count++;
                    }
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
