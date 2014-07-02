

<!-- add image of completed display -->
<!-- 1[]() -->

<!-- introduction text -->

##Installation

###Software
1. update & upgrade all packages
2. Get wiringPi
2. Get this github repo
3. run script to compile C programs
<!--4. run script to set python script to auto run-->

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

###Hardware

* 1x RPi & power to LED Display cable
![Image](./Hardware/DisplayBoardCable.png?raw=true)
* 4x Sure Electronics 8x32 LED Displays
* 1x Car USB adaptor
* 1x 20cm USB micro cable
* 1x set of passive Power Over Ethernet (POE) splitter cables


##License Information

The LED Dot-Matrix Displays are closed source.

wiringPi is released under [GNU LGPLv3](http://www.gnu.org/copyleft/lesser.html). More information available [here](http://wiringpi.com/).

The C code is released under [Creative Commons Share-alike 3.0](http://creativecommons.org/licenses/by-sa/3.0/).

The cable is released under [Creative Commons Share-alike 3.0](http://creativecommons.org/licenses/by-sa/3.0/).


