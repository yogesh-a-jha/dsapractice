// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/
class Solution {
  public:
    struct Node* partition(struct Node* head, int x) {
        // code here
        struct Node *sh=nullptr, *st=nullptr; // smaller
        struct Node *eh=nullptr, *et=nullptr; // equal
        struct Node *gh=nullptr, *gt=nullptr; // greater

        while (head) {
            int val = head->data;
            if (val < x) {
                if (!sh) sh = st = head;
                else {
                    st->next = head;
                    st = st->next;
                }
            } else if (val == x) {
                if (!eh) eh = et = head;
                else {
                    et->next = head;
                    et = et->next;
                }
            } else {
                if (!gh) gh = gt = head;
                else {
                    gt->next = head;
                    gt = gt->next;
                }
            }
            head = head->next;
        }

        // End all lists
        if (gt) gt->next = nullptr;
        if (et) et->next = gh;
        if (st) st->next = eh ? eh : gh;

        if (sh) return sh;
        if (eh) return eh;
        return gh;
         
        
    }
};