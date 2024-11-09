#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;  // Define a maximum size for the stack

struct Stack {
    char arr[MAX_SIZE];  // Array to hold stack elements
    int top = -1;        // Initialize top to -1 (indicates stack is empty)

    // Function to push an element onto the stack
    void push(char data) {
        if (top < MAX_SIZE - 1) {  // Check if stack is not full
            arr[++top] = data;     // Increment top and add element
        }
    }

    // Function to pop an element from the stack
    char pop() {
        if (top >= 0) {            // Check if stack is not empty
            return arr[top--];      // Return top element and decrement top
        }
        return '\0';                // Return null character if stack is empty
    }

    // Function to peek at the top element of the stack
    char peek() const {
        if (top >= 0) {
            return arr[top];
        }
        return '\0';
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }
};

// Function to check if a character is an operator and return its precedence
int isOperator(char a) {
    if (a == '(') {
        return 4;
    } else if (a == ')') {
        return 3;
    } else if (a == '*' || a == '/') {
        return 2;
    } else if (a == '+' || a == '-') {
        return 1;
    }
    return 0;
}

// Function to convert infix expression to postfix
string postFix(const string &infix, Stack &stack) {
    int len = infix.length();
    string postfix;

    for (int i = 0; i < len; i++) {
        int res = isOperator(infix[i]);

        // If character is '(', push it directly to stack
        if (res == 4) {
            stack.push(infix[i]);
        } else if (res == 3) {  // Closing bracket ')'
            while (stack.peek() != '(' && !stack.isEmpty()) {
                postfix += stack.pop();
            }
            stack.pop();  // Remove '(' from the stack
        } else if (res == 0) {
            postfix += infix[i];  // Append operands directly to postfix
        } else {
            // Pop operators with greater or equal precedence
            while (!stack.isEmpty() && res <= isOperator(stack.peek()) && stack.peek() != '(') {
                postfix += stack.pop();
            }
            stack.push(infix[i]);
        }
    }
    // Pop all remaining operators from the stack
    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }
    return postfix;
}

int main() {
    Stack stack;              // Create an array-based stack
    string str = "(a+b)*(c-d)"; // Infix expression
    cout << "POSTFIX STRING: " << postFix(str, stack) << endl;
    return 0;
}
