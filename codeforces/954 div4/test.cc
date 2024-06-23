#include <iostream>
#include <vector>

using namespace std;

bool isLocalMax(const vector<vector<int>>& matrix, int i, int j, int n, int m) {
  // Check all neighbors (up, down, left, right)
  for (int di = -1; di <= 1; ++di) {
    for (int dj = -1; dj <= 1; ++dj) {
      // Skip current cell and diagonal neighbors
      if (di == 0 && dj == 0 || abs(di) == abs(dj)) {
        continue;
      }
      int ni = i + di;
      int nj = j + dj;
      // Check if neighbor is within bounds and has a greater value
      if (0 <= ni && ni < n && 0 <= nj && nj < m && matrix[ni][nj] > matrix[i][j]) {
        return false;
      }
    }
  }
  return true;
}

vector<vector<int>> stabilizeMatrix(vector<vector<int>>& matrix) {
  int n = matrix.size();
  int m = matrix[0].size();

  while (true) {
    bool hasLocalMax = false;
    int minI = n, minJ = m;
    // Find a local maximum
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (isLocalMax(matrix, i, j, n, m)) {
          hasLocalMax = true;
          if (i < minI || (i == minI && j < minJ)) {
            minI = i;
            minJ = j;
          }
        }
      }
    }

    // If no local maximum found, terminate
    if (!hasLocalMax) {
      break;
    }

    // Decrement the local maximum
    matrix[minI][minJ]--;
  }

  return matrix;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> matrix[i][j];
      }
    }

    vector<vector<int>> result = stabilizeMatrix(matrix);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << result[i][j] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
