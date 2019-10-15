 #Servo Control on raspberry pi through GPIO by Johan Porras 2013 
#use the servoblaster user space can be found here https://github.com/richardghirst/PiBits/tree/master/ServoBlaster

#!/usr/bin/env python
# -*- coding: utf-8 -*-

from Tkinter import *

import RPi.GPIO as GPIO
import os
import time
#os.system('sudo ./servod --idle-timeout=50ms')
os.system('sudo ./servod')
import threading 
# initial value for global variable angles
angles=150
# initialise main window
def init(win):
  win.title("Servo Control by JohanpG")


  loopBt.grid(row=0, column=0)
  tloopBt.grid(row=0, column=1)
  inloopBt.grid(row=0, column=2)
  
  labelLeft.grid(row=1, column=0)
  leftBt.grid(row=2, column=0)
  labelCenter.grid(row=1, column=1)
  centerBt.grid(row=2, column=1)
  labelRight.grid(row=1, column=2)
  rightBt.grid(row=2, column=2)
  labelDelay.grid(row=3, column=0, sticky="W")
  entryDelay.grid(row=4, column=0)
  labelLoop.grid(row=5, column=0, sticky="W")
  entryCicle.grid(row=6, column=0)
  labelTloop.grid(row=7, column=0, sticky="W")
  entryTime.grid(row=8, column=0)
  
  servoList.grid(row=4, column=1, rowspan=5)
  yscroll.grid(row=4, column=2, rowspan=5, sticky="NS")

  servoList.configure(yscrollcommand = yscroll.set)
  yscroll.configure(command = servoList.yview)
  entryDelay.insert(INSERT, "0.0015")
  entryCicle.insert(INSERT, "3")
  entryTime.insert(INSERT, "6")

## First define the funtions 


 
##Funtion to set servo  

def setServo(angle):
	global angles 
	cmd="echo 1=" + str(angle) + " > /dev/servoblaster" 
	os.system(cmd)
	angles = angle
	return angles
	


#Funtion to set servo to the right (180 angle)

def right():
	delay_period = float(entryDelay.get())
	#print angles
	time1 = time.time()
	servoList.delete(0, END)
	angles1=(240-angles)/5
	angles2=angles
	#if angles==0:
	for angle in range(0,(angles1+1)):
		setServo(angles2+(angle*5))
		#print "Angle=",angle
		servoList.insert(END, "Pulse Width="+str(angles/100.0)+"ms")
		time.sleep(delay_period)
	
	#elif angles==90:
	#	for angle in range(90,181):
	#		setServo(angle)
	#		#print "Angle=",angle
	#		servoList.insert(END, "Angle="+str(angles))
	#		time.sleep(delay_period)
	#elif angles==180:
		#setServo(180)
	servoList.insert(END, "----------------------------------------------------------------","Operation executed in",str(time.time()- time1)+" Seg")
        #print("Right")





##Funtion to set servo to the left (0 angle)
def left():
	delay_period = float(entryDelay.get())
	#print angles
	time1 = time.time()
	servoList.delete(0, END)
	angles1 = (angles -50)/5 
	angles2 = angles
	for angle in range(0,(angles1+1)):
		setServo(angles2 - (angle*5))
		#print "Angle=",angle
		servoList.insert(END, "Pulse Width="+str(angles/100.0)+"ms")
		time.sleep(delay_period)
	
	servoList.insert(END, "----------------------------------------------------------------","Operation executed in",str(time.time()- time1)+" Seg")
        


##Funtion to make a loop of n-cicles

def loop():
	delay_period = float(entryDelay.get())
	#global cicle
	cicle = int(entryCicle.get())
	#print angles
	time1 = time.time()
	servoList.delete(0, END)
	for i in range(0,cicle):
		loop1(delay_period)
	servoList.insert(END, "----------------------------------------------------------------","Operation executed in",str(time.time()- time1)+" Seg")
    
            
## funtion to make a base loop
def loop1(delay_period):
	#delay_period = float(entryDelay.get())
	
	#print angles
	time1 = time.time()
	servoList.delete(0, END)
	
	for angle in range(0,39):
			setServo(50 +(angle*5))
			servoList.insert(END, "Pulse Width="+str(angles/100.0)+"ms")
			time.sleep(delay_period)
			#print("Right")
	for angle in range(0, 39):
		setServo(240 - (angle*5))
		servoList.insert(END, "Pulse Width="+str(angles/100.0)+"ms")
		time.sleep(delay_period)
	#servoList.insert(END, "----------------------------------------------------------------","Operation executed in",str(time.time()- time1)+" Seg")
    
## funtion to make an infinite loop 

def infloop():
	while True:
		delay_period = float(entryDelay.get())
		loop1(delay_period)
def tloop():
	servoList.delete(0, END)
	delay_period = 0.0017
	seconds = int(entryTime.get())
	startTime =time.time()
	finishTime = startTime + seconds
	while time.time() < finishTime:
		loop1(delay_period)
	servoList.insert(END, "----------------------------------------------------------------","Operation executed in",time.time()- startTime )
        
		
def center():
	delay_period = float(entryDelay.get())
	#print angles
	time1 = time.time()
	servoList.delete(0, END)
	angles2 = angles
	if angles >150:
		angles1=(angles-150)/5
		
		for angle in range (0,(angles1+1)):
			setServo(angles2 - (angle*5))
			servoList.insert(END, "Pulse Width="+str(angles/100.0)+"ms")
			time.sleep(delay_period)
	else:
		angles1=(150-angles)/5
		for angle in range (0,(angles1+1)):
			setServo(angles2 + (angle*5))
			servoList.insert(END, "Pulse Width="+str(angles/100.0)+"ms")
			time.sleep(delay_period)

	servoList.insert(END, "----------------------------------------------------------------","Operation executed in",str(time.time()- time1)+" Seg")
       

def center1():
	setServo(70)


# create top-level window object
win = Tk()

# create widgets
labelLeft = Label(win, text="----------------------------\nLeft")
leftBt = Button(win, text="Go!",width=8, command=left)
labelCenter = Label(win, text="-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\nCenter")
centerBt = Button(win, text="Go!",width=8, command=center)
labelRight = Label(win, text="--------------------------\nRight")
rightBt = Button(win, text="Go!",width=8, command=right)
labelDelay = Label(win, text="----------------\nEntry Step Delay")


labelLoop = Label(win, text="----------------\nEntry Cicles")
loopBt = Button(win, text="Loop",width=8, command=loop)

labelTloop = Label(win, text="----------------\nEntry Time Loop")
tloopBt = Button(win, text="Time-Loop",width=8, command=tloop)

inloopBt = Button(win, text="Infinite Loop",width=8, command=infloop)


entryDelay = Entry(win, width=12)
entryCicle = Entry(win, width=12)
entryTime = Entry(win, width=12)

#entryEnding = Entry(win, width=12)
servoList = Listbox(win, width=80)
yscroll = Scrollbar(win, orient=VERTICAL)

# initialise and run main loop
cmd="echo 1=" + str(angles) + " > /dev/servoblaster" 
os.system(cmd)
servoList.insert(END, "Pulse Width="+str(angles/100.0)+"ms")
#setServo(angles)
init(win)
mainloop()
