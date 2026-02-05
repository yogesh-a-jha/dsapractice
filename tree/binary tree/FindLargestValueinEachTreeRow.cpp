class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode *>q;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int levelSize = q.size();
            int maxVal = INT_MIN;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                maxVal = max(maxVal, node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(maxVal);
        }
        
        return ans;
    }
};