#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int nums[3] = {a, b, c};
        sort(nums, nums + 3);

        int increments = 5;
        while (increments > 0) {
            if (nums[0] <= nums[1] && nums[0] <= nums[2]) {
                nums[0]++;
            } else if (nums[1] <= nums[0] && nums[1] <= nums[2]) {
                nums[1]++;
            } else {
                nums[2]++;
            }
            increments--;
        }

        int max_bananas = nums[0] * nums[1] * nums[2];
        cout << max_bananas << endl;
    }
    return 0;
}
