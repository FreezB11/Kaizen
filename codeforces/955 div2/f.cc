#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> find_minimum_subarray_to_sort(int n, vector<int>& a) {
    if (n == 1) {
        return make_pair(-1, -1);
    }

    int left_sorted_end = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            break;
        }
        left_sorted_end = i;
    }

    if (left_sorted_end == n - 1) {
        return make_pair(-1, -1);
    }

    int right_sorted_start = n;
    for (int i = n - 1; i > 0; --i) {
        if (a[i] < a[i - 1]) {
            break;
        }
        right_sorted_start = i;
    }

    int min_length = right_sorted_start - left_sorted_end - 1;
    return make_pair(left_sorted_end + 1, right_sorted_start);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int q;
        cin >> q;

        // Initial check
        pair<int, int> initial_result = find_minimum_subarray_to_sort(n, a);
        cout << initial_result.first << " " << initial_result.second << "\n";

        // Process modifications
        while (q--) {
            int pos, val;
            cin >> pos >> val;
            a[pos - 1] = val;

            pair<int, int> current_result = find_minimum_subarray_to_sort(n, a);
            cout << current_result.first << " " << current_result.second << "\n";
        }
    }

    return 0;
}
