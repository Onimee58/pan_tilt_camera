import serial
import time

#try:
#    ser = serial.Serial(2, 9600)
#    print("serial set") ; time.sleep(2)
#except:
#    print("serial not set") ; time.sleep(2)


def pan(input):
    try:
        #print('ok')
        send = 'pan%s' % (input)
        print(send[:6]) ; 	ser = serial.Serial('COM5', 9600) ;
        ser.write(send) ; ser.close()


def tilt(input):
    try:
        #print('ok')
        send = 'til%s' % (input)
        print(send[:6]) ; 	ser = serial.Serial('COM5', 9600)
        ser.write(send) ; ser.close()

        #print('ok')

    except:
        #print('no')
