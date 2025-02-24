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
    int key,value;
Node *head=new Node(5);

cout<<"Before Insertion:"<<endl;
print(head);
 cout<<endl;
  for(int i=0;i<5;i++)
{
head=insert(head,i);
}

cout<<"After insertion:"<<endl;
   print(head);
     cout<<endl;
    Node* temp=head;

cout<<"Back insertion:"<<endl;
  print(head);
    cout<<endl;
     while(temp!=NULL)
{
   if(temp->next==NULL)
   {
   insertBack(temp,8); 
    temp=temp->next;
    break;
   }
   temp=temp->next;
}
    print(head);
       cout<<endl;

Node* temp2=head;
cout<<"middle insertion:-"<<endl;
  temp=head;
   cout<<"Enter new value:";
     cin>>value;
      cout<<"Enter position:";
       cin>>key;
   while(temp2!=NULL)
{
    int count=1;
    temp2=temp2->next;
    ++count;    
     if(count==key-1)
     {
         Node* newNode=new Node(value);
         newNode->next=temp2->next;
         temp2->next=newNode;
         break;
     }
    


}
print(head);

    return 0;
}