import numpy as np
#basics
a=np.array([1,2,3])
    

b=np.array([[0,1,2,2,4,5],
            [6,7,8,9,10,11]
            ])
#print(b[1,3])
#print(b[:,1])

#print(b[:,1:-1:2])

#initialize different arrays
#%%
import numpy as np
a=np.zeros(5)
print(a)
a=np.ones((5,5))
a[1:4,1:4]=0
a[2,2]=9
#print(a)
a=np.full((2,2),100)
a=np.random.rand(4,2)
a=np.random.randint(7,size=(3,3))
arr=np.array([[1,2,3]])
a=np.repeat(arr,3,axis=0)

#MATHS
a=np.array([1,2,3,4,5])
b=np.array([1,0,1,0,1])

#LINEAR ALGEBRA
a=np.ones((2,3))
b=np.full((3,2),2)
print(np.matmul(a,b))

c=np.identity(3)
print(np.linalg.det(c))  

 


# %%
