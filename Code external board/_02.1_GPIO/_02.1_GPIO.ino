#define LED 13
#define BUTTON 7
void setup() {
  // put your setup code here, to run once:s
  /*
    DDRH = 0x00; //PORTD la Input de su dung ngat
    PORTH = 0x10; //mac dien tro keo len (dien tro noi trong chip)
    PORTB = 0x80; //mac dien tro keo len (dien tro noi trong chip)
    DDRB = 0x80; //PORTB la output
  */
  pinMode(LED, OUTPUT); // Khai bao chan 13 la OUTPUT
  pinMode(BUTTON, INPUT_PULLUP); // Khai bao chan 7 la INPUT PULL UP
}

void loop() {


  /* byte read_button = PINH & B00010000;
    if (read_byte != 0)
    {
    PORTB = 0x00;
    }
    else
    {
    PORTB = 0x80;
    }
  */
  byte read_button = digitalRead(BUTTON);
  if ( read_button)
  {
    digitalWrite(LED,LOW);
  }
  else
  {
    digitalWrite(LED,LOW);
  }
}
