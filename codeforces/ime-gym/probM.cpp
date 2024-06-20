#include <iostream>
#include <vector>

using namespace std;

// Function to count inversions in a subarray
int countInversions(const vector<int>& arr, int left, int right) {
  int inversions = 0;

    //check
    int c;
    for (size_t i = 1; i < arr.size(); i++)
    {
        if (arr[i] > arr[i-1])
        {
            c++;
        }
        if(c == arr.size()){
            return 0;
        }else{
            continue;
        }
    }
    

  for (int i = left; i < right; ++i) {
    for (int j = i + 1; j <= right; ++j) {
      if (arr[i] > arr[j]) {
        inversions++;
      }
    }
  }
  return inversions;
}

// Function to find the size of the smallest subarray with same inversions
int findSmallestSubarray(const vector<int>& arr) {
  int n = arr.size();
  int totalInversions = countInversions(arr, 0, n - 1);

    if(totalInversions == 0){
        return 0;
    }

  int minSize = n;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int subarrayInversions = countInversions(arr, i, j);
      if (subarrayInversions == totalInversions && j - i + 1 < minSize) {
        minSize = j - i + 1;
      }
    }
  }

  if(minSize<2){
    return 0;
  }else{
    return minSize;
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    int minSubarraySize = findSmallestSubarray(arr);
    cout << minSubarraySize << endl;
  }

  return 0;
}
