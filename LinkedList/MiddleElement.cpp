#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};
Node* convertArrayToLL(vector<int> &v)
{
    Node *head = new Node(v[0], nullptr);
    Node *mover = head;
    for (int i = 1; i < v.size(); i++) // Start from the second element otherwise it will use first element as next
    {
        Node *temp = new Node(v[i], nullptr);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* middleElement(Node *head)
{
    if (head == nullptr) // If the list is empty
        return nullptr;

    Node *slow = head; // Slow pointer
    Node *fast = head; // Fast pointer

    while (fast != nullptr && fast->next != nullptr) // Traverse the list
    {
        slow = slow->next; // Move slow by one step
        fast = fast->next->next; // Move fast by two steps
    }

    return slow; // Slow will be at the middle element when fast reaches the end
}



int main(){
    vector<int> v= {1,2,3,4,5};
    Node* head = convertArrayToLL(v);
}