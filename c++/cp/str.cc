/*
author: hsay
topic: own string ops
*/
#include <iostream>
#include <string>

int main() {
    std::string a, b;

    // Input strings a and b
    std::cout << "Enter string a: ";
    std::getline(std::cin, a);
    std::cout << "Enter string b: ";
    std::getline(std::cin, b);

    // Check if a is a substring of b
    if (b.find(a) != std::string::npos) {
        std::cout << "String a is a substring of string b." << std::endl;
    } else {
        std::cout << "String a is NOT a substring of string b." << std::endl;
    }

    return 0;
}
