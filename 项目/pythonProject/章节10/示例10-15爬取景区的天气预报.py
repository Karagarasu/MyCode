import requests
import re
import time
print('运行此程序需要互联网连接！')
time.sleep(3)
a=input('你今天开心吗？(输入N/Y)')
if a=='Y' or a=='y':
    print('太好了！保持下去ovo')
    input('键入任意值以退出...')
elif a=='N' or a=='n':
    try:
        print('哦，听到你这么说我很难过，希望你开心吧，我帮你找找今日旅游城市吧！')
        time.sleep(2)
        url = 'https://www.weather.com.cn/weather40d/101240101.shtml'  # 爬虫打开的浏览器上的网页
        resp = requests.get(url)  # 打开浏览器并打开网址
        # 设置编码格式
        resp.encoding = 'utf-8'
        # print(resp.text)#resp响应对象            对象名.属性名           resp.text

        city = re.findall('<span class="name">([\u4e00-\u9fa5]*)</span>', resp.text)
        weather = re.findall('<span class="weather">([\u4e00-\u9fa5]*)</span>', resp.text)
        wd = re.findall('<span class="wd">(.*)</span>', resp.text)
        zs = re.findall('<span class="zs">([\u4e00-\u9fa5]*)</span>', resp.text)
        # print(city)
        # print(weather)
        # print(wd)
        # print(zs)

        lst = []
        for a, b, c, d in zip(city, weather, wd, zs):
            lst.append([a, b, c, d])
        #     print(lst)
        for item in lst:
            print(item)
        input('键入任意值以退出...')
    except:
        print('Internet does not CONNECT!!!!!!!!')
        print('我去，隐藏错误被你找到了，你真厉害呢~')
        print('快去连接网络qwq')

else:
    print('你没看见上面提示要输入N/Y吗？让你飞起来！！！！！！！！')
    input('无语死了......')
'''
<span class="name">三亚</span>
<span class="weather">多云</span>
<span class="wd">30/20℃</span>
<span class="zs">适宜</span>

'''