// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    public:
    int data, height;
    Node *left, *right;
    Node(int x){
        data = x;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node *root){
    if(!root){
        return 0;
    }
    else{
        return root->height;
    }
}

int getBalance(Node *root){
    return getHeight(root->left) - getHeight(root->right);
}

Node* rightRotation(Node *root){
    Node *child = root->left;
    Node *childRight = child->right;
    
    child->right = root;
    root->left = childRight;
    
    root->height = 1+max(getHeight(root->left),getHeight(root->right));
    child->height = 1+max(getHeight(child->left),getHeight(child->right));
    
    return child;
}

Node* leftRotation(Node *root){
    Node *child = root->right;
    Node *childLeft = child->left;
    
    child->left = root;
    root->right = childLeft;
    
    root->height = 1+max(getHeight(root->left),getHeight(root->right));
    child->height = 1+max(getHeight(child->left),getHeight(child->right));
    
    return child;
}

Node* insert(Node *root, int key){
    //NULL
    if(!root){
        return new Node(key);
    }
    //exist
    if(root->data > key){
        root->left = insert(root->left, key);
    }
    else if(root->data < key){
        root->right = insert(root->right, key);
    }
    else{
        return root;
    }
    
    //update height
    root->height = 1+max(getHeight(root->left),getHeight(root->right));
    
    //check balance
    int balance = getBalance(root);
    
    // left left
    if(balance > 1 && key < root->left->data){
        return rightRotation(root);
    }
    //right right
    else if(-1 > balance && root->right->data < key){
        return leftRotation(root);
    }
    //left right
    else if(balance > 1 && key > root->left->data){
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    //right left
    else if(-1 > balance && root->right->data > key){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    else{
        return root; 
    }
}

void preorder(Node* root){
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    // Write C++ code here
    Node *root = NULL;
    
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);
    
    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder: ";
    inorder(root);

    return 0;
}