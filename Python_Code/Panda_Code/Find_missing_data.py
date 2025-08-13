import pandas as pd
data={
    'name':['abc','pqr',None],
    'age':[20,30,40],
    'year':['first','second',None]
}
dframe=pd.DataFrame(data)
print(dframe.isnull())
#print(dframe.isnull().sum())