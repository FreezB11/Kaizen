#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> permutation;

        // Place elements from k to n at the beginning
        for (int i = k; i <= n; ++i) {
            permutation.push_back(i);
        }
        
        // Place elements from m+1 to k-1 next
        for (int i = m + 1; i < k; ++i) {
            permutation.push_back(i);
        }
        
        // Place elements from 1 to m at the end
        for (int i = 1; i <= m; ++i) {
            permutation.push_back(i);
        }
        
        // Print the permutation
        for (int i = 0; i < n; ++i) {
            cout << permutation[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}
