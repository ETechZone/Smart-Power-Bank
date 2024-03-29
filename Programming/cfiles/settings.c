/* 
************************* C file for Display Icon status*****************************
*/

//##############################################################
//       File Name : settings.c
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

#include<settings.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "Sh1106_Oled.h"
#include<icon.h>
//
// Global variables
//
union Screen sett_src;
int scr_var123=0x00;
//*********************************************************************************************
//Function Name    : void ScreenInit(Uint8 i)
//No.Of Parameters : 1
//Parameters Type  : Uint8(unsigned char)
//Return Type      : void
//Description      : To initialize Screen status
//**********************************************************************************************
//
void SETTINGS_ScreenInit(){
    sett_src.status =0x00;
}
//
//*********************************************************************************************
//Function Name    : Uint8 Get_SETTINGS_Screen_val()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : Uint8
//Description      : To Get global status of screen
//**********************************************************************************************
//
Uint8 Get_SETTINGS_Screen_val(){
    return sett_src.status;
}

//
//*********************************************************************************************
//Function Name    : void SETTINGS_DOWN_update()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : Uint8
//Description      : To Get global status of screen
//**********************************************************************************************
//
void SETTINGS_DOWN_update(){
    Uint8 i;
    i=Get_SETTINGS_Screen_val();
    i++;
    if(Get_SETTINGS_Screen_val()!=0x04)
    sett_src.status=i;
}
//
//*********************************************************************************************
//Function Name    : void SETTINGS_DOWN_update()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : Uint8
//Description      : To Get global status of screen
//**********************************************************************************************
//
void SETTINGS_UP_update(){
Uint8 i;
i=Get_SETTINGS_Screen_val();
i--;
if(Get_SETTINGS_Screen_val()!=0x00)
   sett_src.status=i;
}
//
//*********************************************************************************************
//Function Name    : Uint8* AC_bitmap()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : Uint8*
//Description      : To get bitmap of the AC related bitmap of the setting screen
//**********************************************************************************************
//


void Icon_Update_Status1(Uint8 i){
    if(scr_var123==i){
        scr_var123=0;
    }else {
    scr_var123=i;
    }
}
Uint8 Icon_Read_Status1(){
    return scr_var123;
}
void AC_bitmap(unsigned int i){
    Uint8 j;
    const Uint8 *ac_ptr;
    //
    // AC logo on and option highlighted
    //
    const Uint8 ac_high_on[]={
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x20, 0x20, 0xC0, 0x00, 0xC0, 0x20, 0x20,
    0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x01, 0x01, 0x0F, 0x00, 0x07, 0x08, 0x08,
    0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1E, 0x1E, 0x1E, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    //
    // AC logo off and option highlighted
    //
    const Uint8 ac_high_off[]={
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x20, 0x20, 0xC0, 0x00, 0xC0, 0x20, 0x20,
    0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x01, 0x01, 0x0F, 0x00, 0x07, 0x08, 0x08,
    0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    if(Icon_Read_Status()&0x01)
        ac_ptr =&ac_high_on[0];
    else
        ac_ptr=&ac_high_off[0];
    for(j=0;j<256;j++,i++)
        Current_Screen[i] = *(ac_ptr+j);
}

//
//*********************************************************************************************
//Function Name    : Uint8* HUB_bitmap()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : Uint8*
//Description      : To get bitmap of the HUB related bitmap of the setting screen
//**********************************************************************************************
//
void HUB_bitmap(unsigned int i){
    //
    // HUB logo off and option highlighted
    //
   Uint8 j,k;
   const Uint8 *hub_ptr;
   const Uint8 hub_high_off[]={
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0xE0, 0x00, 0x00,
    0xE0, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x01, 0x01, 0x0F, 0x00, 0x0F, 0x08, 0x08,
    0x0F, 0x00, 0x0F, 0x09, 0x09, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };


    //
    // HUB logo on and option highlighted
    //
   const Uint8 hub_high_on[]={
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0xE0, 0x00, 0x00,
    0xE0, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x30, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x30, 0x40, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x01, 0x01, 0x0F, 0x00, 0x0F, 0x08, 0x08,
    0x0F, 0x00, 0x0F, 0x09, 0x09, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x18, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x10, 0x10, 0x10, 0x10, 0x10, 0x18, 0x08, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };



    Uint8 reverse_bitmap[256];
    if(Icon_Read_Status()&0x02){
        for(k=0;k<256;k++)
             reverse_bitmap[k]  = Byte_Invert(hub_high_on[k]);
      }
    else{
        for(k=0;k<256;k++)
             reverse_bitmap[k]  = Byte_Invert(hub_high_off[k]);
      }
    if(Get_SETTINGS_Screen_val()==0x01){
            if(Icon_Read_Status()&0x02)
                hub_ptr= &hub_high_on[0];
            else
                hub_ptr= &hub_high_off[0];
    }
    else{
               hub_ptr= &reverse_bitmap[0];
    }
       for(j=0;j<256;j++,i++)
           Current_Screen[i] = *(hub_ptr+j);
}
//
//*********************************************************************************************
//Function Name    : Uint8* PASS_bitmap()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : Uint8*
//Description      : To get bitmap of the HUB related bitmap of the setting screen
//**********************************************************************************************
//
void PASS_bitmap(unsigned int i,int m){
    //
    // PASS logo off and option highlighted
    //
   Uint8 j,k;
   const Uint8 *pass_ptr;
   const Uint8 Pass_high_off[]={
                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xE0, 0x20, 0x20,
                                0xC0, 0x00, 0x20, 0xE0, 0x20, 0x00, 0xC0, 0x20, 0x20, 0xC0, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00,
                                0x20, 0xE0, 0x20, 0x00, 0x20, 0x20, 0xE0, 0x20, 0x20, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00,
                                0x00, 0x00, 0xC0, 0x20, 0x20, 0x20, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0xC0, 0x20, 0x20, 0xC0,
                                0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xC0, 0x20, 0x20, 0x40, 0x00, 0xE0, 0x20, 0x20, 0x20, 0x00,
                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x20, 0x20, 0xC0, 0x00,
                                0xE0, 0x20, 0x20, 0x20, 0x00, 0xE0, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x01, 0x01, 0x00, 0x00, 0x0F, 0x01, 0x01,
                                0x0E, 0x00, 0x08, 0x0F, 0x08, 0x00, 0x07, 0x08, 0x08, 0x07, 0x00, 0x0F, 0x01, 0x01, 0x0E, 0x00,
                                0x08, 0x0F, 0x08, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0E, 0x01, 0x00, 0x00,
                                0x00, 0x00, 0x07, 0x08, 0x08, 0x08, 0x00, 0x0F, 0x01, 0x01, 0x0F, 0x00, 0x0F, 0x01, 0x01, 0x0F,
                                0x00, 0x0F, 0x01, 0x01, 0x0E, 0x00, 0x07, 0x08, 0x0A, 0x0E, 0x00, 0x0F, 0x09, 0x09, 0x08, 0x00,
                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x08, 0x07, 0x00,
                                0x0F, 0x01, 0x01, 0x00, 0x00, 0x0F, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };


    //
    // HUB logo on and option highlighted
    //
   const Uint8 pass_high_on[]={
                               0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xE0, 0x20, 0x20,
                               0xC0, 0x00, 0x20, 0xE0, 0x20, 0x00, 0xC0, 0x20, 0x20, 0xC0, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00,
                               0x20, 0xE0, 0x20, 0x00, 0x20, 0x20, 0xE0, 0x20, 0x20, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00,
                               0x00, 0x00, 0xC0, 0x20, 0x20, 0x20, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0xC0, 0x20, 0x20, 0xC0,
                               0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xC0, 0x20, 0x20, 0x40, 0x00, 0xE0, 0x20, 0x20, 0x20, 0x00,
                               0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                               0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0,
                               0x20, 0x20, 0xC0, 0x00, 0xE0, 0x40, 0x80, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                               0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x01, 0x01, 0x00, 0x00, 0x0F, 0x01, 0x01,
                               0x0E, 0x00, 0x08, 0x0F, 0x08, 0x00, 0x07, 0x08, 0x08, 0x07, 0x00, 0x0F, 0x01, 0x01, 0x0E, 0x00,
                               0x08, 0x0F, 0x08, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0E, 0x01, 0x00, 0x00,
                               0x00, 0x00, 0x07, 0x08, 0x08, 0x08, 0x00, 0x0F, 0x01, 0x01, 0x0F, 0x00, 0x0F, 0x01, 0x01, 0x0F,
                               0x00, 0x0F, 0x01, 0x01, 0x0E, 0x00, 0x07, 0x08, 0x0A, 0x0E, 0x00, 0x0F, 0x09, 0x09, 0x08, 0x00,
                               0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                               0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
                               0x08, 0x08, 0x07, 0x00, 0x0F, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
  Uint8 reverse_bitmap[256];
    if(m){
        for(k=0;k<256;k++)
             reverse_bitmap[k]  = Byte_Invert(pass_high_on[k]);
      }
    else{
        for(k=0;k<256;k++)
             reverse_bitmap[k]  = Byte_Invert(Pass_high_off[k]);
      }
    if(Get_SETTINGS_Screen_val()==0x02){
            if(m)
                pass_ptr= &pass_high_on[0];
            else
                pass_ptr= &Pass_high_off[0];
    }
    else{
               pass_ptr= &reverse_bitmap[0];
    }
       for(j=0;j<256;j++,i++)
           Current_Screen[i] = *(pass_ptr+j);
}
//
//*********************************************************************************************
//Function Name    : Uint8* BC_bitmap()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : Uint8*
//Description      : To get bitmap of the Battery Cycles part of the setting screen
//**********************************************************************************************
//

void  BC_bitmap(unsigned int i){
    //
    // Battery cycles logo HIGH and no.of cycles 500
    //
    Uint8 j,k;
    Uint8 BC_rev[256];
    const Uint8 *bc_ptr;
    const Uint8 bc_high_0k[]={
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xC0, 0x20, 0x20,
    0xC0, 0x00, 0x20, 0x20, 0xE0, 0x20, 0x20, 0x00, 0x20, 0x20, 0xE0, 0x20, 0x20, 0x00, 0xE0, 0x20,
    0x20, 0x20, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00,
    0x00, 0xC0, 0x20, 0x20, 0x20, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0xC0, 0x20, 0x20, 0x20,
    0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x20, 0x20, 0x20, 0x00, 0xC0, 0x20, 0x20, 0x40, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x20, 0x20, 0x20, 0x00, 0xC0,
    0x20, 0x20, 0xC0, 0x00, 0xC0, 0x20, 0x20, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x09, 0x09, 0x06, 0x00, 0x0F, 0x01, 0x01,
    0x0F, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x09,
    0x09, 0x08, 0x00, 0x0F, 0x01, 0x01, 0x0E, 0x00, 0x00, 0x01, 0x0E, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0F, 0x08, 0x08, 0x08, 0x00, 0x00, 0x01, 0x0E, 0x01, 0x00, 0x00, 0x07, 0x08, 0x08, 0x08,
    0x00, 0x0F, 0x08, 0x08, 0x08, 0x00, 0x0F, 0x09, 0x09, 0x08, 0x00, 0x04, 0x09, 0x09, 0x06, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x09, 0x09, 0x06, 0x00, 0x07,
    0x0A, 0x09, 0x07, 0x00, 0x07, 0x0A, 0x09, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    //
    // Battery cycles logo HIGH and no.of cycles 1000
    //
    const Uint8 bc_high_1k[]={
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xC0, 0x20, 0x20,
    0xC0, 0x00, 0x20, 0x20, 0xE0, 0x20, 0x20, 0x00, 0x20, 0x20, 0xE0, 0x20, 0x20, 0x00, 0xE0, 0x20,
    0x20, 0x20, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00,
    0x00, 0xC0, 0x20, 0x20, 0x20, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0xC0, 0x20, 0x20, 0x20,
    0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x20, 0x20, 0x20, 0x00, 0xC0, 0x20, 0x20, 0x40, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0xE0, 0x00, 0x00, 0xC0, 0x20, 0x20, 0xC0, 0x00, 0xC0,
    0x20, 0x20, 0xC0, 0x00, 0xC0, 0x20, 0x20, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x09, 0x09, 0x06, 0x00, 0x0F, 0x01, 0x01,
    0x0F, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x09,
    0x09, 0x08, 0x00, 0x0F, 0x01, 0x01, 0x0E, 0x00, 0x00, 0x01, 0x0E, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0F, 0x08, 0x08, 0x08, 0x00, 0x00, 0x01, 0x0E, 0x01, 0x00, 0x00, 0x07, 0x08, 0x08, 0x08,
    0x00, 0x0F, 0x08, 0x08, 0x08, 0x00, 0x0F, 0x09, 0x09, 0x08, 0x00, 0x04, 0x09, 0x09, 0x06, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0F, 0x08, 0x00, 0x07, 0x0A, 0x09, 0x07, 0x00, 0x07,
    0x0A, 0x09, 0x07, 0x00, 0x07, 0x0A, 0x09, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    //
    // Battery cycles logo HIGH and no.of cycles 2000
    //

    const Uint8 bc_high_2k[]={
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xC0, 0x20, 0x20,
    0xC0, 0x00, 0x20, 0x20, 0xE0, 0x20, 0x20, 0x00, 0x20, 0x20, 0xE0, 0x20, 0x20, 0x00, 0xE0, 0x20,
    0x20, 0x20, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00,
    0x00, 0xC0, 0x20, 0x20, 0x20, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0xC0, 0x20, 0x20, 0x20,
    0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x20, 0x20, 0x20, 0x00, 0xC0, 0x20, 0x20, 0x40, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x20, 0x20, 0xC0, 0x00, 0xC0, 0x20, 0x20, 0xC0, 0x00, 0xC0,
    0x20, 0x20, 0xC0, 0x00, 0xC0, 0x20, 0x20, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x09, 0x09, 0x06, 0x00, 0x0F, 0x01, 0x01,
    0x0F, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x09,
    0x09, 0x08, 0x00, 0x0F, 0x01, 0x01, 0x0E, 0x00, 0x00, 0x01, 0x0E, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0F, 0x08, 0x08, 0x08, 0x00, 0x00, 0x01, 0x0E, 0x01, 0x00, 0x00, 0x07, 0x08, 0x08, 0x08,
    0x00, 0x0F, 0x08, 0x08, 0x08, 0x00, 0x0F, 0x09, 0x09, 0x08, 0x00, 0x04, 0x09, 0x09, 0x06, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0A, 0x09, 0x08, 0x00, 0x07, 0x0A, 0x09, 0x07, 0x00, 0x07,
    0x0A, 0x09, 0x07, 0x00, 0x07, 0x0A, 0x09, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    switch(Icon_Read_Status()&0x0C){
        case 0x04:{
            if(Get_SETTINGS_Screen_val()==0x03){
                bc_ptr= &bc_high_1k[0];
            }
            else{
                for(k=0;k<256;k++)
                     BC_rev[k] = Byte_Invert(bc_high_1k[k]);
                bc_ptr= &BC_rev[0];
            }
            break;
        }
        case 0x08:{
            if(Get_SETTINGS_Screen_val()==0x03){
                  bc_ptr= &bc_high_2k[0];
            }
            else{
                for(k=0;k<256;k++)
                         BC_rev[k] = Byte_Invert(bc_high_2k[k]);
                bc_ptr= &BC_rev[0];
            }
            break;
        }
        default :{
            if(Get_SETTINGS_Screen_val()==0x03){
                bc_ptr= &bc_high_0k[0];
            }
            else{
                for(k=0;k<256;k++)
                  BC_rev[k] = Byte_Invert(bc_high_0k[k]);
                bc_ptr= &BC_rev[0];
            }
            break;
        }
    }
    for(j=0;j<256;j++,i++){
        Current_Screen[i] = *(bc_ptr+j);
             }
}

//
//*********************************************************************************************
//Function Name    : Uint8* BR_bitmap()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : Uint8*
//Description      : To get bitmap of the Battery Reserve part of the setting screen
//**********************************************************************************************
//

void  BR_bitmap(unsigned int i){
    //
    // Battery reserve logo enable and 1000 mah
    //
    const Uint8 br_high_1k[]={
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xC0, 0x20, 0x20,
    0xC0, 0x00, 0x20, 0x20, 0xE0, 0x20, 0x20, 0x00, 0x20, 0x20, 0xE0, 0x20, 0x20, 0x00, 0xE0, 0x20,
    0x20, 0x20, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00,
    0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xE0, 0x20, 0x20, 0x20, 0x00, 0xC0, 0x20, 0x20, 0x40, 0x00,
    0xE0, 0x20, 0x20, 0x20, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0xE0,
    0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0xE0, 0x00, 0x00, 0xC0, 0x20, 0x20, 0xC0, 0x00, 0xC0,
    0x20, 0x20, 0xC0, 0x00, 0xC0, 0x20, 0x20, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x09, 0x09, 0x06, 0x00, 0x0F, 0x01, 0x01,
    0x0F, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x09,
    0x09, 0x08, 0x00, 0x0F, 0x01, 0x01, 0x0E, 0x00, 0x00, 0x01, 0x0E, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0F, 0x01, 0x01, 0x0E, 0x00, 0x0F, 0x09, 0x09, 0x08, 0x00, 0x04, 0x09, 0x09, 0x06, 0x00,
    0x0F, 0x09, 0x09, 0x08, 0x00, 0x0F, 0x01, 0x01, 0x0E, 0x00, 0x07, 0x08, 0x08, 0x07, 0x00, 0x0F,
    0x09, 0x09, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0F, 0x08, 0x00, 0x07, 0x0A, 0x09, 0x07, 0x00, 0x07,
    0x0A, 0x09, 0x07, 0x00, 0x07, 0x0A, 0x09, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    //
    // Battery reserve logo enable and 2000 mah
    //
   const Uint8 br_high_2k[]={
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xC0, 0x20, 0x20,
    0xC0, 0x00, 0x20, 0x20, 0xE0, 0x20, 0x20, 0x00, 0x20, 0x20, 0xE0, 0x20, 0x20, 0x00, 0xE0, 0x20,
    0x20, 0x20, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00,
    0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xE0, 0x20, 0x20, 0x20, 0x00, 0xC0, 0x20, 0x20, 0x40, 0x00,
    0xE0, 0x20, 0x20, 0x20, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0xE0,
    0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x20, 0x20, 0xC0, 0x00, 0xC0, 0x20, 0x20, 0xC0, 0x00, 0xC0,
    0x20, 0x20, 0xC0, 0x00, 0xC0, 0x20, 0x20, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x09, 0x09, 0x06, 0x00, 0x0F, 0x01, 0x01,
    0x0F, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x09,
    0x09, 0x08, 0x00, 0x0F, 0x01, 0x01, 0x0E, 0x00, 0x00, 0x01, 0x0E, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0F, 0x01, 0x01, 0x0E, 0x00, 0x0F, 0x09, 0x09, 0x08, 0x00, 0x04, 0x09, 0x09, 0x06, 0x00,
    0x0F, 0x09, 0x09, 0x08, 0x00, 0x0F, 0x01, 0x01, 0x0E, 0x00, 0x07, 0x08, 0x08, 0x07, 0x00, 0x0F,
    0x09, 0x09, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0A, 0x09, 0x08, 0x00, 0x07, 0x0A, 0x09, 0x07, 0x00, 0x07,
    0x0A, 0x09, 0x07, 0x00, 0x07, 0x0A, 0x09, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    //
    // Battery reserve logo enable and 3000 mah reserve set
    //
    const Uint8 br_high_3k[]={
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xC0, 0x20, 0x20,
    0xC0, 0x00, 0x20, 0x20, 0xE0, 0x20, 0x20, 0x00, 0x20, 0x20, 0xE0, 0x20, 0x20, 0x00, 0xE0, 0x20,
    0x20, 0x20, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00,
    0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xE0, 0x20, 0x20, 0x20, 0x00, 0xC0, 0x20, 0x20, 0x40, 0x00,
    0xE0, 0x20, 0x20, 0x20, 0x00, 0xE0, 0x20, 0x20, 0xC0, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0xE0,
    0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x20, 0x20, 0xC0, 0x00, 0xC0, 0x20, 0x20, 0xC0, 0x00, 0xC0,
    0x20, 0x20, 0xC0, 0x00, 0xC0, 0x20, 0x20, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x09, 0x09, 0x06, 0x00, 0x0F, 0x01, 0x01,
    0x0F, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x09,
    0x09, 0x08, 0x00, 0x0F, 0x01, 0x01, 0x0E, 0x00, 0x00, 0x01, 0x0E, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0F, 0x01, 0x01, 0x0E, 0x00, 0x0F, 0x09, 0x09, 0x08, 0x00, 0x04, 0x09, 0x09, 0x06, 0x00,
    0x0F, 0x09, 0x09, 0x08, 0x00, 0x0F, 0x01, 0x01, 0x0E, 0x00, 0x07, 0x08, 0x08, 0x07, 0x00, 0x0F,
    0x09, 0x09, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x08, 0x09, 0x06, 0x00, 0x07, 0x0A, 0x09, 0x07, 0x00, 0x07,
    0x0A, 0x09, 0x07, 0x00, 0x07, 0x0A, 0x09, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

   // Uint8 status;
   const Uint8 *br_ptr;
    Uint8 BR_rev[256];
    Uint8 k,j;
    switch(Icon_Read_Status() & 0x30){
        case 0x10:{
            if(Get_SETTINGS_Screen_val()==0x04){
                br_ptr= &br_high_2k[0];
            }
            else{
                //br_ptr= &br_low_2k[0];
                for(k=0;k<256;k++){
                   BR_rev[k] = Byte_Invert(br_high_2k[k]);
                    }

                br_ptr= &BR_rev[0];
            }
            break;
        }
        case 0x20:{
            if(Get_SETTINGS_Screen_val()==0x04){
                br_ptr= &br_high_3k[0];
            }
            else{
                for(k=0;k<256;k++){
                    BR_rev[k] = Byte_Invert(br_high_2k[k]);
                       }
                   br_ptr= &BR_rev[0];
               // br_ptr= &br_low_3k[0];
            }
            break;
        }
        default:{
            if(Get_SETTINGS_Screen_val()==0x04){
                br_ptr= &br_high_1k[0];
            }
            else{
        //      br_ptr= &br_low_1k[0];
                for(k=0;k<256;k++){
                          BR_rev[k] = Byte_Invert(br_high_1k[k]);
                            }
                       br_ptr= &BR_rev[0];
            }
            break;
        }
    }
    for(j=0;j<256;j++,i++){
        Current_Screen[i] = *(br_ptr+j);
             }
}
//
//*********************************************************************************************
//Function Name    : Uint8* Exit_bitmap()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : Uint8*
//Description      : To get bitmap of the exit part of the setting screen
//**********************************************************************************************
//

void Exit_bitmap(unsigned int i){
    //
    // EXIT logo HIGH
    //
    Uint8 j;
    const Uint8 *exit_ptr;
    Uint8 exit_invert[256];
    //
    //    Exit logo LOW
    //
    const Uint8 exit_low[]={
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x6F, 0x6F, 0xEF, 0xFF, 0x8F, 0x7F, 0x7F,
    0x8F, 0xFF, 0xEF, 0x0F, 0xEF, 0xFF, 0xEF, 0xEF, 0x0F, 0xEF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xFB, 0xFB, 0xFB, 0xFF, 0xF8, 0xFF, 0xFF,
    0xF8, 0xFF, 0xFB, 0xF8, 0xFB, 0xFF, 0xFF, 0xFF, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
    };

    if(Get_SETTINGS_Screen_val()==0x04){
              for(j=0;j<256;j++){
                  exit_invert[j]=Byte_Invert(exit_low[j]);
              }
                exit_ptr= &exit_invert[0];
            }
            else{
                exit_ptr= &exit_low[0];
            }
         for(j=0;j<256;j++,i++){
             Current_Screen[i] = *(exit_ptr+j);
                }
}
//
//*********************************************************************************************
//Function Name    : void Blank_bitmap(unsigned int i)
//No.Of Parameters : 1
//Parameters Type  : unsigned int
//Return Type      : void
//Description      :
//**********************************************************************************************
//
/*
void Blank_bitmap(unsigned int i){
    //
    // Blank screen bmps
    //
    Uint8 j;

    for(j=0;j<256;j++,i++){
        Current_Screen[i] = 0xFF;
    }
}
*/
//
//*********************************************************************************************
//Function Name    : void Settings_bitmap(unsigned int i)
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : Uint8*
//Description      : To get bitmap of the exit part of the setting screen
//**********************************************************************************************
//
void Settings_bitmap(unsigned int i){
    Uint8 j;
    Uint8 settings[]={
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x6F, 0x6F, 0xDF,
        0xFF, 0x0F, 0x6F, 0x6F, 0xEF, 0xFF, 0xEF, 0xEF, 0x0F, 0xEF, 0xEF, 0xFF, 0xEF, 0xEF, 0x0F, 0xEF,
        0xEF, 0xFF, 0xEF, 0x0F, 0xEF, 0xFF, 0x0F, 0xDF, 0xBF, 0x0F, 0xFF, 0x1F, 0xEF, 0xEF, 0xDF, 0xFF,
        0x9F, 0x6F, 0x6F, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xFB, 0xFB, 0xFC,
        0xFF, 0xF8, 0xFB, 0xFB, 0xFB, 0xFF, 0xFF, 0xFF, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xFF,
        0xFF, 0xFF, 0xFB, 0xF8, 0xFB, 0xFF, 0xF8, 0xFF, 0xFF, 0xF8, 0xFF, 0xFC, 0xFB, 0xFA, 0xF8, 0xFF,
        0xFD, 0xFB, 0xFB, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        };
    for(j=i;j<256;j++,i++){
        Current_Screen[i]=settings[j];     // putting the settings bitmap into entire screen map
            }
}

void sett_blank(unsigned int i){
    Uint8 j;
    for(j=0;j<256;j++,i++){
        Current_Screen[i]=0xFF;
    }
}

//
//*********************************************************************************************
//Function Name    : Uint8* Settings_Get_Bitmap()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : Uint8*
//Description      : To get bitmap of the settings screen
//**********************************************************************************************
//
Uint8* Settings_Get_Bitmap(){
    //
    // settings bmps
    //

    Current_Screen_ptr=&Current_Screen[0];// initializing the pointer with base address of array
    Settings_bitmap(0);
    switch(Get_SETTINGS_Screen_val()){     // switch case
        case 0x01:{
            HUB_bitmap(256);
            if(Icon_Read_Status1()==0x00){
                PASS_bitmap(512,0); // new
                        }else{
                PASS_bitmap(512,1); // new
                        }

            BC_bitmap(768);     // new
         //   BC_bitmap(512);//BR_bitmap();
          // BR_bitmap(768);//BC_bitmap();
            break;
        }
        case 0x02:{
            if(Icon_Read_Status1()==0x00){
            PASS_bitmap(256,0); // new
            }else{
                PASS_bitmap(256,1); // new
            }
            BC_bitmap(512);//new
            Exit_bitmap(768);//new
           // BR_bitmap(768);//new
            //BC_bitmap(256);//
           // BR_bitmap(512);//
            //Exit_bitmap(768);//Exit_bitmap();
            break;
        }
        case 0x03:{
            BC_bitmap(256);//new
            //BR_bitmap(512);//new
            Exit_bitmap(512);//new
            sett_blank(768);// new
            // BR_bitmap(256);
             //Exit_bitmap(512);
             //sett_blank(768); // available on icon.h
             break;
        }
        case 0x04:{
            Exit_bitmap(256);//new
            sett_blank(512);// new
            sett_blank(768);// new
             //Exit_bitmap(256);//Exit_bitmap();
             //sett_blank(512);      //available on icon.h
             //sett_blank(768);      //available on icon.h
              break;
        }
        default :{
            AC_bitmap(256);
            HUB_bitmap(512);
            if(Icon_Read_Status1()==0x00){
                        PASS_bitmap(768,0); // new
                        }else{
                            PASS_bitmap(768,1); // new
                        }
            //BC_bitmap(768);
              break;
        }
    }
    return Current_Screen_ptr;

}

//End of file
//
