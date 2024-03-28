#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char count = 0;

ISR(INT2_vect)
{
  PORTC = (PORTC&0xF0) | count;
  count++;
}
void INT2_Init(void)
{
  DDRB  &= ~(1<<PB2);               
  MCUCSR |= (1<<ISC2);                
  GICR  |= (1<<INT2);                 
  SREG  |= (1<<7);                    
}
int main(){
  INT2_Init();
  DDRC |= 0x0F;
  DDRB &= ~(1<<PB2);
  
  while(1)
  {
    
  }
}
