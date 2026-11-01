from multiprocessing import Queue
if __name__ == '__main__':
    #创建队列
    q = Queue(3) #最多可以接受3条消息
    print('队列是否为空：',q.empty())
    print('队列是否为满：',q.full())
    #往队列中添加消息
    q.put('你好北京')
    q.put('你好上海')
    print('队列是否为空：',q.empty())#False
    print('队列是否为满：',q.full())#False
    q.put('你好广州')
    print('队列是否为空：', q.empty())#False
    print('队列是否为满：', q.full())#True
    print('队列当中消息的个数：',q.qsize())
    #出队
    print(q.get())
    print('队列当中消息的个数：', q.qsize())
    #入队
    q.put_nowait('html')
    #q.put_nowait('sql') #会报错queue.Full
    #q.put('sql')#不报错，会一直等待，等到队列中有位置
    #遍历
    if not q.empty():
        for i in range(q.qsize()):
            print(q.get_nowait())#不等
    print('队列是否为空：', q.empty())#True
    print('队列是否为满：', q.full())#False
    print('队列当中消息的个数：', q.qsize())#0

