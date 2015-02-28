#!/usr/bin/python
import subprocess
import RPi.GPIO as GPIO
import mosquitto
import time
import glob

buttonIP = 4 # Button to display IP on GPIO 4
fileList = glob.glob('./script_*.py')
fileIndex = 0

def printIP(channel):
  print "Button press detected, printing IP"
  
  # get IP address

  mqttc.publish("MessageBoard/Control/IP/string", "The IP address is: 000.000.000.000", retain=True)

# set up GPIO pin
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(buttonIP, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.add_event_detect(buttonIP, GPIO.FALLING, callback=printIP)

# set up MQTT
mqttc = mosquitto.Mosquitto(__file__)
mqttc.connect('localhost', 1883, 60)

# stick IP address in as default text
printIP(0)

# start MessageFormatter.py &
subprocess.Popen(["python", "./MessageFormatter.py", "&"])

while(True):

  subprocess.call(["python", fileList[fileIndex]]) # generate a message

  # lock out Twitter/Meetup messages?

  # incrment index, or reset if at end
  if fileIndex < (len(fileList)-1):
    fileIndex += 1
  else:
    fileIndex = 0


  time.sleep(5) # sleep for 5 seconds
