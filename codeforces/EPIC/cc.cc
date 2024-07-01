#include <iostream>
#include <vector>

using namespace std;

int find_seconds(vector<int>& heights) {
  int n = heights.size();
  int seconds = 0;

  while (true) {
    bool all_zero = true;
    for (int i = 0; i < n - 1; ++i) {
      if (heights[i] > heights[i + 1]) {
        heights[i] = max(0, heights[i] - 1);
        all_zero = false;
      }
    }
    seconds++;

    if (all_zero) {
      break;
    }
  }

  return seconds;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
      cin >> heights[i];
    }

    int seconds = find_seconds(heights);
    cout << seconds << endl;
  }

  return 0;
}
