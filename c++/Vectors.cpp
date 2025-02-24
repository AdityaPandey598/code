#include <bits/stdc++.h>
using namespace std;

struct Node 
{

    int data;
    Node* next;
    Node(int new_data)
    {
        data = new_data;
        next = NULL;
    }
};

Node* insert(Node* head, int new_data)
{
    Node* new_node = new Node(new_data);
    new_node->next = head;
    return new_node;
}

int main()
{
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(6);

    int data = 1;
    head = insert(head, data);

    return 0;
}
