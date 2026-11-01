import os
#删除文件
#os.remove('./a.txt') #如果要删除的文件不存在报错FileNotFoundError
#重命名
#os.rename('./aa.txt','newaa.txt')

#转换时间格式
import time
def date_format(longtime):
    s=time.strftime("%Y-%m-%d %H:%M:%S",time.localtime(longtime))
    return s
#获取文件信息
info=os.stat('./newaa.txt')
print(type(info))
print(info)
print('最近一次访问时间:',date_format(info.st_atime))
print('在Windows操作系统中显示的文件的创建时间：',date_format(info.st_ctime))
print('最后一次修改时间:',date_format(info.st_mtime))
print('文件的大小（单位是字节）：',info.st_size)

#启动路径下文件
#os.startfile('calc.exe')
#启动python解释器
os.startfile(r'D:\python\python.exe')

