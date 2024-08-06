#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s, m;
        cin >> n >> s >> m;
        vector<pair<int, int>> intervals(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> intervals[i].first >> intervals[i].second;
        }
        
        // Sort intervals by their starting times
        sort(intervals.begin(), intervals.end());
        
        bool canShower = false;
        
        // Check if Alex can shower at the start of the day
        if (intervals[0].first >= s) {
            canShower = true;
        } else {
            // Check intervals between tasks
            for (int i = 1; i < n; ++i) {
                if (intervals[i].first - intervals[i-1].second >= s) {
                    canShower = true;
                    break;
                }
            }
            // Check if Alex can shower at the end of the day
            if (m - intervals[n-1].second >= s) {
                canShower = true;
            }
        }
        
        if (canShower) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
