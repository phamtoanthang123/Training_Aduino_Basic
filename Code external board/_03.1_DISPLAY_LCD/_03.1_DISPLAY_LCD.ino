//RS ---> PB7(D13)
//EN ---> PB6(D12)
//BL ---> None
//RW ---> None

//D4:D4 ---> PB5
//D5:D5 ---> PB4
//D6:D6 ---> PH6
//D7:D7 ---> PH5
//////////////////////////////////
//#define USE_BL
//#define USE_WR
///////////////////////////////
#define RS 1<<PB7
#define EN 1<<PB6
#ifdef USE_BL
  #define BL 1<<PB7
#endif
#ifdef USE_WR
  #define BL 1<<PB7
#endif
#define D4 1<<PB5
#define D5 1<<PB4
#define D6 1<<PH6
#define D7 1<<PH5

#define PORT_RS PORTB
#define PORT_EN PORTB

#ifdef USE_BL
  #define PORT_BL 1<<PB7
#endif
#ifdef USE_WR
  #define PORT_WR 1<<PB7
#endif

#define PORT_D4 PORTB
#define PORT_D5 PORTB
#define PORT_D6 PORTH
#define PORT_D7 PORTH
/////////////////////
void LCD_TurnLight(uint8_t status);
void LCD_Enable();
void LCD_Send4Bit(unsigned char Data);
void LCD_SendCommand(unsigned char command);
void LCD_Clear();
void LCD_Init();
void LCD_Gotoxy(unsigned char x, unsigned char y);
void LCD_PutChar(unsigned char Data);
void LCD_Puts(char *s);
////////////////////////
void setup() {
  // put your setup code here, to run once:
DDRB=(1<<DDB7) | (1<<DDB6) | (1<<DDB5) | (1<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=1 Bit6=1 Bit5=1 Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTB=(1<<PORTB7) | (1<<PORTB6) | (1<<PORTB5) | (1<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

  // put your setup code here, to run once:
DDRH=(0<<DDH7) | (1<<DDH6) | (1<<DDH5) | (0<<DDH4) | (0<<DDH3) | (0<<DDH2) | (0<<DDH1) | (0<<DDH0);
// State: Bit7=1 Bit6=1 Bit5=1 Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTH=(0<<PORTH7) | (1<<PORTH6) | (1<<PORTH5) | (0<<PORTH4) | (0<<PORTH3) | (0<<PORTH2) | (0<<PORTH1) | (0<<PORTH0);

LCD_Init();
}

void loop() {
  // put your main code here, to run repeatedly:
LCD_Gotoxy(0,0);
 LCD_Puts("HELLO WORLD");
}
////////////////////////////// LCD FUNCTION /////////////////////////
void LCD_Enable()
{
  PORT_EN |= EN;
  delay(1);
  PORT_EN &= ~EN;
  delay(1); 
}

void LCD_Send4Bit(unsigned char Data)
{
 if(Data&0x01)
 {
  PORT_D4 |= D4;
 }
 else
 {
   PORT_D4 &= ~D4;
 }
 if((Data>>1)&0x01)
 {
  PORT_D5 |= D5;
 
 }
 else
 {
   PORT_D5 &= ~D5;
 }
 if((Data>>2)&0x01)
 {
  PORT_D6 |= D6;
 
 }
 else
 {
   PORT_D6 &= ~D6;
 }
 if((Data>>3)&0x01)
 {
  PORT_D7 |= D7;
 }
 else
 {
   PORT_D7 &= ~D7;
 }
}

void LCD_SendCommand(unsigned char command)
{
  LCD_Send4Bit(command >>4);/* Gui 4 bit cao */
  LCD_Enable();
  LCD_Send4Bit(command);  /* Gui 4 bit thap*/
  LCD_Enable();
}
/* USER CODE END 0 */
void LCD_Clear()
{
  LCD_SendCommand(0x01);  
  delay(1); 
}

void LCD_Init()
{
  LCD_Send4Bit(0x00);
  PORT_RS &= ~RS;
  LCD_Send4Bit(0x03);
  LCD_Enable();
  LCD_Enable();
  LCD_Enable();
  LCD_Send4Bit(0x02);
  LCD_Enable();
  LCD_SendCommand(0x28); // giao thuc 4 bit, hien thi 2 hang, ki tu 5x8
  LCD_SendCommand(0x0C); // cho phep hien thi man hinh
  LCD_SendCommand(0x06); // tang ID, khong dich khung hinh
  LCD_SendCommand(0x01); // xoa toan bo khung hinh
}

void LCD_Gotoxy(unsigned char x, unsigned char y)
{
  unsigned char address;
    if(!y)address=(0x80+x);
    else address=(0xC0+x);
    LCD_SendCommand(address);

}

void LCD_PutChar(unsigned char Data)
{
  PORT_RS |= RS;
  LCD_SendCommand(Data);
  PORT_RS &= ~RS;
}

void LCD_Puts(char *s)
{
    while (*s){
        LCD_PutChar(*s);
      s++;
    }
}
void LCD_TurnLight(uint8_t status)
{
#ifdef USE_BL
 

  if(status)
  {
    
  }
  else
  {
    
  }
#endif
}
