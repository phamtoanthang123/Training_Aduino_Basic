/*
  #define LLE 1<<PB7
  #define CLK 1<<PB6
  #define SDI 1<<PB5
*/
#define LLE 13
#define CLK 12
#define SDI 11
void pinWrite( unsigned int bit, unsigned int val );
void pulseClock ( void );
void shiftOut(unsigned int val);


void setup() {
  /*
    // put your setup code here, to run once:
    DDRB=(1<<DDB7) | (1<<DDB6) | (1<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
    // State: Bit7=1 Bit6=1 Bit5=1 Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T
    PORTB=(1<<PORTB7) | (1<<PORTB6) | (1<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);
  */
  pinMode(LLE, OUTPUT); // chan Lacth
  pinMode(SCK, OUTPUT); // Chan Clock
  pinMode(SDI, OUTPUT); // Chan Data
}

void loop() {


  int i;
  for ( i = 0 ; i < 16 ; i++ ) 
  {
    shiftOut(1 << i);
    delay(50);
  }
  for ( i = 16 ; i >= 0 ; i-- ) 
  {
    shiftOut(1 << i);
    delay(50);
  }

}
void pinWrite( unsigned int bit, unsigned int val )
{
  /*if (val) 
  {
    PORTB |= bit;
  } else 
  {
    PORTB &= ~bit;
  }
  */
  digitalWrite(bit,val);
}
void pulseClock( void )
{
  /*
  PORTB |= CLK;
  PORTB &= ~CLK;
  */
  digitalWrite(CLK,HIGH);
  digitalWrite(CLK,LOW);
}
void shiftOut(unsigned int val)
{
  /*
  //Set LLE to low (should be already)
  PORTB &= ~LLE;

  char i;

  // Iterate over each bit, set SDI pin, and pulse the clock to send it
  // to the shift register
  for (i = 0; i < 16; i++)  {
    pinWrite(SDI, (val & (1 << i)));
    pulseClock();
  }
  // Pulse the LLE pin to write the values into the storage register
  PORTB |= LLE;
  PORTB &= ~LLE;
  */
  //Set LLE to low (should be already)
  digitalWrite(LLE,LOW);

  char i;

  // Iterate over each bit, set SDI pin, and pulse the clock to send it
  // to the shift register
  for (i = 0; i < 16; i++)  {
    pinWrite(SDI, (val & (1 << i)));
    pulseClock();
  }
  // Pulse the LLE pin to write the values into the storage register
  digitalWrite(LLE,HIGH);
  digitalWrite(LLE,LOW);
}

