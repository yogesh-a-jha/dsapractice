
//Implementaton of Circular Queue
#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front, rear, size;

public:
    Queue(int n) {
        arr = new int[n];
        size = n;
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear+1)%size == front;
    }

    void push(int x) {
        if (isEmpty()) {
            front = rear = 0;
            arr[0] = x;
            cout << "Pushed " << x << " into the Queue!" << endl;
        }
        else if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        else {
            rear=(rear+1)%size;
            arr[rear] = x;
            cout << "Pushed " << x << " into the Queue!" << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        else {
            cout << "Popped " << arr[front] << " from the Queue!" << endl;
            if (front == rear) {
                front = rear = -1;
            } else {
                front=(front+1)%size;
            }
        }
    }

    int start() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        else {
            return arr[front];
        }
    }
};

int main() {
    Queue q(5);   // ✅ Correct way

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.start() << endl;

    q.pop();
    q.pop();

    return 0;
}
