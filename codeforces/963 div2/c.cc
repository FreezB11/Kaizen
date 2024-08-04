#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<long long> intervals(n);
        for (int i = 0; i < n; i++) {
            long long ai;
            cin >> ai;
            intervals[i] = 2 * k;
        }

        long long lcm_val = intervals[0];
        for (int i = 1; i < n; i++) {
            lcm_val = lcm(lcm_val, intervals[i]);
        }

        long long max_end = *max_element(intervals.begin(), intervals.end());
        cout << (lcm_val <= max_end ? lcm_val : -1) << endl;
    }
    return 0;
}
