#include <iostream>
#include <cmath>
#include <string>

bool isPerfectSquare(int n) {
    int root = static_cast<int>(std::sqrt(n));
    return root * root == n;
}

bool isBeautifulSquare(const std::string& s, int n) {
    int root = static_cast<int>(std::sqrt(n));
    for (int i = 0; i < root; ++i) {
        if (s[i] != '1' || s[n - root + i] != '1') return false; 
        if (s[i * root] != '1' || s[(i + 1) * root - 1] != '1') return false;
    }
    for (int i = 1; i < root - 1; ++i) {
        for (int j = 1; j < root - 1; ++j) {
            if (s[i * root + j] != '0') return false;
        }
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::string s;
        std::cin >> n >> s;
        
        if (!isPerfectSquare(n)) {
            std::cout << "No" << std::endl;
            continue;
        }

        if (isBeautifulSquare(s, n)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
