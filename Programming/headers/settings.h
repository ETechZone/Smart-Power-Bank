/* 
************************* Heder file for Display Icon status *****************************
*/
//##############################################################
//       File Name : settings.h
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
#ifndef SETTINGS_H
#define SETTINGS_H

#ifdef __cplusplus
extern "C"
{
#endif
typedef unsigned char Uint8;                    // make Uint8 as unsigned char variable

//
// global functions
//
Uint8 Get_SETTINGS_Screen_val();
void SETTINGS_ScreenInit();//void ScreenInit(Uint8 i);             // Screen initialization
//
//UPDATE SETTINGS VALUES
//
void SETTINGS_DOWN_update();
void SETTINGS_UP_update();

//
// Icon read status function
//
Uint8 Icon_Read_Status();             // To read the status regarding the icon
void Icon_Update_Status(Uint8 i);     // To update the status regarding the icon
void Icon_Update_Status1(Uint8 i);  //new
Uint8 Icon_Read_Status1(); //new
//
// Byte invert function
//
//Uint8 Byte_Invert(Uint8 i);
//
//    bitmaps for settings screen
//
void Settings_bitmap(unsigned int i);            // settings bitmap
void AC_bitmap(unsigned int  i);                 // AC bit map
void HUB_bitmap(unsigned int i);                 // Hub bitmap
void PASS_bitmap(unsigned int i,int m);
void BC_bitmap(unsigned int i);                  // BC bitmap
void BR_bitmap(unsigned int i);                  // BR bitmap
void Exit_bitmap(unsigned int i);                // Exit bitmap
void sett_blank(unsigned int i);

//
//end of bitmaps for settings screen
//
Uint8* Settings_Get_Bitmap();                    // Settings bitmap
#ifdef __cplusplus
}
#endif

#endif  // end of F2802x_I2C_DEFINES_H definition

//
//        END OF FILE
//
