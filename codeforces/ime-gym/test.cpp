#include <iostream>
#include <string>
#include <unordered_map>

void findSubstringFrequency(const std::string& str) {
    int len = str.length();
    std::unordered_map<std::string, int> frequency;

    // Iterate over all possible window sizes
    for (int window_size = 1; window_size <= len; ++window_size) {
        // Slide the window across the string
        for (int start = 0; start <= len - window_size; ++start) {
            std::string substring = str.substr(start, window_size);
            frequency[substring]++;
        }
    }

    // Print the frequencies
    for (const auto& pair : frequency) {
        std::cout << "Substring '" << pair.first << "' occurs " << pair.second << " times.\n";
    }
}
int freq(const std::string& str, const std::string& sub) {
    if (sub.length() == 0) return 0;
    int count = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos; 
         offset = str.find(sub, offset + sub.length())) {
        ++count;
    }
    return count;
}

void printSubstrings(const std::string& str,int k) {
    int len = str.length();
    // Generate all substrings
    int ctr =0;
    for (int start = 0; start < len; ++start) {
        for (int length = 1; length <= len - start; ++length) {
            std::string substring = str.substr(start, length);
            std::cout << substring << "["<< substring.length() <<"]"<< "==" << freq(str,substring) << std::endl;
            int l = substring.length();
            int fc = freq(str,substring);
            int m = l*fc;
            if (m == k){
                ctr++;
                std::cout << "ctr is" <<ctr << std::endl;
            }
        }
    }
    std::cout << ctr << std::endl;
}


int main(){
    int n;
    int k;

    std::string s;

    std::cin >>n >>k;
    std::cin >>s;

    int ctr;
    std::string input = "aaaaaa";

    // std::cout << "Finding frequencies of all substrings in \"" << input << "\":\n";
    // findSubstringFrequency(input);
    // printSubstrings(s,k);
    
}