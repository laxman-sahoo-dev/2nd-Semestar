import pandas as pd

dataset={
    'name':['abc','xyz','pqr'],
     'age':[22,24,25],
     'adress':['Bbsr','Ctc','Tlc']
    }

dframe=pd.DataFrame(dataset)
print("Original Data Frame-\n",dframe)
#coloum Selection
name_value=dframe['name']
print("Select name values-\n",name_value)
#how to select more than one column
column=dframe[['name','age']]
print("Multiple coloum values:\n",column)
dframe['country']=['India','China','Africa']
print("New dataframe after adding new colum:\n",dframe)
#add a column reflecting to existing column
dframe['age_new']=dframe['age']+10
print("New data frame after adding a new coloum \n",dframe)
df=dframe[dframe['age']>22]
print("\n\nselect a perticular condition\n\n",df)
#Delete a single column
dframe.drop('adress',axis=1)
print("After deleting data frame: \n",dframe.drop('adress',axis=1))

#Delete multiple coloum
dframe.drop(['age','country'],axis=1 ,inplace=True)
print("After deleting multiple column-\n",dframe)
print(dframe.isnull())