import numpy as np
import matplotlib.pyplot as plt


x=np.array([1.0,2.0])
y=np.array([300.0,500.0])

m=50
c=100

x_bar=np.zeros([len(x)])
y_bar=np.zeros([len(x)])

for i in range(len(x)):
    y_bar[i]=m*x[i]+c
    x_bar[i]=(y_bar[i]-c)/m

plt.plot(x,y,'y.',label="intital points")
plt.plot(x_bar,y_bar,'r.--',label="Predicted spread")
plt.xlabel("Size")
plt.ylabel("Price")
plt.legend()
plt.show()