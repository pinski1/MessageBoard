#!/bin/bash

sudo apt-get install git-core

sudo apt-get update

sudo apt-get upgrade

git clone git://git.drogon.net/wiringPi

cd wiringPi
./build

cd ../

git clone git://github.com/pinski1/display

cd display
./compile.sh

