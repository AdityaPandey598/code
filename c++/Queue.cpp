#include<iostream>
using namespace std;
class Node
{
    public:
     int data;
     Node *next;

     Node(int x)
     {
        data=x;
        next=NULL;
     }

};

class Queue
{
    public:
    Node *front;
    Node *back;

    Queue()
    {
        front=back=NULL;
    }

    void enqueue(int x)
    {
        Node *temp=new Node(x);
        if(front==NULL)
        {
            front=back=temp;
        }
         else
         {
            back->next=temp;
            back=temp;
         }

    }

    void dequeue()
    {
        Node *temp=front;
        front=front->next;
        if(front==NULL)
        {
            back=NULL;
        }
        delete temp;
    }
     
    int Front()
    {
        if(front==NULL)
        {
            front=back;
            cout<<"empty queue";
        }
         else
           return front->data;
    }

    int Back()
    {
        if(front==NULL)
        {
            back=front;
            cout<<"empty queue";
        }
         else
           return back->data;
    }


};

 

int main()
{
    Queue q;

    
    q.enqueue(10);
    q.enqueue(20);

   
    cout << "Queue Front: " << q.Front() << endl;
    cout << "Queue Rear: " << q.Back() << endl;

  
    q.dequeue();
    q.dequeue();

  
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    
    q.dequeue();

    
    cout << "Queue Front: " << q.Front() << endl;
    cout << "Queue Rear: " << q.Back() << endl;



    return 0;
}