class Solution {
  public:
    int lastOcc(vector<int>& arr,int n,int x){
        
        int left=0,right=n-1;
        int last=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            
            if(arr[mid]==x){
                last=mid;
                left=mid+1;
                
            }
            else if(arr[mid]<x){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return last;
    }
    int firstOcc(vector<int>& arr,int n,int x){
        int left=0,right=n-1;
        int first=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            
            if(arr[mid]==x){
                first=mid;
                right=mid-1;
                
            }
            else if(arr[mid]<x){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        
        return first;
        
    }
    
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int first=firstOcc(arr,n,x);
        int last=lastOcc(arr,n,x);
        return {first,last};
    }
};