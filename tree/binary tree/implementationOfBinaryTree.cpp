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


int main() {
    
    cout<<"Enter the Root Node: ";
    Node *root;
    root = binaryTree();

    return 0;
}