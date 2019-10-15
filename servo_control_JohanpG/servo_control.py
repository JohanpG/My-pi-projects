# Servo Control on raspberry pi through GPIO by Johan Porras 2013 
#base on http://learn.adafruit.com/adafruits-raspberry-pi-lesson-8-using-a-servo-motor/software 

#! /usr/bin/python3
import time

## First define the funtions 

def set(property, value):
    try:
		f = open("/sys/class/rpi-pwm/pwm0/" + property, 'w')
		f.write(value)
		f.close()	
    except:
		print("Error writing to: " + property + " value: " + value)
 
##Funtion to set servo  

def setServo(angle):
	set("servo", str(angle))
	
set("delayed", "0")
set("mode", "servo")
set("servo_max", "180")
set("active", "1")

#Funtion to set servo to the right (180 angle)

def right(delay_period):
    for angle in range(90,180):
        setServo(angle)
        time.sleep(delay_period)
        print("Right")

##Funtion to set servo to the left (0 angle)

def left(delay_period):
    for angle in range(0,90):
        setServo(90 - angle)
        time.sleep(delay_period)
        print("Left")
##Funtion to make a loop of n-cicles

def loop(delay_period,cicle):
    for i in range(0,cicle):
        for angle in range(0,180):
            setServo(angle)
            time.sleep(delay_period)
            print("Right")
        for angle in range(0, 180):
            setServo(180 - angle)
            time.sleep(delay_period)
            print("Left")
            
## funtion to make an infinite loop 
def infloop(delay_period):
    for angle in range(0,180):
        setServo(angle)
        time.sleep(delay_period)
        print("Right")
        #time.sleep(0.15)
    for angle in range(0, 180):
        setServo(180 - angle)
        time.sleep(delay_period)
        print("Left")
        #time.sleep(0.15)

setServo(90)

print("----------------------------------------------------------------\nWELCOME TO THE SERVO MOTOR GPIO TEST ON RASPBERRY PI by JohanpG\n----------------------------------------------------------------")

delay_period = float(raw_input('----------------------------------------------------------------\n(If using Time loop function this is fixed!)\nIntroduce step_delay: '))

while True:
    setServo(90)
    
    #print("----------------------------------------------------------------\nWELCOME TO THE SERVO MOTOR GPIO TEST ON RASPBERRY PI by JohanpG\n----------------------------------------------------------------")
    
    move = int(raw_input('----------------------------------------------------------------\nOPTIONS MENU\n----------------------------------------------------------------\nLeft = 0 , Right = 1\nLoop = 2 , Time Loop = 3\nInfinite Loop = 4\nIntroduce  desire Motion: '))
    
    #delay_period = float(raw_input('----------------------------------------------------------------\n(If using Time loop function this is fixed!)\nIntroduce step_delay: '))
    
    ### If to move to the right, base in input
    
    if move ==1:
        
        time1 = time.time()
        right(delay_period)
        print "----------------------------------------------------------------\nOperation executed in",time.time()- time1,"Seg"
        raw_input("Press 'intro' to come back")
        
    ##### If to move to the left, base in input
    elif move ==0 :
        time1 = time.time()
        left(delay_period)
        print "----------------------------------------------------------------\nOperation executed in",time.time()- time1,"Seg"
        raw_input("Press 'intro' to come back")
        
    
    ### Loop with the desire number of cicles
    elif move ==2:
        cicle = int(raw_input('----------------------------------------------------------------\nIntroduce Number of cicles: '))
        time1 = time.time()
        loop(delay_period,cicle)
        print "----------------------------------------------------------------\nOperation executed in",time.time()- time1,"Seg"
        raw_input("Press 'intro' to come back")
        
    ### Loop with the desire time * (only reliable a very small delay_period), fixed to 0.0017
    elif move ==3:
        delay_period = 0.0017
        seconds = input("----------------------------------------------------------------\nNumber of seconds: ")
        #secondsfix = seconds-0.34
        #interval = seconds/delay_period
        startTime =time.time()
        #print (startTime)
        finishTime = startTime + seconds
        while time.time() < finishTime:
            infloop(delay_period)
        print "----------------------------------------------------------------\nOperation executed in",time.time()- startTime 
        raw_input("Press 'intro' to come back")
    
    
    elif move ==4:
        while move ==4:
            infloop(delay_period)
            
    ### When no appropiate move enter
    else :
        setServo(90)
        print("Center")
        raw_input("Bad entry press 'intro' to comeback")
    ### Infinite lopp  base in input 
    

raw_input("Pulsa 'intro' para terminar")
