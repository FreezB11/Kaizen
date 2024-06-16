#include <stdio.h>
#include <string.h>

// Function to calculate the maximum number of 1's in string a that can be obtained
int calculateMaxOnes(char *a, char *b, int l, int r) {
    int count = 0;
    for (int i = l; i <= r; i++) {
        if (a[i] == '1' || b[i] == '1') {
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        char s[n + 1];
        char t[n + 1];
        scanf("%s", s);
        scanf("%s", t);

        int q;
        scanf("%d", &q);

        while (q--) {
            int l, r;
            scanf("%d %d", &l, &r);

            // Convert 1-based index to 0-based index for C arrays
            l--; r--;

            int maxOnes = calculateMaxOnes(s, t, l, r);
            printf("%d\n", maxOnes);
        }
    }

    return 0;
}
