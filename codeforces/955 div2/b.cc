#include <iostream>

using namespace std;

long long modified_collatz(long long  x, long long y, long long k) {
  long long final_x = x;
  for (int i = 0; i < k; ++i) {
    final_x++;
    while (final_x % y == 0) {
      final_x /= y;
    }
  }
  return final_x;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    long long x, y, k;
    cin >> x >> y >> k;
    long final_value = modified_collatz(x, y, k);
    cout << final_value << endl;
  }
  return 0;
}
