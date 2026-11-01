import datetime
#输入日期的函数
def input_date():
    inputdate=input('请输入开始日期：（20281001）后按回车')
    datestr=inputdate[0:4]+'-'+inputdate[4:6]+'-'+inputdate[6:] #切片切出年，月，日
    #类型转换
    dt=datetime.datetime.strptime(datestr,'%Y-%m-%d')
    return dt
#主程序运行
if __name__ == '__main__':
    #print(input_date())
    date=input_date()
    #输入间隔的天数
    in_num=eval(input('请输入间隔天数：'))
    date=date+datetime.timedelta(days=in_num)
    print('您推算的日期是：',date)

