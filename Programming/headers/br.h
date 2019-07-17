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

#include <stdint.h>
#ifndef BR_H
#define BR_H

#ifdef __cplusplus
extern "C" {
#endif
//typedef unsigned char Uint8;
//
//Byte invert
//
//Uint8 Byte_Invert(Uint8 i);
//
//screen status value determination functions
//
Uint8 Get_BR_Screen_val();
void BR_ScreenInit();
//
//UPDATE VALUES
//
void BR_UP_update();
void BR_DOWN_update();
//
//bitmap pickers
//
void br_main(unsigned int i);
void br_1k(unsigned int i);
void br_2k(unsigned int i);
void br_3k(unsigned int i);
void br_4k(unsigned int i);
void br_5k(unsigned int i);
void br_back(unsigned int i);
void br_blank(unsigned int i);
//
//BR_screen prepare function
//
Uint8* BR_screenmap();

#ifdef __cplusplus
}
#endif

#endif  // end of F2802x_I2C_DEFINES_H definition

//
//        END OF FILE
