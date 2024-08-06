#include <iostream>
using namespace std;

int sum_of_digits(int n) {
    return (n / 10) + (n % 10);
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        cout << sum_of_digits(n) << endl;
    }

    return 0;
}
