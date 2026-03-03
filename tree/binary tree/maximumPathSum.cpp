class Solution {
  public:
    int PathSum(Node *root, int &sum){
        if(!root){
            return 0;
        }
        
        //leaf Node
        if(!root->left && !root->right){
            return root->data;
        }
        
        int left = PathSum(root->left, sum);
        int right = PathSum(root->right, sum);
        
        //left and right both exist
        if(root->left && root->right){
            sum = max(sum, root->data + left + right);
            return root->data + max(left,right);
        }
        //only left exist
        if(root->left){
            return root->data + left;
        }
        //only right exist
        if(root->right){
            return root->data + right;
        }
        
        
    }
    int maxPathSum(Node* root) {
        // code here
        int sum = INT_MIN;
        int val = PathSum(root,sum);
        
        // root node bhi special node ho skta hai
        if(root->left && root->right){
            return sum;
        }
        
        return max(sum, val);
        
    }
};