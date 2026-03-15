class Solution {
  public:
    Node* buildTree(vector<int>& arr, int start, int end){
        
        if(start > end)
            return NULL;
        int mid = start + (end - start)/2;
        
        Node* root = new Node(arr[mid]);
        
        root->left = buildTree(arr, start, mid-1);
        root->right = buildTree(arr, mid+1, end);
        return root;
    }
    Node* sortedArrayToBST(vector<int>& arr) {
        // code here
        return buildTree(arr, 0, arr.size()-1);
        
    }
};