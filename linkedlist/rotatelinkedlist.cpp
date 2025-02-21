class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
             if(head==NULL||head->next==NULL){
                return head;
            }
           int l=0,count=0;
           ListNode *temp=head,*prev=NULL,*curr=head;
           
           while(temp){
               temp=temp->next;
               count++;
           }
           k=k%count;
           if(k==0){
               return head;
           }
          count-=k;
          while(count--){
              prev=curr;
              curr=curr->next;
              
          }
          
          prev->next=NULL;
          ListNode *tail=curr;
          
          while(tail->next!=NULL){
              tail=tail->next;
          }
          
          tail->next=head;
          head=curr;
          return head;
        }
    };