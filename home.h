/* 
************************* Heder file for Display Icon status *****************************
*/
//##############################################################
//       File Name : home.h
//       
//       TITLE     : Sh1106 oled with c2000(F28027)
//       
//       Development Kit : LAUNCHXL F28027
// 
//       Date Of Created : 17/05/2019 
//###############################################################
//
//                       Included files
//
#include <stdint.h>
#ifndef HOME_H
#define HOME_H

#ifdef __cplusplus
extern "C" {
#endif
void Update_logo(unsigned int page, unsigned int coloumn, unsigned char logo);
void Top_line_Update(unsigned int page, unsigned int coloumn, unsigned int num);
void bottom_line_Update( unsigned int coloumn, unsigned int num);
//
//To update indipendent variable
//
void Home_var1(unsigned int i);
void Home_var2(unsigned int i);
void Home_var3(unsigned int i);
void Home_var4(unsigned char i);
void fill_battary(unsigned char k);
void Home_var5(int i);
void Home_var6(int i);
void Home_var7(float i);

void min_update(unsigned int i);
void watt_hour_update(unsigned int i);
void percentage_update(unsigned int i);
void temp_update(unsigned int i);
void inwatt_update(unsigned int i);
void outwatt_update(unsigned int i);
void Home_var_intial_update();
//
// To draw the home screen
//
unsigned char* Home_draw();
unsigned char* battary_draw(int i,int k);
void battary_charge();
unsigned char* blank_draw();
#ifdef __cplusplus
}
#endif
#endif  // end of F2802x_I2C_DEFINES_H definition
