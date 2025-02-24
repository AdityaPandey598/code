#include <bits/stdc++.h>
using namespace std;

int main()
{

int arr[]={13,46,24,52,20,9};

for(int i=0;i<6;i++)
{
    for(int j=0;j<6;j++)
    {
        if(arr[j]>=arr[j+1])
        {
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}

for(int i=0;i<6;i++)
{
    cout<<arr[i]<<" ";
}


    return 0;
}


