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

Node* removeTail(Node *head)
{
    if (head == nullptr || head->next == nullptr) // If the list is empty or has only one node
    {
        delete head; // Free the memory of the old head
        return nullptr; // Return null as the new head
    }
    
    Node *temp = head;
    while (temp->next->next != nullptr) // Traverse to the second last node
    {
        temp = temp->next;
    }
    
    delete temp->next; // Free the memory of the last node
    temp->next = nullptr; // Set the next of second last node to null
    return head; // Return the modified list
}

int main(){
    vector<int> v = {1, 2, 3, 4, 5};
}