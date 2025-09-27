
//QUEUE STL
#include <iostream>
#include<queue>
using namespace std;

int main() {
    queue<int>q;
    
    //insert
    q.push(5);
    q.push(6);
    q.push(7);
    
    //delete
    q.pop();
    
    q.push(8);
    
    //front element
    cout<<q.front()<<endl;
    
    //back element
    cout<<q.back()<<endl;
    
    //size
    cout<<q.size()<<endl;
    
    //empty
    cout<<q.empty()<<endl;
    
    
    return 0;
}
