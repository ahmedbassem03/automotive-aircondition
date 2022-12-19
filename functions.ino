#include <avr/io.h>
#include <util/delay.h>

float tempreture(){
  Adc_Init();

  float tempreturevalue;
  char *holds[0];
  
  DDRC=0b00000000;
  PORTC=0b00000000;
  tempreturevalue=Adc_ReadChannel(5);
  itoa(tempreturevalue/20,*holds,10);
  _delay_ms(300);
  LCD_String_xy(0,0,"Temp is ");
  LCD_String_xy(1,0,*holds);
  LCD_String_xy(1,6,"C");
  _delay_ms(300);
  return tempreturevalue;
}
