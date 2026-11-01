import threading
from threading import Thread
import time
class SubThread(Thread):
    def run(self):
        for i in range(3):
            time.sleep(1)
            print(f'线程{threading.current_thread().name}正在执行{i}')
if __name__ == '__main__':
    print('主线程开始执行')
    lst = [SubThread() for i in range(2)]
    for item in lst:#item的数据类型是Thread类型
        #启动线程
        item.start()
    for item in lst:
        item.join() #阻塞主线程，直到子线程执行完毕
    print('主线程执行完毕')
