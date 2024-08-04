#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> results(t);

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        unordered_map<char, int> count;
        count['A'] = 0;
        count['B'] = 0;
        count['C'] = 0;
        count['D'] = 0;
        count['?'] = 0;

        for (char c : s) {
            count[c]++;
        }

        int summ = 0;
        if(count['A'] > n){
            summ = summ + n;
        }else{
            summ = summ + count['A'];
        }
        if(count['B'] > n){
            summ = summ + n;
        }else{
            summ = summ + count['B'];
        }
        if(count['C'] > n){
            summ = summ + n;
        }else{
            summ = summ + count['C'];
        }
        if(count['D'] > n){
            summ = summ + n;
        }else{
            summ = summ + count['D'];
        }



        results[i] = summ ;
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
