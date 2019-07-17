/* 
************************* C file for Display Icon status*****************************
*/

//##############################################################
//       File Name : icon.c
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
#include<icon.h>
//
//      End of Included files


//
//*********************************************************************************************
//Function Name    : Uint8 Byte_Invert(Uint8 i)
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : Uint8
//Description      : To Get global status of screen
//**********************************************************************************************
//
Uint8 Byte_Invert(Uint8 i){
    return (~i);
}

//
//*********************************************************************************************
//Function Name    : void br_blank(unsigned int i)
//No.Of Parameters : 1
//Parameters Type  : unsigned int
//Return Type      : void
//Description      : To get bitmap of the Blank bitmap
//**********************************************************************************************
//
void blank(unsigned int i){
	Uint8 j;
	for(j=0;j<256;j++,i++){
	    Current_Screen[i]=0xFF;
    }
}
//
//
//*********************************************************************************************
//Function Name    : Uint8 Byte_Invert(Uint8 i)
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : Uint8
//Description      : To Get global status of screen
//**********************************************************************************************
//
void Icon_Update_Status(Uint8 i){
    Uint8 j,k;
    k=i<<2;
    j=i<<1;
    if(k==0x03){
        Setting_Icon_status=Setting_Icon_status&0xCF;
        i=i^Setting_Icon_status;
        Setting_Icon_status=i;
    }else if(j==0x01){
        Setting_Icon_status=Setting_Icon_status&0xF3;
        i=i^Setting_Icon_status;
        Setting_Icon_status=i;
    }else{
        i=i^Setting_Icon_status;
        Setting_Icon_status=i;
    }
    //writing  to memory cell  goes here
}
//
//*********************************************************************************************
//Function Name    : Uint8 Byte_Invert(Uint8 i)
//No.Of Parameters : 0
//Parameters Type  : NA
//Return Type      : Uint8
//Description      : To Get global status of screen
//**********************************************************************************************
//
Uint8 Icon_Read_Status(){
    // reading from memory cell goes here
    return Setting_Icon_status;
}

//
// End of File
//
