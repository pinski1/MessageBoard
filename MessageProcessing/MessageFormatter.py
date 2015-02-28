#!/usr/bin/python
from subprocess import call
import mosquitto

# Define event callbacks
def on_connect(rc):
  print("rc: " + str(rc))

def on_message(msg):
  #print(msg.topic + ": " + str(msg.payload))
  call(["echo", "sudo", "write_disp", "-s", "25", "-m", str(msg.payload).strip()])

def on_log(mosq, obj, level, string):
  print(string)

mqttc = mosquitto.Mosquitto(__file__)
# Assign event callbacks
mqttc.on_message = on_message
mqttc.on_connect = on_connect

# Uncomment to enable debug messages
#mqttc.on_log = on_log

# Connect
mqttc.connect('localhost', 1883, 60)

# Start subscribe, with QoS level 0
mqttc.subscribe("MessageBoard/#", 0)

# Continue the network loop, exit when an error occurs
rc = 0
while rc == 0:
    rc = mqttc.loop()
print("rc: " + str(rc))
