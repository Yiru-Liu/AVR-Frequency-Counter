## ATmega328P Frequency Counter

This project uses an ATmega328P as a frequency counter. 

The signal is connected to the INT0 pin of the ATmega328P. The program works by counting the number of rising edges of the signal using the interrupt on INT0 in a second, and outputs the result in Hertz as text through the UART. This frequency counter works for up to 65535 Hz. 