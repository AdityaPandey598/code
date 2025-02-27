import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

binss=[i for i in range(40,100,10)]
bins2=[i for i  in range(0,10000,750)]
fifa =pd.read_csv('fifa_data.csv')
#plt.hist(fifa.Overall,bins=binss,color='#2596be')
left=fifa.loc[fifa['Preferred Foot']=='Left'].count()[0]
right=fifa.loc[fifa['Preferred Foot']=='Right'].count()[0]
labels=['Left','Right']
colours=['#e28743','#2596be']
plt.pie([left,right],labels=labels,colors=colours,autopct='%.1f ')
fifa.Weight=[int(x.strip('lbs'))  if type(x)==str else x for x in fifa.Weight]
#plt.ylabel("Number of players")
#plt.title("Distribution of players")
#plt.xticks(binss)
#plt.yticks(bins2)
plt.show()