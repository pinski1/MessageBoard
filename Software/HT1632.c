#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include "HT1632.h"

int writeCommand(unsigned char channel, unsigned char displayCommand) {
	
	unsigned char tempMessage[2] = {0x00, 0x00};
	int pin, temp;
	
	switch(channel)
	{
		case 0:
			pin = LED_DISPLAY_CS1;
			break;
		case 1:
			pin = LED_DISPLAY_CS2;
			break;
		case 2:
			pin = LED_DISPLAY_CS3;
			break;
		case 3:
			pin = LED_DISPLAY_CS4;
			break;
	}
	digitalWrite(pin, HIGH);
	
	
	
	tempMessage[0] = (HT1632_ID_CMD << 5) | (displayCommand >> 3); // cmd & cmd
	tempMessage[1] = (displayCommand) << 5;
	
	//printf("Command is 0x%0.2X%0.2X\r\n", tempMessage[0], tempMessage[1]);
	
	digitalWrite(pin, LOW); // lower that channel
	temp =  wiringPiSPIDataRW(channel % 2, tempMessage, 2);
	digitalWrite(pin, HIGH); // raise that channel
	
	return temp;
}

int writeDisplay(unsigned char channel, unsigned char pixelColumns[]) {

	int i, pin, temp;
	int bufferLength = 32;
	unsigned char tempMessage[32 + 2];

	switch(channel)
	{
		case 0:
			pin = LED_DISPLAY_CS1;
			break;
		case 1:
			pin = LED_DISPLAY_CS2;
			break;
		case 2:
			pin = LED_DISPLAY_CS3;
			break;
		case 3:
			pin = LED_DISPLAY_CS4;
			break;
	}
	digitalWrite(pin, HIGH);
	
	tempMessage[0] = (HT1632_ID_WR << 5) & 0xE0;
	tempMessage[1] = ((0x3F & pixelColumns[0]) >> 2);
	for(i = 0; i < 32; i++) tempMessage[i + 2] = ((pixelColumns[i] << 6) & 0xC0) | ((pixelColumns[(i+1) % 32] >> 2) & 0x3F);

	digitalWrite(pin, LOW); // lower that channel
	temp = wiringPiSPIDataRW(channel % 2, tempMessage, 32 + 2);
	digitalWrite(pin, HIGH); // raise that channel
	
	return temp;
}

int initDisplay(unsigned char channel, unsigned char master) {
	
	int i, pin; 
    unsigned char clear[32]; 
    for(i = 0; i < 32; i++) clear[i] = 0x00;
	
	wiringPiSetup();
	
	switch (LED_DISPLAY_NUM)
	{
		case 4:
			pinMode(LED_DISPLAY_CS4, OUTPUT) ;
			digitalWrite(LED_DISPLAY_CS4, HIGH);
		case 3:
			pinMode(LED_DISPLAY_CS3, OUTPUT) ;
			digitalWrite(LED_DISPLAY_CS3, HIGH);
		case 2:
			pinMode(LED_DISPLAY_CS2, OUTPUT) ;
			digitalWrite(LED_DISPLAY_CS2, HIGH);
		case 1:
			pinMode(LED_DISPLAY_CS1, OUTPUT) ;
			digitalWrite(LED_DISPLAY_CS1, HIGH);
			break;
	}
	
	wiringPiSPISetup(channel % 2, 1000000); // SPI, 1MHz
	
	// initialisation order taken from http://timewitharduino.blogspot.co.uk/2011/10/difference-between-3208-and-0832-led.html
	writeCommand(channel, HT1632_CMD_SYSDIS); // system disable 
    writeCommand(channel, HT1632_CMD_COMS00); // NMOS 08 x 32  for HT1632C
	//writeCommand(channel, HT1632_CMD_COMS10); // PMOS 08 x 32  for HT1632
    if(master == 1)
	{
		//writeCommand(channel, HT1632_CMD_MSTMD); // enable master mode
		writeCommand(channel, HT1632_CMD_RCCLK);  // HT1632C only command
	}
	else
	{
		writeCommand(channel, HT1632_CMD_SLVMD); // enable slave mode
		//writeCommand(channel, HT1632_CMD_EXTCLK);  // HT1632C only command
	}
    
    writeCommand(channel, HT1632_CMD_SYSON); // enable system 
    writeCommand(channel, HT1632_CMD_LEDON); // enable LEDs 
    writeCommand(channel, HT1632_CMD_PWM | 0x0F); // set brightness (16/16)
	
	
	// need to duplicate for 2nd, 3rd & 4th CE
	i = writeDisplay(channel, clear); // clears display
	
	return i;
}

 
