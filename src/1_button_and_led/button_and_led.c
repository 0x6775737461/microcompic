#include <xc.h>

int main(void) {
  // RB5 (Pino 11) = Entrada
  // RB1 (Pino 7) = Saída
  TRISBbits.TRISB5 = 1;
  TRISBbits.TRISB1= 0;

  PORTBbits.RB1 = 0;

  while(1) {
    // Considerando que ligação de RB5
    // foi feita com um resistor pull-down
    if(PORTBbits.RB5 == 1){
      // Se o botão for pressionado,
      // liga o led.
      PORTBbits.RB1 = 1;
      continue;
    }

    // Se o botão estiver 'solto', o led continua
    // desligado.
    PORTBbits.RB1 = 0;
  }
}
