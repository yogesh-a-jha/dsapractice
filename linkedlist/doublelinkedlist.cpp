#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int value){
        data=value;
        next=NULL;
        prev=NULL;

    }

};

int main(){
     Node *head=NULL;
     //inset at start
     if(head==NULL){ //if head is null
        head=new  Node(5);
     }
     else{            //if node is present
        Node * temp=new Node(5);
        temp->next=head;
        head->prev=temp;
        head=temp;
     }

     Node *temp=head;
     while(temp){
        cout<<temp->data;
        temp=temp->next;
     }
}