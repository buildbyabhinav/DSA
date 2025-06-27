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

Node* reverseLL(Node *head)
{
    Node *prev = nullptr; // Previous node
    Node *temp = head; // Current node

    while (temp != nullptr) // Traverse the list
    {
        Node* nextToTemp = temp->next; // Store the next node
        temp->next = prev; // Reverse the link
        prev = temp; // Move prev to current
        temp = nextToTemp; // Move current to next
    }
    return prev; // New head of the reversed list
}

int main(){
    vector<int> v= {1,2,3,4,5};
    Node* head= convertArrayToLL(v);
}