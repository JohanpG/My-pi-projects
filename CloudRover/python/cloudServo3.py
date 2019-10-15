 #Servo Control on raspberry pi through GPIO by Johan Porras 2013 
#use the servoblaster user space can be found here https://github.com/richardghirst/PiBits/tree/master/ServoBlaster

# Full webiopi no servoblaster

#!/usr/bin/env python
# -*- coding: utf-8 -*-

#from Tkinter import *
import webiopi
import os
import time




# initial value for global variable angles



angles=150


delay_period = 0.2

# initialise main window

## First define the funtions 


 
##Funtion to set servo  

def setServo(angle):
	global angles 
	cmd="echo 1=" + str(angle) + " > /dev/servoblaster" 
	os.system(cmd)
	angles = angle
	return angles
	


#Funtion to set servo to the right (180 angle)

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
	os.system('sudo ./servod')
	setServo(angles)
	
	return 0


@webiopi.macro
def right():
	global delay_period 
	
	time1 = time.time()
	
	angles1=int((240-angles)/5)
	angles3= int(angles1+1)
	angles2=angles

	for angle in range(0,(angles3)):
		setServo(angles2+(angle*5))
		
		
		time.sleep(delay_period)
	





##Funtion to set servo to the left (0 angle)

@webiopi.macro
def left():
	delay_period 
	
	time1 = time.time()
	
	
	angles2 = angles
	angles1=int((angles-50)/5)
	angles3= int(angles1+1)
	
	
	for angle in range(0,(angles1)):
		setServo(angles2 - (angle*5))
		
		time.sleep(delay_period)
	
	#servoList.insert(END, "----------------------------------------------------------------","Operation executed in",str(time.time()- time1)+" Seg")
        


##Funtion to make a loop of n-cicles

#def loop():
	#delay_period = float(entryDelay.get())
	#global cicle
#	cicle = int(entryCicle.get())
	#print angles
#	time1 = time.time()
	#servoList.delete(0, END)
#	for i in range(0,cicle):
#		loop1(delay_period)
	#servoList.insert(END, "----------------------------------------------------------------","Operation executed in",str(time.time()- time1)+" Seg")
    
            
## funtion to make a base loop
#def loop1(delay_period):
	#delay_period = float(entryDelay.get())
	
	#print angles
#	time1 = time.time()
#	s#ervoList.delete(0, END)
	
#	for angle in range(0,39):
#			setServo(50 +(angle*5))
#			servoList.insert(END, "Pulse Width="+str(angles/100.0)+"ms")
#			time.sleep(delay_period)
#			#print("Right")
#	for angle in range(0, 39):
#		setServo(240 - (angle*5))
#		servoList.insert(END, "Pulse Width="+str(angles/100.0)+"ms")
#		time.sleep(delay_period)
#	#servoList.insert(END, "----------------------------------------------------------------","Operation executed in",str(time.time()- time1)+" Seg")
    
## funtion to make an infinite loop 

#def infloop():
#	while True:
#		delay_period = float(entryDelay.get())
#		loop1(delay_period)
#def tloop():
#	servoList.delete(0, END)
#	delay_period = 0.0017
#	seconds = int(entryTime.get())
#	startTime =time.time()
#	finishTime = startTime + seconds
#	while time.time() < finishTime:
#		loop1(delay_period)
#	servoList.insert(END, "----------------------------------------------------------------","Operation executed in",time.time()- startTime )
        
@webiopi.macro
def center():
	
	#print angles
	time1 = time.time()
#	servoList.delete(0, END)
	angles2 = angles
	if angles >150:
		angles1=(angles-150)/5
		angles3= int(angles1+1)
		
		for angle in range (0,(angles3)):
			setServo(angles2 - (angle*5))
#			servoList.insert(END, "Pulse Width="+str(angles/100.0)+"ms")
			time.sleep(delay_period)
	else:
		angles1=(150-angles)/5
		angles3=int(angles1+1)
		for angle in range (0,(angles3)):
			setServo(angles2 + (angle*5))
#			servoList.insert(END, "Pulse Width="+str(angles/100.0)+"ms")
			time.sleep(delay_period)

#	servoList.insert(END, "----------------------------------------------------------------","Operation executed in",str(time.time()- time1)+" Seg")
       
@webiopi.macro
def center1():
	setServo(150)
	

