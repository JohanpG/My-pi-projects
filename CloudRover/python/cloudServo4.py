 #Servo Control on raspberry pi through GPIO by Johan Porras 2013 
#use the servoblaster user space can be found here https://github.com/richardghirst/PiBits/tree/master/ServoBlaster
#Servo con arduino uno, sends serial messages no pwm on pi
#!/usr/bin/env python
# -*- coding: utf-8 -*-

#from Tkinter import *
import webiopi
import os
import time
from webiopi.devices.serial import Serial




# initial value for global variable angles
serial = Serial("ttyACM0", 9600)

GPIO = webiopi.GPIO

angles=0
servo= 18
led=23

delay_period = 1

# initialise main window

## First define the funtions 




@webiopi.macro
def getDelay():
	global delay_period
	return "%d" % (delay_period)
	
@webiopi.macro
def setDelay(delay):
	global delay_period 
	delay_period = int(delay)
	dts=str(delay_period)
	if (delay_period==1):
		serial.writeString("1DL\n")
	if (delay_period==5):
		serial.writeString("5DL\n")
	if (delay_period==10):
		serial.writeString("10DL\n")
	if (delay_period==15):
		serial.writeString("15DL\n")
	if (delay_period==20):
		serial.writeString("20DL\n")
	return delay_period
		
def setup():
	GPIO.setFunction(servo, GPIO.PWM)
	GPIO.pulseAngle(servo,angles)
	GPIO.setFunction(led, GPIO.OUT)
	GPIO.digitalWrite(led,GPIO.HIGH)
	
	
	
	time.sleep(2)
	
	return 0


#Funtion to set servo to the right (180 angle)
@webiopi.macro
def right():
	global angles
	global delay_period
	serial.writeString("RG\n")
	
	time1 = time.time()
	
	
	GPIO.digitalWrite(led,GPIO.HIGH)
	
	
	





##Funtion to set servo to the left (0 angle)

@webiopi.macro
def left():
	global angles
	global delay_period 
	
	serial.writeString("LF\n")
	time1 = time.time()
	
	GPIO.digitalWrite(led,GPIO.LOW)
	
	
	
def destroy():
	GPIO.setFunction(servo, GPIO.IN)
	GPIO.setFunction(led, GPIO.IN)
	

@webiopi.macro	
def center():
	global angles
	global delay_period 
	serial.writeString("CT\n")
	
	
	
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
	serial.writeString("LP\n")
	global led
	if (GPIO.digitalRead(led)== GPIO.HIGH):
		GPIO.digitalWrite(led,GPIO.LOW)
		
	
		
	
@webiopi.macro
def ledOff():
	global led
	if (GPIO.digitalRead(led)== GPIO.LOW):
		GPIO.digitalWrite(led,GPIO.HIGH)
		
	


