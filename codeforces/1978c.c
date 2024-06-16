#include <stdio.h>
#include <stdlib.h>

void solve(int n, long long k) {
    long long max_possible_value = (long long)n * (n - 1) / 2;
    
    if (k > max_possible_value) {
        printf("No\n");
        return;
    }
    
    printf("Yes\n");
    
    int *permutation = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        permutation[i] = i + 1;
    }
    
    long long current_value = 0;
    
    for (int i = n - 1; i >= 0; --i) {
        if (current_value == k) {
            break;
        }
        long long current_target = current_value + (n - 1 - i);
        if (current_target <= k) {
            current_value = current_target;
            for (int j = 0; j < (n - i) / 2; ++j) {
                int temp = permutation[i + j];
                permutation[i + j] = permutation[n - 1 - j];
                permutation[n - 1 - j] = temp;
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        printf("%d ", permutation[i]);
    }
    printf("\n");
    
    free(permutation);
}

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        int n;
        long long k;
        scanf("%d %lld", &n, &k);
        solve(n, k);
    }
    
    return 0;
}
