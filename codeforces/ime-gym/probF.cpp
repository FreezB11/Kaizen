#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

// Function to find and mark all palindromic substrings
void findPalindromes(const string &s, vector<vector<bool>> &dp) {
    int n = s.size();
    
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true; // Single character palindromes
    }

    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            if (length == 2) {
                dp[i][j] = (s[i] == s[j]);
            } else {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
        }
    }
}

// Function to perform DFS and mark all reachable nodes
void dfs(int node, const vector<vector<int>> &graph, vector<bool> &visited) {
    stack<int> stack;
    stack.push(node);

    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                stack.push(neighbor);
            }
        }
    }
}

int countConnectedComponents(const string &s) {
    int n = s.size();
    if (n == 1) {
        return 1;
    }

    // Step 1: Find all palindromic substrings using DP
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    findPalindromes(s, dp);

    // Step 2: Construct graph adjacency list
    vector<vector<int>> graph(n);

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (dp[i][j]) {
                graph[i].push_back(j);
                if (i != j) {
                    graph[j].push_back(i);
                }
            }
        }
    }

    // Step 3: Count connected components using DFS
    vector<bool> visited(n, false);
    int connectedComponents = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i, graph, visited);
            ++connectedComponents;
        }
    }

    return connectedComponents;
}

int main() {
    string s;
    cin >> s;
    cout << countConnectedComponents(s) << endl;
    return 0;
}
