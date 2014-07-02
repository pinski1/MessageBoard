

<!-- add image of completed display -->
<!-- 1[]() -->

<!-- introduction text


influenced by London Hackspace message board
  don't have the same network inastructure, no 24/7 servers/PCs
  Raspberry Pi available and I'd not used one
  It was capable of running everything with plenty of power left over for smarts
  
worst part was the display initialising being different for different models of the same display

-->

##Setup

###Hardware

####Get the Parts
* 1x Raspberry Pi B
* 1x 20cm USB micro cable
![USB Cable](./Hardware/20cm micro usb.png)
* 1x ethernet cable
* 1x set of passive Power Over Ethernet (POE) splitter cables
![Ethernet POE splitter](./Hardware/passive POE splitter.png)
* 1x Car USB adaptor
* 1x RPi & power to LED Display cable
* 4x Sure Electronics 8x32 LED Displays
![LED dot matrix displays](./Hardware/LED Dot Matrix.png)

####Making the Custom Cable
* 20x female crimps
* 1x 2x13 way female socket
* 1x 2x? way female socket
* 1x 150mm SWG30-SWG26 multicore red wire
* 2x 150mm SWG30-SWG26 multicore black wire
* 1x 150mm SWG30-SWG26 multicore green wire
* 1x 150mm SWG30-SWG26 multicore yellow wire
* 1x 150mm SWG30-SWG26 multicore blue wire
* 1x 150mm SWG30-SWG26 multicore purple wire
* 1x 150mm SWG30-SWG26 multicore white wire

<!---
1. Strip ~ 2mm from each end of every cable
2. Crimp each end with a female crimp
3. Insert the following cables into the 2x13 socket
 * A free black wire into
 * A free green wire into
 * A free yellow wire into
 * A free blue wire into
 * A free purple wire into
 * white wire into
4. insert the ?
5. insert the ?
-->

####Connecting it all Together
![Image](./Hardware/DisplayBoardCable.png?raw=true)

###Software
Type/copy the following lines into your Raspberry Pi's terminal:
```bash
sudo apt-get update
sudo apt-get upgrade
git clone git://git.drogon.net/wiringPi
git clone git://github.com/pinski1/MessageBoard
cd wiringPi
./build
cd ~/MessageBoard
./compile.sh
```
Assuming everything is connected properly you should now see the time & date scrolling across the message board.

As the message board is likely to be the only display connected to your Raspberry Pi it would be helpful to have that display the IP on boot up. I too the instructions from Jim Schrempp and can be found [here](http://www.jimschrempp.com/features/computer/rpi_boot_email.htm).
```bash
sudo cp /Scripts/boot_disp_ip.sh /etc/init.d
sudo update-rc.d boot_disp_ip.sh defaults
```

<!--- need to add python script stuff -->

##License Information

The LED Dot-Matrix Displays are closed source.

wiringPi is released under [GNU LGPLv3](http://www.gnu.org/copyleft/lesser.html). More information available [here](http://wiringpi.com/).

The C code is released under [Creative Commons Share-alike 3.0](http://creativecommons.org/licenses/by-sa/3.0/).

The cable is released under [Creative Commons Share-alike 3.0](http://creativecommons.org/licenses/by-sa/3.0/).


