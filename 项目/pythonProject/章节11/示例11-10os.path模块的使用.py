import os.path
print('获取目录或文件的绝对路径',os.path.abspath('./b.txt'))
print('判断目录或文件在磁盘上是否存在',os.path.exists('b.txt'))#相对路径 True
print('判断目录或文件在磁盘上是否存在',os.path.exists('newb.txt'))#False
print('判断目录或文件在磁盘上是否存在',os.path.exists('./好好学习'))#False
print('拼接路径',os.path.join('D:/pycharm/项目/pythonProject/章节11','b.txt'))
print('分割文件名和文件后缀名',os.path.splitext('b.txt'))#a]元组类型
print('提取文件名：',os.path.basename(r'D:\pycharm\项目\pythonProject\章节11\b.txt'))#b.txt
print('提取路径',os.path.dirname(r'D:\pycharm\项目\pythonProject\章节11\b.txt'))#D:\pycharm\项目\pythonProject\章节11
print('判断一个路径是否有效',os.path.isdir(r'D:\pycharm\项目\pythonProject\章节11'))#True
print('判断一个路径是否有效',os.path.isdir(r'D:\pycharm\项目\pythonProject\章节110'))#False
print('判断一个路径是否有效文件',os.path.isfile(r'D:\pycharm\项目\pythonProject\章节11\b.txt'))#True
print('判断一个路径是否有效文件',os.path.isfile(r'D:\pycharm\项目\pythonProject\章节11\bbbbb.txt'))#False
