class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
         int n = arr.size();
        vector<int> ans(n,1);
        stack<int> st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]<arr[i]){
                ans[st.top()]=st.top()-i;
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            ans[st.top()]=st.top()+1;
            st.pop();
        }
        
        return ans;
    }
};