import serial
import time
import cv2
arduino = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=.1)
value = ''
print("Commands:\nL - left\nR - right\nQ - quit")
def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data
while True:
    img = cv2.imread('saturn.jpg')
    cv2.imshow("Window", img)
    key = cv2.waitKey(0)
    if key == ord('l'):
        value = write_read('l')
        time.sleep(0.2)
    if key == ord('r'):
        value = write_read('r')
        time.sleep(0.2)
    if key == ord('q'):
        print('stopping')
        break
