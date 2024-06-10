#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> generate_substrings(const string& s, int k) {
    set<string> unique_substrings;
    int n = s.length();
    for (int i = 0; i <= n - k; ++i) {
        string substring = s.substr(i, k);
        unique_substrings.insert(substring);
    }
    
    return unique_substrings;
}

int main() {
    string s;
    int k;
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the length of substrings: ";
    cin >> k;

    set<string> result = generate_substrings(s, k);

    cout << "Unique substrings of length " << k << " are:\n";
    for (const string& substring : result) {
        cout << substring << "end"<< endl;
    }
    
    return 0;
}
