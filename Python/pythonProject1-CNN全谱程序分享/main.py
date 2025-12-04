import torch
import numpy as np            #as就是取别名，因为之前的名字的那个库太长了，不能每次都打很长的，就简简单单的，取两个字母的缩写
import pandas as pd               #numpy和pandas都是一个小工具，用来转换的，不是运算的
from torch import nn       #这个是最重要的torch和nn，我们用torch多，用nn也多5
from sklearn.metrics import r2_score
from torch.utils.data import DataLoader
from sklearn.metrics import mean_squared_error
from sklearn.model_selection import train_test_split
import datetime
import os
import matplotlib.pyplot as plt


print('代码分享在github上，如下')
print('https://github.com/qinshiqisky/1DCNN_for_NIR')
print('数据集不公开呢，需要自己的数据更替上去')
folder_path = 'saved_files'
# 如果文件夹不存在，则创建它
if not os.path.exists(folder_path):
    os.makedirs(folder_path)


def dddraw(a,b):
    b = b.transpose()                         #重新进行画图，需要转置反射率
    plt.figure()
    plt.plot(a, b, linewidth=1)      #1的格式是(228,) （变为.values） 2的格式是[228 rows x 310 columns]  这样对应上的，228是横轴长度，都放到最前面了
    plt.xlabel('spectrum/nm')                        #1的格式也可以是(228,)   未变为.values
    plt.ylabel('reflectivity')
    plt.pause(10)                     #为方便展示，设定10秒，后续可设定为1s
    plt.close()


num_epochs = 30              #每次训练要经历多少轮？每轮会得出一个新的loss值，一般要在3000+,50为快速调试程序所设定值，一个epoch就是把所有样本遍历一次的概念
batch_size =32                  # 这个会影响迭代速度，设置为1会慢很多，设置为5是之前的标准，设置为10进一步加速了，而且机器应该顶得住，但是设置为30的时候，7000次迭代只有0.48的r方
                                    #探索各种超参数，可以把这里的数值改为动态的变量并且输入 然后在循环中不停地探索最佳的参数



now = datetime.datetime.now()
formatted_time = now.strftime("%m-%d_%H-%M") #在这里记录好此次训练的起始时间，之后用这个时间值来保存最优模型，即模型中途更新了很多次，每次都用这个名称重新写入新的值，不过最优参数一直在改，最后结束时输出的最后一次是这个的，也是最优值，这样一次执行，就会出一个最优结果
print('微信交流什么的，QSKKK18031937628，加我的时候备注一下近红外之类的')

def load_array(data_arrays, batch_size, is_train=True):  #简单理解就是不用管它，不了解这个也不影响使用代码，在这里只是定义这个函数
    """构造一个PyTorch数据迭代器"""   #就是定义一个类，然后有几个参数
    dataset = torch.utils.data.TensorDataset(*data_arrays)
    #实质上是为了用tensordataset的函数//括号内内容为 x和y的数据存放位置，用的是指针的方式读取的
    #TensorDataset 可以用来对 tensor 进行打包，就好像 python 中的 zip 功能。该类通过每一个 tensor 的第一个维度进行索引。
    #这里传入了训练数据X_train和标签Y_train以及一个batch_size参数，用于指定每个小批量的样本数量。
    #简单理解，就是将x和y的数据长量化后进行放置，方便后面运算，并存入 dataset变量中
    # 函数功能就是 传入输入数据，生成中间级，然后把数据传给下一级，下一级会方便运算。
    # 在其他地方没有调用这个了，这个就是唯一调用的位置，但很重要，它将很重要的参数拿到手了，如输入的x和y，组的大小，是否训练（是否训练与否在于程序会进行判断）
    # 最后返回的是这个函数，但是函数会进行执行，最后得到的是什么呢
    print(DataLoader(dataset, batch_size, shuffle=is_train))
    print("****************************************************************")
    return DataLoader(dataset, batch_size, shuffle=is_train)     #返回的就是是传过去的数据集的加载器，是数据集的加载器 ，加载器是什么下次再说


if __name__ == '__main__':

    file_path = '全氮600份，集成光谱仪，标准格式2024.3.17.xlsx'


    data = pd.read_excel(file_path,header=None)#加载反射率，加载标签值，加载光谱波长

    spectrum = data.iloc[0, 1:]             #第0行，且从第1到最后一列              右上区
    reflectivity = data.iloc[1:, 1:]        #第一行到最后一行，第一列到最后一列     右下区
    target = data.iloc[1:, 0]               #第一行到最后一行，第0列             左下区

    print('打印光谱波长')
    print(spectrum)
    print(spectrum.shape)

    print("打印光谱反射率")
    reflectivity = round(reflectivity, 4)
    print(reflectivity)
    reflectivity = reflectivity.values  # 统一转化为np格式，用于化为tensor
    print(reflectivity)

    print("生成光谱曲线")
    a = spectrum
    b = reflectivity.transpose()  # 重新进行画图，需要转置反射率
    plt.figure()
    plt.plot(a, b, linewidth=1)  # 1的格式是(228,) （变为.values） 2的格式是[228 rows x 310 columns]  这样对应上的，228是横轴长度，都放到最前面了
    plt.xlabel('spectrum/nm')  # 1的格式也可以是(228,)   未变为.values
    plt.ylabel('reflectivity')
    plt.pause(3)  # 延时6s后继续执行下面的程序  ，用draw函数，就必须配这一行，这一行执行才会出那个图
    plt.close()

    print("打印全氮含量")
    print(target)
    target = target.values # 统一转化为np格式，用于化为tensor
    target = target.astype(np.float32)
    print(target)

    plt.scatter(range(len(target)), target,s=3)  #生成一下标签分布图
    plt.title("Data Visualization")
    plt.xlabel("Index")
    plt.ylabel("Value")
    plt.pause(3)                     #为方便展示，设定10秒，后续可设定为1s
    plt.close()

    print("下面进行数据集划分，8:2的比例设置")
    X_train, X_test, Y_train, Y_test = train_test_split(reflectivity, target, test_size=0.2, random_state=42 )
    print("划分完毕")

    print('下面是X_train格式')
    print(X_train)
    print('下面是X_test格式')
    print(X_test)
    print('下面是Y_train格式')
    print(Y_train)
    print('下面是Y_test格式')
    print(Y_test)

    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    print('如果输出为 cuda，说明你正在使用 GPU')
    print(device)  # 如果输出为 'cuda'，说明你正在使用 GPU
    # 以下为改成张量格原来不是深度学习的格式，式，经过操作之后改为深度学习格式。
    X_train = torch.tensor(X_train, dtype=torch.float32).to("cuda")
    X_test = torch.tensor(X_test, dtype=torch.float32).to("cuda")
    Y_train = torch.tensor(Y_train, dtype=torch.float32).to("cuda")
    Y_test = torch.tensor(Y_test, dtype=torch.float32).to("cuda")
    print('经过torch.tensor操作变成了tensor的模式,用法为torch.tensor（目标变量，torch类型）')
    print("已经进行了两个数据（x系列的）的转换tensor模式，原模式不是tensor格式，无法使用。")
    print("y系列为单值，需要转换tensor格式，不转换会报错：AttributeError: 'numpy.ndarray' object has no attribute 'to'，这里没问题，会在后面报错")
    print("\n\n\n\n")

    print("以下为X_train格式输出，它代表的是训练集的反射率，输出前缀有tensor。tensor里面括号里面包含的就是一组一组的单个的值")
    print(X_train)
    a=X_train.shape[0]    #tongj统计个数用的  shape0 代表统计的是行数
    print('训练集样本数量为：')
    print(a)

    print("以下为X_test格式输出，它代表的是验证集的反射率，输出前缀有tensor、")
    print(X_test)
    b = X_test.shape[0]
    print('测试集样本数量为：')
    print(b)


    print("以下为Y_train格式输出，它代表的是训练集的全氮含量，是要和神经网络的输出做差值进行损失函数联系的，输出前缀应该有tensor、")
    print(Y_train)   #这里的tensor是连在一起的，不能用于训练，要进行分开
    print("\n\n")

    print("以下为Y_test格式输出，它是我们土壤全氮的真实值，要和y_pre这个预测值进行比较，和y—train一样，是tensor里的单个值")
    print(Y_test)
    print("\n\n")


    Y_train = Y_train.reshape(a, 1) #调整为单个的值，而非一序列值
    print(Y_train)
    Y_test  =  Y_test.reshape(b, 1)#，当然，也可以用-1代替b，-1即自己计算出的结果  分别输出了 可以看看结果的
    print(Y_test)


    print('数据加载的工作已经彻底完成，接下来对网络进行声明')

    net = nn.Sequential(#nn是一个功能，是被引入的，都叫nn，然后nn的序列参数功能：.Sequential启动
        nn.Conv1d(1,16, 13, stride=2),
        nn.BatchNorm1d(16),
        nn.ReLU(),
        nn.Conv1d(16, 32, 11, stride=2),
        nn.BatchNorm1d(32),
        nn.ReLU(),
        nn.MaxPool1d(2, stride=1),

        nn.Conv1d(32, 64,9, stride=1),
        nn.BatchNorm1d(64),
        nn.ReLU(),
        nn.Conv1d(64, 64,7, stride=2),
        nn.BatchNorm1d(64),
        nn.ReLU(),
        nn.MaxPool1d(2, stride=1),

        nn.Conv1d(64, 128, 5, stride=1),
        nn.BatchNorm1d(128),
        nn.ReLU(),
        nn.Conv1d(128, 256, 3, stride=2),
        nn.BatchNorm1d(256),
        nn.ReLU(),
        nn.MaxPool1d(2, stride=2),

        nn.Flatten(),
        nn.Linear(512, 256),#改动地方  两个矩阵如果出现差异，就改这里，让第二个数和第三个数一致即可，不需要其他操作
        nn.ReLU(),
        nn.Dropout(0.2),   #要加这个，但是具体参数不确定

        nn.Linear(256, 64),
        nn.ReLU(),
        nn.Dropout(0.2),

        nn.Linear(64,32),
        nn.ReLU(),
        nn.Dropout(0.2),
        nn.Linear(32, 1)
    ).to("cuda")      #net编写好了，之后每运行一次迭代次数，都会执行一边net



    #这里依然是定义了一些参数和方式，包括用的什么优化器，优化器的目标是mse的值等等
    loss = nn.MSELoss()  #nn是总功能参数，然后调用了它的mseloss函数进行计算loss值
    trainer = torch.optim.SGD(net.parameters(), lr=0.003)#用sgd梯度下降法来进行调整参数 ，trainer就是 要调整参数的东西吧。
    data_iter = load_array((X_train, Y_train), batch_size, is_train=True)    #定义一个data_iter函数，(z这里不是# ) 该函数接收批量大小、特征矩阵和标签向量作为输入，生成大小为batch_size的小批量
    ee=0                  #定义了一个记录迭代次数的值
    best_loss = 1000     #随意设定的一个比较大的值


    #这里开始训练，一个epoch就是所有的样本都过一遍
    for epoch in range(num_epochs):
        for X_, y_ in data_iter:
            X_ = X_.unsqueeze(1)
            yy=net(X_)
            l = loss(yy, y_)   #yy是预测，y_是实际
            trainer.zero_grad()
            l.backward()            #反向传播计算得到每个参数的梯度值
            trainer.step()          #梯度下降执行一步参数更新（optimizer.step()
        l = loss(net(X_train.unsqueeze(1)), Y_train)
        print("进行迭代中，", f'epoch的次数为 {epoch + 1}, loss {l:.6f}，最佳loss值为{best_loss:.6f},最佳模型更替在{ee+1}次' )

        if l < best_loss:
            # print('新训练模型损失值更小，需要进行更新')
            best_loss = l
            file_name = f"best_model233333--Temporary_{formatted_time}.pth"
            # torch.save(net.state_dict(), 'best_model233333.pth')  # 保存最佳模型参数，不可用中文，中文报错
            file_path = os.path.join(folder_path, file_name)
            torch.save(net.state_dict(), file_path)#filepath包含了名称以及路径
            print('更新了最佳模型力！')
            ee=epoch   #记录此时迭代次数
            kk=best_loss   #记录此时最小损失值
            kk=float(kk)   #转为浮点数
            kk=round(kk, 4)  #保留4位小数
        else:
            pass
            # print('模型没更新嗷')
        #f'为固定格式，实际为f''，引号中间放入字符串，还有可以用大括号放入变量，转换为字符串，大括号里有l即可，会识别到数值并转化为字符串
        # 后面的:.6f就是转为浮点数且6位的意思，epoch是从0开始的，所以 上面下面的输出要设置为epoch+1次
        # print('循环又进行了一次，共需要进行'+str(num_epochs)+'次,此数值为设定值，'+'目前迭代了'+str(epoch+1)+'次')
        # print("此次循环结束\n\n")



print("训练完毕了，模型已经好了，下面是后续处理")
print("以下是test-y的测试集输出，y-test是真实值，和预测值要进行比较")
print(Y_test)
Y_true = Y_test
Y_true = Y_true.cpu().numpy()     #.numpy的作用就是去tensor,实际上ytest没有用到tensor 上层代码为了统一美观对每个集都做了gpu操作和tensor操作  这两个操作是分开的，可以只做tensor操作，即在cpu‘上训练
print(Y_true)


print('预测值就是在这里进行预测的,.detach的意思就是生成新的tensor，之后又立即进行numpy操作，转换成非tensor值')
Y_pred = net(X_test.unsqueeze(1))    #net网络就是之前的训练网络 ，输入对应的X序列，得到预测的y值
Y_pred = Y_pred.cpu().detach().numpy()   #
print(Y_pred)



print("本次训练结果输出")
y_pred_reshaped = Y_pred.reshape(1, -1)    #这个是重塑为1行多列的格式 zhiq之前的应该是多行一列的形式，不管如何  操作了就ok的
y_true_reshaped = Y_true.reshape(1, -1)    #写-1，那就是自动计算要多少列
print("真值为\n" +      str(np.round(y_true_reshaped, 2)))  #tongyi统一一下小数点位数，用的是np.round
print("预测值为\n" +     str(np.round(y_pred_reshaped, 2)))
print('此程序对应          集成光谱仪')

r2 = r2_score(Y_true, Y_pred)
r2=('%.2f' % r2)
print("R方指标为：", r2)
mse = mean_squared_error(Y_true, Y_pred)
print("MSE  : ", round(mse, 4))
rmse = np.sqrt(mse)
print("RMSE : ", round(rmse, 4))
print('在第',ee,'次时，获取到最佳模型，此次loss值为',kk)


cc=f"model__{formatted_time}__R2={r2}_迭代{num_epochs}次"
new_name = f'{cc}.pth'
newfile_path=os.path.join(folder_path, new_name)
os.rename(file_path, newfile_path)
print(f"模型参数文件已保存为：{new_name}")

tt1=min(Y_true)
tt2=max(Y_true)
plt.clf()    #qingkong  清空之前的记录
plt.scatter(Y_true, Y_pred)#将要绘制散点图
plt.xlim(0.7*tt1,1.1*tt2)   #  =两端高一点 dazhi大致如此 训练集里没有最大值，所以右侧看着有点空，但是最小值肯定有的 因为无梯度的样本太多了
plt.ylim(0.7*tt1,1.1*tt2)
plt.text(0.45*tt2, 0.9*tt2, 'R\u00b2 ='+r2, fontsize=12, ha='center')
x = np.arange(0, 100, 0.1)    #均衡线，就是那条线从哪到哪，从0到10就够用了，不过有机物用的多，可以定为100
y = x
plt.plot(x, y, '-r')        #设为红色线条
plt.xlabel('True Values g/kg')
plt.ylabel('Predictions g/kg')
new_name = f'{cc}.png'
file_path = os.path.join(folder_path,new_name)
plt.savefig(file_path,dpi=300)
print(f"模型R2图文件已保存为：{new_name}")
plt.pause(5)  # 延时6s后继续执行下面的程序  ，用draw函数，就必须配这一行，这一行执行才会出那个图
plt.close()





