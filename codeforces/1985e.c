#include <stdio.h>
#include <math.h>

void find_max_locations(int x, int y, int z, long long k, int *result) {
    int max_locations = 0;

    for (int a = 1; a <= sqrt(k); ++a) {
        if (k % a != 0) continue;

        long long ab = k / a;

        for (int b = 1; b <= sqrt(ab); ++b) {
            if (ab % b != 0) continue;

            int c = ab / b;

            if (a <= x && b <= y && c <= z) {
                int locations = (x - a + 1) * (y - b + 1) * (z - c + 1);
                if (locations > max_locations) {
                    max_locations = locations;
                }
            }

            if (b <= x && a <= y && c <= z) {
                int locations = (x - b + 1) * (y - a + 1) * (z - c + 1);
                if (locations > max_locations) {
                    max_locations = locations;
                }
            }

            if (a <= x && c <= y && b <= z) {
                int locations = (x - a + 1) * (y - c + 1) * (z - b + 1);
                if (locations > max_locations) {
                    max_locations = locations;
                }
            }

            if (c <= x && a <= y && b <= z) {
                int locations = (x - c + 1) * (y - a + 1) * (z - b + 1);
                if (locations > max_locations) {
                    max_locations = locations;
                }
            }

            if (b <= x && c <= y && a <= z) {
                int locations = (x - b + 1) * (y - c + 1) * (z - a + 1);
                if (locations > max_locations) {
                    max_locations = locations;
                }
            }

            if (c <= x && b <= y && a <= z) {
                int locations = (x - c + 1) * (y - b + 1) * (z - a + 1);
                if (locations > max_locations) {
                    max_locations = locations;
                }
            }
        }
    }

    *result = max_locations;
}

int main() {
    int t;
    scanf("%d", &t);

    int results[t];

    for (int i = 0; i < t; ++i) {
        int x, y, z;
        long long k;
        scanf("%d %d %d %lld", &x, &y, &z, &k);
        
        find_max_locations(x, y, z, k, &results[i]);
    }

    for (int i = 0; i < t; ++i) {
        printf("%d\n", results[i]);
    }

    return 0;
}
