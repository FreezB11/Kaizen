#include <iostream>
#include <vector>
#include <unordered_map>

void solve(){
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    std::unordered_map<int, int> frequencyMap;

    for (size_t i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    for (int element : arr) {
        frequencyMap[element]++;
    }
    int maxFrequency = 0;


    // Find the element with the maximum frequency
    for (const auto& pair : frequencyMap) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
        }
    }


    std::cout << n-maxFrequency << std::endl;

}


int main(){
    int t;
    std::cin >> t;
    while (t--){
        solve();
    }
    return 0;
}