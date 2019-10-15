import os
import time
os.system('sudo ./servod')

angles=150

cmd="echo 1=" + str(angles) + " > /dev/servoblaster" 

os.system(cmd)

time.sleep(1)

cmd="echo 1=" + str(angles+100) + " > /dev/servoblaster" 
os.system(cmd)
time.sleep(1)

cmd="echo 1=" + str(angles-100) + " > /dev/servoblaster" 
os.system(cmd)
time.sleep(1)
cmd="echo 1=" + str(angles+100) + " > /dev/servoblaster" 
os.system(cmd)
time.sleep(1)
cmd="echo 1=" + str(angles+100) + " > /dev/servoblaster" 
os.system(cmd)
time.sleep(1)
cmd="echo 1=" + str(angles) + " > /dev/servoblaster" 
os.system(cmd)
time.sleep(1)

angleb=float(3.0/2.0)

print angleb
