class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int n=a.size();
        sort(a.begin(),a.end());
        int start=0;
        int end=m-1;
        int minimised=INT_MAX;
        while(start<=n-m&&end<=n-1){
            if(a[end]-a[start]<=minimised){
                minimised=a[end]-a[start];
            }
            start++;
            end++;
        }
        
        return minimised;
    }
};