class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
         sort(arr.begin(), arr.end());

    int left = 0, right = arr.size() - 1;
    while (left < right){
        int sum = arr[left] + arr[right];
        if (sum == target)
            return true;
        else if (sum < target)
            left++; 
        else
            right--; 
    }
    return false;
    }
};