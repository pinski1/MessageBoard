#MessageBoard

This project was inspired by London Hackspace's [Notification Board](https://wiki.london.hackspace.org.uk/view/Project:Notification_Board) but with modifications to suit the Cambridge [Makespace](http://makespace.org/).

The primary modification was to remove the need for separate computer , this was done by replacing the Arduino with an ethernet shield with a Raspberry Pi. Whilst it probably wasn't the most efficient use of computing power I had a Raspberry Pi free and I wanted to use it for a worthwhile project. In addition it's spare power could be used to increase the functionality of the message board by having scripts running 24/7 to display useful informaition about local food, transport and weather as well as displaying current and future events.

##Hardware
###Parts

* 1x Raspberry Pi B (any Model B will do)
* 1x 20cm USB micro cable
* 1x ethernet cable
* 1x set of passive Power Over Ethernet (POE) splitter cables
* 1x Car USB adaptor
* 1x RPi & power to LED Display cable
* 4x Sure Electronics 8x32 LED Displays
* 1x 220uF 16V electrolytic capacitor
* 1x set of lasercut parts for  enclosure
* 8x M3x16mm cap bolt, M3 washer, M3 nut (square is best)

##Software

With the hardware connected up properly it now needs the software in order todisplay messages.

###Installation

Git? 'sudo apt-get install git-core'

1. Install [WiringPi](http://wiringpi.com/)
    * '''bash
      git clone git://git.drogon.net/wiringPi
      cd wiringPi
      ./build
      '''
2. Install up to date copy of Python
    * '''bash
      sudo apt-get install python
      '''
    * PIP?
3. Install Mosquitto
    * '''bash
      sudo apt-get install mosquitto mosquitto-clients python-mosquitto
      sudo /etc/init.d/mosquitto stop
      '''
4. Install JSON, urllib2, twython, RPi.GPIO
4. Install MessageBoard
    * '''bash
      git clone git://github.com/Pinski1/MessageBoard
      '''
      Things about installation scripts

5. Copy C driver to bin
6. Set startup python script to run at boot
7. Restart

###Adding New Scripts

1. Write new script using example scripts
2. Add to startup python script
3. Run the new script in the background

##Licence Information
<a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a><br /><span xmlns:dct="http://purl.org/dc/terms/" href="http://purl.org/dc/dcmitype/Dataset" property="dct:title" rel="dct:type">MessageBoard</span> by <a xmlns:cc="http://creativecommons.org/ns#" href="http://www.wiresandbits.co.uk" property="cc:attributionName" rel="cc:attributionURL">Pinski1</a> is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by/4.0/">Creative Commons Attribution 4.0 International License</a>.<br />Based on a work at <a xmlns:dct="http://purl.org/dc/terms/" href="https://github.com/Pinski1/MessageBoard" rel="dct:source">https://github.com/Pinski1/MessageBoard</a>.
