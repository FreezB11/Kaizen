#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

// Function to compute (a^b) % mod
int mod_pow(int a, int b, int mod) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (1LL * res * a) % mod;
        }
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}

// Function to compute modular inverse using Fermat's Little Theorem
int mod_inv(int a, int mod) {
    return mod_pow(a, mod - 2, mod);
}

// Function to precompute factorials and inverse factorials
void precompute_factorials_and_inverses(int max_n, vector<int> &fact, vector<int> &ifact, int mod) {
    fact[0] = ifact[0] = 1;
    for (int i = 1; i <= max_n; ++i) {
        fact[i] = (1LL * fact[i - 1] * i) % mod;
    }
    ifact[max_n] = mod_inv(fact[max_n], mod);
    for (int i = max_n - 1; i > 0; --i) {
        ifact[i] = (1LL * ifact[i + 1] * (i + 1)) % mod;
    }
}

// Function to compute binomial coefficient C(n, k) % mod
int binom(int n, int k, const vector<int> &fact, const vector<int> &ifact, int mod) {
    if (k > n || k < 0) return 0;
    return (1LL * fact[n] * ifact[k] % mod * ifact[n - k] % mod) % mod;
}

// Function to solve the problem
int solve(int n, int k) {
    vector<int> fact(n + 1), ifact(n + 1);
    precompute_factorials_and_inverses(n, fact, ifact, MOD);
    
    int total_ways = binom(n, k, fact, ifact, MOD);
    for (int i = 1; i <= k; ++i) {
        int ways = (1LL * binom(k, i, fact, ifact, MOD) * binom(n - i - 1, k - i - 1, fact, ifact, MOD)) % MOD;
        if (i % 2 == 1) {
            total_ways = (total_ways - ways + MOD) % MOD;
        } else {
            total_ways = (total_ways + ways) % MOD;
        }
    }
    return total_ways%MOD;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}
