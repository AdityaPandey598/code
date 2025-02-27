import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

gas=pd.read_csv('gas_prices.csv')
plt.figure(figsize=(8,5),dpi=150)
plt.title("Gas Prices over time")
#plt.plot(gas.Year,gas.USA,'y.-',label='United States')
#plt.plot(gas.Year,gas.Canada,'b.-',label="Canada")
#plt.plot(gas.Year,gas['South Korea'],'r.-',label="South Korea")
for country in gas:
    if country!='Year':
        plt.plot(gas.Year,gas[country],'.-')

plt.xticks(gas.Year[::3])
plt.xlabel('Years')
plt.ylabel('Prices')


plt.show()
