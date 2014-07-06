#!/bin/bash

touch HT1632.c HT1632.h HT1632_driver.c font.h

gcc HT1632.c HT1632_driver.c -o write_disp.o -l wiringPi

sudo cp write_disp.o /etc/write_disp # update cmd line

echo Finished compiling.

sudo write_disp -s 75 -m "`date`"

# to update boot script:
# sudo nano boot_disp_ip.sh
# sudo update-rc.d boot_disp_ip.sh defaults
