import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

#BASIC GRAPHS
x2=np.arange(0,4,0.5)
 
plt.plot(x2  ,x2**2,label='X^2')
plt.plot([1,2,4,6],[6,7,2,1],'y.--',label='2x')
plt.title("First graph",fontdict={'fontname': 'Comic Sans MS','fontsize':20})
plt.savefig('mygraph.png',dpi=300)
plt.show()

labels=['A','B','C']
values=[1,4,2]
bars=plt.bar(labels,values)
plt.show()