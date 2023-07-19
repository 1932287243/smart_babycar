#实验名称：人脸检测
#翻译和注释：01Studio
#参考链接：http://blog.sipeed.com/p/675.html

import sensor,lcd,time
import KPU as kpu
from Maix import GPIO
from fpioa_manager import fm
# 配置传输IO
fm.register(16, fm.fpioa.GPIO0,force=True)
fm.register(18, fm.fpioa.GPIO1,force=True)
pin16 = GPIO(GPIO.GPIO0, GPIO.OUT) #构建 LED 对象
pin18 = GPIO(GPIO.GPIO1, GPIO.OUT) #构建 LED 对象

#设置摄像头
sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.set_vflip(1)    #设置摄像头后置
#sensor.set_auto_gain(False) # must be turned off for color tracking
#sensor.set_auto_whitebal(False) # must be turned off for color tracking

lcd.init() #LCD初始化

clock = time.clock()

#task = kpu.load(0x300000) #需要将模型（face.kfpkg）烧写到flash的 0x300000 位置
task = kpu.load("/sd/facedetect.kmodel") #模型SD卡上

#模型描参数
anchor = (1.889, 2.5245, 2.9465, 3.94056, 3.99987, 5.3658, 5.155437, 6.92275, 6.718375, 9.01025)

#初始化yolo2网络
a = kpu.init_yolo2(task, 0.5, 0.3, 5, anchor)

while(True):
    clock.tick()
    img = sensor.snapshot()
    code = kpu.run_yolo2(task, img) #运行yolo2网络

    #识别到人脸就画矩形表示
    if code:
        for i in code:
            img.draw_rectangle(i.rect())
            img.draw_cross(i.rect()[0]+i.rect()[2]//2, i.rect()[1]+i.rect()[3]//2, color = (255, 255, 255), size = 20,thickness = 2)
            if (i.rect()[0]+i.rect()[2]//2)<120:
                pin16.value(0)
                pin18.value(1)
            elif (i.rect()[0]+i.rect()[2]//2)>200:
                pin16.value(1)
                pin18.value(0)
            elif (i.rect()[2])*(i.rect()[3])<1000:  #原值2500
                pin16.value(1)
                pin18.value(1)
                img.draw_string(160, 120, "TOO FAR!", color = (255, 255,
                255), scale = 2,mono_space = False)
            else:
                pin16.value(0)
                pin18.value(0)
    else:
        pin16.value(1)
        pin18.value(1)
        img.draw_string(160, 120, "NO FACE!", color = (255, 255,
        255), scale = 2,mono_space = False)
    #LCD显示
    img.draw_string(10, 10, str(clock.fps()), color = (255, 255,
    255), scale = 2,mono_space = False)
    lcd.display(img)

    print(clock.fps())   #打印FPS
