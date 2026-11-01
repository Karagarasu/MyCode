def find_answer(question):
    with open('replay.txt','r',encoding='gbk') as file:
        while True:
            line=file.readline() #第一次 订单|如果您有任何订单问题，可以登录淘宝账号，点击“我的订单”，查看订单详情
            if line=='':
                break #退出while
            #字符串分割
            keyword=line.split('|')[0]
            reply = line.split('|')[1]
            if keyword in question:
                return reply
    return False
if __name__ == '__main__':
    question=input('HI,XXX你好，小蜜在此等主人很久了，有什么烦恼和小蜜说说吧：')
    while True:
        if question=='bye' or question=='再见' or question=='拜拜':
            break #退出循环
        else:
            #开始查找回复答案
            reply=find_answer(question)
            if reply==False:#返回值如过是False
                question=input('小蜜不知道你在说什么，你可以问问关于一些订单，物流，支付，账户方面的问题，退出输入bye：')
            else:
                print(reply)
                question=input('小主你还可问一些订单，物流，支付，账户方面的问题，退出输入bye：')
    print('小主再见')
