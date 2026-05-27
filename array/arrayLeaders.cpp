

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> leaders;
        
        int maxi = arr[n-1];
        leaders.push_back(maxi);
        
        for(int i = n-2;i>=0;i--){
            if(arr[i]>=maxi){
                leaders.push_back(arr[i]);
                maxi = arr[i];
            }
        }
        
        reverse(leaders.begin(),leaders.end());
        
        return leaders;
    }
};