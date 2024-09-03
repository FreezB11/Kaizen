#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


int main() {
    int t;
    std::cin >> t;

    while (t--) {
        long long n, k;
        std::cin >> n >> k;
        std::vector<int> min(n);
        for (int i = 1; i < n; i++)
        {
            long long sum = 2*k*i-2*k*n + i + i*n - (n*n - n)/2 + n - 2*i;
            min[i-1] = sum;
        }
        int smallest = *min_element(min.begin(), min.end());
        std::cout << smallest << std::endl;
    }

    return 0;
}
