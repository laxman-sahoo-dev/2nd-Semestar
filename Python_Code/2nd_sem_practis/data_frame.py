import pandas as pd
data={
    'name':["hari","gopal"],
    'id':[3,4]
    }
data2=[['abc',34],['pqr',44],['xyz',55]]
df=pd.DataFrame(data)
df1=pd.DataFrame(data2,columns=['student name','roll'])
print(df)
print(df1)
roll_val=df1['roll']
print(roll_val)
