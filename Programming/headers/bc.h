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
#ifndef BC_H
#define BC_H

#ifdef __cplusplus
extern "C" {
#endif
//
//screen status value determination functions
//
Uint8 Get_BC_Screen_val();
void BC_ScreenInit();
//
//update screen values
//
void BC_UP_update();
void BC_DOWN_update();
//
//bitmap pickers
//
void bc_main(unsigned int i);
void bc_1k(unsigned int i);
void bc_2k(unsigned int i);
void bc_3k(unsigned int i);
void bc_back(unsigned int i);
void BC_blank(unsigned int i);
//
//BR_screen prepare function
//
Uint8* BC_screenmap();

#ifdef __cplusplus
}
#endif
#endif  // end of F2802x_I2C_DEFINES_H definition

//
//        END OF FILE
//
