#include <stdio.h>

#define MOD 1000000007

long long power(long long x, long long y) {
    if (y == 0)
        return 1;
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return res;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);

        long long ans = 0;
        for (int n = 1; n <= 9; ++n) {
            long long digits = power(10, l - 1) * n;
            long long sum_digits = (n * (power(10, r) - 1) / 9) % MOD;
            long long sum_k_digits = (sum_digits * k) % MOD;
            if (sum_k_digits == digits) {
                ans++;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}
