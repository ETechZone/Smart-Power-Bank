/* 
************************* Heder file for Display Icon status *****************************
*/
//##############################################################
//       File Name : icon.h
//       
//       TITLE     : Sh1106 oled with c2000(F28027)
//       
//       Development Kit : LAUNCHXL F28027
// 
//       Date Of Created : 07/05/2019 
//###############################################################
//
//                       Included files
//
//#include <stdint.h>
#ifndef ICON_H
#define ICON_H

#ifdef __cplusplus
extern "C"
{
#endif
//
// Defines
//
typedef unsigned char Uint8;
//
//bitmap for the current bitmap
//
static unsigned char Current_Screen[1024];
static unsigned char Setting_Icon_status;
static unsigned char* Current_Screen_ptr;
//
//Screes status variable
//
union Screen{
	Uint8 status;
};
struct Home_parameters{
    long int minutes;
    long int watt_hour;
    Uint8 percentage;
    float temp;
    int in_watt;
    int out_watt;
};
//
// screen levels
//


//
//   global functions
//
void Icon_Update_Status(unsigned char i);     // To update the status regarding the icon

unsigned char Icon_Read_Status();             // To read the status regarding the icon

unsigned char Byte_Invert(unsigned char i);           // for inverting a byte

void blank(unsigned int i);           // blank screen for BC, BR & Settings Screen

//
//  End off global functions
//

#ifdef __cplusplus
}
#endif

//
//
//
#endif  // end of F2802x_I2C_DEFINES_H definition

//
//        END OF FILE
//
