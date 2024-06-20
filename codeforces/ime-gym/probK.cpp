#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void countSubstrings(int n, long long k, string s) {
    int *count = 0;
    string smallest, largest;
    
    // Calculate frequencies of all substrings
    for (int start = 0; start < n; ++start) {
        unordered_map<char, int> freq;
        for (int end = start; end < n; ++end) {
            char current_char = s[end];
            freq[current_char]++;
            
            int len_t = end - start + 1;
            int freq_t = freq[current_char];
            
            // Check if len_t * freq_t == k
            if (k % len_t == 0) {
                int expected_freq = k / len_t;
                if (freq_t == expected_freq) {
                    (*count)++;
                    string substring = s.substr(start, len_t);
                    if (smallest.empty() || substring < smallest) {
                        smallest = substring;
                    }
                    if (largest.empty() || substring > largest) {
                        largest = substring;
                    }
                }
            }
        }
    }
    
    // Output the results
    cout << count << endl;
    if (count > 0) {
        cout << smallest << endl;
        cout << largest << endl;
    }
}

int main() {
    int n;
    long long k;
    string s;
    
    // Read input
    cin >> n >> k;
    cin >> s;
    
    // Call function to solve the problem
    countSubstrings(n, k, s);
    
    return 0;
}
