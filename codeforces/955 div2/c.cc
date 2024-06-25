#include <iostream>
#include <vector>
using namespace std;

vector<int> maxWinningRounds(int t, vector<vector<int>>& test_cases) {
    vector<int> results;
    for (int i = 0; i < t; i++) {
        int n = test_cases[i][0];
        int l = test_cases[i][1];
        int r = test_cases[i][2];
        vector<int> a(test_cases[i].begin() + 3, test_cases[i].end());

        int start = 0;
        int current_sum = 0;
        int win_count = 0;
        
        for (int end = 0; end < n; end++) {
            current_sum += a[end];
            
            while (current_sum > r && start <= end) {
                current_sum -= a[start];
                start++;
            }
            
            if (l <= current_sum && current_sum <= r) {
                win_count++;
                start = end + 1;
                current_sum = 0;
            }
        }
        
        results.push_back(win_count);
    }
    return results;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    vector<vector<int>> test_cases(t);
    
    for (int i = 0; i < t; i++) {
        int n, l, r;
        cin >> n >> l >> r;
        test_cases[i].push_back(n);
        test_cases[i].push_back(l);
        test_cases[i].push_back(r);
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            test_cases[i].push_back(val);
        }
    }
    
    vector<int> results = maxWinningRounds(t, test_cases);
    
    for (int result : results) {
        cout << result << '\n';
    }
    
    return 0;
}
