class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        int n=a.size();
        int m=b.size();
        
        vector<int>uni;
        vector<int>result;
        
        for(int i=0;i<n;i++){
                uni.push_back(a[i]);
        }
        for(int i=0;i<m;i++){
                uni.push_back(b[i]);
        }
        
        sort(uni.begin(),uni.end());
        
        result.push_back(uni[0]);
        for(int i=1;i<uni.size();i++){
            if(uni[i]!=uni[i-1]){
                result.push_back(uni[i]);
            }
        }
        
        
        
        
        
        return result;
        // return vector with correct order of elements
    }
};