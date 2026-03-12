class Solution {
public:
    bool checkBST(TreeNode* root, long long& prev){
        if(!root){
            return true;
        }
        
        bool l = checkBST(root->left, prev);
        if(!l){
            return false;
        }
        if(root->val <= prev){
            return false;
        }
        
        prev = root->val;
        return checkBST(root->right, prev);
    }
    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;
        return checkBST(root, prev);
    }
};