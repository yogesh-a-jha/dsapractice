875. Koko Eating Bananas
Solved
Medium
Topics
Companies
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23

#code
class Solution {
    public:
        int minEatingSpeed(vector<int>& arr, int h) {
            int start=0;
            int n=arr.size();
            int end=0;
            long long sum=0;
            for(int i=0;i<n;i++){
                if(arr[i]>end){
                    end=arr[i];
                }
                sum+=arr[i];
    
    
            }
            start=sum/h;
            if(start==0){
                start=1;
            }
            int mid;
            int ans;
            while(start<=end){
                mid=start+(end-start)/2;
                int k=0;
                for(int i=0;i<n;i++){
                    k+=arr[i]/mid;
                    if(arr[i]%mid!=0){
                        k++;
    
                    }
                    
                }
                if(k>h){
                    start=mid+1;
    
                }
                else{
                    ans=mid;
                    end=mid-1;
                }
    
            }
            return ans;
        }
    };