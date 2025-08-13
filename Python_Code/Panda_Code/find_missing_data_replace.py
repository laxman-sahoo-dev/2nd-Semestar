import pandas as pd
data={
    'name':['abc',None,'pqr'],
    'age':[20,None,900],
    'year':['first','second',None]
}
df=pd.DataFrame(data)
print(df)
print(df.isnull())
print(df.isnull().sum())
data_new=df.fillna({'name':'jkl','age':df['age'].sum(),'year':'ninth'})
#data_new=df.fillna({'name':'jkl','age':88,'year':'ninth'})
print("Updated dataframe-\n",data_new)