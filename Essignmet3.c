#include <avr/io.h>
#include <avr/interrupt.h>
unsigned char state;
int main(){ 
   // Write your code here
    state = 1;
    DDRC = 0xFF;
    TIMSK0 = 0x01;
    TCCR0B = 0x04;
    TCCR0A = 0x00;
    TCNT0 = 126;
    PORTC = 0x00;
   sei();
    while(1);
    return 0;
  
 }
 ISR(TIMER0_OVF_vect)
{
   if(state==1){
      TCNT0 = 126;
      PORTC = 0x01;
      state = 2;
   }
   else if(state==2){
      TCNT0 = 126;
      PORTC = 0x03;
      state = 3;
   }
   else if(state==3){
      TCNT0 = 126;
      PORTC = 0x02;
    state = 4;  
   }
   else{
      TCNT0 = 126;
      PORTC = 0x00;
      state = 1;
   }
}