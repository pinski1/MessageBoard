/** Commands for HT1632(C) LED Display driver chip
 * 
 */
#ifndef HT1632_h
#define HT1632_h

#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>

/* Display Settings */
#define LED_DISPLAY_NUM 4
#define LED_DISPLAY_CS1 10
#define LED_DISPLAY_CS2 11
#define LED_DISPLAY_CS3 5
#define LED_DISPLAY_CS4 6

#if(LED_DISPLAY_NUM > 4 | LED_DISPLAY_NUM < 1)
	#error "Displays must be between 1 and 4."
#endif

#define HT1632C // add C if that's your chip

/** \brief HT1632 Commands
 *  
 *  \details Taken from datasheet.
 */
#define HT1632_ID_CMD		0b100	// ID = 100 - Commands
#define HT1632_ID_RD		0b110	// ID = 110 - Read RAM
#define HT1632_ID_WR		0b101	// ID = 101 - Write RAM
#define HT1632_CMD_SYSDIS	0x00	// CMD = 0000-0000-x Turn off osc
#define HT1632_CMD_SYSON	0x01	// CMD = 0000-0001-x Enable system osc
#define HT1632_CMD_LEDOFF	0x02	// CMD = 0000-0010-x LEDs off
#define HT1632_CMD_LEDON	0x03	// CMD = 0000-0011-x LEDs on
#define HT1632_CMD_BLOFF	0x08	// CMD = 0000-1000-x Blink on
#define HT1632_CMD_BLON		0x09	// CMD = 0000-1001-x Blink off
#define HT1632_CMD_SLVMD	0x10	// CMD = 0001-0000-x Slave Mode
#define HT1632_CMD_MSTMD	0x14	// CMD = 0001-0100-x Master Mode
#define HT1632_CMD_RCCLK	0x18	// CMD = 0001-1000-x Use on-chip clock
#define HT1632_CMD_EXTCLK	0x1C	// CMD = 0001-1100-x Use external clock
#define HT1632_CMD_COMS00	0x20	// CMD = 0010-0000-x NMOS 8 x 32
#define HT1632_CMD_COMS01	0x24	// CMD = 0010-0100-x NMOS 16 x 24
#define HT1632_CMD_COMS10	0x28	// CMD = 0010-1000-x PMOS 8 x 32
#define HT1632_CMD_COMS11	0x2C	// CMD = 0010-1100-x PMOS 16 x 24
#define HT1632_CMD_PWM		0xA0	// CMD = 1010-PPPP-x PWM duty cycle

/** \brief Sends a command to a display.
 *  
 *  \param displayCommand Command to be sent to the display, see #defines.
 *  \return The return code from the underlying ioctl() function call. In this case anything >= 0 is good.
 *  
 *  \details One very important thing to note, either CE0 or CE1 MUST be lowered/raised, so write to displays 2 & 3 first.
 */
int writeCommand(unsigned char channel, unsigned char displayCommand);

/** \brief Writes 32 bytes of pixels to a display
 *  
 *  \param channel Which display to write to
 *  \param pixelColumns An array of 32 unsigned chars of pixel data, [0] is the first column, bit 7 is pixel 0
 *  \return The return code from the underlying ioctl() function call. In this case anything >= 0 is good.
 *  
 *  \details Pixels must be packed into 8bit chunks that will be sent over SPI. To avoid erronous pixels being transmitted and for efficiency the entire display is sent as one transfer. One problem with this is the last byte only contains 2 bits of valid pixel data but the next 4 bits are assumed to be valid by the HT1632 and thus must contain copies of the first 4 pixels. One very important thing to note, either CE0 or CE1 MUST be lowered/raised, so write to displays 2 & 3 first.
 */
int writeDisplay(unsigned char channel, unsigned char pixelColumns[]);

/** \brief Initialises a display
 *  
 *  \param channel Which display to write to
 *  \param master Is the display master or slave.
 *  \return The return code from the underlying ioctl() function calls. In this case anything >= 0 is good.
 *  
 *  \details Details
 */
int initDisplay(unsigned char channel, unsigned char master);

#endif
 
