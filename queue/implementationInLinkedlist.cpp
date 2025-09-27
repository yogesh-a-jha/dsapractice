//Implementaton of Circular Queue
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int value){
            data=value;
            next=NULL;
        }
};
class Queue {
    Node *front, *rear;

public:
    Queue() {
       front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void push(int x) {
        if (isEmpty()) {
            front = rear = new Node(x);
            cout << "Pushed " << x << " into the Queue!" << endl;
            return;
        }
        else {
            rear->next = new Node(x);
            rear=rear->next;
            cout << "Pushed " << x << " into the Queue!" << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        else {
            cout<<"Popped "<<front->data<<" from the Queue!"<<endl;
            Node *temp = front;
            front=front->next;
            delete temp;
        }
    }

    int start() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        else {
            return front->data;
        }
    }
};

int main() {
    Queue q;   // ✅ Correct way

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.start() << endl;

    q.pop();
    q.pop();

    return 0;
}
