
//##############################################################
//       File Name : interrupt.c
//
//       TITLE     : Sh1106 oled with c2000(F28027)
//
//       Development Kit : LAUNCHXL F28027
//
//       Date Of Created : 16/05/2019
//###############################################################
//
// Included Files
#include<interrupt.h>
#include "Sh1106_Oled.h"
#include"settings.h"
#include<home.h>
#include<bc.h>
#include<br.h>
Uint8 *oledptr;
//
// #defines
union Position level1;
//

#define INITIAL_VALUE 0x00
//
//*********************************************************************************************
//Function Name    : void Home_screen_draw()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : void
//Type             : Sub routine
//Description      :
//**********************************************************************************************
//
void Home_screen_draw(){
    int i=0;
    Up_var_of_home(0);
    //
    //OLED pointer initialization
    //
    oledptr=Home_draw();
    //
    //Drawing bitmap
    //
    DrawBitMap(0,0,oledptr);
    //
    //INverting the display
    //
    InvertDisplay(0x01);
    //
    //  Icon initialization
    //
    Icon_Update_Status(0x00);

    level1.pos=0x00;

    for(i=0;i<10;i++){
            delay(1000);
    }
 }

//
//*********************************************************************************************
//Function Name    :void Batt_Screen_draw()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : void
//Type             : Sub routine
//Description      :
//**********************************************************************************************
//new
//
//
void Batt_Screen_draw(){
    int i=0;
    //
    //OLED pointer initialization
    //
    oledptr=battary_draw(3,0);
    //
    //Drawing bitmap
    //
    DrawBitMap(0,0,oledptr);
    //
    //INverting the display
    //
   // InvertDisplay(0x01);
    for(i=0;i<10;i++){
        delay(1000);
    }
 }
void Batt_Screen_draw1(){
    int i=0;
    //
    //OLED pointer initialization
    //
    oledptr=battary_draw(10,0);
    //
    //Drawing bitmap
    //
    DrawBitMap(0,0,oledptr);
    //
    //INverting the display
    //
   // InvertDisplay(0x01);
    for(i=0;i<30;i++){
        delay(1000);
    }
 }
//
//new
//

void AC_detect(){
    int i=0,j=0;
    InvertDisplay(0x01);
        for(j=0;j<2;j++){
        for(i=1;i<11;i++){
            oledptr= battary_draw(i,1);
            DrawBitMap(0,0,oledptr);
            delay(1000);
            delay(1000);
        }
       }
        inwatt_update(44);// variable update
        oledptr=Home_draw();

       DrawBitMap(0,0,oledptr);
       for(i=0;i<20;i++){
           delay(1000);
       }
       inwatt_update(99);
       outwatt_update(73);
       // variable update
       oledptr=Home_draw();
      DrawBitMap(0,0,oledptr);

}
//
//*********************************************************************************************
//Function Name    : void pwr_int_setup()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : void
//Type             : Sub routine
//Description      :
//**********************************************************************************************
//
void pwr_Int_setup(){
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO3 = 0;
    GpioCtrlRegs.GPAPUD.bit.GPIO2 = 0;
    EDIS;
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;          // Enable the PIE block
    PieCtrlRegs.PIEIER1.bit.INTx4 = 1;          // Enable PIE Group 1 INT4
    PieCtrlRegs.PIEIER1.bit.INTx5 = 1;          // Enable PIE Group 1 INT4
    IER |= M_INT1;                              // Enable CPU INT1
    EINT;                                       // Enable interrupts
    EALLOW;
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 0;     // GPIO
    GpioCtrlRegs.GPADIR.bit.GPIO3 = 0;      // input
    GpioCtrlRegs.GPAQSEL1.bit.GPIO3 = 2;    // XINT2 Qual using 3 samples
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;     // GPIO
    GpioCtrlRegs.GPADIR.bit.GPIO2 = 0;      // input
    GpioCtrlRegs.GPAQSEL1.bit.GPIO2 = 2;    // XINT2 Qual using 3 samples
    GpioCtrlRegs.GPACTRL.bit.QUALPRD0 = 0xFF;
    EDIS;
    EALLOW;
    GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL = 3;   // XINT1 is GPIO3
    GpioIntRegs.GPIOXINT2SEL.bit.GPIOSEL = 2;   // XINT1 is GPIO3
    EDIS;
    XIntruptRegs.XINT1CR.bit.POLARITY = 0;      // falling edge interrupt
    XIntruptRegs.XINT2CR.bit.POLARITY = 0;      // falling edge interrupt
 }

//
//*********************************************************************************************
//Function Name    : void down_int_set()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : void
//Type             : Sub routine
//Description      : To set down_button on GPIO2 as External interrupt 2
//**********************************************************************************************
//
void down_Int_set(){
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO2 = 0;
    EDIS;
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;          // Enable the PIE block
    PieCtrlRegs.PIEIER1.bit.INTx5 = 1;          // Enable PIE Group 1 INT5
    IER |= M_INT1;                              // Enable CPU INT1
    EINT;                                       // Enable interrupts

    EALLOW;
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;     // GPIO
    GpioCtrlRegs.GPADIR.bit.GPIO2 = 0;      // input
    GpioCtrlRegs.GPAQSEL1.bit.GPIO2 = 2;    // XINT2 Qual using 3 samples
    GpioCtrlRegs.GPACTRL.bit.QUALPRD0 = 0xFF;
    EDIS;
    EALLOW;
    GpioIntRegs.GPIOXINT2SEL.bit.GPIOSEL = 2;   // XINT1 is GPIO3
    EDIS;
    XIntruptRegs.XINT2CR.bit.POLARITY = 0;      // falling edge interrupt
 }

//
//*********************************************************************************************
//Function Name    : up_Int_set()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : void
//Type             : Sub routine
//Description      : To set down_button on GPIO6 as External interrupts
//**********************************************************************************************
//
void up_Int_set(){
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;
    EDIS;
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;          // Enable the PIE block
    PieCtrlRegs.PIEIER12.bit.INTx1 = 1;         // Enable the interrupt
    IER |= M_INT1 | M_INT12;                    // Enable CPU INT1 and INT 12
    EINT;                                       // Enable interrupts
    EALLOW;
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 0;     // GPIO
    GpioCtrlRegs.GPADIR.bit.GPIO6 = 0;      // input
    GpioCtrlRegs.GPAQSEL1.bit.GPIO6 = 2;    // XINT2 Qual using 3 samples
    GpioCtrlRegs.GPACTRL.bit.QUALPRD0 = 0xFF;
    EDIS;
    EALLOW;
    GpioIntRegs.GPIOXINT3SEL.bit.GPIOSEL = 6;   // XINT1 is GPIO3
    EDIS;
    XIntruptRegs.XINT3CR.bit.POLARITY = 0;      // falling edge interrupt
}

//
//*********************************************************************************************
//Function Name    : __interrupt void Sett_pwr_isr(void)
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : void
//Type             : Sub routine
//Description      : Nothing
//**********************************************************************************************
//
__interrupt void Sett_pwr_isr(void){
    Settings_Int_Handle();
            switch(level1.pos){
            case 0x00:{
                up_Int_set();
                down_Int_set();
                setting_src_init();
                level1.pos = 0x01;
                Refresh_screen();
                delay(1000);
                delay(1000);
                XIntruptRegs.XINT2CR.bit.ENABLE = 1;        // Enable XINT2
            //   PieCtrlRegs.PIEACK.all = 0xFFFF;
                break;
            }
            case 0x01:{
                if(Get_SETTINGS_Screen_val()==0x00){
                    while(1){
                        oledptr=battary_draw(0,1);
                            //
                            //Drawing bitmap
                            //
                         DrawBitMap(0,0,oledptr);
                         delay(1000);
                         oledptr=blank_draw();

                         DrawBitMap(0,0,oledptr);
                         delay(1000);
                    }
                    // AC toggle
                    //  Icon_Update_Status(0x01); commented
                }else if(Get_SETTINGS_Screen_val()==0x01){
                    // HUB toggle
                   // Icon_Update_Status(0x02); commented
                }else if(Get_SETTINGS_Screen_val()==0x02){
                    inwatt_update(99);
                    outwatt_update(94);
                    Icon_Update_Status1(0xFF);
                    // enter to BC screen
                  //  level1.pos = 0x02;     commented
                   // BC_ScreenInit();        commented
                }else if(Get_SETTINGS_Screen_val()==0x03){
                    // enter to br screen
                  //  level1.pos = 0x03;        commented
                  //  BR_ScreenInit();          commented
                }else{
                    level1.pos = 0x00;
                }
                break;
            }
            case 0x02:{
                /*
                // routine for the BC
                if(Get_BC_Screen_val()==0x00){
                      // BC 500  cycles setting
                     Icon_Update_Status(0x80);
                 }else if(Get_BC_Screen_val()==0x01){
                      // BC 1000  cycles setting
                     Icon_Update_Status(0x84);
                 }else if(Get_BC_Screen_val()==0x02){
                     // BC 2000  cycles setting
                     Icon_Update_Status(0x88);
                 }else{
                     //back selection
                     level1.pos = 0x01;
                 }
                 */
                break;

            }
            case 0x03:{
                /*
                // routine for the BR
                if(Get_BR_Screen_val()==0x00){
                    // BR 1000  cycles setting
                    Icon_Update_Status(0xC0);
                }else if(Get_BR_Screen_val()==0x01){
                    // BR 2000  cycles setting
                    Icon_Update_Status(0xD0);
                }else if(Get_BR_Screen_val()==0x02){
                    // BR 3000  cycles setting
                    Icon_Update_Status(0xE0);
                }else{
                  //back selection
                  level1.pos = 0x01;
                }
                */
                break;
            }
            default:{
                  //
                  //
                  //
            }
            }
            Refresh_screen();
            PieCtrlRegs.PIEACK.all = 0xFFFF;
}

//
//*********************************************************************************************
//Function Name    : __interrupt void Sett_up_isr(void);
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : void
//Type             : Sub routine
//Description      : Nothing
//**********************************************************************************************
//
__interrupt void Sett_up_isr(void){
if(level1.pos==0x01){
    SETTINGS_UP_update();
    Settings_Int_Handle();

}else if(level1.pos==0x02){
   // BC_UP_update();
   // BC_Int_Handle();
}else if(level1.pos==0x03){
   // BR_UP_update();
   // BR_Int_Handle();
}else{

}
Refresh_screen();
//delay(1000);
//delay(1000);

PieCtrlRegs.PIEACK.all = 0xFFFF;
}

//
//*********************************************************************************************
//Function Name    : __interrupt void Sett_down_isr(void);
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : void
//Type             : Sub routine
//Description      : Nothing
//**********************************************************************************************
//
__interrupt void Sett_down_isr(void){
    if(level1.pos==0x01){
        SETTINGS_DOWN_update();
        Settings_Int_Handle();
    }else if(level1.pos==0x02){
       // BC_DOWN_update();
       // BC_Int_Handle();
    }else if(level1.pos==0x03){
        //BR_DOWN_update();
       /// BR_Int_Handle();
    }else{
    }
    Refresh_screen();
   // delay(1000);
   // delay(1000);

    PieCtrlRegs.PIEACK.all = 0xFFFF;
}

//
//*********************************************************************************************
//Function Name    : void delay(unsigned int i)
//No.Of Parameters : 1
//Parameters Type  : NA
//Return Type      : unsigned char
//Type             : normal function
//Description      : Nothing
//**********************************************************************************************
//
void delay(unsigned int i){
    unsigned int j=0;
    for(;i>0;i--)
    for(j=0;j<1000;j++);
}

//
//*********************************************************************************************
//Function Name    : void Refresh_screen()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : unsigned char
//Type             : normal function
//Description      : Nothing
//**********************************************************************************************
//
void Refresh_screen(){

    if(level1.pos == 0x01){
        oledptr=Settings_Get_Bitmap();
        DrawBitMap(0,0,oledptr);
        InvertDisplay(0x22);
    }else if(level1.pos==0x02){
        oledptr=BC_screenmap();
        DrawBitMap(0,0,oledptr);
        InvertDisplay(0x22);

    }else if(level1.pos == 0x03){
         oledptr=BR_screenmap();
         DrawBitMap(0,0,oledptr);
         InvertDisplay(0x22);
    }else {
        Refresh_home();
       // Home_screen_draw();
        //InvertDisplay(0x22);
    }

}

//
//*********************************************************************************************
//Function Name    : void setting_src_init()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : unsigned char
//Type             : normal function
//Description      : Nothing
//**********************************************************************************************
//
void setting_src_init(){
          Icon_Update_Status(0x00);
          SETTINGS_ScreenInit();
 }

//
//*********************************************************************************************
//Function Name    : void Settings_Int_Handle()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : unsigned char
//Type             : normal function
//Description      : Nothing
//**********************************************************************************************
//
void Settings_Int_Handle(){
    if(Get_SETTINGS_Screen_val()<0x04){
             XIntruptRegs.XINT2CR.bit.ENABLE = 1;        // Enable XINT2
      }else {
             XIntruptRegs.XINT2CR.bit.ENABLE = 0;        // Disable XINT2
       }
     if(Get_SETTINGS_Screen_val()==0x00){
             XIntruptRegs.XINT3CR.bit.ENABLE = 0;        // Disable XINT2
      }else {
            XIntruptRegs.XINT3CR.bit.ENABLE = 1;        // Enable XINT
      }
     EALLOW;
            PieCtrlRegs.PIEACK.all = 0xFFFF; // acknowledge the interrupt to repeat the interrupts of same group
     EDIS;
}
//
//*********************************************************************************************
//Function Name    : void Settings_Int_Handle()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : unsigned char
//Type             : normal function
//Description      : Nothing
//**********************************************************************************************
//
/*
void BC_Int_Handle(){
    if(Get_SETTINGS_Screen_val()<0x04){
                 XIntruptRegs.XINT2CR.bit.ENABLE = 1;        // Enable XINT2
          }else {
                 XIntruptRegs.XINT2CR.bit.ENABLE = 0;        // Disable XINT2
           }
         if(Get_SETTINGS_Screen_val()==0x00){
                 XIntruptRegs.XINT3CR.bit.ENABLE = 0;        // Disable XINT2
          }else {
                XIntruptRegs.XINT3CR.bit.ENABLE = 1;         // Enable XINT
          }
         EALLOW;
                PieCtrlRegs.PIEACK.all = 0xFFFF;             // acknowledge the interrupt to repeat the interrupts of same group
         EDIS;
}
*/
//
//*********************************************************************************************
//Function Name    : void Settings_Int_Handle()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : unsigned char
//Type             : normal function
//Description      : Nothing
//**********************************************************************************************
//
/*
void BR_Int_Handle(){
    if(Get_SETTINGS_Screen_val()<0x04){
                     XIntruptRegs.XINT2CR.bit.ENABLE = 1;        // Enable XINT2
              }else {
                     XIntruptRegs.XINT2CR.bit.ENABLE = 0;        // Disable XINT2
               }
             if(Get_SETTINGS_Screen_val()==0x00){
                     XIntruptRegs.XINT3CR.bit.ENABLE = 0;        // Disable XINT2
              }else {
                    XIntruptRegs.XINT3CR.bit.ENABLE = 1;         // Enable XINT
              }
             EALLOW;
                    PieCtrlRegs.PIEACK.all = 0xFFFF;             // acknowledge the interrupt to repeat the interrupts of same group
             EDIS;
}
*/
//
//*********************************************************************************************
//Function Name    : void Refresh_screen()
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : unsigned char
//Type             : normal function
//Description      : Nothing
//**********************************************************************************************
//
/*
void BR_refresh(){
     oledptr=BC_screenmap();
      DrawBitMap(0,0,oledptr);
     InvertDisplay(0x22);
}
*/
void Refresh_home(){
  oledptr=Home_draw();
  DrawBitMap(0,0,oledptr);
}
//
//
//
void Up_var_of_home(int i){
    Home_var_intial_update();
    percentage_update(34);
    watt_hour_update(2500);
    temp_update(43);
    outwatt_update(i);
    inwatt_update(0);
    min_update(0);

}
