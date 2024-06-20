#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<vector<bool>> find_palindromic_substrings(const string &s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));


    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
        }
    }
    for (int length = 3; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
            }
        }
    }

    return dp;
}

void dfs(int node, const vector<vector<int>> &graph, vector<bool> &visited) {
    vector<int> stack = {node};
    while (!stack.empty()) {
        int v = stack.back();
        stack.pop_back();
        for (int neighbor : graph[v]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                stack.push_back(neighbor);
            }
        }
    }
}

int count_connected_components(const string &s) {
    int n = s.size();
    auto dp = find_palindromic_substrings(s);

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

    vector<bool> visited(n, false);
    int connected_components = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            ++connected_components;
            visited[i] = true;
            dfs(i, graph, visited);
        }
    }

    return connected_components;
}

int main() {
    string s;
    cin >> s;
    cout << count_connected_components(s) << endl;
    return 0;
}
