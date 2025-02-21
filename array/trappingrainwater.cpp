42. Trapping Rain Water
Solved
Hard
Topics
Companies
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

#code

class Solution {
    public:
        int trap(vector<int>& arr) {
            int n=arr.size();
             int rightmax=0;
        int leftmax=0;
        int index=0;
        int water=0;
        int maxheight=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
            maxheight=maxi;
            if(maxi<=arr[i]){
                index=i;  
            }
        }
        // cout<<index<<maxi;
        maxi=INT_MIN;
        for(int i=0;i<index;i++){
            maxi=max(arr[i],maxi);
            leftmax=min(maxi,maxheight);
            // cout<<leftmax;
            water+=leftmax-arr[i];
            // cout<<water<<" ";
        }
        maxi=INT_MIN;
        for(int i=n-1;i>index;i--){
            maxi=max(arr[i],maxi);
            rightmax=min(maxi,maxheight);
            // cout<<rightmax;
            water+=rightmax-arr[i];
            // cout<<water<<" ";
        }
        return water;
        }
    };