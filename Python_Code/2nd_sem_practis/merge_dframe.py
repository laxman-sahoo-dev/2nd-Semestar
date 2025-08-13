import pandas as pd

df1 = pd.DataFrame({
    'ID': [1, 2, 3],
    'Name': ['Alice', 'Bob', 'Charlie']
})

df2 = pd.DataFrame({
    'ID': [2, 3, 4],
    'Score': [90, 85, 88]
})

result = pd.merge(df1, df2, on='ID', how='left')
#result=pd.concat([df1, df2], axis=1)
print(result)

import pandas as pd

df1 = pd.DataFrame({'A': [1, 2, 3]})
df2 = pd.DataFrame({'B': ['x', 'y', 'z']})

# Concatenate along columns (axis=1)
result = pd.concat([df1, df2], axis=1)
#result = df1.merge(df2,how='cross')
print(result)
