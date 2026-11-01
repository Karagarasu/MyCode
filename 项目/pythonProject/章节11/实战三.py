import time
def show_info():
    print('输入提示数字，执行相应操作：0.退出 1.查看登录日志')

#记录日志
def write_loginfo(username):
    with open('log.txt','a',encoding='utf-8') as file:
        s=f'用户名:{username},登陆时间:{time.strftime("%Y-%m-%d %H:%M:%S",time.localtime(time.time()))}'
        file.write(s)
        file.write('\n')

#读取日志
def read_loginfo():
    with open('log.txt','r',encoding='utf-8') as file:
        while True:
            line=file.readline()
            if line=='':
                break
            else:
                print(line)
if __name__ == '__main__':
    # write_loginfo('admin')
    username=input('请输入用户名：')
    pwd=input('请输入密码：')
    if username=='admin' and pwd=='admin':
        print('登陆成功')
        #将登录信息写入日志文件
        write_loginfo(username)
        #提示用户操作
        show_info()
        num=eval(input('请输入要操作的数字：'))
        while True:
            if num==0:
                print('退出成功')
                break #退出while
            elif num==1:
                print('查看登录日志')
                read_loginfo()
                show_info() #再次显示信息
            else:
                print('你™输错了')
                show_info()
            num=eval(input('请输入要操作的数字：'))
    else:
        print('用户名或密码不正确')
