#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        
        vector<long long> p(n + 1);
        for (long long i = 1; i <= n; ++i) {
            cin >> p[i];
        }

        long long count = 0;

        for (long long i = 1; i <= n; ++i) {
            for (long long j = i + 1; j <= n; ++j) {
                if ((p[i] * p[j]) % (i * j) == 0) {
                    count++;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
