// User function Template for C++

class Solution {
  public:
    int findDays(int arr[],int n,int cap){
        int day=1,load=0;
        for(int i=0;i<n;i++){
            if(arr[i]+load>cap){
                day++;
                load=arr[i];
            }
            else{
                load+=arr[i];
            }
        }
        
        return day;
        
    }
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        // int n=arr.size();
        int maxw=INT_MIN;
        int sum=0;
        
        for(int i=0;i<n;i++){
            maxw=max(maxw,arr[i]);
            sum+=arr[i];
        }
        
        int low=maxw;
        int high=sum;
        
        while(low<=high){
            int mid= low+(high-low)/2;
            
            int noOfDays = findDays(arr,n,mid);
            
            if(noOfDays<=d){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return low;
    }
};