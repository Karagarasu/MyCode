def printMenu():
    print("*************************")
    print("*****  1、添加联系人  *****" )
    print("*****  2、显示联系人  *****" )
    print("*****  3、删除联系人  *****" )
    print("*****  4、查找联系人  *****" )
    print("*****  5、修改联系人  *****" )
    print("*****  6、清空联系人  *****" )
    print("*****  0、退出通讯录  *****" )
    print("*************************" )
while True:
    printMenu()
    select=input("请输入目标数字：")
    match select:
        case "1":
            print("添加联系人")
        case "2":
            print("显示联系人")
        case "3":
            print("删除联系人")
        case "4":
            print("查找联系人")
        case "5":
            print("修改联系人")
        case "6":
            print("清空联系人")
        case "0":
            print("退出通讯录,欢迎再次使用")
            break
        case _:
            print("输入错误")