# -*- coding: utf-8 -*-
"""
Created on Sat Sep  7 12:46:03 2019

@author: Aylmer
"""
import requests
import http.client as hp
import urllib
import time
import serial
import re

key = 'XFJL5FT2QEHBM95A'

def communicateArduino():
    data = arduino.readline()
    if data:
        data = str(data)
        data = re.findall(r'\d+', data) 
        data = int(data[0])
        print(data)
        return data

def update_distance():
    while True:
        dist = communicateArduino()
        print(dist)
        params = urllib.parse.urlencode({'field1': dist, 'key':key }) 
        headers = {"Content-typZZe": "application/x-www-form-urlencoded","Accept": "text/plain"}
        conn = hp.HTTPConnection("api.thingspeak.com:80")
        try:
            conn.request("POST", "/update", params, headers)
            response = conn.getresponse()
            print (dist)
            print (response.status, response.reason)
            data = response.read()
            conn.close()
        except:
            print( "connection failed")
        time.sleep(15)
        #break

arduino = serial.Serial('COM6', 9600, timeout=.1)
update_distance()