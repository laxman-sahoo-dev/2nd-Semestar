import pandas as pd
import numpy as np
dataset={
    'name':['abc','xyz','pqr'],
     'age':[22,24,25],
     'adress':['Bbsr','Ctc','Tlc']
    }
dframe=pd.DataFrame(dataset)
print(dframe)
num_arr=dframe.to_numpy()
print("numpy array values are- \n\n",num_arr)
sr=pd.Series([10,11,22,34])
num_arr=sr.to_numpy()
print("numpy array of series \n",num_arr)