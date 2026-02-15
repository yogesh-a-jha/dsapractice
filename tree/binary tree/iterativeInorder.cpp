
class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        vector<int>ans;
        stack<Node*>s;
        stack<bool>visited;
        if(!root){
            return ans;
        }
        s.push(root);
        visited.push(0);
        
        
        while(!s.empty()){
            Node * temp = s.top();
            s.pop();
            bool flag = visited.top();
            visited.pop();
            if(!flag){
                if(temp->right){
                    s.push(temp->right);
                    visited.push(0);
                }
                s.push(temp);
                visited.push(1);
                if(temp->left){
                    s.push(temp->left);
                    visited.push(0);
                }
            }
            else{
                ans.push_back(temp->data);
                
            }
        }
        
        return ans;
    }
};