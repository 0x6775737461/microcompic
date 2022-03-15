#include <xc.h>

int main(void) {
  TRISBbits.TRISB5 = 1;
  TRISBbits.TRISB1= 0;

  PORTBbits.RB1 = 0;

  while(1) {
    if(PORTBbits.RB5 == 1){
      PORTBbits.RB1 = 1;
      continue;
    }

    PORTBbits.RB1 = 0;
  }

}
