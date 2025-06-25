#include <bits/stdc++.h>
using namespace std;    
struct Node {
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1 = nullptr, Node *back1 = nullptr) {
        data = data1;
        next = next1;
        back = back1;
    }
};