#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int n,int index)
{
    int left=2*index+1;
    int right=2*index+2;
    int largest=index;

     if(left<n && arr[left]>arr[largest])
     {
        largest=left;
     }
       if(right<n && arr[right]>arr[largest])
     {
        largest=right;
     }

      if(largest!=index)
      {
        int temp=arr[largest];
        arr[largest]=arr[index];
         arr[index]=temp;
          heapify(arr,n,largest);
      }
      
}
void Buildheap(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
}

void SortHeap(int arr[],int i)
{
  int index=0;
  while(i>=0)
  {
    cout<<arr[index]<<" ";
    arr[index]=arr[i-1]; 
      i--;
      heapify(arr,i,index);
  }
}
int main()
{
int arr[]={10,3,9,5,13,18,14,11,70};
 Buildheap(arr,9);

 /*/ for(int i=0;i<9;i++)
  {
    cout<<arr[i]<<" ";
  }*/ 
   SortHeap(arr,9);


    return 0;
}