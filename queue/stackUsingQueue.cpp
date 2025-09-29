class myStack {

  public:
     queue<int>q1;
    queue<int>q2;

    int topElement;
    void push(int x) {
        // Inserts an element x at the top of the stack
         topElement = x;
        if(empty()){
            q1.push(x);
        }
        else if(q1.empty()){
            q2.push(x);
        }
        else{
            q1.push(x);
        }
    }

    int pop() {
        // Removes an element from the top of the stack
        if(empty()){
           return -1;
        }
        else if(q1.empty()){
            while(q2.size()>1){
                topElement = q2.front();
                q1.push(q2.front());
                q2.pop();
            }
            int element = q2.front();
            q2.pop();
            return element;
        }
        else{
           while(q1.size()>1){
                topElement = q1.front();
                q2.push(q1.front());
                q1.pop();
            }
            int element = q1.front();
            q1.pop();
            return element;
        }
    }

    int top() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        return empty() ? -1 : topElement;
    }
    
    bool empty() {
        return q1.empty()&&q2.empty();
    }

    int size() {
        // Returns the current size of the stack
        return !q1.empty()?q1.size() : q2.size();
    }
};
