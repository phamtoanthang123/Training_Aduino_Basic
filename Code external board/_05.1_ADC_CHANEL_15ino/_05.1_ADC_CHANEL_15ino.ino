
uint16_t ADC_val;

// Voltage Reference: AVCC pin
#define ADC_VREF_TYPE ((0<<REFS1) | (1<<REFS0) | (0<<ADLAR))
unsigned int adc_read(unsigned char adc_input)
{
ADMUX=(adc_input & 0x1f) | ADC_VREF_TYPE;
if (adc_input & 0x20) ADCSRB|=(1<<MUX5);
else ADCSRB&=~(1<<MUX5);
// Delay needed for the stabilization of the ADC input voltage
delayMicroseconds(100);
// Start the AD conversion
ADCSRA|=(1<<ADSC);
// Wait for the AD conversion to complete
while ((ADCSRA & (1<<ADIF))==0);
ADCSRA|=(1<<ADIF);
return ADCW;
}
void setup() {
  // AREF = AVcc
    ADMUX = (1<<REFS0);
 
    // ADC Enable and prescaler of 128
    // 16000000/128 = 125000
    ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
    
Serial.begin(9600);
Serial.println("hello");
}

void loop() {
  // put your main code here, to run repeatedly:
  ADC_val=adc_read(B100111);
Serial.println(ADC_val);
delay(100);
}
