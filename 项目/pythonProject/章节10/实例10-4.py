from my_info import *
from introduce import *
#导入的模块中具有同名的变量和函数,后导入的会覆盖前导入
info()
#如果不想覆盖，解决方案，使用import
import my_info
import introduce
#使用模块中的函数或变量时，模块名打点调用
my_info.info()
introduce.info()
