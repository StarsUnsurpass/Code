import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score

# df = pd.read_excel('data.xlsx')
 df = pd.read_excel('test.xlsx')

# df1 = pd.read_csv('test_1.csv')
# df2 = pd.read_csv('test_2.csv')
# df3 = pd.read_csv('test_3.csv')
# df4 = pd.read_csv('test_4.csv')
#
# combined_df1 = pd.concat([df1, df2])
# combined_df1.drop_duplicates(inplace=True)
# combined_df1.to_csv('file1.csv', index=False)
#
# combined_df2 = pd.concat([df3, df4])
# combined_df2.drop_duplicates(inplace=True)
# combined_df2.to_csv('file2.csv', index=False)
#
# df = pd.concat([combined_df1, combined_df2])
# combined_df2.drop_duplicates(inplace=True)

X = df.iloc[:, :-1].values
y = df.iloc[:, -1].values

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

clf = DecisionTreeClassifier(random_state=42)

clf.fit(X_train, y_train)

y_pred = clf.predict(X_test)

accuracy = accuracy_score(y_test, y_pred)
print(f'Accuracy: {accuracy}')