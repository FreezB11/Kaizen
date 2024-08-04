#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int odd_count = 0, even_count = 0;
        for (int num : a) {
            if (num % 2 == 0) {
                even_count++;
            } else {
                odd_count++;
            }
        }

        cout << min(odd_count, even_count) << endl;
    }

    return 0;
}
