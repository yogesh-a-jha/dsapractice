class Solution {
  public:
    void checkBST(Node* root, int& k, int& el){
        if(!root ){
            return ;
        }
        
        checkBST(root->left, k, el);
        if(k == 1){
            el = root->data;
        }
        k--;
        checkBST(root->right, k, el);
    }
    int kthSmallest(Node *root, int k) {
        // code here
        int el = -1;
        checkBST(root, k, el);

        return el;
        
    }
};