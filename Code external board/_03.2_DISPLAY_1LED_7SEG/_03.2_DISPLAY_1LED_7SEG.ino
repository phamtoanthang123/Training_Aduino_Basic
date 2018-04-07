/*
  #define DS0 1<<PB7
  #define DS1
  #define DS2
  #define DS3

  #define PORT_DS0 PORTB
  #define PORT_DS1
  #define PORT_DS2
  #define PORT_DS3

  #define SEG_A   1<<PB6
  #define SEG_B   1<<PB5
  #define SEG_C   1<<PB4
  #define SEG_D   1<<PH6
  #define SEG_E   1<<PH5
  #define SEG_F   1<<PH4
  #define SEG_G   1<<PH3
  #define SEG_DOT 1<<PH1

  #define PORT_SEG_A PORTB
  #define PORT_SEG_B PORTB
  #define PORT_SEG_C PORTB
  #define PORT_SEG_D PORTH
  #define PORT_SEG_E PORTH
  #define PORT_SEG_F PORTH
  #define PORT_SEG_G PORTH
  #define PORT_SEG_DOT PORTH
*/
#define DS0 13
#define SEG_A   12
#define SEG_B   11
#define SEG_C   10
#define SEG_D   9
#define SEG_E   8
#define SEG_F   7
#define SEG_G   6
#define SEG_DOT 5
byte led_data[16] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e};
void setup() {
  /*
    // put your setup code here, to run once:
    DDRB=(1<<DDB7) | (1<<DDB6) | (1<<DDB5) | (1<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
    // State: Bit7=1 Bit6=1 Bit5=1 Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T
    PORTB=(1<<PORTB7) | (1<<PORTB6) | (1<<PORTB5) | (1<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

    // put your setup code here, to run once:
    DDRH=(0<<DDH7) | (1<<DDH6) | (1<<DDH5) | (1<<DDH4) | (1<<DDH3) | (0<<DDH2) | (1<<DDH1) | (0<<DDH0);
    // State: Bit7=1 Bit6=1 Bit5=1 Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T
    PORTH=(0<<PORTH7) | (1<<PORTH6) | (1<<PORTH5) | (1<<PORTH4) | (1<<PORTH3) | (0<<PORTH2) | (1<<PORTH1) | (0<<PORTH0);
    PORT_DS0 &=~DS0;
  */
  pinMode(DS0, OUTPUT);
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);
  pinMode(SEG_DOT, OUTPUT);
  digitalWrite(DS0, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 16; i++)
  {
    LED_SEG_data(led_data[i], 0);
    delay(500);
  }


  for (int i = 0; i < 16; i++)
  {
    LED_SEG_data(led_data[i], 1);
    delay(500);
  }
}
void LED_SEG_data(unsigned char data, byte use_dot)
{
  /*

    if (data & 0x01)
    {
    PORT_SEG_A |= SEG_A;
    } else {
    PORT_SEG_A &= ~SEG_A;
    }
    if ((data & 0x02) >> 1)
    {
    PORT_SEG_B |= SEG_B;
    } else {
    PORT_SEG_B &= ~SEG_B;
    }
    if ((data & 0x04) >> 2)
    {
    PORT_SEG_C |= SEG_C;
    } else {
    PORT_SEG_C &= ~SEG_C;
    }
    if ((data & 0x08) >> 3)
    {
    PORT_SEG_D |= SEG_D;
    } else {
    PORT_SEG_D &= ~SEG_D;
    }
    if ((data & 0x10) >> 4)
    {
    PORT_SEG_E |= SEG_E;
    } else {
    PORT_SEG_E &= ~SEG_E;
    }
    if ((data & 0x20) >> 5)
    {
    PORT_SEG_F |= SEG_F;
    } else {
    PORT_SEG_F &= ~SEG_F;
    }
    if ((data & 0x40) >> 6)
    {
    PORT_SEG_G |= SEG_G;
    } else {
    PORT_SEG_G &= ~SEG_G;
    }
    if (use_dot)
    {
    PORT_SEG_DOT &= ~SEG_DOT;
    } else {
    PORT_SEG_DOT |= SEG_DOT;
    }
  */
  digitalWrite(SEG_A, data & 0x01);
  digitalWrite(SEG_B, data & 0x02);
  digitalWrite(SEG_C, data & 0x04);
  digitalWrite(SEG_D, data & 0x08);
  digitalWrite(SEG_E, data & 0x10);
  digitalWrite(SEG_F, data & 0x20);
  digitalWrite(SEG_G, data & 0x40);
  if (use_dot)
  {
    digitalWrite(SEG_DOT, data & 0x80);
  }


}
