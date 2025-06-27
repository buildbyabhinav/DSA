#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *convertArray2dLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

int main()
{
    vector<int> arr = {2, 3, 4, 5};
    Node *y = new Node(arr[0], nullptr, nullptr);
    cout << y << endl;
    cout << y->data << endl;
    cout << y->next << endl;

    Node *head = convertArray2dLL(arr);
    cout<<head<<endl;
    cout<<head->data<<endl;
    cout<<head->next<<endl;
    cout<<head->back<<endl;
}