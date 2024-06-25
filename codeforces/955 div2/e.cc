#include <iostream>
#include <vector>
#include <algorithm>

const long long MOD = 1000000007;

// Helper function to count the number of set bits (1s) in a number
int count_bits(long long x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

// Function to compute number of k-good subarrays for given n and k
long long count_k_good_subarrays(long long n, int k) {
    // Store the valid numbers count
    long long valid_count = 0;
    
    // Iterate over numbers from 0 to n-1
    for (long long i = 0; i < n; ++i) {
        if (count_bits(i) <= k) {
            ++valid_count;
        }
    }

    // The number of k-good subarrays is the sum of the first valid_count natural numbers
    return valid_count * (valid_count + 1) / 2 % MOD;
}

int main() {
    int t;
    std::cin >> t;

    std::vector<long long> results(t);
    for (int i = 0; i < t; ++i) {
        long long n;
        int k;
        std::cin >> n >> k;
        results[i] = count_k_good_subarrays(n, k);
    }

    for (const auto& result : results) {
        std::cout << result << std::endl;
    }

    return 0;
}
