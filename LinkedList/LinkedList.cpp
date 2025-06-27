#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0], nullptr); // initialized head
    Node *mover = head;                     // mover is pointing to head
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]); // given temporary to the next value in linked list
        mover->next = temp;            // pointed mover to that temporary node
        mover = temp;                  // now move on to that temporary i.e. mover is temporary and temporary is the next one
    }
    return head;
}

int lengthOfLL(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int checkIfPresent(Node *head, int val)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == val)
            return 1;
        temp = temp->next;
    }
    return 0;
}

Node *deleteHead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}

Node *deleteK(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next == prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {2, 3, 4, 5};
    Node *y = new Node(arr[0], nullptr);
    cout << y << endl;
    // Node* z = &Node(arr[0], nullptr);
    // cout<<z<<endl;
    cout << y->data << endl;
    Node *head = convertArr2LL(arr);
    cout << head->data << endl;
    cout << head->next << endl;

    // traversing a linked list
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

    int x = lengthOfLL(head);
    cout << x << endl;

    head = deleteHead(head);
    cout << head << endl;
}
