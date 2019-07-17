//###########################################################################
//
// FILE:    main.c
//
// TITLE:   f2802x EPwm Timer Interrupt From Flash Example.
//
// ASSUMPTIONS:
//
//    This program requires the f2802x header files.
//
//    As supplied, this project is configured for "boot to FLASH"
//    operation.  The 2802x Boot Mode table is shown below.
//    For information on configuring the boot mode of an eZdsp,
//    please refer to the documentation included with the eZdsp,
//
//    $Boot_Table
//    While an emulator is connected to your device, the TRSTn pin = 1,
//    which sets the device into EMU_BOOT boot mode. In this mode, the
//    peripheral boot modes are as follows:
//
//      Boot Mode:   EMU_KEY        EMU_BMODE
//                   (0xD00)         (0xD01)
//      ---------------------------------------
//      Wait         !=0x55AA        X
//      I/O          0x55AA          0x0000
//      SCI          0x55AA          0x0001
//      Wait         0x55AA          0x0002
//      Get_Mode     0x55AA          0x0003
//      SPI          0x55AA          0x0004
//      I2C          0x55AA          0x0005
//      OTP          0x55AA          0x0006
//      Wait         0x55AA          0x0007
//      Wait         0x55AA          0x0008
//      SARAM        0x55AA          0x000A
//      Flash        0x55AA          0x000B   <-- "Boot to Flash"
//      Wait         0x55AA          Other
//
//   Write EMU_KEY to 0xD00 and EMU_BMODE to 0xD01 via the debugger
//   according to the Boot Mode Table above. Build/Load project,
//   Reset the device, and Run example
//
//   $End_Boot_Table
//
//    The program must first be compiled and then programmed into the
//    flash.
//
// Included Files
//

#include "DSP28x_Project.h"     // Device Headerfile and Examples Include Fill
#include "Sh1106_Oled.h"
#include"interrupt.h"
#include "icon.h"
#include"f2802x_adc.h"
//
// #defines
//
//
// Function Prototypes
//
void Oled_setup();
__interrupt void timer0(void);
__interrupt void adc_isr(void);
void Adc_Config(void);
void gpiosetup();
void delay_main(unsigned int i);
//
// Globals
//
//uint16_t LoopCount;
//uint16_t ConversionCount;
//uint16_t Voltage1[10];
//uint16_t Voltage2[10];
//__interrupt void home_isr(void);
//void Interrupt_setup();
//void Oled_Refresh();

//
// Main
//
void main(void)
{
#ifdef _FLASH
//
    // WARNING: Always ensure you call memcpy before running any functions from
    // RAM InitSysCtrl includes a call to a RAM based function and without a
    // call to memcpy first, the processor will go "into the weeds"
    //
    memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);
#endif
    //
    // Step 1. Initialize System Control:
    // PLL, WatchDog, enable Peripheral Clocks
    // This example function is found in the f2802x_SysCtrl.c file.



    //
    InitSysCtrl();


    //
   // Step 2. Initialize GPIO:
    // This example function is found in the f2802x_Gpio.c file and
    // illustrates how to set the GPIO to it's default state.
    //
   // InitGpio();  // Skipped for this example
    DINT;

    //
    // Initialize the PIE control registers to their default state.
    // The default state is all PIE interrupts disabled and flags
    // are cleared.
    // This function is found in the f2802x_PieCtrl.c file.
    //

    InitPieCtrl();
    //
    // Disable CPU interrupts and clear all CPU interrupt flags
    //
    IER = 0x0000;
    IFR = 0x0000;
    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    // This will populate the entire table, even if the interrupt
    // is not used in this example.  This is useful for debug purposes.
    // The shell ISR routines are found in f2802x_DefaultIsr.c.
    // This function is found in f2802x_PieVect.c.
    //
  InitPieVectTable();
    //
    // Copy time critical code and Flash setup code to RAM
     delay_main(1000);
    EALLOW;             // This is needed to write to EALLOW protected registers
       PieVectTable.XINT1 = &Sett_pwr_isr;
       PieVectTable.XINT2 = &Sett_down_isr;
      PieVectTable.XINT3 = &Sett_up_isr;
        //PieVectTable.TINT0 = &timer0;
      // PieVectTable.ADCINT1 = &adc_isr;
    EDIS;
    // The  RamfuncsLoadStart, RamfuncsLoadEnd, and RamfuncsRunStart
    // symbols are created by the linker.
    //
   InitCpuTimers();
        //
        // Configure CPU-Timer 0 to interrupt every 500 milliseconds:
        // 60MHz CPU Freq, 50 millisecond Period (in uSeconds)
        //
 ConfigCpuTimer(&CpuTimer0, 60, 10000000);
 memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);
    //
    // Call Flash Initialization to setup flash wait states
    // This function must reside in RAM
    //
    EALLOW;
       GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0;
       GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;
       EDIS;
      //
      // Use write-only instruction to set TSS bit = 0
      //
                            //   CpuTimer0Regs.TCR.all = 0x4001;
       //
       // Enable TINT0 in the PIE: Group 1 interrupt 7
       //
            PieCtrlRegs.PIEIER1.bit.INTx1 = 1; // Enable INT 1.1 in the PIE
            PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
          //
          // Enable CPU INT1 which is connected to CPU-Timer 0
          //
            IER |= M_INT1;
            EINT;                                 // Enable Global interrupt INTM
            ERTM;
    InitFlash();          // Flash sector initialization
    //
    // TO setup oled
    //
    gpiosetup();
    Oled_setup();
    //
        Batt_Screen_draw();
        Home_screen_draw();
        pwr_Int_setup();
        XIntruptRegs.XINT1CR.bit.ENABLE = 1;        // Enable XINT1
               XIntruptRegs.XINT2CR.bit.ENABLE = 1;
               XIntruptRegs.XINT3CR.bit.ENABLE = 1;
        while(1){
                if(GpioDataRegs.GPADAT.bit.GPIO16 ==1){
                //AC ok sequence
                AC_detect();
                break;
                }
            }

    while(1);

      // Oled_Refresh();
}
/*
__interrupt void timer0(void)
{
    CpuTimer0.InterruptCount++;
       if(CpuTimer0.InterruptCount==6){
    GpioDataRegs.GPATOGGLE.bit.GPIO0 = 1;
    //OledClear();
    //     __asm(" IDLE");
       }
    //    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
*/
//
// End of main
//

//
// adc_isr -
//

//
// Oled_setup()
//
void Oled_setup(){
        I2CGpio_Setup();      // Preparing GPIO32 and GPIO33 for I2C communication
        I2CInit_Oled();      // Preparing I2C registers for I2C communication
        Oled_Init();         // SH1106 OLED initialization with respective commands
        OledClear();         // OLED clear
}
// End of file
//
void gpiosetup(){
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO16 =1;   // Enable pullup on GPIO16 (SPICLKA)
    //GpioDataRegs.GPASET.bit.GPIO16 = 0;   // Load output latch

    GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 0;  // GPIO6 = GPIO6
    GpioCtrlRegs.GPADIR.bit.GPIO16 = 0;   // GPIO16 = input
    EDIS;
}
void delay_main(unsigned int i){
    unsigned int j=0;
    for(;i>0;i--)
    for(j=0;j<1000;j++);
}
