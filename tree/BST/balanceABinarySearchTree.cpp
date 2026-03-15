class Solution {
public:
    void inorder(TreeNode* root, vector<int>& arr) {
        if (!root) return;
        
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    TreeNode* buildBST(vector<int>& arr, int l, int r) {
        if (l > r) return nullptr;
        
        int mid = (l + r) / 2;
        
        TreeNode* root = new TreeNode(arr[mid]);
        
        root->left = buildBST(arr, l, mid - 1);
        root->right = buildBST(arr, mid + 1, r);
        
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        
        inorder(root, arr);
        
        return buildBST(arr, 0, arr.size() - 1);
    }
};