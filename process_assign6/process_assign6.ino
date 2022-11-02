#include <Wire.h>
#define SLAVE_ADDR 9
int analogPin = A3;
int val=0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  delay(50);
  //read pot value 
  //map to rnge of 1-255 for flash rate 
  val = map(analogRead(analogPin),0,1023,255,1);

  //write a charcter to the slave 
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(val);
  Wire.endTransmission();

}
