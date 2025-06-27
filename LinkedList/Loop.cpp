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

Node *convertArrayToLL(vector<int> &v)
{
    Node *head = new Node(v[0], nullptr);
    Node *mover = head;
    for (int i = 1; i < v.size(); i++)
    { // Start from the second element
        Node *temp = new Node(v[i], nullptr);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

bool hasCycle(Node *head)
{
    Node *slow = head; // Slow pointer
    Node *fast = head; // Fast pointer

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next; // Move fast pointer two steps

        if (slow == fast)
        { // If they meet, there is a cycle
            return true;
        }
    }
    return false; // No cycle found
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
    Node *head = convertArrayToLL(v);
}