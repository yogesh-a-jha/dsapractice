class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // code here
        int res=0;
        for(int i=0;i<arr.size();i++){
            res=res^arr[i];
        }
        
        return res;
    }
};