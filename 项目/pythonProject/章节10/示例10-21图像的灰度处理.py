import numpy as np
import matplotlib.pyplot as plt
#读取图片
n1=plt.imread('Google-Logo.png')
# Chatgpt代码如果是 RGBA 图片，去掉第四个透明度通道
if n1.shape[2] == 4:
    n1 = n1[:, :, :3]

print(type(n1), n1.shape)  # 检查新的形状，确认是否为 RGB 三通道

# 绢子姐教程print(type(n1),n1) #数组类型 ，三维数组，最高维度表示的是图像的高，次高维度表示图像宽，最低维[R,G,B]颜色
plt.imshow(n1)
#编写一个灰度公式
n2=np.array([0.299,0.587,0.114]) #创建数组
#将n1(RGB)颜色值与数组n2(灰度公式固定值)，进行点乘运算
x=np.dot(n1,n2)
#传入数组，显示灰度
plt.imshow(x,cmap='gray')
#显示图像
plt.show()