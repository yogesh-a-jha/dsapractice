class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // code here
        vector<int> ans;
        queue<Node *>q;
        
        q.push(root);
        ans.push_back(root->data);
        while(!q.empty()){
            Node *temp = q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
                ans.push_back(temp->left->data);
            }
            if(temp->right){
                q.push(temp->right);
                ans.push_back(temp->right->data);
            }
        }
        
        return {ans};
    }
};