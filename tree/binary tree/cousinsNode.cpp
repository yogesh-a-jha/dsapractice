class Solution {
  public:
    // Function to check if two nodes are cousins in a tree
    bool parent(Node* root, int x, int y){
        if(!root){
            return false;
        }
        if(root->left && root->right){
            if(root->left->data == x && root->right->data == y){
                return true;
            }
            if(root->left->data == y && root->right->data == x){
                return true;
            }
        }
        
        return parent(root->left,x,y)||parent(root->right,x,y);
    }
    bool isCousins(Node* root, int x, int y) {
        if (!root || x == y) return false;
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
                
            int size = q.size();
            bool foundX = false, foundY = false;
    
            for (int i = 0; i < size; i++) {
                Node* temp = q.front();
                q.pop();
    
                if (temp->data == x) foundX = true;
                if (temp->data == y) foundY = true;
    
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
    
            if (foundX && foundY)
                return !parent(root, x, y);
    
            if (foundX || foundY)
                return false;
        }
        
        return false;
        
        
    }
};