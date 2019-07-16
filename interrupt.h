/* 
************************* Heder file for Display Icon status *****************************
*/
//##############################################################
//       File Name : interrupt.h
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
#ifndef INTERRUPT_H
#define INTERRUPT_H

#ifdef __cplusplus
extern "C" {
#endif

union Position{
    unsigned char pos;
};

//
void delay(unsigned int i);                       // delay for some time
void Refresh_screen();                            // refresh screen
//void BR_refresh();
//
//
//

void Home_screen_draw();
void setting_src_init();
//
// Power interrupt setup
//
void pwr_Int_setup();                             // power interrupt setup
void down_Int_set();                              // down interrupt setup
void up_Int_set();                                // up interrupt setup
//
//interrupt handles for different screens
//
void Settings_Int_Handle();                       // settings interrupt handle
//void BC_Int_Handle();                             // BC interrupt handle
//void BR_Int_Handle();                             // BR interrupt handle
//
//interrupt subroutine
//
__interrupt void Sett_pwr_isr(void);              // Power button interrupt setup
__interrupt void Sett_up_isr(void);               // Upword button interrupt setup
__interrupt void Sett_down_isr(void);             // Down button interrupt setup
void Batt_Screen_draw();
void AC_detect();
void Refresh_home();
void Up_var_of_home(int i);
void Batt_Screen_draw1();
#ifdef __cplusplus
}
#endif
#endif  // end of F2802x_I2C_DEFINES_H definition
