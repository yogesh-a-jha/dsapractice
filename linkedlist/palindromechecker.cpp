class Solution {
    public:
        bool isPalindrome(ListNode* head) {
              int count=0;
            ListNode * temp=head;
            while(temp){
                count++;
                temp=temp->next;
            }
            if(count==1){
                return 1;
            }
            count/=2;
            
            ListNode * prev=NULL,*curr=head;
            while(count--){
                prev=curr;
                curr=curr->next;
            }
            
            prev->next=NULL;
            
            prev=NULL;
            ListNode *fut=NULL;
            while(curr){
                fut=curr->next;
                curr->next=prev;
                prev=curr;
                curr=fut;
            }
            
            ListNode * head1=head,*head2=prev;
            
            while(head1){
                if(head1->val!=head2->val)
                return 0;
                head1=head1->next;
                head2=head2->next;
            }
            return 1;
        }
    };