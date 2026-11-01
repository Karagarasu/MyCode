from threading import Thread
a=100 #全局变量
def add():
    print('加线程开始执行')
    global a
    a+=30
    print(f'a={a}')
    print('加线程执行完毕')
def sub():
    print('减线程开始执行')
    global a
    a -= 50
    print(f'a={a}')
    print('减线程执行完毕')
if __name__ == '__main__':
    print('主线程开始执行')
    print(f'--------全局变量a的值为{a}')
    #线程
    add=Thread(target=add)
    sub=Thread(target=sub)
    add.start()
    sub.start()
    add.join() #当加线程执行完毕
    sub.join()
    print('---主线程执行完毕')