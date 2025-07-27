/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        if(head==nullptr || head->next==nullptr){
            return ;
        }
        Node *slow=head,*fast=head;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                break;
            }
        }
        if(fast==nullptr || fast->next==nullptr){
            return;
        }
          slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            
            while(slow->next!=fast){
                slow=slow->next;
            }
            
            slow->next=nullptr;
        
        return ;
    }
};