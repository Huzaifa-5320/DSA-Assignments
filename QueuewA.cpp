#include<iostream>
using namespace std;

class Queue {
    static const int MAX = 5; // Define maximum size of the Queue
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1; // Initialize front to -1 indicating empty queue
        rear = -1;  // Initialize rear to -1 indicating empty queue
    }

    // Check if the queue is full
    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Enqueue operation
    void enQueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }

        // If queue is empty, set both front and rear to 0
        if (front == -1) {
            front = 0;
            rear =0;
        }

        // Move rear to the next position (circular increment)
        rear = (rear + 1) % MAX;
        arr[rear] = x;
    }

    // Dequeue operation
    int deQueue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }

        int result = arr[front];
        // If there is only one element in the queue, reset front and rear to -1
        if (front == rear) {
            front = rear = -1;
        } else {
            // Move front to the next position (circular increment)
            front = (front + 1) % MAX;
        }
        return result;
    }

    // Peek the front element
    int peek() {
        if (isEmpty()) {
            cout << "No element in Queue" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main() {
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    
    // Attempt to enqueue when the queue is full
    q.enQueue(6); // This should print "Queue Overflow"

    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;

    // Attempt to dequeue from an empty queue
    cout << q.deQueue() << endl; // This should print "Queue Underflow"

    return 0;
}
