class Solution {
public:
    class Box {
        public:
        bool bst;
        int sum;
        int min;
        int max;
        
        Box(int data){
            bst = 1;
            sum = data;
            min = data;
            max = data;
        }
    };

    Box* find(TreeNode *root, int &totalSum){
        if(!root->left && !root->right){
            totalSum = max(totalSum, root->val);
            return new Box(root->val);
        }
        else if(!root->left && root->right){
            Box *head = find(root->right, totalSum);
            
            if(head->bst && head->min > root->val){
                head->sum += root->val;
                head->min = root->val;
                totalSum = max(totalSum, head->sum);
                return head;
            }
            else{
                head->bst = 0;
                head->sum = 0;
                return head;
            }
        }
        else if(root->left && !root->right){
            Box *head = find(root->left, totalSum);
            
            if(head->bst && head->max < root->val){
                head->sum += root->val;
                head->max = root->val;
                totalSum = max(totalSum, head->sum);
                return head;
            }
            else{
                head->bst = 0;
                head->sum = 0;
                return head;
            }
        }
        else{
            Box *leftHead = find(root->left, totalSum);
            Box *rightHead = find(root->right, totalSum);
            
            if(leftHead->bst && rightHead->bst && leftHead->max < root->val
            && rightHead->min > root->val){
                Box *head = new Box(root->val);
                head->sum += leftHead->sum + rightHead->sum;
                head->min = leftHead->min;
                head->max = rightHead->max;
                
                totalSum = max(totalSum, head->sum);
                return head;
            }
            else{
                leftHead->bst = 0;
                leftHead->sum = 0;
                return leftHead;
            }
        }
    }
    int maxSumBST(TreeNode* root) {
        int totalSum = 0;
        
        find(root, totalSum);
        
        return totalSum;
    }
};