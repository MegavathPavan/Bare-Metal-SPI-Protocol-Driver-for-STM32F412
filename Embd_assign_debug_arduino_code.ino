#include <SPI.h>

int slaveSelect = 10; // configuration for Arduino board
int delayTime = 1;  // delay for smooth functioning
void setup() {

 Serial.begin(115200);  //baud rate selection for serial monitor

 // configuatration for SPI protocol on Arduino board
 pinMode(slaveSelect,OUTPUT);
 digitalWrite(slaveSelect,HIGH);
 SPI.begin();
 SPI.setBitOrder(MSBFIRST);
 SPI.setDataMode(SPI_MODE0);
 SPI.setClockDivider(SPI_CLOCK_DIV2);
}

void loop() {
    // for receiving signal/data
  if (Serial.available()>0){  //check if there is data in buffer
    while(Serial.available()>0){  // send until buffer is empty
      char x =  Serial.read();  // read from serial monitor
      digitalWrite(slaveSelect,LOW);  //select to send it to slave
      delay(1); // delay 1ms
      SPI.transfer(x);  // send data
      delay(1); //delay ms
      digitalWrite(slaveSelect,HIGH); //stop transmission
      delay(1); //delay 1ms
      Serial.print(x);
      }
    }
}
