import pandas as pd

# 读取多个CSV文件
df1 = pd.read_csv('test_1.csv')
df2 = pd.read_csv('test_2.csv')

# 假设两个文件结构相同，进行纵向合并
combined_df = pd.concat([df1, df2])

# 去除重复行
combined_df.drop_duplicates(inplace=True)

# 保存合并后的数据到一个新的CSV文件
combined_df.to_csv('file1.csv', index=False)
