class Solution {
    public:
      // Function to delete a node without any reference to the head pointer.
      void deleteNode(Node* curr) {
          // Your code here
          Node *temp=curr->next;
          curr->next=temp->next;
          curr->data=temp->data;
          
          delete temp;
      }
  };