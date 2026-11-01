from multiprocessing import Queue
if __name__ == '__main__':
    q = Queue(3)
    #向队列中添加元素（入队）
    q.put('hello')#block=True
    q.put('world')
    q.put('python')
    q.put('html')
