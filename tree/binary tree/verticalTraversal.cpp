class Solution {
public:
    void find(TreeNode *root, int pos, int &left, int &right){
        if(!root){
            return;
        }
        
        left = min(pos,left);
        right = max(pos,right);
        find(root->left, pos-1, left, right);
        find(root->right, pos+1, left, right);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int left = 0, right = 0;
        find(root, 0, left, right);
        
        int n = right-left+1;
        
        vector<vector<pair<int,int>>> temp(n);
        
        queue<TreeNode*> q;
        queue<int> index;
        queue<int> level;
        
        q.push(root);
        index.push(-left);
        level.push(0);
        
        while(!q.empty()){
            
            TreeNode *node = q.front();
            q.pop();
            
            int pos = index.front();
            index.pop();
            
            int row = level.front();
            level.pop();
            
            temp[pos].push_back({row, node->val});
            
            if(node->left){
                q.push(node->left);
                index.push(pos-1);
                level.push(row+1);
            }
            
            if(node->right){
                q.push(node->right);
                index.push(pos+1);
                level.push(row+1);
            }
        }
        
        // final answer
        vector<vector<int>> ans(n);
        
        for(int i = 0; i < n; i++){
            
            sort(temp[i].begin(), temp[i].end());
            
            for(auto &p : temp[i]){
                ans[i].push_back(p.second);
            }
        }
        
        
        return ans;
    }
};