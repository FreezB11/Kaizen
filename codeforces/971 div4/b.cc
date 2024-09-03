#include <iostream>
#include <vector>
#include <string>

int main() {
    int t;  // Number of test cases
    std::cin >> t;

    while (t--) {
        int n;  // Number of rows in the beatmap
        std::cin >> n;
        std::vector<int> result(n);  // To store the column indices of the notes

        // Read each row of the beatmap from top to bottom
        for (int i = 0; i < n; ++i) {
            std::string row;
            std::cin >> row;

            // Find the position of '#' in the row
            for (int j = 0; j < row.length(); ++j) {
                if (row[j] == '#') {
                    result[n - i - 1] = j + 1;  // Store the position (1-based index) from bottom to top
                    break;
                }
            }
        }

        // Output the results for the current test case
        for (int i = 0; i < n; ++i) {
            std::cout << result[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
