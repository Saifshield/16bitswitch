#define D6 13

byte MSByte;
byte LSByte;

byte arr[8] = {0x00, 0x01, 0x00, 0x02, 0x00, 0x04, 0x00, 0x08};

void setup() { 
  Serial.begin(9600);
  /* Set MOSI and SCK output, all others input */
  DDRB = (1<<DDB2)|(1<<DDB1)|(1<<DDB0);
  /* Enable SPI, Master, set clock rate fck/4 */
  SPCR =(1<<SPE)|(1<<MSTR)|(1<<CPOL)|(1<<CPHA)|(1<<SPR1); 
  /* GPIO */
  pinMode(D6, OUTPUT);
  digitalWrite(D6, HIGH);  
} 

void loop() 
{ 
//  if (Serial.available() >= 2)
//  {
//    MSByte = Serial.read();
//    LSByte = Serial.read();
//    Serial.print(MSByte);
//    Serial.print(LSByte);
//    SPDR = MSByte;              //Start transmission
//    while(!(SPSR & (1<<SPIF))); //Wait for transmission complete
//    SPDR = LSByte;
//    while(!(SPSR & (1<<SPIF)));
//    delayMicroseconds(100); 
//    digitalWrite(D6, LOW);
//    delayMicroseconds(100); 
//    digitalWrite(D6, HIGH);
//  }

 for( int i = 0; i < 8; i++) {
    SPDR = arr[i];
    while(!(SPSR & (1<<SPIF)));
    Serial.println(i);
    //Serial.println(arr[i]);
    i++;
    SPDR = arr[i];
    while(!(SPSR & (1<<SPIF)));
    Serial.println(i);
    //Serial.println(arr[i]);
    digitalWrite(D6, LOW);
    delay(2000);
    digitalWrite(D6, HIGH);
 }

//    SPDR = arr[0];
//    while(!(SPSR & (1<<SPIF)));
//    //Serial.println(arr[i]);
//    SPDR = arr[7];
//    while(!(SPSR & (1<<SPIF)));
//    //Serial.println(arr[i]);
//    digitalWrite(D6, LOW);
//    //delay(1000);
//    digitalWrite(D6, HIGH);
}

