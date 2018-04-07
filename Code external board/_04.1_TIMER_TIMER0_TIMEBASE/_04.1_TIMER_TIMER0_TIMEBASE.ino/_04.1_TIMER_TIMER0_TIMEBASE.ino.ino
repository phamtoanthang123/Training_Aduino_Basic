unsigned int toggle = 0;  //used to keep the state of the LED
unsigned int count = 0;   //used to keep count of how many interrupts were fired


unsigned long now_time=0;
extern unsigned long timer0_millis;
void setup() {
  // put your setup code here, to run once:
/*TCCR0A=(0<<COM0A1) | (0<<COM0A0) | (0<<COM0B1) | (0<<COM0B0) | (0<<WGM01) | (0<<WGM00);
TCCR0B=(0<<WGM02) | (1<<CS02) | (0<<CS01) | (1<<CS00);
TCNT0=0x60;
OCR0A=0x00;
OCR0B=0x00;
pinMode(13,OUTPUT);
sei();
*/
TCCR0A=(0<<COM0A1) | (0<<COM0A0) | (0<<COM0B1) | (0<<COM0B0) | (0<<WGM01) | (0<<WGM00);
TCCR0B=(0<<WGM02) | (0<<CS02) | (1<<CS01) | (1<<CS00);
TCNT0=0x06;
OCR0A=0x00;
OCR0B=0x00;
sei();
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*if (TCNT0 >= 191)
        {
            toggle = !toggle;
            digitalWrite(13,toggle);
            TCNT0 = 0;            // reset counter
        }*/
        if(TCNT0>=255)
        {
          TCNT0=0x06;
          TIFR0 = 0x00; 
           count++;               //Increments the interrupt counter
          if(count > 1000){
            toggle = !toggle;    //toggles the LED state
            
            count = 0;           //Resets the interrupt counter
        }
        //digitalWrite(13,toggle);
        PORTB=(toggle<<PB7);
        }
  /*if(timer0_millis-now_time>1)
  {
    
    count++;               //Increments the interrupt counter
  if(count > 1000){
    toggle = !toggle;    //toggles the LED state
    count = 0;           //Resets the interrupt counter
  }
 // digitalWrite(13,toggle);
 TCNT0=0x06;
 TIFR0 = 0x00;          //Timer2 INT Flag Reg: Clear Timer Overflow Flag
    now_time=timer0_millis;
  }*/

}
