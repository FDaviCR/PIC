#include <P18F4550.h>
#include <delays.h>
#include <timers.h>
#pragma config FOSC = HS
#pragma config WDT = OFF
#pragma config PWRT = ON
#pragma config BOR = ON 
#pragma config BORV = 1 
#pragma config PBADEN = OFF
#pragma config LVP = OFF 
#define chave PORTBbits.RB0
#define display LATD

int conta = 0;
int n = 0;

unsigned char tabela[10] = {0b00111111,
0b00000110,
0b01011011,
0b01001111,
0b01100110,
0b01101101,
0b01111100,
0b00000111,
0b01111111,
0b01100111

};

#pragma code int_pr = 0x08
#pragma interrupt trata_TIMER1
void trata_TIMER1(void)
{ 
    TMR1L = 0XB0;
    TMR1H = 0X3C;
    PIR1bits.TMR1IF = 0;
    conta++;
if( conta == 10)
{ 
    conta = 0;
    if(chave)
        {n++;
    if(n == 10)n = 0; }
    else
    { n--;
    if(n == -1)n=9;}
    }
}

void main(void)
{
TRISA = 0b00000000;
TRISB = 0b00000001;
TRISC = 0b00000000;
TRISD = 0b00000000;
TRISE = 0b00000000;

T1CONbits.RD16 = 0;
T1CONbits.T1RUN = 0;
T1CONbits.T1CKPS1 = 1;
T1CONbits.T1CKPS0 = 0;
T1CONbits.T1OSCEN = 0;
T1CONbits.T1SYNC = 0;
T1CONbits.TMR1CS = 0;
T1CONbits.TMR1ON = 1;

TMR1L = 0xB0;
TMR1H = 0x3C;

PIR1bits.TMR1IF = 0; 
PIE1bits.TMR1IE = 1; 

INTCONbits.GIEH = 1;
INTCONbits.PEIE = 1;

while(1)
{
    display = tabela[n];
}


}
