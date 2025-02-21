class Solution {
    public:
      Node* deleteK(Node* head, int k) {
          // code here
          int count=1;
          Node *temp=head,*prev=NULL;
          if(k==1){
              return NULL;
          }
          while(temp){
              
             
              if(count==k){
                prev->next=temp->next;
                count=1;
                delete temp;
                temp=prev->next;
              }
              else{
                   prev=temp;
              temp=temp->next;
              count++;
              }
          }
          return head;
      }
  };