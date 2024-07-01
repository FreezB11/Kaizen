#include <iostream>
#include <vector>
using namespace std;

// Structure to represent a node in the tree
struct TreeNode {
    int value;
    vector<int> children;
};

// Function to perform DFS and calculate required increments
void dfs(vector<TreeNode>& tree, vector<int>& a, vector<int>& increments, int v) {
    int sumChildren = 0;
    for (int u : tree[v].children) {
        dfs(tree, a, increments, u);
        sumChildren += a[u - 1] + increments[u];
    }
    
    if (!tree[v].children.empty()) {
        if (a[v - 1] < sumChildren) {
            increments[v] = sumChildren - a[v - 1];
        } else {
            increments[v] = 0;
        }
    }
}

// Function to process each test case and return the minimum operations required
int processTestCase(int n, vector<int>& a, vector<int>& parent) {
    // Constructing the tree as an adjacency list
    vector<TreeNode> tree(n + 1);
    for (int i = 1; i <= n; ++i) {
        tree[i].value = a[i - 1];
    }
    for (int i = 1; i < n; ++i) {
        tree[parent[i - 1]].children.push_back(i + 1);
    }
    
    // To keep track of required increments
    vector<int> increments(n + 1, 0);
    
    // Perform DFS to calculate the required increments
    dfs(tree, a, increments, 1);
    
    // The result is the increment needed at the root (vertex 1)
    return increments[1];
}

int main() {
    int t;
    cin >> t;
    
    vector<int> results;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        vector<int> parent(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> parent[i];
        }
        
        // Process each test case and store the result
        results.push_back(processTestCase(n, a, parent));
    }
    
    // Output results for each test case
    for (int result : results) {
        cout << result << "\n";
    }
    
    return 0;
}
