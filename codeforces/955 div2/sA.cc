#include <iostream>
#include <vector>
using namespace std;

void solve(int t, vector<pair<pair<int, int>, pair<int, int>>>& test_cases) {
    for (int i = 0; i < t; ++i) {
        int x1 = test_cases[i].first.first;
        int y1 = test_cases[i].first.second;
        int x2 = test_cases[i].second.first;
        int y2 = test_cases[i].second.second;
        
        if (x1 < y1) {
            if (x2 >= y2) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        } else if (x1 > y1) {
            if (x2 <= y2) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    vector<pair<pair<int, int>, pair<int, int>>> test_cases(t);
    for (int i = 0; i < t; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        test_cases[i] = {{x1, y1}, {x2, y2}};
    }
    solve(t, test_cases);
    return 0;
}
