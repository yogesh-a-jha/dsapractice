class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        queue<Node*> q;
        vector<int>ans;
        if(!root){
            return ans;
        }
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int>level;
            while(size--){
                Node *temp = q.front();
                q.pop();
                level.push_back(temp->data);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            ans.push_back(level[0]);
        }
        
        return ans;
    }
};