
#include <avr/interrupt.h>
#include <avr/io.h>

#define LED 13
volatile int state = 0;

void setup()
{
  pinMode(LED, OUTPUT);   //attached to LED annode
  pinMode(2, INPUT_PULLUP);     //Button input tied to INT4

  /*
    EICRB = 0x03;          //INT4, triggered on any edge
    EIMSK = 0x10;          //Enable only INT4
  */
  attachInterrupt(digitalPinToInterrupt(pin), blink, LOW);
}

void loop()
{
  // put your main code here, to run repeatedly:

}
void blink() 
{
  state = !state;
  digitalWrite(LED, state);
}
/*
  ISR(INT4_vect)
  {
  state = !state;
  digitalWrite(LED, state);
  }
*/
