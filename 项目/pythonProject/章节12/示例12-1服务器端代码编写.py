from socket import socket,AF_INET,SOCK_STREAM
#AF_INET 用于Internet 进程间通信
#SOCK_STREAM 用于TCP 协议
#(1)创建socket对象
server_Socket=socket(AF_INET,SOCK_STREAM)
#(2)绑定IP 地址和端口号
ip='127.0.0.1'#等同于localhost
port=8888#端口范围
server_Socket.bind((ip,port))
#(3)使用listen()方法监听端口
server_Socket.listen(5)#5 表示最多接受5 个连接
print('服务器启动成功')
#(4)等待客户端连接
client_socket,client_addr=server_Socket.accept() #系列解包赋值
#（5）接受客户端发送的数据
data=client_socket.recv(1024)
print('客户端发送的数据为：',data.decode('utf-8'))#要求客户端发送的数据为utf-8 编码
#（6）关闭socket
server_Socket.close()