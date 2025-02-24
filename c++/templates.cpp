#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
class book
{
    public:

    string title;
    string author;
    int isbn;
    float price;
    int quantity;

    void getinfo()
    {
        cout<<"enter title:";
        cin>>title;
        cout<<"enter author:";
        cin>>author;
        cout<<"enter price:";
        cin>>price;
        cout<<"enter quantity:";
        cin>>quantity;
    }
};

int main()
{
    int i=0;
    int isbn,response;
    book *ptr;
    ptr=new book[5];
    map<int,book&> m;

  vapas:
  system("CLS");
   cout<<"Enter 1 to add a new book:"<<endl;
   cout<<"enter 0 to delete a book:"<<endl;
   cout<<"enter 2 to update details:"<<endl;
   cout<<"enter 3 to display all books:"<<endl;
   cin>>response;
    if(response==1)
   {
    for(int i=0;i<5;i++)
   {
    cout<<"enter isbn:";
    cin>>isbn;
    ptr[i].getinfo();
    ptr[i].isbn=isbn;
    m.insert(pair<int,book&>(isbn,ptr[i]));
    i++;
        cout<<"5 to go back to screen"<<endl;
        cin>>response;
          if(response==5) 
          {
            goto vapas;
          }
   }
   }  
    if(response==0)
    {
        int count=0;
        cout<<"enter isbn:";
        cin>>isbn;
         for(map<int,book&>::iterator it=m.begin();it!=m.end();it++)
         {
            if(isbn==it->first)
            {
                m.erase(isbn);
                cout<<"book succefully deleted.";
            }
             else 
              count++;
         }
         if(count!=0)
         {
            cout<<"book does not exist";
         }
          cout<<"5 to go back to screen"<<endl;
        cin>>response;
          if(response==5) 
          {
            goto vapas;
          }
    }
    if(response==2)

    {
        cout<<"enter isbn";
        cin>>isbn;
        m.erase(isbn);
        ptr->getinfo();
        ptr->isbn=isbn;
         cout<<"5 to go back to screen"<<endl;
        cin>>response;
          if(response==5) 
          {
            goto vapas;
          }
    }
    if(response==3)
    {
        for(int i=0;i<(m.size()-1);i++)
        {
            cout<<"title:";
            cout<<ptr[i].title<<endl;
            cout<<"Author:";
            cout<<ptr[i].author<<endl;
            cout<<"ISBN:";
            cout<<ptr[i].isbn<<endl;
            cout<<"Price:";
            cout<<ptr[i].price<<endl;
            cout<<"Quantity:";
            cout<<ptr[i].quantity<<endl;
        }
        cout<<endl;
         cout<<"5 to go back to screen"<<endl;
        cin>>response;
          if(response==5) 
          {
            goto vapas;
          }
    }

    return 0;
}



