class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> leaders;
        
        int maxi = arr[n-1];
        leaders.push_back(-1);
        
        for(int i = n-2;i>=0;i--){
            if(arr[i]>=maxi){
                leaders.push_back(maxi);
                maxi = arr[i];
            }
            else{
                leaders.push_back(maxi);
            }
        }
        
        reverse(leaders.begin(),leaders.end());
        
        return leaders;
    }
};