#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

// Function to evaluate the expression
long long evaluateExpression(const string& expr) {
    vector<long long> nums;
    vector<char> ops;
    long long num = 0;
    
    // Parse the expression long longo numbers and operators
    for (char ch : expr) {
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        } else {
            nums.push_back(num);
            ops.push_back(ch);
            num = 0;
        }
    }
    nums.push_back(num);
    
    // Evaluate multiplication first
    vector<long long> new_nums;
    vector<char> new_ops;
    
    new_nums.push_back(nums[0]);
    for (size_t i = 0; i < ops.size(); ++i) {
        if (ops[i] == '*') {
            long long last_num = new_nums.back();
            new_nums.pop_back();
            new_nums.push_back(last_num * nums[i + 1]);
        } else {
            new_nums.push_back(nums[i + 1]);
            new_ops.push_back(ops[i]);
        }
    }
    
    // Evaluate addition
    long long result = new_nums[0];
    for (size_t i = 0; i < new_ops.size(); ++i) {
        result += new_nums[i + 1];
    }
    
    return result;
}

// Function to find the minimum result
long long findMinResult(const string& s, long long n) {
    long long min_result = LONG_LONG_MAX;
    long long num_symbols = n - 2;
    
    long long total_combinations = pow(2, num_symbols);
    
    for (long long i = 0; i < total_combinations; ++i) {
        string expr;
        expr += s[0];
        for (long long j = 0; j < num_symbols; ++j) {
            if (i & (1 << j)) {
                expr += '*';
            } else {
                expr += '+';
            }
            expr += s[j + 1];
        }
        expr += s[n - 1];
        
        long long result = evaluateExpression(expr);
        min_result = min(min_result, result);
    }
    
    return min_result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long t;
    cin >> t;
    vector<long long> results(t);
    
    for (long long i = 0; i < t; ++i) {
        long long n;
        string s;
        cin >> n >> s;
        
        if (n == 2) {
            results[i] = stoi(s);
        } else {
            results[i] = findMinResult(s, n);
        }
    }
    
    for (long long result : results) {
        cout << result << '\n';
    }
    
    return 0;
}
