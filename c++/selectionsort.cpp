#include<iostream>
using namespace std;


int main()
{
    int arr[]={7,5,9,2,8};
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            if(arr[j]<=arr[i])
            {
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
            
    }
    for(int i=0;i<5;i++)
    {
        cout<<arr[i];
    }


    return 0;
}