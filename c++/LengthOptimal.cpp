#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#define NULL __null
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node(int D)
    {
        data=D;
        next=NULL;
    }
    Node(){}

};
 Node* insert(Node *head,int value)
 {
    Node* temp=new Node(value);
    temp->next=head;
    cout<<temp->data<<" ";
    return temp;
 }
 
 void insertBack(Node *a,int value)
 {
     Node *temp=new Node(value);
     a->next=temp;
 }
 void print(Node *head)
 {
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
 }

 int main()
 {
    Node *head=new Node(5);
     for(int i=0;i<6;i++)
     {
        head=insert(head,i+1);
     }

     Node *temp=head;
     Node *temp2=head;
      while(temp!=NULL && temp->next!=NULL)
      {
        temp2=temp2->next;
        temp=temp->next->next;
      }
       cout<<temp2->data;

    return 0;
 }