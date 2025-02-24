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

Node * dll(int arr[],int i,int size,Node *back){
    if(i==size){
        return NULL;
    }
    Node *temp=new Node(arr[i]);
    temp->prev=back;
    temp->next=dll(arr,i+1,size,temp);

    return temp;


}

int main(){
     Node *head=NULL,*tail=NULL;

     int arr[5]={1,2,3,4,5};


     //create with recurssion

     head=dll(arr,0,5,NULL);


    //  //copy array data into linkedlist
    //  for(int i=0;i<5;i++){
    //     if(head==NULL){
    //         head=new Node(arr[i]);
    //         tail=head;
    //     }
    //     else{
    //         Node * temp=new Node(arr[i]);
    //         tail->next=temp;
    //         temp->prev=tail;
    //         tail=temp;
    //     }
    //  }

    //  //inset at start
    //  if(head==NULL){ //if head is null
    //     head=new  Node(5);
    //  }
    //  else{            //if node is present
    //     Node * temp=new Node(5);
    //     temp->next=head;
    //     head->prev=temp;
    //     head=temp;
    //  }

     Node *temp=head;
     while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
     }
}