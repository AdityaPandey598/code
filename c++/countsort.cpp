#include<iostream>
using namespace std;
int max(int arr[],int n)
{
    int max=arr[0];
     for(int i=0;i<n;i++)
     {
        if(arr[i]>=max)
        {
            max=arr[i];
        }
     }
      return max;
}

    void countsort(int arr[],int n)
    {
        int len=max(arr,n);
        int temp[len+1]={0};
        for(int i=0;i<n;i++)
        {
            temp[arr[i]]++;
        }
        cout<<endl;
        int *ptr=arr;

        for(int i=0;i<len+1;i++)
        {
            while(temp[i]>0)
            {
            *ptr=i;
            ptr++;
            temp[i]--;
            }
        }

    }

int main()
{

    int arr[]={9,1,4,14,4,15,6};
    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    countsort(arr,7);

     for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }




    return 0;
}