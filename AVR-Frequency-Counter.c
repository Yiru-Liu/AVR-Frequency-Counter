
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include "USART.h"

#define COUNT_TIME 1000

// -------  Global Variables ---------- //
volatile uint16_t freqCount;

// ------- Functions -------- //

ISR(INT0_vect) {  // Run every time INT0 is triggered on a rising edge:
  freqCount++;    // Increase the count by 1
}

void initInterrupt0(void) { // Initialize the interrupt INT0 to trigger on a rising edge:
  EIMSK |= (1 << INT0); // Enable INT0
  EICRA |= 3;           // Trigger on a rising edge (set both ISC01 (bit 1) and ISC00 (bit 0) to 1)
}

int main(void) {
  // -------- Inits --------- //
  initUSART();      // Initialize the UART at 9600 baud
  initInterrupt0(); // Initialize INT0 to trigger on a rising edge

  // ------ Event loop ------ //
  while (1) {
    freqCount = 0;
    sei();
    _delay_ms(COUNT_TIME);
    cli();
    printWord(freqCount);
    printString("\r\n");
  }                                                  /* End event loop */
  return 0;                            /* This line is never reached */
}
