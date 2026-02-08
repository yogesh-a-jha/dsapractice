class Solution {
public:
    int height(TreeNode* a, bool &valid){
        if(!a){
            return 0;
        }
        int lheight = height(a->left,valid);
        int rheight = height(a->right,valid);
        if(abs(lheight - rheight)>1){
            valid = 0;
        }
        return 1 + max(lheight,rheight);
    }
    bool isBalanced(TreeNode* root) {
        bool valid =1;
        
        height(root, valid);
        return valid;
    }
};