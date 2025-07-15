class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Your Code Here
       int n = arr.size();
    sort(arr.begin(), arr.end());
    
    // Fix the first element as arr[i] 
    for (int i = 0; i < n - 2; i++) {
      
        // Initialize left and right pointers with 
        // start and end of remaining subarray
        int l = i + 1, r = n - 1;
      
        int requiredSum = target - arr[i];
        while(l < r) {
            if(arr[l] + arr[r] == requiredSum)
                return true;
            if(arr[l] + arr[r] < requiredSum)
                l++;
            else if(arr[l] + arr[r] > requiredSum)
                r--;
        }
    } 

    // If we reach here, then no triplet was found 
    return false; 
    }
};