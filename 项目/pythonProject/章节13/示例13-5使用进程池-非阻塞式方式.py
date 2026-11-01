from multiprocessing import Pool
import time,os
#编写任务
def task(name):
    print(f'子进程的PID：{os.getpid()},执行的任务：{name}')
    time.sleep(1)
if __name__ == '__main__':
    #主进程
    start=time.time()
    print('父进程开始执行')
    #创建进程池
    p=Pool(3)
    #创建任务
    for i in range(10):
        #非阻塞方式
        p.apply_async(func=task,args=(i,))
    p.close()#关闭进程池，不再接受新任务
    p.join()#阻塞父进程，等待所有子进程执行完毕后，才会执行父进程的代码
    print('所有的子进程执行完毕，父进程执行完毕')
    print(time.time()-start)
