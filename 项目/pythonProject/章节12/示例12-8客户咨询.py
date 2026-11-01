from socket import socket,AF_INET,SOCK_DGRAM
#(1)创建socket
send_socket=socket(AF_INET,SOCK_DGRAM)

#
while  True:
    #(2)准备发送数据
    data=input('客户说：')
    #(3)发送
    send_socket.sendto(data.encode('utf-8'),('127.0.0.1',8888))
    if data=='bye':
        break
    #(4)接受来自客服人员的回复信息
    recv_data,addr=send_socket.recvfrom(1024)
    print('客服回：',recv_data.decode('utf-8'))
#(5)关闭
send_socket.close()