class Solution {
public:
    void checkBST(TreeNode* root, int& prev, int& minD){
        if(!root){
            return ;
        }
        
        checkBST(root->left, prev, minD);
        if(prev != INT_MIN){
            minD = min(minD, abs(root->val - prev));
        }
        
        prev = root->val;
        return checkBST(root->right, prev, minD);
    }
    int minDiffInBST(TreeNode* root) {
        int prev = INT_MIN;
        int minD = INT_MAX;
        checkBST(root, prev, minD);

        return minD;
    }
};