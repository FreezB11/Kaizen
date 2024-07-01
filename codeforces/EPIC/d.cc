#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void maximize_cakes(int t, vector<pair<int, vector<int>>> &test_cases) {
    vector<int> results;
    
    for (int i = 0; i < t; ++i) {
        int n = test_cases[i].first;
        vector<int> a = test_cases[i].second;
        
        // Sort the tastiness values
        sort(a.begin(), a.end());
        
        // dp array to store the maximum cakes Alice can eat
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Starting condition
        
        for (int j = 1; j <= n; ++j) {
            dp[j] = dp[j - 1]; // Initially, Alice can eat up to j cakes
            
            if (j > 1 && a[j - 1] > a[j - 2]) {
                dp[j] += 1;
            }
        }
        
        results.push_back(dp[n]);
    }
    
    for (int result : results) {
        cout << result << endl;
    }
}

int main() {
    int t;
    cin >> t;
    
    vector<pair<int, vector<int>>> test_cases;
    
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        
        test_cases.push_back({n, a});
    }
    
    maximize_cakes(t, test_cases);
    
    return 0;
}
