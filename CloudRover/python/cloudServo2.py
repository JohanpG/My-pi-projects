 #Servo Control on raspberry pi through GPIO by Johan Porras 2013 
#use the servoblaster user space can be found here https://github.com/richardghirst/PiBits/tree/master/ServoBlaster

#!/usr/bin/env python
# -*- coding: utf-8 -*-

#from Tkinter import *
import webiopi
import os
import time
from webiopi.devices.serial import Serial




# initial value for global variable angles
#serial = Serial("ttyAMA0", 9600)

GPIO = webiopi.GPIO

angles=0
servo= 18
led=23

delay_period = 0.2

# initialise main window

## First define the funtions 




@webiopi.macro
def getDelay():
	global delay_period
	return "%d" % (delay_period)
	
@webiopi.macro
def setDelay(delay):
	global delay_period 
	delay_period = float(delay)
	return delay_period
		
def setup():
	GPIO.setFunction(servo, GPIO.PWM)
	GPIO.pulseAngle(servo,angles)
	GPIO.setFunction(led, GPIO.OUT)
	GPIO.digitalWrite(led,GPIO.HIGH)
	#serial = Serial("ttyAMA0", 9600)
	
	
	time.sleep(2)
	
	return 0


#Funtion to set servo to the right (180 angle)
@webiopi.macro
def right():
	global angles
	global delay_period
	
	
	#serial.writeString("RIGHT\r")
	
	time1 = time.time()
	
	angles1=int((90-angles)/5)
	angles2=angles
	angles3= int(angles1+1)
	for angle in range(0,(angles3)):
		global delay_period
		angles= (angles2+(angle*5))
		GPIO.pulseAngle(servo,angles)
		time.sleep(delay_period)
	GPIO.digitalWrite(led,GPIO.HIGH)
	
	
	





##Funtion to set servo to the left (0 angle)

@webiopi.macro
def left():
	global angles
	global delay_period 
	
	
	#serial.writeString("LEFT\r")
	time1 = time.time()
	
	angles1=int((angles+90)/5)
	angles2=angles
	angles3= int(angles1+1)
	for angle in range(0,(angles3)):
		global delay_period
		angles= (angles2-(angle*5))
		GPIO.pulseAngle(servo,angles)
		time.sleep(delay_period)
	GPIO.digitalWrite(led,GPIO.LOW)
	
	
	
def destroy():
	GPIO.setFunction(servo, GPIO.IN)
	GPIO.setFunction(led, GPIO.IN)
	

@webiopi.macro	
def center():
	global angles
	global delay_period 
	#serial = Serial("ttyAMA0", 9600)
	#serial.writeString("CENTER\r")
	
	
	if angles >0:
		angles1=int((angles+0)/5)
		angles2=angles
		angles3= int(angles1+1)
		for angle in range(0,(angles3)):
			global delay_period
			angles= (angles2-(angle*5))
			GPIO.pulseAngle(servo,angles)
			time.sleep(delay_period)
	
	else:
		angles1=int((0-angles)/5)
		angles2=angles
		angles3= int(angles1+1)
		for angle in range(0,(angles3)):
			global delay_period
			angles= (angles2+(angle*5))
			GPIO.pulseAngle(servo,angles)
			time.sleep(delay_period)
	GPIO.digitalWrite(led,GPIO.LOW)

#	servoList.insert(END, "----------------------------------------------------------------","Operation executed in",str(time.time()- time1)+" Seg")
       
@webiopi.macro
def center1():
	
	global angles
	GPIO.pulseAngle(servo,0)
	GPIO.digitalWrite(led,GPIO.LOW)
	time.sleep(1)
	angles=0
	
@webiopi.macro
def ledOn():
	global led
	if (GPIO.digitalRead(led)== GPIO.HIGH):
		GPIO.digitalWrite(led,GPIO.LOW)
		
	
		
	
@webiopi.macro
def ledOff():
	global led
	if (GPIO.digitalRead(led)== GPIO.LOW):
		GPIO.digitalWrite(led,GPIO.HIGH)
		
	


