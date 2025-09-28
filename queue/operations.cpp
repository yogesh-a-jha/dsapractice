
//print
#include <iostream>
#include<queue>
using namespace std;

int main() {
    queue<int>q;
    
    //insert
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    
    int size = q.size();
    
    while(size--){
        cout<<q.front()<<endl;
        // int x = q.front();
        q.push(q.front());
        q.pop();
    }
    
    
    return 0;
}

//reverse
#include <iostream>
#include<queue>
#include<stack>
using namespace std;

int main() {
    queue<int>q;
    
    //insert
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    
    stack<int>s; //using stack to store the elements 
        
    //reversing
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    //printing after the reversal
    int size = q.size();
    
    while(size--){
        cout<<q.front()<<endl;
        // int x = q.front();
        q.push(q.front());
        q.pop();
    }

    
    
    return 0;
}

