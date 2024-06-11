#include <stdio.h>

void find_center(int n, int m, char grid[n][m], int *center_x, int *center_y) {
    int min_row = n, max_row = -1, min_col = m, max_col = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#') {
                if (i < min_row) min_row = i;
                if (i > max_row) max_row = i;
                if (j < min_col) min_col = j;
                if (j > max_col) max_col = j;
            }
        }
    }

    *center_x = (min_row + max_row) / 2 + 1;
    *center_y = (min_col + max_col) / 2 + 1;
}

int main() {
    int t;
    scanf("%d", &t);

    int results[t][2];

    for (int i = 0; i < t; ++i) {
        int n, m;
        scanf("%d %d", &n, &m);
        char grid[n][m];
        for (int j = 0; j < n; ++j) {
            scanf("%s", grid[j]);
        }

        int center_x, center_y;
        find_center(n, m, grid, &center_x, &center_y);
        results[i][0] = center_x;
        results[i][1] = center_y;
    }

    for (int i = 0; i < t; ++i) {
        printf("%d %d\n", results[i][0], results[i][1]);
    }

    return 0;
}
