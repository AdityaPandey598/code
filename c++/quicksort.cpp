#include <bits/stdc++.h>
using namespace std;
int partation(int arr[],int low,int high)
{
    int pivot=arr[low];
    int i=low;
    int j=high;

    while(i<j)
    {
        while(arr[i]<=pivot && i<=high-1)
        {
            i++;
        }
         while(arr[i]>pivot && j>=low+1)
         {
            j--;
         }
          if(i<j)
          {
            swap(arr[i],arr[j]);
          }
          swap(arr[low],arr[j]);
          return j;
    }
}
void qs(int arr[],int low,int high)
{
    if(low<high)
    {
        int pIndex=partation(arr,low,high);
        qs(arr,low,pIndex-1);
        qs(arr,pIndex+1,high);

    }

}


int main()
{



    return 0;

} 