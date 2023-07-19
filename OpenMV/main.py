# Single Color RGB565 Blob Tracking Example
#
# This example shows off single color RGB565 tracking using the OpenMV Cam.

import sensor, image, time, math
from pyb import Pin
pin7 = Pin('P7', Pin.OUT_PP, Pin.PULL_NONE)
pin8 = Pin('P8', Pin.OUT_PP, Pin.PULL_NONE)
threshold_index = 6 # 0 for red, 1 for green, 2 for blue

# Color Tracking Thresholds (L Min, L Max, A Min, A Max, B Min, B Max)
# The below thresholds track in general red/green/blue things. You may wish to tune them...
thresholds = [(30, 100, 15, 127, 15, 127), # generic_red_thresholds
              (30, 100, -64, -8, -32, 32), # generic_green_thresholds
              (0, 30, 0, 64, -128, 0),     # generic_blue_thresholds
              (0, 18, -13, 5, -19, 103),
              (47, 26, -4, -23, -25, 4),
              (53, 7, -74, -7, -24, 75),
              (27, 5, -86, 3, -37, 10)]


sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 2000)
sensor.set_auto_gain(False) # must be turned off for color tracking
sensor.set_auto_whitebal(False) # must be turned off for color tracking
clock = time.clock()

# Only blobs that with more pixels than "pixel_threshold" and more area than "area_threshold" are
# returned by "find_blobs" below. Change "pixels_threshold" and "area_threshold" if you change the
# camera resolution. "merge=True" merges all overlapping blobs in the image.
last_area  = 0
while(True):
    clock.tick()
    img = sensor.snapshot()
    blobs = img.find_blobs([thresholds[threshold_index]], pixels_threshold=2000, area_threshold=2000, merge=True)
    if blobs:
        for blob in blobs:
        # These values depend on the blob not being circular - otherwise they will be shaky.
            if blob.elongation() > 0.5:
                pass
                #img.draw_edges(blob.min_corners(), color=(255,0,0))
                #img.draw_line(blob.major_axis_line(), color=(0,255,0))
                #img.draw_line(blob.minor_axis_line(), color=(0,0,255))
            # These values are stable all the time.
            img.draw_rectangle(blob.rect())
            img.draw_cross(blob.cx(), blob.cy())
            if blob.cx()<100 and blob.area():
                pin7.value(1)
                pin8.value(0)
                print("B")
            elif blob.cx()>220 and blob.area()>1200:
                pin7.value(0)
                pin8.value(1)
                print('A')
            elif 100<=blob.cx()<=220 and blob.area()>1200:
                pin7.value(0)
                pin8.value(0)
                print("forward")
            else:
               pin7.value(1)
               pin8.value(1)
               print("no people")
                #if -100<(blob.area()-last_area)<200:
                    #pin7.value(1)
                    #pin8.value(1)
                    #print('stop stop')
                #else:
                    #pin7.value(0)
                    #pin8.value(0)
            last_area = blob.area()
            # Note - the blob rotation is unique to 0-180 only.
            #img.draw_keypoints([(blob.cx(), blob.cy(), int(math.degrees(blob.rotation())))], size=20)
    else:
        pin7.value(1)
        pin8.value(1)
        print("no people")
    print(clock.fps())
