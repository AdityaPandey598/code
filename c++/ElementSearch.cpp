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

 void print(Node *head)
 {
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
 }

Node* insert(Node *head,int value)
{
    Node* temp=new Node(value);
    temp->next=head;
    return temp;
}

int main()
{
    int target;
     Node *head=new Node(5);
      

     for(int i=0;i<5;i++)
     {
    head=insert(head,i);
     }

       Node* itr=head;

       print(head);
      cout<<"Enter value:";
       cin>>target;
       while(itr!=NULL)
    {
         if(itr->data==target)
         {
            cout<<itr->data;
         }
         else
         {
            cout<<"Element not found";
         }
         itr=itr->next;
    }

       return 0;
}