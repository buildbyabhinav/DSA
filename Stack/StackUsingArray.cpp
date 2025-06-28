#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; } // Constructor to initialize the stack with top at -1 (indicating an empty stack)
    void push(int item); // Function to push an item onto the stack
    int pop(); // Function to pop an item from the stack
    int peek(); // Function to peek at the top item of the stack without removing it
    bool isFull();  // Function to check if the stack is full
    bool isEmpty(); // Function to check if the stack is empty
};

void Stack::push(int item) { //scope resolution is used to define the member function outside the class
    // Check if the stack is full before pushing an item
    if (isFull()) {
        cout << "Stack overflow!" << endl; // If the stack is full, we cannot push a new item
        return;  
    }
    arr[++top] = item;  // Increment top and add the item to the stack
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack underflow!" << endl; // If the stack is empty, we cannot pop an item
        return -1;     
    }
    return arr[top--];
}

int Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl; // If the stack is empty, we cannot peek at the top item
        return -1;
    }
    return arr[top]; // Return the top item without removing it
}

bool Stack::isFull() {
    return top == MAX - 1;  // Check if the stack is full
}

bool Stack::isEmpty() {
    return top == -1;  // Check if the stack is empty
}

int main() {
    Stack stack;
    stack.push(1);   // Push one element onto the stack
    stack.push(2);  // Push two elements onto the stack
    stack.push(3); // Push three elements onto the stack

    cout << "Popped element is " << stack.pop() << endl; // Output: 3
    cout << "Top element is " << stack.peek() << endl;   // Output: 2
    cout << "Is stack empty? " << stack.isEmpty() << endl; // Output: False
    cout << "Is stack full? " << stack.isFull() << endl;   // Output: False

    return 0;
}