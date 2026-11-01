import threading
from threading import Thread
import time
ticket=50 #代表的是50张票
def sale_ticket():
    global ticket
    for i in range(100):#每个线程要执行100次循环
        if ticket>0:
            print(f'{threading.current_thread().name}正在出售第{ticket}张票')
            ticket-=1
        time.sleep(1)
if __name__ == '__main__':
    for i in range(3):#创建三个线程，代表三个窗口
        t=Thread(target=sale_ticket)
        t.start() #启动了线程

