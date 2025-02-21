// // Online C++ compiler to run C++ program online
// #include <iostream>
// using namespace std;

// class Node{
//     public:
//     int data;
//     Node *next;
//     Node(int value){
//         data=value;
//         next=NULL;
//     }
// };
// //insertion by recurssion at end
// Node* createLinkedList(int arr[],int index,int size){
//     if(index==size)
//     return NULL;
    
//     Node *temp;
//     temp=new Node(arr[index]);
//     temp->next= createLinkedList(arr,index+1,size);
//     return temp;
// }// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int value){
        data=value;
        next=NULL;
    }
};
//insertion by recurssion at end
Node* createLinkedList(int arr[],int index,int size){
    if(index==size)
    return NULL;
    
    Node *temp;
    temp=new Node(arr[index]);
    temp->next= createLinkedList(arr,index+1,size);
    return temp;
}

int main() {
    // Write C++ code here
   Node *head;
//   head=NULL;
   int n=5;
   int arr[n]={10,20,30,40,50};
   head=createLinkedList(arr,0,n);
   
  
// //insert at start
//   for(int i=0;i<n;i++){
//       if(head==NULL){
//           head= new Node(arr[i]);
//       }
//       else{
//           Node *temp;
//           temp=new Node(arr[i]);
//           temp->next=head;
//           head=temp;
//       }
//   }
// //insert at end
//     Node *tail;
//     tail=NULL;
    
//     for(int i=0;i<n;i++){
//         if(head==NULL){
//             head= new Node(arr[i]);
//             tail=head;
//         }
//         else{
//             tail->next=new Node(arr[i]);
//             tail=tail->next;
//         }
//     }
   
   //Insert at a perticular place
    Node *temp=head;
   int x=3;
   int value=35;
   x--;
   while(x--){
       temp=temp->next;
       
       
   }
   
   Node *temp2;
   temp2=new Node(value);
   temp2->next=temp->next;
   temp->next=temp2;
   //print values
   temp=head;
   while(temp!=NULL){
       cout<<temp->data<<" ";
       temp=temp->next;
   }

    return 0;
}

int main() {
    // Write C++ code here
   Node *head;
//   head=NULL;
   int n=5;
   int arr[n]={10,20,30,40,50};
   head=createLinkedList(arr,0,n);
   
  
// //insert at start
//   for(int i=0;i<n;i++){
//       if(head==NULL){
//           head= new Node(arr[i]);
//       }
//       else{
//           Node *temp;
//           temp=new Node(arr[i]);
//           temp->next=head;
//           head=temp;
//       }
//   }
// //insert at end
//     Node *tail;
//     tail=NULL;
    
//     for(int i=0;i<n;i++){
//         if(head==NULL){
//             head= new Node(arr[i]);
//             tail=head;
//         }
//         else{
//             tail->next=new Node(arr[i]);
//             tail=tail->next;
//         }
//     }
   
   //print values
   Node *temp=head;
   while(temp!=NULL){
       cout<<temp->data<<" ";
       temp=temp->next;
   }

    return 0;
}