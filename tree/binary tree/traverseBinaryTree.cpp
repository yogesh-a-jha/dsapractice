// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int value){
       data = value;
       left = right = NULL;
    }
};

Node * binaryTree(){
    int x;
    cin>>x;
    
    if(x==-1){
        return NULL;
    }
    
    Node *temp = new Node(x);
    cout<<"Enter the Left Node of "<<x<<" : ";
    temp->left = binaryTree(); //left node
    cout<<"Enter the Right Node of "<<x<<" : ";
    temp->right = binaryTree(); //right node
    
    return temp;
}

void preOrder(Node* root) {
        // code here
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
        
    }
void inOrder(Node* root) {
        // code here
        if(root==NULL){
            return;
        }
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
        
    }
void postOrder(Node* root) {
        // code here
        if(root==NULL){
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
        
    }
int main() {
    
    cout<<"Enter the Root Node: ";
    Node *root;
    root = binaryTree();
    cout<<"PreOrder:";
    preOrder(root);
    cout<<"\ninOrder:";
    inOrder(root);
    cout<<"\npostOrder:";
    postOrder(root);

    return 0;
}