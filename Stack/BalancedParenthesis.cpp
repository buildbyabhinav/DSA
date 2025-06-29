#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)  
{
    int n = s.size(); // Get the size of the string
    if (n % 2 != 0) // If the length of the string is odd, it cannot be valid
        return false;
    stack<char> st; // Create a stack to keep track of opening brackets
    // Iterate through each character in the string
    // If the character is an opening bracket, push it onto the stack
    // If it is a closing bracket, check if it matches the top of the stack
    // If it does not match or the stack is empty when it should not be, return false
    // Finally, check if the stack is empty to ensure all brackets were matched
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')  
        {
            st.push(s[i]);  // Push opening brackets onto the stack
        }
        else
        {
            if (st.empty()) // If the stack is empty and we encounter a closing bracket, it's invalid
                return false;   
            char ch = st.top(); // Get the top element of the stack
            // Pop the top element from the stack
            st.pop();
            if ((s[i] == '}' && ch != '{') || (s[i] == ']' && ch != '[') || (s[i] == ')' && ch != '('))  
            {
                return false; // If the closing bracket does not match the top of the stack, return false
            }
        }
    }
    return st.empty();
}

int main()
{
    string expression;
    cout << "Enter an expression: ";
    cin >> expression; // Read the expression from the user

    if (isValid(expression))
    {
        cout << "The expression is valid." << endl; // Output if the expression is valid
    }
    else
    {
        cout << "The expression is invalid." << endl; // Output if the expression is invalid
    }   
    return 0; // Return 0 to indicate successful execution
}