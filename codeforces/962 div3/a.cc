#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> test_cases(t);

    for (int i = 0; i < t; ++i) {
        cin >> test_cases[i];
    }

    for (int i = 0; i < t; ++i) {
        int n = test_cases[i];
        int max_cows = n / 4;
        int remaining_legs = n % 4;

        if (remaining_legs == 0) {
            cout << max_cows << endl;
        } else {
            cout << max_cows + 1 << endl;
        }
    }

    return 0;
}
