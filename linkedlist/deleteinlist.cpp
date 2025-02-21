class Solution {
    public:
      /* Function to delete a node from a linked list */
      Node* deleteNode(Node* head, int x) {
          // cdoe here
          
          if(x==1){
              Node *temp=head->next;
              delete head;
              return temp;
          }
          
          head->next=deleteNode(head->next,x-1);
          
          return head;
      }
  };