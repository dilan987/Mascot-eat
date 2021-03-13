from ubidots import ApiClient
import serial
import time

if __name__**'__main__':
dato=0

    try:
        print("Conectado")
        arduino = serial.Serial('COM1',9600,timeout=2.0)
        time.sleep(1)
        

