#include <iostream>
#include <set>
#include <string>
// #define NULL 0
using namespace std;

int count_unique_substrings(int n,const string& s, int k) {
    set<string> unique_substrings;
    for (int i = 0; i <= n - k; ++i) {
        string substring = s.substr(i, k);

        unique_substrings.insert(substring);
    }
    return unique_substrings.size();
}
 
int main() {
    string s;
    int n,k;

    cin >> n >> k;
    cin >> s;

    int result = count_unique_substrings(n,s, k);

    cout << result << endl;
    return 0;
}
