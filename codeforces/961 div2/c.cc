#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int minActsOfJustice(vector<int>& a) {
    int n = a.size();
    int operations = 0;

    for (int i = 0; i < n - 1; ++i) {
        while (a[i] > a[i + 1]) {
            if (a[i + 1] * a[i + 1] > 1e6) return -1;
            a[i + 1] *= a[i + 1];
            ++operations;
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) return -1;
    }

    return operations;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cout << minActsOfJustice(a) << endl;
    }

    return 0;
}
