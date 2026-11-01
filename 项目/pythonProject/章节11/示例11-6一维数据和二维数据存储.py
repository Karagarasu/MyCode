#存储和读取一维数组
def my_write():
    #一维数据，可以使用列表，元组，或集合
    lst=['张三','李四','王五','陈六','麻七']
    with open('student.csv','w',encoding='gbk') as file:
        file.write(','.join(lst))#将列表转成字符串

def my_read():
    with open('student.csv','r') as file:
        s=file.read()
        lst=s.split(',')
        print(lst)

#存储和读取二维数据
def my_write_table():
    lst=[
        ['商品名称','单价','采购数量'],
        ['水杯','98.5','20'],
        ['鼠标','89','100']

    ]
    with open('table.csv','w',encoding='utf-8') as file:
       for item in lst: #item数据类型是列表
           line=','.join(item)
           file.write(line)
           file.write('\n')
def my_read_table():
    data=[]
    with open('table.csv','r',encoding='utf-8') as file:
        lst=file.readlines() #每一行是列表中的一个元素
        #print(type(lst),lst)
        for item in lst:#item是字符串类型
            new_lst=item[:len(item)-1].split(',')
            data.append(new_lst)
    print(data)
if __name__ == '__main__':
    #my_write()
    # lst = ['张三', '李四', '王五', '陈六', '麻七']
    # print(','.join(lst))
    #my_read()
    #my_write_table()
    my_read_table()