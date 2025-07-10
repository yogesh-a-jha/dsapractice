class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size()+1;
        vector<int>frequency (n,0);
        int missing=-1;
        int repeating=-1;
        
        for(int i=0;i<n-1;i++){
            frequency[arr[i]]++;
        }
        
        for(int i =0;i<n;i++){
            if(frequency[i]==0){
                missing=i;
            }
            if(frequency[i]==2){
                repeating=i;
            }
        }
        
        return {repeating,missing};
    }
};