import pandas as pd
dataset={
    'name':['abc','xyz','pqr'],
     'age':[22,37,25],
     'adress':['Bbsr','Ctc','Tlc']
    }
dframe=pd.DataFrame(dataset)
print("Original Dataframe-\n",dframe)

#select a single row label wise
print(dframe.loc[1])

#select a single row positivewise
print(dframe.iloc[0])

#selct multiple rows
print(dframe.loc[[0,2]])

#select row based on condition
print(dframe[dframe['age'] < 30])

#Add a row
dframe.loc[3]=['LMN','34','Puri']
print(dframe)

#Delte a row
dframe.drop(index=0)
print("Delete data with label 0\n",dframe)