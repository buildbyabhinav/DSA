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

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Node* head = convertArrayToLL(v);

}