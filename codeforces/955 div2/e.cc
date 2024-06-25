#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 1000000007;

// Function to count the number of '1's in the binary representation of x
int bit_count(long long x) {
    int count = 0;
    while (x > 0) {
        if (x & 1) count++;
        x >>= 1;
    }
    return count;
}

// Function to compute the number of k-good subarrays for an array of length n
long long count_k_good_subarrays(long long n, int k) {
    if (k == 0) {
        return (n * (n + 1) / 2) % MOD;
    }
    
    long long result = 0;
    for (long long i = 0; i < n; ++i) {
        if (bit_count(i) <= k) {
            result += (n - i);
            if (result >= MOD) result -= MOD;
        } else {
            break;
        }
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    
    vector<long long> results;
    while (t--) {
        long long n;
        int k;
        cin >> n >> k;
        
        long long result = count_k_good_subarrays(n, k);
        results.push_back(result);
    }
    
    for (long long result : results) {
        cout << result << endl;
    }
    
    return 0;
}
