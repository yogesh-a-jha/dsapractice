
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int answer=0;
        int n=prices.size();
        
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1]){
                answer+=prices[i]-prices[i-1];
            }
        }
        
        return answer;
    }
};
