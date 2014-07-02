### BEGIN INIT INFO
# Provides:		boot_disp_ip
# Required-Start:	$local_fs $syslog
# Required-Stop:	$local_fs $syslog
# Default-Start:	2 3 4 5
# Default-Stop:	        0 1 6
# Short-Description:    Display the ip address on screen
# Description:		display the ip address on screen
### END INIT INFO
# Author: Robert Karpinski
#
# If you modify this, please add your contact info
#
#
#  Send email of ip address upon boot up
#

#! /bin/bash

disp_init.0 -m '.'

TRYLOOP=1
while [ $TRYLOOP -gt "0" ]
  do

    TRYLOOP=`expr $TRYLOOP + 1`
    if [ $TRYLOOP -gt "30" ]
    then 
      TRYLOOP=0
    fi

    MYIP=$(/sbin/ifconfig eth0 | grep "inet addr" | awk -F: '{print $2}' | awk '{print $1}')

    if [ -z "$MYIP" ]
      then
         sleep 10s
      else
         TRYLOOP=0
    fi

done

echo 'ip is: '$MYIP

if [ -n "$MYIP" ]
  then
    sudo write_disp -s 75 -m "The ip for this display is $MYIP"
fi
