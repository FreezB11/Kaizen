#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct State {
    int position;
    int swam;
};

bool canReachBank(int n, int m, int k, const string& river) {
    vector<bool> visited(n + 2, false);
    queue<State> q;
    q.push({0, 0});
    visited[0] = true;

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        int pos = current.position;
        int swam = current.swam;

        if (pos == n + 1) {
            return true;
        }

        // Try to jump
        for (int jump = 1; jump <= m; ++jump) {
            int newPos = pos + jump;
            if (newPos > n + 1) break;
            if (!visited[newPos] && (newPos == n + 1 || river[newPos - 1] != 'C')) {
                visited[newPos] = true;
                q.push({newPos, swam});
            }
        }

        // Try to swim
        if (pos <= n && river[pos - 1] == 'W' && swam < k) {
            int newPos = pos + 1;
            if (newPos <= n + 1 && !visited[newPos]) {
                visited[newPos] = true;
                q.push({newPos, swam + 1});
            }
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string river;
        cin >> river;

        if (canReachBank(n, m, k, river)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
