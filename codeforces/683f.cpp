#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void formatString(string& s) {
    string result;
    bool newSentence = true;
    
    // Remove leading spaces
    int i = 0;
    while (i < s.length() && s[i] == ' ') {
        i++;
    }
    
    while (i < s.length()) {
        if (isalpha(s[i])) {
            // Add the character, adjusting the case if needed
            if (newSentence) {
                result += toupper(s[i]);
                newSentence = false;
            } else {
                result += tolower(s[i]);
            }
        } else if (s[i] == ' ') {
            // Skip extra spaces
            if (!result.empty() && result.back() != ' ' && result.back() != '.' && result.back() != ',') {
                result += ' ';
            }
        } else if (s[i] == '.' || s[i] == ',') {
            // Add punctuation and handle space after if necessary
            result += s[i];
            newSentence = s[i] == '.';
            
            // Move past spaces after punctuation
            int j = i + 1;
            while (j < s.length() && s[j] == ' ') {
                j++;
            }
            
            // Add a space if there is a word after punctuation
            if (j < s.length() && isalpha(s[j])) {
                result += ' ';
            }
            
            i = j - 1; // Adjust the index to the new position
        }
        i++;
    }
    
    // Remove trailing space
    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }
    
    cout << result << endl;
}

int main() {
    string s;
    getline(cin, s);
    formatString(s);
    return 0;
}
