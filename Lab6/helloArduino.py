'''
Edit 'message' to send an SOS message to Arduino
'''

import serial
import time

ser = serial.Serial('/dev/ttyUSB0', 9600)
message = input("Message to Pass: ")
while True:
    try:
        ser.write(b'message')  # arbitrary message
        time.sleep(1.25)
    except KeyboardInterrupt:
        ser.close()
        break
