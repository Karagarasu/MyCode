from multiprocessing import Process
a=100

def add():
    print('子进程1开始执行')
    global a
    a+=30
    print('a=',a)
    print('子进程1执行完毕')
def sub():
    print('子进程2开始执行')
    global a
    a-=50
    print('a=',a)
    print('子进程2执行完毕')
if __name__ == '__main__':
    #父进程
    print('父进程开始执行')
    print('a=',a)
    #创建加的子进程
    p1=Process(target=add)
    # 创建减的子进程
    p2=Process(target=sub)
    #启动子进程
    p1.start()
    p2.start()
    #阻塞主进程
    p1.join()
    p2.join()
    print('父进程执行结束')
    print('a=',a)