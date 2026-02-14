class Solution {
  public:
    void find(Node *root, int pos, int &left, int &right){
        if(!root){
            return;
        }
        
        left = min(pos,left);
        right = max(pos,right);
        find(root->left, pos-1, left, right);
        find(root->right, pos+1, left, right);
        
    }
    vector<int> topView(Node *root) {
        // code here
        int left = 0, right = 0;
        
        find(root, 0, left, right);
        int n = right-left+1;
        vector<int>ans(n);
        vector<int>filled(n,0);
        
        queue<Node*>q;
        queue<int>index;
        
        q.push(root);
        index.push(-1*left);
        
        while(!q.empty()&&!index.empty()){
            Node * temp = q.front();
            q.pop();
            int t = index.front();
            index.pop();
            
            if(filled[t]==0){
                ans[t] = temp->data;
                filled[t]+=1;
            }
            
            
            if(temp->left){
                q.push(temp->left);
                index.push(t-1);
            }
            if(temp->right){
                q.push(temp->right);
                index.push(t+1);
            }
        }
        
        return ans;
        
    }
};