#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

void calculateMEOW(vector<int>& results, int max_n) {
    vector<long long> dp(max_n + 1);
    dp[0] = 0;  // Base case: MEX of empty set is 0
    
    for (int k = 1; k <= max_n; ++k) {
        dp[k] = (dp[k - 1] * 2 + k) % MOD;
    }
    
    for (int n = 1; n <= max_n; ++n) {
        results[n] = (results[n - 1] + dp[n]) % MOD;
    }
}

int main() {
    int t;
    cin >> t;
    
    vector<int> test_cases(t);
    int max_n = 0;
    
    for (int i = 0; i < t; ++i) {
        cin >> test_cases[i];
        max_n = max(max_n, test_cases[i]);
    }
    
    vector<int> results(max_n + 1);
    calculateMEOW(results, max_n);
    
    for (int i = 0; i < t; ++i) {
        cout << results[test_cases[i]] << "\n";
    }
    
    return 0;
}
