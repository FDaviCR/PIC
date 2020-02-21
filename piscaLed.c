#include <p18F4550.h>
#include <delays.h>
#pragma config FOSC = HS
#pragma config CPUDIV = OSC1_PLL2
#pragma config WDT = OFF //Desabilita o Watchdog Timer (WDT).
#pragma config PWRT = ON //Habilita o Power-up Timer (PWRT).
#pragma config BOR = ON  //Brown-out Reset (BOR) habilitado somente no hardware.   
#pragma config BORV = 1    //Voltagem do BOR é 4,33V.
#pragma config PBADEN = OFF   //RB0,1,2,3 e 4 configurado como I/O digital.
#pragma config LVP = OFF   //Desabilita o Low Voltage Program.
   

#define led   PORTDbits.RD0



void main(void) {
  
  TRISB = 0b00000001;
  TRISD = 0b00000000;

  led = 0;

  while(1)
  {
      led = ~led;
      Delay10KTCYx(200);
  }
  
}