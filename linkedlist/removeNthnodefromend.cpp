class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
    
            int count =0;
            ListNode *temp=head;
            ListNode *prev=NULL;
    
            while(temp){
                count++;
                temp=temp->next;
            }
    
            if(count==n){
                head=head->next;
            }
            else{
                 count-=n;
            
            temp=head;
    
            while(count--){
                prev=temp;
                temp=temp->next;
            }
             prev->next=temp->next;
             delete temp;
            }
           
            return head;
            
        }
    };