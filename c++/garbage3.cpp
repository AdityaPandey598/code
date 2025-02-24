#include <bits/stdc++.h>
using namespace std;


int main()
{
stack<char> st;
string temp;
string input;
cout<<"enter line:";
getline(cin,input);

for(int i=0;i<input.length();i++)
{
    if(input[i]=='(')
    {
        
    }
}
for(int i=0;i,input.length();i++)
{
     if(input[i]=='(')
    {
        while(input[i]!=')')
        {
            cout<<st.top();
            st.pop();
            i++;
        }
    }
    cout<<input[i];   
}


    return 0;

}