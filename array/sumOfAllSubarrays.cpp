// User function template for C++

class Solution {
  public:
    long long subarraySum(vector<int>& arr) {
        // Your code goes here
     const long long MOD = 1000000007;
        int n = arr.size();
        long long result = 0;
        for (int i = 0; i < n; i++) {
            long long a = arr[i] % MOD;
            long long b = (i + 1LL);
            long long c = (n - i);
            long long contrib = ((a * b) % MOD * c) % MOD;
            result = (result + contrib) % MOD;
        }
        return result;
    
    }
};