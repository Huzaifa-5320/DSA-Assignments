#include<iostream>
#include<string>
#include<cstring>
using namespace std;


//                              *** Stack using Array ***
struct Stack {
    static const int MAX = 100; 
    int arr[MAX];               
    int top = -1;               

   
    void push(int data) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = data; 
    }

  
    int pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--]; 
    }

    
    void peek() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << arr[top] << endl; 
    }

    
    bool isEmpty() {
        return top == -1; 
    }
};

int main(){
    Stack *top = new Stack;
    top->push(1);
    top->push(2);
    top->peek();
    
    top->pop();
    top->pop();
    top->pop(); // will cause stack underflow as there are no more values to be poped.

    top->peek();
    cout << top->isEmpty() << endl; // will return 1 (true) as stack is empty!

    top->push(1);
    cout << top->isEmpty() << endl; // will return 0 (false) as stack is not empty!

    return 0;
}