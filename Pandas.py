import pandas as pd
df=pd.read_csv('pokemon_data.csv')
#READING DATA

#print(df.head(3))
#print(df[['Name','Type 1','HP']])
#print(df.iloc[-1,1])

#for index,row in df.iterrows():
 #print(index,row['Name'])
 #print('\n')

#print(df.loc[df['Type 1']=="Fire"])
#print(df.describe())
#print(df.sort_values('HP'))

#MANIPULATING DATA
#df['Total']=df['HP']+df['Attack']+df['Defense']
#df['Total']=df.iloc[:,4:10].sum(axis=1)
#cols=list(df.columns.values)
#df=df[[cols[0]]+cols[4:10]+cols[1:4]+cols[11:-1]]
#print(df.head(5))

#SAVING CSV
#df.to_csv('Any_name_of_your-choics.csv')

#FILTERING
#new_df=df.loc[(df['Type 1']=='Grass') | (df['Type 2']=='Posion')]
#new_df.reset_index(drop='T rue')
#print(new_df.loc[~new_df['Name'].str.contains('Mega')])
#print(new_df)  

#CONDITIONAL CHANGES
#df.loc[df['Type 1']=='Fire', 'Type 1']='flamers'
#print(df.loc[df['Type 1']=='Fire']) 
# Ensure the column name 'Type 1' exists
if 'Type 1' not in df.columns:
    raise KeyError("'Type 1' column not found in DataFrame")

# Group by 'Type 1' and calculate mean only for numeric columns
test_df = df.groupby(['Type 1']).apply(lambda x: x.select_dtypes(include=['number']).mean())

print(test_df)


