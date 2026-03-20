class Solution {
public:
    TreeNode* buildBst(vector<int>& preorder,int& index, int lower, int upper){

        if(index == preorder.size() || preorder[index] < lower || preorder[index] > 
        upper){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        root->left = buildBst(preorder,index,lower,root->val);
        root->right = buildBst(preorder,index,root->val,upper);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return buildBst(preorder,index,INT_MIN,INT_MAX);
    }
};