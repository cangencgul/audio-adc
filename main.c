#include <xc.h>

#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ 4000000


void main(void) {
    TRISA = 0x00;
    PORTA = 0x00;
    TRISB = 0x01;
    PORTB = 0x00;
    unsigned char sample = 0;
    while(1){
        RA0 = 0;
        int i;
        for (i = 0; i < 9; i++ ){
            RA1 = 0;
            __delay_us(50);
            sample <<= 1;
            sample += RB0;
            RA1 = 1;
            __delay_us(50); // total delay 100 us 10kHz clk frequency 
        }
        RA0 = 1;
        RA1 = 0;
        RB0 = 0;
        __delay_us(2);
    }
    return;
}
