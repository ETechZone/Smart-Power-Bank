/* 
************************* Heder file for OLED display*****************************
*/

//##############################################################
//       File Name : Sh1106_Oled.c
//       
//       TITLE     : Sh1106 oled with c2000(F28027)
//       
//       Development Kit : LAUNCHXL F28027
// 
//       Date Of Created : 03/05/2019 
//###############################################################
//
// Included Files
//
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "F2802x_PieCtrl.h"
#include "F2802x_I2c.h"
#include "DSP28x_Project.h"     // Device Header file and Examples Include File
#include "F2802x_Device.h"     // F2802x Header file Include File
#include "Sh1106_Oled.h"       // for OLED initilization

//
//      End of Included files
//
//typedef unsigned char Uint8;
const Uint8 OledFont[][8] =
{
    // starts form space
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x00,0x5F,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x00,0x07,0x00,0x07,0x00,0x00,0x00},
  {0x00,0x14,0x7F,0x14,0x7F,0x14,0x00,0x00},
  {0x00,0x24,0x2A,0x7F,0x2A,0x12,0x00,0x00},
  {0x00,0x23,0x13,0x08,0x64,0x62,0x00,0x00},
  {0x00,0x36,0x49,0x55,0x22,0x50,0x00,0x00},
  {0x00,0x00,0x05,0x03,0x00,0x00,0x00,0x00},
  {0x00,0x1C,0x22,0x41,0x00,0x00,0x00,0x00},
  {0x00,0x41,0x22,0x1C,0x00,0x00,0x00,0x00},
  {0x00,0x08,0x2A,0x1C,0x2A,0x08,0x00,0x00},
  {0x00,0x08,0x08,0x3E,0x08,0x08,0x00,0x00},
  {0x00,0xA0,0x60,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x08,0x08,0x08,0x08,0x08,0x00,0x00},
  {0x00,0x60,0x60,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x20,0x10,0x08,0x04,0x02,0x00,0x00},
  {0x00,0x3E,0x51,0x49,0x45,0x3E,0x00,0x00},
  {0x00,0x00,0x42,0x7F,0x40,0x00,0x00,0x00},//0
  {0x00,0x62,0x51,0x49,0x49,0x46,0x00,0x00},//1
  {0x00,0x22,0x41,0x49,0x49,0x36,0x00,0x00},//2
  {0x00,0x18,0x14,0x12,0x7F,0x10,0x00,0x00},//3
  {0x00,0x27,0x45,0x45,0x45,0x39,0x00,0x00},//4
  {0x00,0x3C,0x4A,0x49,0x49,0x30,0x00,0x00},//5
  {0x00,0x01,0x71,0x09,0x05,0x03,0x00,0x00},//6
  {0x00,0x36,0x49,0x49,0x49,0x36,0x00,0x00},//7
  {0x00,0x06,0x49,0x49,0x29,0x1E,0x00,0x00},//8
  {0x00,0x00,0x36,0x36,0x00,0x00,0x00,0x00},//9
  {0x00,0x00,0xAC,0x6C,0x00,0x00,0x00,0x00},
  {0x00,0x08,0x14,0x22,0x41,0x00,0x00,0x00},
  {0x00,0x14,0x14,0x14,0x14,0x14,0x00,0x00},
  {0x00,0x41,0x22,0x14,0x08,0x00,0x00,0x00},
  {0x00,0x02,0x01,0x51,0x09,0x06,0x00,0x00},
  {0x00,0x32,0x49,0x79,0x41,0x3E,0x00,0x00},
  {0x00,0x7E,0x09,0x09,0x09,0x7E,0x00,0x00},
  {0x00,0x7F,0x49,0x49,0x49,0x36,0x00,0x00},
  {0x00,0x3E,0x41,0x41,0x41,0x22,0x00,0x00},
  {0x00,0x7F,0x41,0x41,0x22,0x1C,0x00,0x00},
  {0x00,0x7F,0x49,0x49,0x49,0x41,0x00,0x00},
  {0x00,0x7F,0x09,0x09,0x09,0x01,0x00,0x00},
  {0x00,0x3E,0x41,0x41,0x51,0x72,0x00,0x00},
  {0x00,0x7F,0x08,0x08,0x08,0x7F,0x00,0x00},
  {0x00,0x41,0x7F,0x41,0x00,0x00,0x00,0x00},
  {0x00,0x20,0x40,0x41,0x3F,0x01,0x00,0x00},
  {0x00,0x7F,0x08,0x14,0x22,0x41,0x00,0x00},
  {0x00,0x7F,0x40,0x40,0x40,0x40,0x00,0x00},
  {0x00,0x7F,0x02,0x0C,0x02,0x7F,0x00,0x00},
  {0x00,0x7F,0x04,0x08,0x10,0x7F,0x00,0x00},
  {0x00,0x3E,0x41,0x41,0x41,0x3E,0x00,0x00},
  {0x00,0x7F,0x09,0x09,0x09,0x06,0x00,0x00},
  {0x00,0x3E,0x41,0x51,0x21,0x5E,0x00,0x00},
  {0x00,0x7F,0x09,0x19,0x29,0x46,0x00,0x00},
  {0x00,0x26,0x49,0x49,0x49,0x32,0x00,0x00},
  {0x00,0x01,0x01,0x7F,0x01,0x01,0x00,0x00},
  {0x00,0x3F,0x40,0x40,0x40,0x3F,0x00,0x00},
  {0x00,0x1F,0x20,0x40,0x20,0x1F,0x00,0x00},
  {0x00,0x3F,0x40,0x38,0x40,0x3F,0x00,0x00},
  {0x00,0x63,0x14,0x08,0x14,0x63,0x00,0x00},
  {0x00,0x03,0x04,0x78,0x04,0x03,0x00,0x00},
  {0x00,0x61,0x51,0x49,0x45,0x43,0x00,0x00},
  {0x00,0x7F,0x41,0x41,0x00,0x00,0x00,0x00},
  {0x00,0x02,0x04,0x08,0x10,0x20,0x00,0x00},
  {0x00,0x41,0x41,0x7F,0x00,0x00,0x00,0x00},
  {0x00,0x04,0x02,0x01,0x02,0x04,0x00,0x00},
  {0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00},
  {0x00,0x01,0x02,0x04,0x00,0x00,0x00,0x00},
  {0x00,0x20,0x54,0x54,0x54,0x78,0x00,0x00},
  {0x00,0x7F,0x48,0x44,0x44,0x38,0x00,0x00},
  {0x00,0x38,0x44,0x44,0x28,0x00,0x00,0x00},
  {0x00,0x38,0x44,0x44,0x48,0x7F,0x00,0x00},
  {0x00,0x38,0x54,0x54,0x54,0x18,0x00,0x00},
  {0x00,0x08,0x7E,0x09,0x02,0x00,0x00,0x00},
  {0x00,0x18,0xA4,0xA4,0xA4,0x7C,0x00,0x00},
  {0x00,0x7F,0x08,0x04,0x04,0x78,0x00,0x00},
  {0x00,0x00,0x7D,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x80,0x84,0x7D,0x00,0x00,0x00,0x00},
  {0x00,0x7F,0x10,0x28,0x44,0x00,0x00,0x00},
  {0x00,0x41,0x7F,0x40,0x00,0x00,0x00,0x00},
  {0x00,0x7C,0x04,0x18,0x04,0x78,0x00,0x00},
  {0x00,0x7C,0x08,0x04,0x7C,0x00,0x00,0x00},
  {0x00,0x38,0x44,0x44,0x38,0x00,0x00,0x00},
  {0x00,0xFC,0x24,0x24,0x18,0x00,0x00,0x00},
  {0x00,0x18,0x24,0x24,0xFC,0x00,0x00,0x00},
  {0x00,0x00,0x7C,0x08,0x04,0x00,0x00,0x00},
  {0x00,0x48,0x54,0x54,0x24,0x00,0x00,0x00},
  {0x00,0x04,0x7F,0x44,0x00,0x00,0x00,0x00},
  {0x00,0x3C,0x40,0x40,0x7C,0x00,0x00,0x00},
  {0x00,0x1C,0x20,0x40,0x20,0x1C,0x00,0x00},
  {0x00,0x3C,0x40,0x30,0x40,0x3C,0x00,0x00},
  {0x00,0x44,0x28,0x10,0x28,0x44,0x00,0x00},
  {0x00,0x1C,0xA0,0xA0,0x7C,0x00,0x00,0x00},
  {0x00,0x44,0x64,0x54,0x4C,0x44,0x00,0x00},
  {0x00,0x08,0x36,0x41,0x00,0x00,0x00,0x00},
  {0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x41,0x36,0x08,0x00,0x00,0x00,0x00},
  {0x00,0x02,0x01,0x01,0x02,0x01,0x00,0x00},
  {0x00,0x02,0x05,0x05,0x02,0x00,0x00,0x00}
};
//
//*********************************************************************************************
//Function Name    : 1. void __delay_ms(unsigned long t)
//No.Of Parameters : 1
//Parameters Type  : unsigned long
//Return Type      : void 
//Description      : To delay controller for some duration of time
//**********************************************************************************************
//
void __delay_ms(unsigned long t)
{
	unsigned long i;
	for (i=0;i<t;i++)
		DSP28x_usDelay(1000);	              //usDelay
}


//
//*********************************************************************************************
//Function Name    : 2.I2CGpio_Setup()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : void 
//Description      : To initialize GPIO's that are necessary for the I2C communication
//**********************************************************************************************
//

void I2CGpio_Setup(){
	EALLOW;                                 // To allow writings on EALLOW protected registers 
	
	// 1. enable multiplexing on respective gpio's
    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 1;    // Configure GPIO32 for SDAA
    GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 1;    // Configure GPIO33 for SCLA
	
    // 2. respective pull-up should be enable 
    GpioCtrlRegs.GPBPUD.bit.GPIO32 = 0;     // Enable pull-up for GPIO32 (SDAA)
    GpioCtrlRegs.GPBPUD.bit.GPIO33 = 0;     // Enable pull-up for GPIO33 (SCLA)

    // 3. set qualification to '3' i.e asynchronous mode 
    GpioCtrlRegs.GPBQSEL1.bit.GPIO32 = 3;   // Asynchronous input GPIO32 (SDAA)
    GpioCtrlRegs.GPBQSEL1.bit.GPIO33 = 3;   // Asynchronous input GPIO33 (SCLA)
	
	EDIS;                                   // To toggle EALLOW bit to prevent spurious writings
}

//
//*********************************************************************************************
//Function Name    : 3.I2CInit_OLED()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : void 
//Description      : To initialize I2c registers that are necessary for the I2C communication
//**********************************************************************************************
//
void I2CInit_Oled()
{
   // 1. I2c mode register bits 
	I2caRegs.I2CMDR.all = 0x0000;                                 // IRS = 0 in I2CMDR
	
	// 2. set I2C slave address to I2CSAR register
	I2caRegs.I2CSAR = I2C_SLAVE_ADDR;                             // To set 0x3C as I2C slave address
	                              
	// 3. set all I2C interrupts disable 
	I2caRegs.I2CIER.all = 0x0000;	                              // disable all i2c interrupts
	
    // 4. I2c Pre-scaler set	
	/*
	// for F28027 device SYSCLK0UT = 60MHz
	//  ----------------------------------------
	// I2C module clock = SYSCLKOUT /(IPSC + 1)                   // To get i2c clock to 7-12 MHz IPSC should be 5 
	// -----------------------------------------
	                 -  I2C_clock  = 60MHz/(5+1)
					 -  I2C_clock  = 10MHz
	*/
    I2caRegs.I2CPSC.all = I2C_PRESCALE_VAL;		    		      // Prescaler - need 7-12 Mhz on module clk
	
    // 5. I2c ICCL & ICCH set
	/*
	//   For IPSC > 1  "d" should be 5(d = 5)
	//  -------------------------------------------------------
	//   Tm = (IPSC + 1)[(ICCLKL + d) + (ICCLKH + d)]/ SYSCLKOUT
	// --------------------------------------------------------
	//   Tm = (5 + 1)[(10 + 5) + (5 + 5)]/ 60MHz
	//   Tm = 2.5us "fit for 400KHz i2c device."
	//
	*/
	I2caRegs.I2CCLKL = I2CCLKL_VAL;					              // NOTE: must be non zero
    I2caRegs.I2CCLKH = I2CCLKH_VAL;					              // NOTE: must be non zero
	
	//  6.  I2C interrupts enable register
	I2caRegs.I2CIER.all = 0x0024;                                 // Enable SCD & ARDY interrupts

    // 7. Take I2C out of reset. Stop I2C when suspended 
    I2caRegs.I2CMDR.all = 0x0620;                                 // i.e IRS = 1 in I2CMDR register  and setting the module as master transmitter                    
  
    // 8. Enable FIFO transmission and reception
    I2caRegs.I2CFFTX.all = 0x6000;                                // Enable FIFO mode and TXFIFO
    I2caRegs.I2CFFRX.all = 0x0000;                                // Enable RXFIFO, clear RXFFINT,

}


//
//*********************************************************************************************
//Function Name    : 4. Write_Command(Uint8* wdata, int wsize)
//No.Of Parameters : 2
//Parameters Type  :  1. pointer to a unsigned char,
//					  2. int
//Return Type      : Uint8 
//Description      : To write command on to the I2C wire with respective address
//**********************************************************************************************
//
Uint8 Write_Command(Uint8* wdata, int wsize )
{
Uint16 i;
    I2caRegs.I2CSAR = I2C_SLAVE_ADDR;           			// I2C slave address
    I2caRegs.I2CCNT = wsize; 	                            // Setup number of bytes to send
	if(I2caRegs.I2CSTR.bit.BB==0)
	{
  	I2caRegs.I2CMDR.all = 0x66A0; 		
for (i=0; i<wsize; i++)
	{
		I2caRegs.I2CDXR = *(wdata+i);                       //
		while(!I2caRegs.I2CSTR.bit.XRDY);                   // checking for the I2C byte send
		}
	I2caRegs.I2CMDR.bit.STP = 1;	                       // manual set of Stop
	while(I2caRegs.I2CMDR.bit.STP == 1);
   if (I2caRegs.I2CSTR.bit.NACK == 1)	                   // Set stop bit & return error if
   {									                   //    NACK received
      I2caRegs.I2CMDR.bit.STP = 1;                         //  I2C communication end with not successful
      return ERROR;
        }
   I2caRegs.I2CMDR.bit.STP = 1;                           //  I2C communication end with successful
   return NO_ERROR;
	    }
	return ERROR;
}

//
//*********************************************************************************************
//Function Name    : 5.OLEDCommand()
//No.Of Parameters : 1
//Parameters Type  : uint16_t
//Return Type      : void 
//Description      : To send command to OLED
//**********************************************************************************************
//
void Oled_Command( Uint8 ch )
{
    Uint8 bytes[2];
    bytes[0] = SH1106_CMD_MODE;
    bytes[1] = ch;
    Write_Data(bytes, 2);
}


//
//*********************************************************************************************
//Function Name    : 6. Oled_Init()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : void 
//Description      : To initialize GPIO's that are necessary for the I2C communication
//**********************************************************************************************
//
void Oled_Init(){
	Oled_Command( SH1106_DISPLAYOFF );                 // SH1106_DISPLAYOFF = 0XAE
	__delay_ms( 100 );
	Oled_Command( SH1106_SETDISPLAYCLOCKDIV );         // SH1106_SETDISPLAYCLOCKDIV =0xD5
	Oled_Command( 0x80 );                              // the suggested ratio 0x80
	__delay_ms( 100 );
	Oled_Command( SH1106_SETMULTIPLEX );               //SH1106_SETMULTIPLEX = 0xA8
	Oled_Command( 0x3F );                              // 3F for 64 pixel height OLED  
	__delay_ms( 100 );
	Oled_Command( SH1106_SETDISPLAYOFFSET );           //SH1106_SETDISPLAYOFFSET = 0xD3
	Oled_Command( 0x00 );                              // no offset
	__delay_ms( 100 );
	Oled_Command(SH1106_SETSTARTLINE | 0x00);          // SH1106_SETSTARTLINE = 0x40
	__delay_ms( 100 );
	Oled_Command( SH1106_CHARGEPUMP );                 // SH1106_CHARGEPUMP = 0x8D
	Oled_Command( 0x14 );                                            
	__delay_ms( 100 );
	Oled_Command( SH1106_MEMORYMODE );                 // SH1106_MEMORYMODE 0x20
	Oled_Command( 0x00 );                              // 0x0 act like ks0108
	__delay_ms( 100 );
				 
	Oled_Command(SH1106_SEGREMAP | 0x1);              // SH1106_SEGREMAP 0xA0
	Oled_Command(SH1106_COMSCANDEC);                  //SH1106_COMSCANDEC 0xC8
	Oled_Command(SH1106_SETCOMPINS);                  // SH1106_SETCOMPINS 0xDA
	Oled_Command(0x12);
	Oled_Command(SH1106_SETCONTRAST);                 // SH1106_SETCONTRAST 0x81
	Oled_Command(0xCF);
	Oled_Command(SH1106_SETPRECHARGE);                // SH1106_SETPRECHARGE 0xD9
	Oled_Command(0xF1);
	Oled_Command(SH1106_SETVCOMDETECT);               // SH1106_SETVCOMDETECT 0xDB
	Oled_Command(0x40);
	Oled_Command(SH1106_DISPLAYALLON_RESUME);         // SH1106_DISPLAYALLON_RESUME 0xA4
	Oled_Command(SH1106_NORMALDISPLAY);               // SH1106_NORMALDISPLAY 0xA6
	Oled_Command(SH1106_DISPLAYON);                   // SH1106_DISPLAYON 0xAF
}


//
//*********************************************************************************************
//Function Name    : 7. Write_Data(Uint8* wdata, int wsize)
//No.Of Parameters : 2
//Parameters Type  :  1. pointer to a unsigned char,
//					  2. int
//Return Type      : Uint8 
//Description      : To write data on to the I2C wire with respective address (repeated i2c used)
//**********************************************************************************************
//
Uint8 Write_Data(Uint8* wdata, int wsize )
{
	Uint16 i;

	I2caRegs.I2CSAR = I2C_SLAVE_ADDR;           			// I2C slave address
  //  while (I2caRegs.I2CSTR.bit.BB == 1);		// still busy?
    I2caRegs.I2CCNT = wsize;					           // Setup number of bytes to send
  	I2caRegs.I2CMDR.all = 0x66A0; 				           // STT=1 			:   0110 0110 1010 0000	RM, STT


	//start transfer of 4 bytes max
	for (i=0; i<wsize; i++)
		{
		I2caRegs.I2CDXR = *(wdata+i);
		while(!I2caRegs.I2CSTR.bit.XRDY);                 // checking for I2C byte sent
		}
	I2caRegs.I2CMDR.bit.STP = 1;	                      // manual set of Stop
	while(I2caRegs.I2CMDR.bit.STP == 1);		          // stop bit loop
	return NO_ERROR;
}


//
//*********************************************************************************************
//Function Name    : 8. void oledGotoYX(unsigned char Row, unsigned char Column)
//No.Of Parameters : 2
//Parameters Type  :  1. unsigned char,
//					  2. unsigned char
//Return Type      : void 
//Description      : To set the cursor position on the OLED
//**********************************************************************************************
//
void OledGotoYX(unsigned char Row, unsigned char Column)
{
    Oled_Command( 0xB0 + Row);                                 // 0xB0 for SH1106 OLED
    Oled_Command( 0x00 + ((8*Column & 0x0F) +0x02));                  // Lower Coloumn Address = 0x0000[Lower 4 bits]
    Oled_Command( 0x10 + ((8*Column>>4)&0x0F) );               // High Coloumn Address = 0x0001[Higher 4 bits]
}

//
//*********************************************************************************************
//Function Name    : 9. void oledPutChar( char ch )
//No.Of Parameters : 1
//Parameters Type  : char
//Return Type      : void 
//Description      : To put character on OLED
//**********************************************************************************************
//
void OledPutChar( char ch )
{
    if ( ( ch < 32 ) || ( ch > 127 ) )  ch = ' ';
    const Uint8 *base = &OledFont[ch - 32][0];
    Uint8 bytes[9];
    bytes[0] = SH1106_DATA_MODE;
    memmove( bytes + 1, base, 8 );
    Write_Data(bytes, 9);
}


//
//*********************************************************************************************
//Function Name    : 10. void OledClear()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : void 
//Description      : To clear the oled 
//**********************************************************************************************
//
void OledClear()
{
Uint16 row, col;
    for ( row = 0; row < 8; row++ ) {
        for ( col = 0; col < 16; col++ ) {
            OledGotoYX(row, col);                     // Setting cursor position
            OledPutChar( ' ' );                       // writing the space character on to OLED
        }
    }
}


//
//*********************************************************************************************
//Function Name    : 11. void OledPutCharx(Uint8* ptrr1)
//No.Of Parameters : 1
//Parameters Type  : Uint8*
//Return Type      : void
//Description      : To clear the OLED
//**********************************************************************************************
//
void OledPutCharx(Uint8* ptrr1){
    Uint16 i;
       Uint8 bytes[9];
        bytes[0] = SH1106_DATA_MODE;
        memmove( bytes + 1, ptrr1, 8 );
        for(i=0;i<8;i++){
            ptrr1++;
        }
        Write_Data(bytes, 9);                         // writing the data to OLED
}


//
//*********************************************************************************************
//Function Name    : 12. void DrawBitMap()
//No.Of Parameters : 3
//Parameters Type  : 1.unsigned char Row,
//                   2.unsigned char Column,
//                   3.Uint8* wdata
//Return Type      : void 
//Description      : To Draw bitmap with respective commands on the OLED
//**********************************************************************************************
//
void DrawBitMap(unsigned char Row, unsigned char Column, Uint8* wdata){
        Uint8 i;
        Uint16 row, col;
            for ( row = 0; row < 8; row++ ) {
                for ( col = 0; col < 16; col++ ) {
                    OledGotoYX( row, col );                        // setting the cursor position
                    OledPutCharx(wdata);                           // putting the WDATA on to OLED
                    for(i=0;i<8;i++){
                        wdata++;
                    }
                }
            }
	
}

//
//*********************************************************************************************
//Function Name    : 13. void OledPrint( char *s )
//No.Of Parameters : 1
//Parameters Type  : char *s
//Return Type      : void
//Description      : To print char on to OLED
//**********************************************************************************************
//
void OledPrint( char *s ){
    while (*s) OledPutChar( *s++);
}


//
//*********************************************************************************************
//Function Name    : 14. void InvertDisplay(Uint8 i)
//No.Of Parameters : 1
//Parameters Type  : Uint8
//Return Type      : void
//Description      : To invert OLED color
//**********************************************************************************************
//
void InvertDisplay(Uint8 i){
    if (i) {
          Oled_Command(SH1106_INVERTDISPLAY);                   // OLED command to invert display
      } else {
          Oled_Command(SH1106_NORMALDISPLAY);                  // OLED command to normal display
      }
}
void OLED_clean(){
            Uint16 row, col;
                for ( row = 0; row < 8; row++ ) {
                    for ( col = 0; col < 16; col++ ) {
                        OledGotoYX( row, col );                        // setting the cursor position
                        OledPutCharx(&OledFont[0][0]);                           // putting the WDATA on to OLED

                    }
                }
}
//
//     END of SH1106_Oled.c
//
