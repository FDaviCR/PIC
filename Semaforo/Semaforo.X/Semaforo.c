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
   

#define vermelha1   PORTDbits.RD0
#define amarela1   PORTDbits.RD1
#define verde1   PORTDbits.RD2

#define vermelha2   PORTDbits.RD3
#define amarela2   PORTDbits.RD4
#define verde2   PORTDbits.RD5

void main(void) {
  
  TRISB = 0b00000001;
  TRISD = 0b00000000;
  /*
  vermelha1 = 0;
  vermelha2 = 0;
  amarela1 = 0;
  amarela2 = 0;
  verde1 = 0;
  verde2 = 0;
  */
  while(1)
  {
      //Inicio do ciclo do semaforo 1
      vermelha1 = 1;
      vermelha2 = 1;
      Delay10KTCYx(200);
      vermelha2 = 1;
      vermelha1 = 0;
      verde1 = 1;
      Delay10KTCYx(200);
      vermelha2 = 1;
      verde1 = 0;
      amarela1 = 1;
      Delay10KTCYx(100);
      amarela1 = 0;
      vermelha1 = 1;
      //Fim do ciclo do semaforo 1
      
      //Inicio do ciclo do semaforo 2
      Delay10KTCYx(100);
      vermelha1 = 1;
      vermelha2 = 1;
      Delay10KTCYx(200);
      vermelha1 = 1;
      vermelha2 = 0;
      verde2 = 1;
      Delay10KTCYx(200);
      vermelha1 = 1;
      verde2 = 0;
      amarela2 = 1;
      Delay10KTCYx(100);
      amarela2 = 0;
      //Fim do ciclo do semaforo 2
  }
  
}