ListNode * reverse(ListNode * curr,ListNode *prev){
    if(curr==NULL){
        return prev;
    }

    ListNode * fut=curr->next;
    curr->next=prev;
    return reverse(fut,curr);
 }
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //   vector<int>ans;
        // ListNode *temp=head;
        // while(temp!=NULL){
        //     ans.push_back(temp->val);
        //     temp=temp->next;
        // }
        
        // int i=ans.size()-1;
        // temp=head;
        // while(temp!=NULL){
        //     temp->val=ans[i];
        //     i--;
        //     temp=temp->next;
        // }

        //Second method

        // ListNode *curr=head,*prev=NULL,*fut=NULL;
        // while(curr){
        //     fut=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=fut;
        // }

        // head=prev;

        // return head;

        head=reverse(head,NULL);
        return head;

    }
};