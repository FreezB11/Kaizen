#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool hasUniqueDigits(int year) {
    string yearStr = to_string(year);
    unordered_set<char> seen;
    
    for (char digit : yearStr) {
        if (seen.count(digit) > 0) {
            return false; // Found a duplicate digit
        }
        seen.insert(digit);
    }
    
    return true; // All digits are unique
}

int findNextYearWithDistinctDigits(int y) {
    y++; // Start checking from y + 1
    while (!hasUniqueDigits(y)) {
        y++;
    }
    return y;
}

int main() {
    int y;
    cin >> y;
    
    int result = findNextYearWithDistinctDigits(y);
    cout << result << endl;
    
    return 0;
}
