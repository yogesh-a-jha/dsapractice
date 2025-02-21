//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
     void lpsFind(vector<int>&lps,string s){
        int pre=0;
        int suf=1;
        while(suf<s.size()){
            if(s[pre]==s[suf]){
                lps[suf]=pre+1;
                pre++;
                suf++;
            }
            else{
                if(pre==0){
                    lps[suf]=0;
                    suf++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
    }
    int KMP_MATCH(string haystack, string needle) {
        vector<int>lps(needle.size(),0);
        lpsFind(lps,needle);
        int first =0,second=0;
        while(first<haystack.size()&&second<needle.size()){
            if(haystack[first]==needle[second]){
                first++,second++;
            }
            else{
                if(second==0)
                first++;
                else
                second=lps[second-1];
            }
        }

        if(second==needle.size())
        return 1;

        return 0;


    }  
    int repeatedStringMatch(string a, string b) {
        // Your code goes here
        
        
        if(a==b){
            return 1;
        }
        
        int repeat=1;
        
        string temp=a;
        while(temp.size()<b.size()){
            temp+=a;
            repeat++;
            
        }
        
        if(KMP_MATCH(temp,b)==1){
            return repeat;
        }
        if(KMP_MATCH(temp+a,b)==1){
            return repeat+1;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A;
        cin >> B;
        Solution obj;
        cout << obj.repeatedStringMatch(A, B) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends