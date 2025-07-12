class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n=arr.size();
       vector<int>pref;
       vector<int>suf;
       int pre=0;
       int su=0;
       for(int i=0;i<n;i++){
           pre+=arr[i];
           pref.push_back(pre);
       }
       for(int i=n-1;i>=0;i--){
           su+=arr[i];
           suf.push_back(su);
       }
       
       for(int i=1;i<n-1;i++){
           if(pref[i]==suf[n-i-1]){
              return i;
           }
       }
        return -1;
    }
};