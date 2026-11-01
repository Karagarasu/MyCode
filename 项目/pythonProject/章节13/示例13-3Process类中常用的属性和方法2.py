from multiprocessing import Process
import os
import time
#函数式创建子进程
def sub_process(name):
    print(f'子进程PID:{os.getpid()},父进程的PID:{os.getppid()},-------------{name}')
    time.sleep(1)
def sub_process2(name):
    print(f'子进程PID:{os.getpid()},父进程的PID:{os.getppid()},-------------{name}')
    time.sleep(1)
if __name__ == '__main__':
    #主进程
    print('主进程开始执行')
    for i in range(5):
        #创建第一个子进程
        p1=Process(target=sub_process,args=('HeiJin',)) #没有给target参数，不会执行自己编写的函数的代码，会调用执行Process类run方法
        #创建第二个子进程
        p2=Process(target=sub_process2,args=('CangYe',))
        p1.start() #如果Process类创建对象时没有指定target参数，调用Process类中run方法去执行
        p2.start()#如果Process类创建对象时指定了target参数，start()调用target指定的函数去执行
        #终止进程
        p1.terminate()
        p2.terminate()
    print('主进程执行结束')