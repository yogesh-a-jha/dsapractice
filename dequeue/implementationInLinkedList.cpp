
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next, *prev;
    
    Node (int value){
        data = value;
        next = prev = NULL;
    }
};

class Dequeue{
    Node *front, *rear;
    
    public:
    Dequeue(){
        front = rear = NULL;
    }
    
    //push front
    void push_front(int x){
        if(front == NULL){
            front = rear = new Node(x);
            cout<<x<<" is pushed at front!\n";
            return;
        }
        else{
            Node *temp = new Node(x);
            temp->next = front;
            front->prev=temp;
            front=temp;;
            cout<<x<<" is pushed at front!\n";
            return;
        }
    }
    //push back
    void push_back(int x){
        if(front == NULL){
            front = rear = new Node(x);
            cout<<x<<" is pushed at back!\n";
            return;
        }
        else{
            Node *temp = new Node(x);
            temp->prev=rear;
            rear->next=temp;
            rear=temp;
            cout<<x<<" is pushed at back!\n";
            return;
        }
        
    }
    //pop front
    void pop_front(){
        if(front == NULL){
            cout<<"Dequeue is underflow!\n";
            return;
        }
        else{
            Node *temp = front;
            cout<<"Poped "<<temp->data<<" from front!\n";
            front=front->next;
            delete temp;
            //front node is there
            if(front){
                front->prev=NULL;
            }
            else{  //front node is null i.e.empty
                rear=NULL;
            }
            
        }
    }
    //pop back
    void pop_back(){
        if(front == NULL){
            cout<<"Dequeue is underflow!";
            return;
        }
        else{
            Node *temp = rear;
            cout<<"Poped "<<temp->data<<" from back!\n";
            rear=rear->prev;
            delete temp;
            //front node is there
            if(rear){
                rear->next=NULL;
            }
            else{  //front node is null i.e.empty
                front=NULL;
            }
            
        }
    }
    //start
    int start(){
        if(front == NULL){
            cout<<"Dequeue is underflow!";
            return -1;
        }
        else{
            return front->data;
        }
    }
    //end
    int end(){
        if(front == NULL){
            cout<<"Dequeue is underflow!";
            return -1;
        }
        else{
            return rear->data;
        }
    }
};

int main() {
    // Write C++ code here
    Dequeue d;
    d.push_back(5);
    d.push_front(8);
    cout<<d.start()<<endl;
    cout<<d.end()<<endl;
    d.pop_back();
    cout<<d.start()<<endl;
    cout<<d.end()<<endl;

    return 0;
}