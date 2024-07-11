#include <iostream>
#include <string>
#include <vector>
#ifndef mmin
#define mmin(a,b) (((a) < (b)) ? (a) : (b))
#endif

using namespace std;

bool isCorrectAnswer(int n, int a, int b) {
    // Handle cases where the string would become empty after subtraction
    if (b >= n * to_string(a).length()) {
        return false;
    }

    string result;
    // Simulate K1o0n's faulty multiplication
    for (int i = 0; i < a; ++i) {
        result += to_string(n);
    }

    // Remove the last b characters for subtraction
    result.erase(result.length() - b, b);

    // Check if the remaining string represents a valid integer
    try {
        stoi(result);
        return true; // Converted to integer successfully
    } catch (const invalid_argument& e) {
        return false; // Invalid integer representation
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int badTests = 0;
        vector<pair<int, int>> validPairs;

        // Try different values of a and b
        for (int a = 1; a <= 10000; ++a) {
            for (int b = 1; b <= mmin(10000, n * to_string(a).length()); ++b) {
                if (isCorrectAnswer(n, a, b)) {
                    badTests++;
                    validPairs.push_back({a, b});
                }
            }
        }

        cout << badTests << endl;
        for (const auto& pair : validPairs) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    return 0;
}
