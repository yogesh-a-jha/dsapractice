// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> postOrder(Node* root) {
        // code here
        vector<int>ans;
        stack<Node*>s;
        if(!root){
            return ans;
        }
        
        s.push(root);
        
        while(!s.empty()){
            Node *temp = s.top();
            s.pop();
            ans.push_back(temp->data);
            if(temp->left){
                s.push(temp->left);
            }
            if(temp->right){
                s.push(temp->right);
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};