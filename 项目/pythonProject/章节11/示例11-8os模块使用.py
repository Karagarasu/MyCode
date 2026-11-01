import os
print('当前工作路径',os.getcwd())
lst=os.listdir()
print('当前路径下的所有目录及文件',lst)
print('指定路径下的所有目录及文件',os.listdir('D:/pycharm/项目/pythonProject'))
#创建目录
#os.mkdir('好好学习') 如果要创建的文件夹存在则报错FileExistsError
#os.makedirs('./aa/bb/cc')
#删除目录
#os.rmdir('./好好学习') #./表示当前路径 如果要删除的目录不存在报错FileNotFoundError
#os.removedirs('./aa/bb/cc') 删除多个
#改变当前工作路径
os.chdir('D:/pycharm/项目')
print('当前工作路径',os.getcwd()) #再写代码，工作路径是D:/pycharm/项目
#遍历目录树 ，相当于递归操作
for dirs,dirlst,filelst in os.walk('D:/pycharm/项目/pythonProject'):
    print(dirs)
    print(dirlst)
    print(filelst)
    print('-'*10)



