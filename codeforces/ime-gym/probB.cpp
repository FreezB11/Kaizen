#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

map<int, int> prime_factors(int n) {
    map<int, int> factors;
    for (int d = 2; d * d <= n; ++d) {
        while (n % d == 0) {
            factors[d]++;
            n /= d;
        }
    }
    if (n > 1) {
        factors[n]++;
    }
    return factors;
}

map<int, int> factorial_prime_factors(int n) {
    map<int, int> total_factors;
    for (int i = 2; i <= n; ++i) {
        map<int, int> factors = prime_factors(i);
        for (const auto& factor : factors) {
            total_factors[factor.first] += factor.second;
        }
    }
    return total_factors;
}

int sum_of_digits(ll n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int solve(int a, int b) {
    // Get the prime factorization of a!
    map<int, int> fact_factors = factorial_prime_factors(a);

    // Each prime factor exponent is multiplied by b
    for (auto& factor : fact_factors) {
        factor.second *= b;
    }

    // To find the maximum c such that (a!^b)^c divides p(a!^b)
    ll max_c = LLONG_MAX;
    for (const auto& factor : fact_factors) {
        max_c = min(max_c, static_cast<ll>(factor.second / 2));
    }

    // Sum the digits of the maximum c
    return sum_of_digits(max_c);
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << solve(a, b) << endl;

    return 0;
}
