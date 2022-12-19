#include <avr/io.h>
#include <util/delay.h>


void init(){
  Adc_Init(); //initialization of ADC
  LCD_Init(); //initialization of the LCD
  tempreture(); //function that shows the tempreture
  PWM_init(); //initialization of pulse width modulation
}
int main(){
 init();
 DDRD=0b11111111;
 DDRB=0b11100111;
 float maximumvalue=40; //maximum limit of the range
 float tempreturevalue; //holds the value of the tempreture 
  char *holdsdata[0]; //buffer holds data
  while(1)
  {
  tempreturevalue = tempreture(); //holds value of tempreture for the function 
  _delay_ms(200);
  if((tempreturevalue/20)>maximumvalue){ 
  PORTB |=(1<<2);
  }
  else{  
  PORTB &=~(1<<2);
  }
if(Adc_ReadChannel(0)>750){ //to check if the button is pressed
  _delay_ms(50);
  if(PORTB&(1<<3)!=1){
    LCD_Clear();
    maximumvalue++;//increase the set range by 1
  }
    LCD_String_xy(0,0,"40 C turns to ");//displays on the first row of the LCD
    itoa(maximumvalue,*holdsdata,10);//turn the float value to string to display on the LCD
    LCD_String_xy(1,0,*holdsdata);
    LCD_String_xy(1,6,"C");
    _delay_ms(2000);
    LCD_Clear();
  }
if(Adc_ReadChannel(1)>750){
  _delay_ms(50);
  if(PORTB&(1<<3)!=1){
    LCD_Clear();
    maximumvalue--;//decrease the set range by 1
  }
    LCD_String_xy(0,0,"40 C turns to ");
    itoa(maximumvalue,*holdsdata,10);
    LCD_String_xy(1,0,*holdsdata);
    LCD_String_xy(1,6,"C");
    _delay_ms(2000);
    LCD_Clear();
  }
  if(Adc_ReadChannel(2)>750){
  _delay_ms(50);
  if(PORTB&(1<<3)!=1){
    LCD_Clear();
    PORTD &=~(1<<0);
    PORTD &=~(1<<1);
    _delay_ms(300);
  }
    LCD_String_xy(0,0,"Right and fast");
    _delay_ms(700);
    PORTD=0b11110101;
    highspeed();//rotate right fast
    _delay_ms(200);
    LCD_Clear();
  }
  if(Adc_ReadChannel(3)>750){
  _delay_ms(50);
  if(PORTB&(1<<3)!=1){
    LCD_Clear();
    PORTD &=~(1<<0);
    PORTD &=~(1<<1);
    _delay_ms(300);
  }
    LCD_String_xy(0,0,"left and slow");
    _delay_ms(800);
    PORTD=0b11110110;
    lowspeed();//turn left slowly
    _delay_ms(200);
    LCD_Clear();
  }
    if(Adc_ReadChannel(4)>750){
  _delay_ms(50);
  if(PORTB&(1<<3)!=1){
    LCD_Clear();
    PORTD &=~(1<<0);
    PORTD &=~(1<<1);
    _delay_ms(300);
  }
    LCD_String_xy(0,0,"motor stops");
    _delay_ms(700);
    PORTD=0b11110100;//shuts down the motor, stops rotating
    _delay_ms(200);
    LCD_Clear();
  }
}

}
