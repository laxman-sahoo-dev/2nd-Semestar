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

#Delete a single column
df=dframe.drop('adress',axis=1)
print("After deleting data frame: \n",df)

#Delete multiple coloum
df=dframe.drop(['adress','country'],axis=1)
print("After deleting multiple column-\n",df)