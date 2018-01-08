import serial
from time import sleep

ser=serial.Serial("/dev/cu.usbmodem1421",9600)  #change ACM number as found from ls /dev/tty/ACM*
ser.baudrate=9600
sleep(3)

commands = dict()
commands["fwd"] = b'\x01'
commands["right"] = b'\x02'
commands["left"] = b'\x03'
commands["180"] = b'\x04'

'''
ser.write(commands["right"])
print(ser.read())

ser.write(commands["fwd"])
print(ser.read())

ser.write(commands["180"])
print(ser.read())

ser.write(commands["fwd"])
print(ser.read())
'''

ser.write(commands["fwd"])
print(ser.read())
ser.write(commands["fwd"])
print(ser.read())
ser.write(commands["fwd"])
print(ser.read())

sleep(1)
ser.write(commands["right"])
print(ser.read())
sleep(1)

ser.write(commands["fwd"])
print(ser.read())
ser.write(commands["fwd"])
print(ser.read())