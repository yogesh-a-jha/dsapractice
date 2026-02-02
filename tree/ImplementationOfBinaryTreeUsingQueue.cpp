#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
    Node(int value){
        data = value;
        left = right = NULL;
    }
};

int main() {
    
    int x;
    int first,second;
    queue<Node *>q; //using Queue for nodes
    
    cout<<"Enter the Root node: ";
    cin>>x;
    
    Node *root = new Node(x);
    q.push(root);
    
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        cout<<"Enter left Node of "<<temp->data<<" : ";
        cin>>first;
        //for left nodes
        if(first!=-1){
            temp->left = new Node(first);
            q.push(temp->left);
        }
        cout<<"Enter right Node of "<<temp->data<<" : ";
        cin>>second;
        //for right node
        if(second!=-1){
            temp->right = new Node(second);
            q.push(temp->right);
        }
    }

    return 0;
}