import math

def split(arr):
    mid=len(arr)//2
    if len(arr)<=1:
        return arr
    
    if arr[mid-1]==arr[mid]:
        if len(arr[:mid+1])%2!=0:
            return split(arr[:mid+1])
        else:
            return split(arr[mid+1:])
    else:
        if len(arr[:mid])%2!=0:
            return split(arr[:mid])
        else:
         return split(arr[mid:])




arr=[1,3,3,4,4,5,5,7,7,8]
res=split(arr)
print(res)
