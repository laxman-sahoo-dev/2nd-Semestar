import pandas as pd

# Creating a simple DataFrame
data = {
    'Name': ['Alice', 'Bob', 'Charlie'],
    'Age': [25, 30, 35],
    'City': ['New York', 'Los Angeles', 'Chicago']
}

df = pd.DataFrame(data)

print(df)
print("Shape:", df.shape)
print("Columns:", df.columns)
print("Index:", df.index)
print("Data Types:\n", df.dtypes)
print("Values:\n", df.values)
df.info()
