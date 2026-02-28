class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        //left
        //node
        //right
        
        vector<int>ans;
        
        while(root){
            //left not exist
            if(!root->left){
                ans.push_back(root->data);
                root = root->right;
            }
            //left exist
            else{
                Node *curr = root->left;
                while(curr->right && curr->right!=root){
                    curr = curr->right;
                }
                //not traversed
                if(curr->right == NULL){
                    curr->right = root;
                    root = root->left;
                }
                //already traversed
                else{
                    curr->right = NULL;
                    ans.push_back(root->data);
                    root = root->right;
                }
            }
        }
        
        return ans;
    }
};