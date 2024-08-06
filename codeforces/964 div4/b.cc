#include <iostream>
using namespace std;

int countSuneetWins(int a1, int a2, int a3, int a4) {
    int suneetWins = 0;
    // Consider all permutations of flipping cards:
    // Suneet: (a1, a2) and Slavic: (b1, b2)
    if ((a1 > a3 && a2 > a4)) {
        suneetWins++;
    }
    // Suneet: (a2, a1) and Slavic: (b1, b2)
    if ((a2 > a3 && a1 > a4)) {
        suneetWins++;
    }

    if ((a1 > a4 && a2 > a3)) {
        suneetWins++;
    }

    if ((a2 > a4 && a1 > a3)) {
        suneetWins++;
    }
    return suneetWins;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        cout << countSuneetWins(a1, a2, b1, b2) << endl;
    }
    return 0;
}
