#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers (used for sorting)
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, c;
        scanf("%d %d", &n, &c);

        int a[n];
        long long total_fans = 0;

        // Read the number of fans for each candidate and calculate total fans
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            total_fans += a[i];
        }

        // Sort the array of fans
        qsort(a, n, sizeof(int), compare);

        // Calculate the minimum number of exclusions for each candidate
        int exclusions[n];
        long long current_sum = 0;
        int idx = 0;

        for (int i = 0; i < n; ++i) {
            // Add the fans of the current candidate to the sum
            current_sum += a[i];
            // Calculate number of undecided voters if excluding candidates from 0 to i
            long long undecided_voters = (long long)(i + 1) * a[i] - current_sum + total_fans - current_sum;
            // Determine number of exclusions needed to make this candidate win
            if (undecided_voters <= c) {
                exclusions[i] = i;
                idx = i + 1;
            } else {
                exclusions[i] = idx;
            }
        }

        // Print the results for the current test case
        for (int i = 0; i < n; ++i) {
            printf("%d ", exclusions[i]);
        }
        printf("\n");
    }

    return 0;
}
