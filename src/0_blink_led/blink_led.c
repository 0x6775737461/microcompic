#include "../../h_files/pin_config.h"

#include <xc.h>

void main(void) {
  // Configurando o DDR (Data Direction Register)
  // para SAÍDA de dados.
  TRISBbits.TRISB0 = 0;

  // Deixando o RB0 em 0V (Volts)
  PORTBbits.RB0 = 0;

  while(1){
    // O operador '~' (tilde) é um operador bit-a-bit
    // que inverte os bits de uma variável.
    // Pesquise: Operador de Complemento a 1
    PORTBbits.RB0 = ~(PORTBbits.RB0);

    __delay_ms(1000);
  }
  
  return;
}
