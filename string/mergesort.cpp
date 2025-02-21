//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
   void merge(vector<int>& arr,int start,int mid,int end){
        vector<int>temp(end-start+1);
        int left=start,right=mid+1,index=0;
        
        while(left<=mid&&right<=end){
            if(arr[left]<=arr[right]){
                temp[index]=arr[left];
                index++,left++;
            }
            else{
                temp[index]=arr[right];
                index++,right++;
            }
        }
        
        //left array
        
        while(left<=mid){
            temp[index]=arr[left];
            index++,left++;
        }
        
        //right array
        
        while(right<=end){
            temp[index]=arr[right];
            index++,right++;
        }
        
        index=0;
        
        while(start<=end){
            arr[start]=temp[index];
            start++,index++;
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        int start=l,end=r;
        
        if(start==end)
        return;
        
        int mid=start+(end-start)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
        
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends