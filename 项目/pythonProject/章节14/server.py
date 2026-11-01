#coding:utf-8
import threading
import time
from wx import *
from socket import socket,AF_INET,SOCK_STREAM
import wx
class HeiJinandCangYeServer(wx.Frame):
    def __init__(self,name):
        wx.Frame.__init__(self,None,id=1002,title=name,pos=wx.DefaultPosition,size=(400,450))
        #窗口放面板
        pl=wx.Panel(self)
        #面板上放盒子
        box=wx.BoxSizer(wx.VERTICAL)#垂直放向上自动排版
        #可伸缩的网格布局
        fgz1 = wx.FlexGridSizer(wx.HSCROLL)  # 水平方向布局
        start_server_btn=wx.Button(pl,size=(133,40),label='启动服务')
        record_btn = wx.Button(pl, size=(133, 40), label='保存聊天记录')
        stop_server_btn = wx.Button(pl, size=(133, 40), label='停止服务')
        #放到可伸缩网格布局中
        fgz1.Add(start_server_btn,1,wx.TOP)
        fgz1.Add(record_btn, 1, wx.TOP)
        fgz1.Add(stop_server_btn, 1, wx.TOP)
        #将可伸缩网格放到盒子里
        box.Add(fgz1,1,wx.ALIGN_CENTRE)
        #只读的文本框
        self.show_text = wx.TextCtrl(pl, size=(400, 410), style=wx.TE_MULTILINE | wx.TE_READONLY)
        box.Add(self.show_text, 1, wx.ALIGN_CENTRE)
        #把盒子放进面板
        pl.SetSizer(box)
        self.name=name
        '''----------以上代码都是界面的绘制代码----------'''
        '''服务器功能实现的必要属性'''
        self.isOn=False #存储服务器的启动状态，默认未False，默认没启动
        #服务器端绑定的IP地址和端口号
        self.host_port=('',8888)#''空字符串代表本机的所有IP地址
        #创建socket
        self.server_socket=socket(AF_INET,SOCK_STREAM)
        #绑定IP地址和端口
        self.server_socket.bind(self.host_port)
        #监听
        self.server_socket.listen(5)
        #创建一个字典，存储与客户端对话的会话线程
        self.session_thread_dict={}#key-value {客户端的名称key：会话线程value}
        #当鼠标点击“启动服务”按钮，要执行
        self.Bind(wx.EVT_BUTTON, self.start_server, start_server_btn)
        #保存聊天记录按钮绑定
        self.Bind(wx.EVT_BUTTON, self.save_record, record_btn)
        #断开按钮绑定
        self.Bind(wx.EVT_BUTTON, self.stop_server, stop_server_btn)
    def stop_server(self,event):
        self.isOn=False
        print('服务器已停止服务')
    def save_record(self,event):
        #获取只读文本框中内容
        record=self.show_text.GetValue()
        with open('record.log','w',encoding='utf-8') as file:
            file.write(record)

    def start_server(self,event):
        #判断服务器是否已经启动，只有没启动才启动
        if not self.isOn: #等价于if self.isOn==False
            #启动服务器
            self.isOn=True
            #创建主线程对象，函数式创建主线程
            main_thread=threading.Thread(target=self.do_work)
            #设置为守护线程，父线程执行结束（窗体界面）子线程也自动关闭
            main_thread.daemon=True
            #启动主线程
            main_thread.start()

    def do_work(self):
        #判断isOn的值
        while self.isOn:
            #接收客户端的连接请求
            session_socket,client_addr=self.server_socket.accept()
            #客户端发送连接请求后，发送过来的第一条数据是客户端的名称，客户端的名称去作为字典的key
            user_name=session_socket.recv(1024).decode('utf-8')
            #创建一个绘画线程对象
            session_thread=SesstionThread(session_socket,user_name,self)
            #存储到字典中
            self.session_thread_dict[user_name]=session_thread
            #启动会话线程
            session_thread.start()
            #输出服务器提示信息
            self.show_info_and_send_client('服务器通知',f'欢迎{user_name}进入聊天室！',time.strftime('%Y-%m-%d %H:%M:%S',time.localtime()))
        #当self.isOn==False时，关闭服socket对象
        self.server_socket.close()
    def show_info_and_send_client(self,data_source,data,date_time):
        #字符串拼接操作
        send_data=f'{data_source}:{data}\n时间：{date_time}'
        #只读文本框
        self.show_text.AppendText('-'*40+'\n'+send_data+'\n')
        #每个客户端都发送一次
        for client in self.session_thread_dict.values():
            #判断当前会话是否开启
            if client.isOn:
                client.client_socket.send(send_data.encode('utf-8'))
                #发送数据
            client.client_socket.send(send_data.encode('utf-8'))
#服务器端绘画线程的类
class SesstionThread(threading.Thread):
    def __init__(self,client_socket,usr_name,server):
        #调用父类的初始化方法
        threading.Thread.__init__(self)
        self.client_socket=client_socket
        self.user_name=usr_name
        self.server=server
        self.isOn=True #会话线程是否启动，当创建SesstionThread对象时，绘画线程即启动
    def run(self) -> None:
        print(f'客户端：{self.user_name}已经和服务器连接成功，服务器启动一个会话线程')
        while self.isOn:
            #接收客户端发送过来的数据存储到data
            data=self.client_socket.recv(1024).decode('utf-8')
            #如果客户端点击断开按钮，先给服务器发送一句话，消息自定义
            if data=='disconnect':
                self.isOn=False
                #发送服务器通知
                self.server.show_info_and_send_client('服务器通知', f'{self.user_name}离开服务器',time.strftime('%Y-%m-%d %H:%M:%S', time.localtime()))
            else:
                #其他聊天信息显示给所有客户端，包括服务器端也显示
                self.server.show_info_and_send_client(self.user_name,data,time.strftime('%Y-%m-%d %H:%M:%S',time.localtime()))
        #socket关闭
        self.client_socket.close()
if __name__ == '__main__':
    # 初始化App
    app = wx.App()
    # 创建自己的服务端界面对象
    server= HeiJinandCangYeServer('服务器端')
    server.Show()
    # 循环刷新显示
    app.MainLoop()