#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/delay.h>
void PWM_init(){
  TCCR2B= _BV(WGM22) | _BV(CS21);
  TCCR2A = _BV(COM2A0) | _BV(COM2B1) | _BV(COM2B0) | _BV(WGM20);
  OCR2A=1022;

}
void highspeed(){
  OCR2B=1023;
}
void lowspeed(){
  OCR2B=300;
}