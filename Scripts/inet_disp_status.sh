#!/bin/bash

STATUS = ping -c 1 www.google.co.uk | grep -e "\s(\d)\sreceived" -o

if "STATUS = 0"; then
	sudo disp_write -s 50 -m "The internet is down!"
fi
