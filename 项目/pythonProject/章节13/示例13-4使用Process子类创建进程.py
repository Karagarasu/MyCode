from multiprocessing import Process
import os,time
class SubProcess(Process):
    #编写初始化方法
    def __init__(self,name):
        super().__init__()
        self.name=name
    #重写父类中的run方法
    def run(self):
        print(f'子进程的名称:{self.name},PID:{os.getpid()},父进程的PID:{os.getppid()}')
if __name__ == '__main__':
    print('父进程开始执行')
    lst=[]
    for i in range(1,6):
        p1=SubProcess(f'进程：{i}')
        #启动进程
        p1.start()
        lst.append(p1)
        #阻塞主进程
    for item in lst:
        item.join()
    print('父进程执行结束')