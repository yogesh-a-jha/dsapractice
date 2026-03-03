class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int key) {
        if(!root){
            return NULL;
        }
        
        if(root->val == key){
            return root;
        }

        return key < root->val ? searchBST(root->left, key) : 
                                searchBST(root->right, key);
    }
};