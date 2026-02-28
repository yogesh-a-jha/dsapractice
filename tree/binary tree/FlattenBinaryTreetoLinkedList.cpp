class Solution {
public:
    void flatten(TreeNode* root) {
        while(root){
            //left not exist
            if(!root->left){
                root = root->right;
            }
            //left exist
            else{
                TreeNode *curr = root->left;
                
                while(curr->right && curr->right!=root){
                    curr = curr->right;
                }
                curr->right = root->right;
                root->right = root->left;
                root->left = NULL;
                root = root->right;
            }
        }
    }
};