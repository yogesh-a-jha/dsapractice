class Solution {
    stack<int>st1;
        stack<int>st2;
  public:

    // Add an element to the top of Stack
    void push(int x) {
        
        // code here
        if(st1.empty()){
            st1.push(x);
            st2.push(x);
        }
        else{
            st1.push(x);
            if(x<=st2.top()){
                st2.push(x);
            }
            else{
                st2.push(st2.top());
            }
        }
    }

    // Remove the top element from the Stack
        
    void pop() {
        // code here
        if(st1.empty()){
            return ;
        }
        else{
            int element = st1.top();
            st1.pop();
            st2.pop();
            return;
        }
    }

        
    // Returns top element of the Stack
    int peek() {
        // code here
        if(st1.empty()){
            return -1;
        }
        return st1.top();
    }
        

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(st2.empty()){
            return -1;
        }
        else{
            return st2.top();
        }
    }
};