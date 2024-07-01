#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int timeToZeroHeight(vector<int> &heights) {
    int n = heights.size();
    int seconds = 0;

    while (true) {
        bool allZero = true;
        vector<int> new_heights = heights;

        for (int i = 1; i <= n; ++i) {
            if (i == n|| heights[i-1] > heights[i]) {
                new_heights[i] = max(0, heights[i] - 1);
            }
            if (new_heights[i] > 0) {
                allZero = false;
            }
        }

        heights = new_heights;
        seconds++;

        if (allZero) {
            break;
        }
    }

    return seconds;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> heights(n);
        for (int j = 0; j < n; ++j) {
            cin >> heights[j];
        }
        std::cout <<  timeToZeroHeight(heights) <<std::endl;
    }
    return 0;
}
