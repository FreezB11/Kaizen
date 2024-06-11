#include <stdio.h>

int max_sum_of_multiples(int n) {
    int best_x = 2;
    long long max_sum = 0;

    for (int x = 2; x <= n; x++) {
        int k = n / x;
        long long sum = x * k * (k + 1) / 2;
        if (sum > max_sum) {
            max_sum = sum;
            best_x = x;
        }
    }

    return best_x;
}

int main() {
    int t;
    scanf("%d", &t);

    int results[t];

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        results[i] = max_sum_of_multiples(n);
    }

    for (int i = 0; i < t; i++) {
        printf("%d\n", results[i]);
    }

    return 0;
}
