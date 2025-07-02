#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if(op == '^') return 3; // Exponentiation has the highest precedence
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string expression) {
    stack<char> st; // Stack to hold operators
    string postfix = ""; // Resulting postfix expression

    for(char ch : expression) {
        if(isalnum(ch)) { // If the character is an operand (number or letter)
            postfix += ch; // Add it to the postfix expression
        }
        else if(ch == '(') { // If the character is an opening parenthesis
            st.push(ch); // Push it onto the stack
        }
        else if(ch == ')') { // If the character is a closing parenthesis
            while(!st.empty() && st.top() != '(') { // Pop from stack until an opening parenthesis is found
                postfix += st.top(); // Add the operator to the postfix expression
                st.pop(); // Remove the operator from the stack
            }
            st.pop(); // Pop the opening parenthesis from the stack
        }
        else { // If the character is an operator
            while(!st.empty() && (st.top() == '*' || st.top() == '/' || st.top() == '+' || st.top() == '-') && 
                  (ch == '+' || ch == '-' || ch == '*' || ch == '/')) {
                postfix += st.top(); // Add the operator at the top of the stack to the postfix expression
                st.pop(); // Remove the operator from the stack
            }
            st.push(ch); // Push the current operator onto the stack
        }
    }

    // Pop all remaining operators from the stack and add them to the postfix expression
    while(!st.empty()) {
        postfix += st.top(); // Add the operator at the top of the stack to the postfix expression
        st.pop(); // Remove the operator from the stack
    }
    return postfix; // Return the resulting postfix expression
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;
    string postfix = infixToPostfix(expression);
    cout << "Postfix expression: " << postfix << endl;
    return 0;   
}