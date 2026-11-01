#coding:utf-8
from socket import socket,AF_INET,SOCK_STREAM
import threading
import wx
class HeiJinandCangYe(wx.Frame):
    def __init__(self,client_name):
        #调用父类初始化方法
        # None:无父级窗口,id是当前窗口的编号,pos是窗口的打开位置
        #size是窗体大小，单位像素，400宽，450高
        wx.Frame.__init__(self,None,id=1001,title=client_name,pos=wx.DefaultPosition,size=(400,450))
        #创建面板对象
        pl=wx.Panel(self)
        #在面板中放盒子
        box=wx.BoxSizer(wx.VERTICAL)#垂直方向布局
        #可伸缩的网格布局
        fgz1=wx.FlexGridSizer(wx.HSCROLL)#水平方向布局
        #创建两个按钮
        conn_btn=wx.Button(pl,size=(200,40),label='连接')
        dis_conn_btn = wx.Button(pl, size=(200, 40), label='断开')
        #把两个按钮放到可伸缩的网格布局
        fgz1.Add(conn_btn,1,wx.TOP|wx.LEFT)
        fgz1.Add(dis_conn_btn, 1, wx.TOP | wx.RIGHT)
        #（可伸缩的网格布局）添加到盒子
        box.Add(fgz1,1,wx.ALIGN_CENTRE)
        #只读文本框，显示聊天内容
        self.show_text=wx.TextCtrl(pl,size=(400,210),style=wx.TE_MULTILINE|wx.TE_READONLY)
        box.Add(self.show_text, 1, wx.ALIGN_CENTRE)
        #创建聊天内容的文本框
        self.chat_text = wx.TextCtrl(pl, size=(400, 120), style=wx.TE_MULTILINE | wx.TE_READONLY)
        box.Add(self.chat_text, 1, wx.ALIGN_CENTRE)
        # 可伸缩的网格布局
        fgz2 = wx.FlexGridSizer(wx.HSCROLL)  # 水平方向布局
        # 创建两个按钮
        reset_btn = wx.Button(pl, size=(200, 40), label='重置')
        send_btn = wx.Button(pl, size=(200, 40), label='发送')
        fgz2.Add(reset_btn, 1, wx.TOP | wx.LEFT)
        fgz2.Add(send_btn, 1, wx.TOP | wx.LEFT)
        box.Add(fgz2, 1, wx.ALIGN_CENTRE)
        #将盒子放到面板中
        pl.SetSizer(box)
        '''----------------------以上代码是客户端界面的绘制----------------------'''
        self.Bind(wx.EVT_BUTTON,self.connect_to_server,conn_btn)
        #实例属性设置
        self.client_name=client_name
        self.isConnected=False #存储客户端连接服务器的状态，默认为False，没连接
        self.client_socket=None #设置客户端socket对象为空
    def connect_to_server(self,event):
        print(f'客户端{self.client_name}连接服务器成功')
        #如果客户端没有连接服务器，就开始连接
        if not self.isConnected: #等价于self.isConnected==False
            #TCP编程的步骤
            server_host_port=('127.0.0.1',8888)
            #创建socket对象
            self.client_socket=socket(AF_INET,SOCK_STREAM)
            #发送连接请求
            self.client_socket.connect(server_host_port)
            #只要连接成功，发送一条数据
            self.client_socket.send(f'{self.client_name}连接服务器'.encode('utf-8'))
            #启动一个线程，客户端的线程要与服务器端的会话线程进行通信
            client_thread=threading.Thread(target=self.recv_data)
            #设置成守护线程，窗体关掉，子线程也结束
            client_thread.daemon=True
            #修改连接状态
            self.isConnected=True
            #启动线程
            client_thread.start()
    def recv_data(self):
        #如果是连接状态，就接收数据
        while self.isConnected:
            #接受来自服务器的数据
            data=self.client_socket.recv(1024).decode('utf-8')
            #显示到只读文本框
            self.show_text.AppendText('-'*40+'\n'+data+'\n')



if __name__ == '__main__':
    #初始化App
    app=wx.App()
    #创建自己的客户端界面对象
    client=HeiJinandCangYe('是黑祲和苍野呀2')
    client.Show()#可以改成HeiJinandCangYe('是黑祲和苍野呀').Show()
    #循环刷新显示
    app.MainLoop()