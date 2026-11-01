import socket
#(1)创建一个socket对象
client_socket = socket.socket()
#(2)IP地址和主机端口
ip='127.0.0.1'
port=8888
client_socket.connect((ip,port))
print('-------与服务器连接已连接-------')
#（3）发送数据
client_socket.send('Wlocome to Python world'.encode('utf-8'))
#(4)关闭连接
client_socket.close()
print('发送数据完毕')