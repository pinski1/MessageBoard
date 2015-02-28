#!/usr/bin/python

import mosquitto
import random
import linecache

fileName = "./Messages.txt"
numLines = sum(1 for line in open(fileName))
lineNumb = random.randint(1,numLines)

lineBuffer = linecache.getline(fileName, lineNumb)

# create MQTT object
mqttc = mosquitto.Mosquitto(__file__)

# Connect
mqttc.connect("localhost", 1883, 60)

# Publish a message
mqttc.publish("MessageBoard/StoredMessages/string", lineBuffer)
