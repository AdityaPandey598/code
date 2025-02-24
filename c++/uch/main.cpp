#include<iostream>
#include<stack>
#include<string>
using namespace std;



int main()
{

 stack<string> st;
 stack<string> sp;
 st.push()


for(string c: st)
{
  if(st=="(" || st=="[" || st=="{")
  {
    sp.push[st];
  }
   if(st==")" && sp.top()=="(")
   {
    sp.pop();
   }
    else if(st=="]" && sp.top()=="[")
    {
      sp.pop();
    }
     else if(st=="}" && sp.top()=="{")
     {
      sp.pop();
     }
}
 if(sp.empty())
 {
  cout<<"balanced stack";
 }
  else{
    cout<<"Not balanced";
  }

    return 0;
}
