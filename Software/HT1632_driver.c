#include <stdio.h>
#include <stdlib.h>
#include "font.h"
#include <string.h>
//#include <wiringPi.h>
//#include <wiringPiSPI.h>
#include "HT1632.h"

/**
 *  // argv[0] = display_write.c
	// argv[n] = '-s'
	// argv[n+1] = new speed
	// argv[m] = '-m'
	// argv[m+1] = 'blagh blagh'
 */
int main(int argc, char *argv[]) {

	int i, j, localCurrentChar, localCurrentColumn;
	int idString = 0;
	unsigned int speed = 500;
	int scrolling = 0;
	unsigned char buffer[32];
	
	for(i = 0; i < 32; i++) buffer[i] = 0x00;
	
	unsigned int currentChar = 0, currentColumn = 0;
	
	for(j = LED_DISPLAY_NUM-1; j  >= 0; j --)
	{
		i = (j == 0) ? 1 : 0;
		initDisplay(j, i); // channel j, master mode
	}
	
	
	//check arguments
	for(i = 1; i < argc; i++)
	{
		if(strcmp(argv[i], "-s") == 0)
		{
			speed = atoi(argv[i + 1]);
			if(speed < 0 || speed > 5000)
			{
				printf("Speed must be limited between 0 and 5000.\r\n");
				return 1;
			}
		}
		
		if(strcmp(argv[i], "-m") == 0)
		{
			idString = i + 1;
		}
	}
	
	if(idString == 0)
	{
		printf("Usage: %s [-s speed] -m 'text string'\r\n", argv[0]);
		return 1;
	}

	
	scrolling = 1;
	while(scrolling)
	{
		localCurrentChar = currentChar;
		localCurrentColumn = currentColumn;
		
		// draw current display
		for(j = LED_DISPLAY_NUM - 1; j >= 0; j--)
		{
			
			// draw current frame
			for(i = 0; i < 32; i++)
			{
				if(localCurrentChar == 0 && localCurrentColumn == 0 && i == 31 && j == 0 && speed == 0) scrolling = 0;
				if(localCurrentChar >= 0 && localCurrentChar < strlen(argv[idString])) // to check it is not nonsense
				{
					buffer[31-i] = font_5x7[argv[idString][localCurrentChar] - 32][localCurrentColumn];
				}
				else
				{
					buffer[31-i] = 0x00;
				}
				
				if(currentChar > (strlen(argv[idString]) + (6*LED_DISPLAY_NUM) + 1)) scrolling = 0; // dirty FILTHY hack
									
			
				if(localCurrentColumn == 0)
				{
					localCurrentColumn = 4;
					localCurrentChar -= 1;
				}
				else
				{
					localCurrentColumn -= 1;
				}
			
			}
		
			writeDisplay(j, buffer); // send text to display
		}
		
		// setup start points for next frame
		if(currentColumn == 4)
		{
			currentColumn = 0;
			currentChar += 1;
		}
		else
		{
			currentColumn += 1;
		}
		
		delay(speed);
	}
	
	return 0;
}
