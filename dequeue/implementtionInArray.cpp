// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Deque{
    int front, rear, size;
    int *arr;
    public:
    Deque(int n){
        size=n;
        arr = new int[n];
        front=rear=-1;
    }
    
    bool isEmpty(){
        return front==-1;
    }
    
    bool isFull(){
        return (rear+1)%size==front;
    }
    
    void push_front(int x){
        if(isEmpty()){
            front=rear=0;
            arr[front]=x;
            cout<<x<<" is pushed at front!\n";
            return;
        }
        else if(isFull()){
            cout<<"Deque is full!\n";
            return;
        }
        else{
            front = (front-1+size)%size;
            arr[front]=x;
            cout<<x<<" is pushed at front!\n";
            return;
        }
    }
    void push_back(int x){
        if(isEmpty()){
            front=rear=0;
            arr[front]=x;
            cout<<x<<" is pushed at back!\n";
            return;
        }
        else if(isFull()){
            cout<<"Deque is full!\n";
            return;
        }
        else{
            rear = (rear+1)%size;
            arr[rear]=x;
            cout<<x<<" is pushed at back!\n";
            return;
        }
        
    }
    void pop_front(){
        if(isEmpty()){
            cout<<"Deque UnderFlow!\n";
            return;
        }
        else{
            front = (front+1)%size;
            cout<<"Poped from front!\n";
            return;
        }
    }
    void pop_back(){
        if(isEmpty()){
            cout<<"Deque UnderFlow!\n";
            return;
        }
        else{
            rear = (rear-1+size)%size;
            cout<<"Poped from back!\n";
            return;
        }
    }
    
    int getFront(){
        if(isEmpty()){
            cout<<"Deque UnderFlow!\n";
            return -1;
        }
        else{
            cout<<"Data at front: "<<arr[front]<<endl;
            return 0;
        }
    }
    int getBack(){
        if(isEmpty()){
            cout<<"Deque UnderFlow!\n";
            return-1;
        }
        else{
            cout<<"Data at back: "<<arr[rear]<<endl;
            return 0;
        }
        
    }
    
};
int main() {
    
    Deque d(5);
    d.push_front(2);
    d.push_back(5);
    d.getFront();
    d.getBack();
    
    return 0;
}