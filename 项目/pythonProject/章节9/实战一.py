class Circle:
    def  __init__(self,r):
        self.r=r

    #计算面积的方法
    def  get_area(self):
        #return 3.14*self.r*self.r
        return 3.14*pow(self.r,2)
    #计算周长的方法
    def  get_perimeter(self):
        return 2*3.14*self.r

#创建对象
r=eval(input('请输入半径:'))
c=Circle(r)
#调用方法
area=c.get_area()#调用计算面积的方法
perimeter=c.get_perimeter()#调用计算周长的方法
print('圆的面积为：',area)
print('圆的周长为：',perimeter)