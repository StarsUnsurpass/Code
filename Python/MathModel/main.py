"""x = 1
print(type(x))"""

"""y = 1.1
print(type(y))"""

"""c=[99, 2, 3, 5, 6]
print(c[0])
print(list(c))
print(c)
print(type(c))"""

"""print(isinstance(2, int))
print(isinstance('HwlloWorld', str))"""

"""a = 3 + 4j
b = 5 + 6j
c = a + b
print(c.real)
print(c.imag)
print(a.conjugate())
print(a * b)
print(a / b)"""

"""a = 'abc' + '123'
print(a)
x = '123''abc'
print(x)"""

#print('Hello\nWorld')
#print('\106')
#print('\x46')
#p = r'C\Windows\notepad.exe'
#print(p)

"""x = [1, 2, 'abc']
print(x)
print(list(range((5))))"""

"""a = [2, 2, 2, 5, 5, 5, 8, 8, 'Hello', 'tom', 'tom']
a = list(set(a))
print(a)"""

"""a = {1, 4, 5, 7, 2}
b = {4, 6, 7, 3, 5}"""
"""a = [1, 4, 5, 7, 2]
b = [4, 6, 7, 3, 5]"""
"""a = (1, 4, 5, 7, 2)
b = (4, 6, 7, 3, 5)"""
"""print(a ^ b)
print(a - b)
print(a & b)
print(a | b)"""

"""def remove_duplicates(n):
    x =[]
    for i in n:
        if i not in x:
            x.append(i)
    return x

import timeit
print(timeit.timeit('remove_duplicates([1, 2, 3, 1, 7])', globals=globals(),number=10000))
print(timeit.timeit('list(set([1, 2, 3, 1, 7]))', number=10000))"""

"""dict = {}
dict['one'] = "1 - 一"
dict[2] = "2 - 二"
tinydict = {0 : 'runoob', 'code' : 1, 'site' : 'www.runoob.com'}
print(dict['one'])
print(dict[2])
print(tinydict)
print(tinydict.keys())
print(tinydict.values())
"""

"""fruits = ['apple', 'pear', 'peach']
for fruit in fruits:
    print('当前水果：', fruit)
for i in range(3):
    print('当前水果：', fruits[i])"""

"""for letter in 'Python':
    print('当前字母：', letter)"""

"""for i in range(1, 10):
    for j in range(1, i + 1):
        print('{0}*{1}={2}'.format(i, j, i * j), end = ' ')
    print(' ')"""

"""rows = 4
i = j = k = 1
print("等腰直角三角形1")
for i in range(0, rows):
    for k in range(0, rows - i):
        print(' * ', end = '')
        k += 1
    i += 1"""
#    print("\n")

"""a = (2, 3, 4, 5, 6, 7, 8, 9, 10)
b = []
for i, element in enumerate(a):
    if i % 2 == 1 and element > 5:
        b.append(element)
b = tuple(b)
print(b)"""

import numpy as np
"""a = np.array([1, 2, 3])
print(type(a))
b = np.array(range(10))
print(b)
c = list(range(10))
print(c)
d = np.arange(10)
print(d)
d1 = np.arange(5, 10, 2)"""

"""a = np.array([2, 5, 8])
print(type(a))
print(a)
print(a.dtype)
b = [2, 5, 8.2]
a = np.array(b)
print(a.dtype)
a = np.array([2, 5, 8.2, 2 + 3j])
print(a.dtype)
a = np.array([2, 3.5, 2 + 3j, 'hellp'])
print(a.dtype)
print(a[0])
print(type(a[1]))
a = np.array([2, 3.5, 2 + 3j, 'hellp'], dtype = object)
print(a.dtype)
print(a[0])
print(type(a[0]))"""

#print(np.random.randn(10))
"""a = np.random.randn(300)
print(a)
print(np.mean(a))
print(np.var(a))"""

"""a = np.random.randint(0, 100, 5)
print(a)
b = np.random.rand(10)
print(b)"""

"""c = (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
     13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23)
d = c.reshape(8, 3)
print(d)
"""

"""from numpy.random import randn
names = np.array(['Bob', 'Joe', 'Jhon', 'Will', 'Bob', 'Joe', 'Joe'], dtype='<U4')
data = randn(7, 4)
print(names)
print(data)
print(data[names=='Bob',:])
print(data[(names=='Bob') | (names=='Joe'), :])"""

"""mat1 = [[1, 2, 3], [4, 5, 6]]
a = np.mat(mat1)
print(type(a))
mat2 = np.mat([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
print(mat1 * mat2)
print(a * mat2)"""

"""a1 = [1, 2, 3]
a2 = np.mat(np.diag(a1))
print(np.diag(a1))
print(type(np.diag(a1)))
print(a2)
print(type(a2))"""

"""a = [[0, 1, 2, 3],
     [4, 5, 6, 7],
     [8, 9, 10, 11],
     [12, 13, 14, 15]]
b = np.diag(a)
c = np.diag(b)
print(c)"""

import time
import math

"""x = [i * 0.001 for i in range(1000000)]
start = time.perf_counter()
for i, t in enumerate(x):
     x[i] = math.sin(t)
print("math.sin:", time.perf_counter() - start)
x = [i * 0.001 for i in range(1000000)]
x = np.array(x)
start = time.perf_counter()
np.sin(x,x)
print("numpy.sin:", time.perf_counter() - start)

x = [i * 0.001 for i in range(1000000)]
start = time.perf_counter()
for i, t in enumerate(x):
     x[i] = np.sin(t)
print("numpy.sin loop:", time.perf_counter() - start)"""

"""x = np.linspace(0, 2, 1000)
def triangle_func(c, c0, hc):
    def trifunc(x):
        x = x - int(x)
        if x >= c: r = 0.0
        elif x < c0: r = x / c0 * hc
        else: r = (c-x) / (c-c0) * hc
        return r
    return np.frompyfunc(trifunc, 1, 1)

y2 = triangle_func(0.6, 0.4, 1.0)(x)
print(y2)
print(y2.astype(np.float64))"""

"""arr1 = np.array([[0, 0, 0],[1, 1, 1],[2, 2, 2], [3, 3, 3]])
arr2 = np.array([[1,1],[2,1],[3,1],[4,1]])
arr1 + arr2

arr1 = np.array([[0, 0, 0],[1, 1, 1],[2, 2, 2], [3, 3, 3]])
arr2 = np.array([[1],[2],[3],[4],[4]])
arr1 + arr2

arr1 = np.array([[0, 0, 0],[1, 1, 1],[2, 2, 2], [3, 3, 3]])
arr2 = np.array([1,1])
arr1 + arr2

arr1 = np.array([[0, 0, 0],[1, 1, 1],[2, 2, 2], [3, 3, 3]])
arr2 = np.array([1])
arr1 + arr2"""


"""c,v = np.loadtxt(r"F:/MyDoc/学校相关文件/大三上/程序设计与数据分析/stock.csv", delimiter = ',', usecols = (3,6), skiprows = 1, unpack = True, comments = '#')
c = np.loadtxt(r"F:/MyDoc/学校相关文件/大三上/程序设计与数据分析/stock.csv", delimiter = ',', usecols = (3, 6), skiprows = 1, unpack = True, comments = '#')
print(c.shape)"""

"""mean = np.mean(c)
vwap = np.average(c, weights = v)
print(vwap)"""

"""c = np.arange(1, 4)
d = np.arange(3, 0, -1)
print(np.average(c, weights = d))
print(np.average(c))

t = np.arange(len(c))
twap = np.average(c, weights = t)
print(twap)"""

"""c = np.loadtxt(r"F:/MyDoc/学校相关文件/大三上/程序设计与数据分析/stock.csv", delimiter = ',', usecols = (3, ), skiprows = 1, unpack = True, comments = '#')
returns = np.diff(c)/c[:-1]
print(c)
print(c[:-1])
print(np.diff(c))
print(np.diff(c)/c[:-1])"""

import pandas as pd

"""data = {'state': ['Ohio', 'Ohio', 'Ohio', 'Nevada', 'Nevada', 'Nevada'],
        'year': [2000, 2001, 2002, 2001, 2002, 2003],
        'pop': [1.5, 1.7, 3.6, 2.4, 2.9, 3.2]}
df= pd.DataFrame(data)
print(df)"""

"""data = {'state': ['Ohio', 'Ohio', 'Ohio', 'Nevada', 'Nevada', 'Nevada'],
        'year': [2000, 2001, 2002, 2001, 2002, '2003aaa'],
        'pop': [1.5, 1.7, 3.6, 2.4, 2.9, 3.2]}
df= pd.DataFrame(data)
# print(df)
# print(data['year'])

df2 = pd.DataFrame(data, columns = ['year', 'state', 'pop', 'debt'], index = ['one', 'two','three', 'four', 'five', 'six'])
# print(df2)

pop = {'Nevada': {2001: 2.4, 2002: 2.9},'Ohio': {2000: 1.5, 2001: 1.7, 2002: 3.6}}
df3 = pd.DataFrame(pop)
# print(df3)"""

"""a = np.arange(24)
a = a.reshape(4,6)
df = pd.DataFrame(a,columns=['mon','tue','wed','thu','fri','sat'])
print(df)"""

# print(df2.info())

"""df2['debt'] = 2.8
df2['debt'] = [1, 2, 3, 4, 5, 6]

df2['eastern'] = df2.state == 'Ohio'
# print(df2)

del df2['eastern']
# print(df2.columns)

if df.empty == True:
    print(df2.loc[['three', 'four'], ['year', 'state']])
    print(df2.iloc[[2, 3], [0, 1]])

df2.sort_values('pop')
df2.sort_values('pop',ascending=False)
df3=df2.iloc[[0,1,2,3,4,5],[0,2,3]]
df3.sort_values('two',axis=1,ascending=True)
df2.sort_values(['year','pop'])"""

df = pd.read_csv(r"F:\MyDoc\学校相关文件\大三上\程序设计与数据分析\titanic_train.csv", engine = 'python')
# print(df.head())
# print(df['Survived'].mean())

"""print(df[df.Sex == 'female'][df.Survived == 1].groupby('Pclass').count())
print(df[df.Sex == 'female'].groupby('Pclass').mean)"""

import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif'] = ['SimHei']

x1 = np.array([6])
y1 = np.array([4])
plt.scatter(x1,y1)
plt.show()

x2 = np.array([1,9])
y2 = np.array([1,8])
plt.plot(x2,y2)
plt.show()

plt.scatter(x1,y1,color='blue')
plt.plot(x2,y2,color='red',linewidth=3,linestyle='--')
plt.text(5.2, 3, '文字说明',fontdict={'size': 16, 'color': 'b'})
plt.show()




















