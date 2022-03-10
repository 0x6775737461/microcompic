#include "../../h_files/pin_config.h"

#include <xc.h>

void main(void) {
  TRISBbits.TRISB0 = 0;
  PORTBbits.RB0 = 0;

  while(1){
    PORTBbits.RB0 = ~(PORTBbits.RB0);

    __delay_ms(1000);
    /*
    PORTBbits.RB0 = 1;
    __delay_ms(1000);

    PORTBbits.RB0 = 0;
    __delay_ms(1000);
    */
  }
  
  return;
}
