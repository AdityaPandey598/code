#include <bits/stdc++.h>
using namespace std;

bool ternarySearch(int arr[],int target,int start,int end)
{
    int mid=(start+end)/2;
    int p1=mid/2;
    int p2=mid+mid/2;
    if(arr[mid]==target) return true;

    if(target<arr[p1])
    ternarySearch(arr,target,start,p1);

    if(target>arr[p2])
    ternarySearch(arr,target,p2,end);
    
    if(target>arr[p1] && target<arr[p2])
    ternarySearch(arr,target,p1,p2)

    return false;

}

int main()
{
int target=6;
int arr[]={1,2,3,4,5,6,7,8,9};


    return 0;
}