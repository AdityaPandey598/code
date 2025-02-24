#include<iostream>
using namespace std;
class stck
{
public:
int st[10];
int top=-1;

    void push(int x)
    {
        if(top==9)
        {
            cout<<"stack overflow";
        }
         else
            {
                ++top;
                st[top]=x;   
            }    
    }

    int top()
    {
      if(top==-1)
      {
        return 0;
      }  
       else
        return st[top];
    }

    int pop()
    {
        if(top==-1)
        {
            cout<<"Stack is empty";
        }
         else
         {
            return st[top];
            --top;
         }
    }

};

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
 Node* push(Node *head,int value)
 {
    Node* temp=new Node(value);
    temp->next=head;
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

    Node* pop(Node *head)
    {
        Node *temp=head;
        head=head->next;
        delete temp;
        return head;
    }


 };


int main()
{
 
    
 return 0;
}