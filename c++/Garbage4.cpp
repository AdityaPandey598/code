#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={2,5,5,5,6,6,8,9,9,9};
    int n,target,index1,count=0,index2;
    cin>>target;
    for(int i=0;i<10;i++)
    {
        if(arr[i]==target && arr[i+1]==target && count==0)
        {
            index1=i; 
            count++;
        }
        if(arr[i]==target && arr[i+1]!=target)
        {
            index2=i;
            break;
        }
        
    }
    if(count==0)
        {
            cout<<"Not found";
        }
        else
        {
            cout<<index1<<endl<<index2;
        }



    return 0;
}


