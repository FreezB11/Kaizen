#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reduceGrid(int n, int k, const vector<string>& grid) {
    vector<string> reducedGrid;
    
    for (int i = 0; i < n; i += k) {
        string reducedRow = "";
        for (int j = 0; j < n; j += k) {
            reducedRow += grid[i][j];
        }
        reducedGrid.push_back(reducedRow);
    }
    
    for (const string& row : reducedGrid) {
        cout << row << endl;
    }
}

int main() {
    int t;
    cin >> t;
    
    for (int test = 0; test < t; ++test) {
        int n, k;
        cin >> n >> k;
        
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }
        
        reduceGrid(n, k, grid);
        if (test < t - 1) {
            cout << endl; // Separate test cases by a newline
        }
    }
    
    return 0;
}
