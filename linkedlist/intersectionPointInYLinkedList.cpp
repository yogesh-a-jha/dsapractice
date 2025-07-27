// Linked list Node
/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        Node *h1=head1, *h2=head2;
        int count1=0,count2=0;
        
        while(h1){
            count1++;
            h1=h1->next;
        }
        while(h2){
            count2++;
            h2=h2->next;
        }
        
        int count3=abs(count1-count2);
        h1=head1;
        h2=head2;
        if(count1>count2){
            int i=count3;
            
            while(i--){
                h1=h1->next;
            }
            while(h1!=h2){
                h1=h1->next;
                h2=h2->next;
            }
            
            return h1;
        }
        else{
            int i=count3;
            
            while(i--){
                h2=h2->next;
            }
            while(h1!=h2){
                h1=h1->next;
                h2=h2->next;
            }
            
            return h1;
        }
        
        
    }
};