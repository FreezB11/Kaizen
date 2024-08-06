#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s, t;
        cin >> s >> t;

        int j = 0;
        bool possible = true;
        for (int i = 0; i < s.size() && j < t.size(); i++) {
            if (s[i] == t[j]) {
                j++;
            } else if (s[i] == '?') {
                s[i] = t[j];
                j++;
            } else {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES\n" << s << endl;
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
