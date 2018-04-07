/*
#define DS0 1<<PB7
#define DS1
#define DS2
#define DS3

#define PORT_DS0 PORTD
#define PORT_DS1 PORTD
#define PORT_DS2 PORTD
#define PORT_DS3 PORTD

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
byte led_data[16]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
long cout_sec,counter,now_time,a,b,c,d;
byte sw_led;
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

  // put your setup code here, to run once:
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (1<<DDD3) | (1<<DDD2) | (1<<DDD1) | (1<<DDD0);
// State: Bit7=1 Bit6=1 Bit5=1 Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (1<<PORTD3) | (1<<PORTD2) | (1<<PORTD1) | (1<<PORTD0);
*/
}

void loop() {

  if(micros()-now_time>5)
  {
    sw_led++;cout_sec++;
    if(counter>9999)counter=0;
    a=counter/1000;
    b=counter/100-a*10;
    c=counter/10-a*100-b*10;
    d=counter-a*1000-b*100-c*10;
    now_time=micros();
  }
  if(cout_sec>1000)
  {
    cout_sec=0;counter++;
    
    }
  if(sw_led>3)sw_led=0;
  if(sw_led==0)
  {
    LED_SEG_DATA(led_data[d],0);
    PORTD=0x0e;
    
  }
  else if(sw_led==1)
  {
    if(counter>9)
    {
    LED_SEG_DATA(led_data[c],0);
    PORTD=0x0d;
    }
    
  }
  else if(sw_led==2)
  {
    if(counter>99)
    {
    LED_SEG_DATA(led_data[b],0);
    PORTD=0x0b;
    }
    
  }
  else if(sw_led==3)
  {
    if(counter>999)
    {
    LED_SEG_DATA(led_data[a],1);
    PORTD=0x07;
    }
    
  }
  
}
void LED_SEG_DATA(unsigned char Data,byte use_dot)
{
  if (Data & 0x01)     {PORT_SEG_A |= SEG_A;}else{ PORT_SEG_A &= ~SEG_A;}
  if ((Data & 0x02)>>1){PORT_SEG_B |= SEG_B;}else{ PORT_SEG_B &= ~SEG_B;}
  if ((Data & 0x04)>>2){PORT_SEG_C |= SEG_C;}else{ PORT_SEG_C &= ~SEG_C;}
  if ((Data & 0x08)>>3){PORT_SEG_D |= SEG_D;}else{ PORT_SEG_D &= ~SEG_D;}
  if ((Data & 0x10)>>4){PORT_SEG_E |= SEG_E;}else{ PORT_SEG_E &= ~SEG_E;}
  if ((Data & 0x20)>>5){PORT_SEG_F |= SEG_F;}else{ PORT_SEG_F &= ~SEG_F;}
  if ((Data & 0x40)>>6){PORT_SEG_G |= SEG_G;}else{ PORT_SEG_G &= ~SEG_G;}
  if(use_dot){PORT_SEG_DOT &= ~SEG_DOT;}else{PORT_SEG_DOT |= SEG_DOT;}
  
}
