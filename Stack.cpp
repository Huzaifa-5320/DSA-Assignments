#include<iostream>
#include<string>
#include<cstring>
using namespace std;


//                              *** Stack using Linked List ***
struct Node{
    int data;
    Node *next;
};

struct Stack
{
    Node *top = nullptr;

    void push(int data){
    Node *temp = new Node;
    temp->data=data;
    temp->next=top;
    top=temp;
    }    

    int pop(){
        if(top==nullptr){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        Node *temp = top;
        int result = temp->data;
        top = top->next;
        return result;
    }

    void peek(){
        if(top==nullptr){
            cout <<"Stack is empty" << endl;
            return;
        }
        cout << top->data << endl;
    }

    bool isEmpty(){
        Node* temp = top;
        if(temp==nullptr){
            return true;
        }
        return false;
    } 
};


int main(){
    Stack *top = new Stack;
    top->push(1);
    top->push(2);
    top->push(3);
    top->push(4);
    top->push(5);
    top->push(6);
    top->peek();
    
    top->pop();
    top->pop();
    top->pop();
    top->pop();
    top->pop();
    top->pop();
    top->pop(); // will cause stack underflow as there are no more values to be poped.

    top->peek();
    cout << top->isEmpty() << endl; // will return 1 (true) as stack is empty!

    top->push(1);
    cout << top->isEmpty() << endl; // will return 0 (false) as stack is not empty!

    return 0;
}
