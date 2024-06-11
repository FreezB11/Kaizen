#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 4096;

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

vector<vector<int>> bfs_minimum_moves(int N, int M) {
    vector<vector<int>> F(N + 1, vector<int>(M + 1, INT_MAX));
    F[1][1] = 0;
    queue<pair<int, int>> q;
    q.push({1, 1});

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && F[nx][ny] == INT_MAX) {
                F[nx][ny] = F[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return F;
}

int compute_G(int X, int Y, int N, int M, vector<vector<int>> &F) {
    long long total_sum = 0;
    for (int i = X; i <= N; i++) {
        for (int j = Y; j <= M; j++) {
            total_sum = (total_sum + F[i][j]) % MOD;
        }
    }
    return total_sum;
}

int main() {
    int T;
    cin >> T;
    vector<int> results;

    while (T--) {
        int X, Y, N, M;
        cin >> X >> Y >> N >> M;

        if (max(N, M) > MAX_N) {
            // Efficient handling of large N and M is needed.
            cout << "Handling large N and M efficiently is needed." << endl;
        } else {
            vector<vector<int>> F = bfs_minimum_moves(N, M);
            int result = compute_G(X, Y, N, M, F);
            results.push_back(result);
        }
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
