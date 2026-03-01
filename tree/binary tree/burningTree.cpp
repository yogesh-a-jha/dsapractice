class Solution {
public:
    int burn(TreeNode* root, int &timer, int target){
        if(!root){
            return 0;
        }
        
        if(root->val == target){
            return -1;
        }
        
        int left = burn(root->left, timer, target);
        int right = burn(root->right, timer, target);
        
        if(left<0){
            timer = max(timer,abs(left) + right);
            return left-1;
        }
        if(right<0){
            timer = max(timer,abs(right) + left);
            return right-1;
        }
        
        return 1+max(left,right);
    }
    
    void find(TreeNode* root, int target, TreeNode* &targetNode){
        if(!root){
            return;
        }
        if(root->val == target){
            targetNode = root;
            return ;
        }
        find(root->left,target, targetNode);
        find(root->right,target, targetNode);
    }
    
    int height(TreeNode* targetNode) {
        if(!targetNode){
            return 0;
        }
        
        return 1 + max(height(targetNode->left),height(targetNode->right));
    }
    int amountOfTime(TreeNode* root, int target) {

        int timer = 0;
        burn(root, timer, target);
        
        TreeNode *targetNode = NULL;
        
        find(root,target, targetNode);
        
        int high = height(targetNode)-1;
        
        return max(timer, high);
    }
};