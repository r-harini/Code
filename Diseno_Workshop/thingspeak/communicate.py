# -*- coding: utf-8 -*-
"""
Created on Sat Sep  7 12:52:58 2019

@author: Aylmer
"""

import serial, time
import re

arduino = serial.Serial('COM6', 9600, timeout=.1)
time.sleep(1) #give the connection a second to settle
#arduino.write("Hello from Python!")
while True:
    data = arduino.readline()
    if data:
        data = str(data)
        data = re.findall(r'\d+', data) 
        print(int(data[0])) #strip out the new lines for now