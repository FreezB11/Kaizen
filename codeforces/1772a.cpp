#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    
    while (t--) {
        std::string expression;
        std::cin >> expression;

        size_t plus_pos = expression.find('+');

        std::string a_str = expression.substr(0, plus_pos);
        std::string b_str = expression.substr(plus_pos + 1);

        int a = stoi(a_str);
        int b = stoi(b_str);
        int result = a + b;
        std::cout << result << std::endl;
    }
    
    return 0;
}
