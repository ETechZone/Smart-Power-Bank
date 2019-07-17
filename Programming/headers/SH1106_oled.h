/* 
************************* Heder file for OLED display*****************************
*/
//##############################################################
//       File Name : Sh1106_Oled.h
//       
//       TITLE     : Sh1106 oled with c2000(F28027)
//       
//       Development Kit : LAUNCHXL F28027
// 
//       Date Of Created : 03/05/2019 
//###############################################################
//
//                       Included files
//
#ifndef SH1106_OLED_H
#define	SH1106_OLED_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "F2802x_Device.h"                      // F2806x Headerfile Include File
#include "F2802x_I2c_defines.h"                 // Macros used for I2C examples.

typedef unsigned char Uint8;                    // make Uint8 as unsigned char variable

#define SH1106_LCDWIDTH   128                  // Width of a SH1106 OLED
#define SH1106_LCDHEIGHT  64                   // Length of a SH1106 OLED

#define I2C_SLAVE_ADDR 0x3C                      // slave address 
#define I2C_PRESCALE_VAL 5                       // prescalar value
#define I2CCLKL_VAL 10				             // NOTE: must be non zero
#define I2CCLKH_VAL 5                            // NOTE : must be non zero

#define SH1106_CMD_MODE 0x00                   // OLED command initiate byte for SH1106
#define SH1106_DATA_MODE 0X40                  // OLED data initiate byte for SH1106

#define ERROR 0xFFFF
#define NO_ERROR 0X0000
//
//                     ASCII character set 
//

//#########################################################################
//                                   COMMANDS FOR SH1106 OLED
//#########################################################################
#define SH1106_SETCONTRAST 0x81
#define SH1106_DISPLAYALLON_RESUME 0xA4
#define SH1106_DISPLAYALLON 0xA5
#define SH1106_NORMALDISPLAY 0xA6
#define SH1106_INVERTDISPLAY 0xA7
#define SH1106_DISPLAYOFF 0xAE
#define SH1106_DISPLAYON 0xAF

#define SH1106_SETDISPLAYOFFSET 0xD3
#define SH1106_SETCOMPINS 0xDA

#define SH1106_SETVCOMDETECT 0xDB

#define SH1106_SETDISPLAYCLOCKDIV 0xD5
#define SH1106_SETPRECHARGE 0xD9

#define SH1106_SETMULTIPLEX 0xA8

#define SH1106_SETLOWCOLUMN 0x02 //to use with SSD1306, set to 0x00
#define SH1106_SETHIGHCOLUMN 0x10

#define SH1106_SETSTARTLINE 0x40

#define SH1106_MEMORYMODE 0x20
#define SH1106_COLUMNADDR 0x21
#define SH1106_PAGEADDR   0x22

#define SH1106_COMSCANINC 0xC0
#define SH1106_COMSCANDEC 0xC8

#define SH1106_SEGREMAP 0xA0

#define SH1106_CHARGEPUMP 0x8D

#define SH1106_EXTERNALVCC 0x01
#define SH1106_SWITCHCAPVCC 0x02

// Scrolling #defines
#define SH1106_ACTIVATE_SCROLL 0x2F
#define SH1106_DEACTIVATE_SCROLL 0x2E
#define SH1106_SET_VERTICAL_SCROLL_AREA 0xA3
#define SH1106_RIGHT_HORIZONTAL_SCROLL 0x26
#define SH1106_LEFT_HORIZONTAL_SCROLL 0x27
#define SH1106_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define SH1106_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A
//################################################################################
//                            End of I2C SH1106 COMMANDS
//################################################################################
//
//************************************************************************************
//        File Name     : oled_display.h
//        Date          : 29/04/2019
//        Description   : To develop prototypes for SH1106 I2C OLED
// ***********************************************************************************
//
 void __delay_ms(unsigned long t);
 void I2CGpio_Setup();                            // initial setup on GPIO32(SDA) and GPIO(SCL)
 void I2CInit_Oled(); 
 Uint8 Write_Command(Uint8* wdata, int wsize);   // used to write command in repeated mode
 void Oled_Command( Uint8 ch );                  // Oled command 
 void Oled_Init();                                // Oled intilization

 Uint8 Write_Data(Uint8* wdata, int wsize );
 void OledGotoYX(unsigned char Row, unsigned char Column);
 void OledPutChar( char ch );
 void OledClear();
 void OledPrint( char *s );
 void OledPutCharx(Uint8* ptrr1);
 void DrawBitMap(unsigned char Row, unsigned char Column, Uint8* wdata);
 void InvertDisplay(uint8_t i);
void ClearDisplay(void);                // yet to write
void InvertDisplay(uint8_t i);          // yet to write
void Display();                         // yet to write
void OLED_clean();
//void OLED_Write_Data(X , Y, color);     // yet to write
#ifdef __cplusplus
}
#endif /* extern "C" */


#endif	/* SH1106_OLED_H*/
