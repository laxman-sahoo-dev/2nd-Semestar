import pandas as pd
dataset={
    'name':['abc','xyz','pqr'],
     'age':[22,37,25],
     'adress':['Bbsr','Ctc','Tlc']
    }
dframe=pd.DataFrame(dataset,index=[101,102,103])
print("Original Dataframe-\n",dframe)

#select a single row label wise
print("single row selection using label-\n")
row=dframe.loc[103]
print(row)

#select a single row positivewise
row_p=dframe.iloc[1]
print("Single row selection using position-\n",row_p)

#selct multiple rows
row_mp=dframe.loc[[101,102]]
print("Multile row selection using label-\n",row_mp)
#select row based on condition
print(dframe[dframe['age'] < 30])

#Add a row
print("Add row using position wise - ")
dframe.loc[999]=['LMN',34,'Puri']
print(dframe)

#Delte a row
dframe.drop(index=[101,103] , inplace=True)
print("Delete data with label 0\n",dframe)