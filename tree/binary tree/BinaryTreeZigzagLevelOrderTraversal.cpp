class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*>dq;
        vector<vector<int>>ans;

        if(!root){
            return ans;
        }

        dq.push_back(root);
        bool leftToRight = true;

        while(!dq.empty()){
            int size = dq.size();
            vector<int>level;

            for (int i = 0; i < size; i++) {

                if (leftToRight) {
                    TreeNode* temp = dq.front();
                    dq.pop_front();

                    level.push_back(temp->val);

                    if (temp->left) dq.push_back(temp->left);
                    if (temp->right) dq.push_back(temp->right);

                } else {
                    TreeNode* temp = dq.back();
                    dq.pop_back();

                    level.push_back(temp->val);

                    if (temp->right) dq.push_front(temp->right);
                    if (temp->left) dq.push_front(temp->left);
                }
            }
            ans.push_back(level);
            leftToRight = !leftToRight;
        }
        
        return ans;
    }
};