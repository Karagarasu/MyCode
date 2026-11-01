from PIL import Image
#加载图片
im=Image.open('Google-Logo.png')
# print(type(im),im)
#提取P图像的颜色通道，返回结果是图像的副本
p=im.split
#合并通道
om=Image.merge(mode='P',bands=(p))
om.save('new.jpg')