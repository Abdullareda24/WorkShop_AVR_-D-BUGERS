#include <avr/io.h>
#include <avr/delay.h>

void common_cathode_SevenSegment_Display(char value)
{
  switch(value)
  {
    case 0:
    PORTA |= (1<<1);
    PORTA |= (1<<2);
    PORTA |= (1<<3);
    PORTA |= (1<<4);
    PORTA |= (1<<5);
    PORTA |= (1<<6);
    PORTA &= ~(1<<7);
    break;
    case 1:
    PORTA &= ~(1<<1);
    PORTA |= (1<<2);
    PORTA |= (1<<3);
    PORTA &= ~(1<<4);
    PORTA &= ~(1<<5);
    PORTA &= ~(1<<6);
    PORTA &= ~(1<<7);
    break;
    case 2:
    PORTA |= (1<<1);
    PORTA &= ~(1<<2);
    PORTA |= (1<<3);
    PORTA |= (1<<4);
    PORTA |= (1<<5);
    PORTA &= ~(1<<6);
    PORTA |= (1<<7);
    break;
    case 3:
    PORTA |= (1<<1);
    PORTA |= (1<<2);
    PORTA |= (1<<3);
    PORTA |= (1<<4);
    PORTA &= ~(1<<5);
    PORTA &= ~(1<<6);
    PORTA |= (1<<7);
    break;
    case 4:
    PORTA &= ~(1<<1);
    PORTA |= (1<<2);
    PORTA |= (1<<3);
    PORTA &= ~(1<<4);
    PORTA &= ~(1<<5);
    PORTA |= (1<<6);
    PORTA |= (1<<7);
    break;
    case 5:
    PORTA |= (1<<1);
    PORTA &= ~(1<<2);
    PORTA |= (1<<3);
    PORTA |= (1<<4);
    PORTA &= ~(1<<5);
    PORTA |= (1<<6);
    PORTA |= (1<<7);
    break;
    case 6:
    PORTA |= (1<<1);
    PORTA &= ~(1<<2);
    PORTA |= (1<<3);
    PORTA |= (1<<4);
    PORTA |= (1<<5);
    PORTA |= (1<<6);
    PORTA |= (1<<7);
    break;
    case 7:
    PORTA |= (1<<1);
    PORTA |= (1<<2);
    PORTA |= (1<<3);
    PORTA &= ~(1<<4);
    PORTA &= ~(1<<5);
    PORTA &= ~(1<<6);
    PORTA &= ~(1<<7);
    break;
    case 8:
    PORTA |= (1<<1);
    PORTA |= (1<<2);
    PORTA |= (1<<3);
    PORTA |= (1<<4);
    PORTA |= (1<<5);
    PORTA |= (1<<6);
    PORTA |= (1<<7);
    break;
    case 9:
    PORTA |= (1<<1);
    PORTA |= (1<<2);
    PORTA |= (1<<3);
    PORTA &= ~(1<<4);
    PORTA &= ~(1<<5);
    PORTA |= (1<<6);
    PORTA |= (1<<7);
    break;
     
    
  }
}
int main(void)
{
  char num = 0;
  DDRD &= ~(1<<2) &~(1<<3);
  DDRC |= (1<<6);
  PORTC |= (1<<6);
  DDRA |= 0xFE;
  common_cathode_SevenSegment_Display(num);

  while(1)
  {
    if( !(PIND & (1<<PD2)))
    {
      _delay_ms(20);
      if( !(PIND & (1<<PD2)))
      {
        if(num != 9)
        {
          num++;
        }
        common_cathode_SevenSegment_Display(num);
      }
      while(!(PIND & (1<<PD2))){}
    } 
    else if(!(PIND & (1<<PD3)))
    {
      _delay_ms(20);
      if( !(PIND & (1<<PD3)))
      {
        if(num != 0)
        {
          num--;
        }
        common_cathode_SevenSegment_Display(num);
      }
      while(!(PIND & (1<<PD3))){}
    }
    
  }
}
