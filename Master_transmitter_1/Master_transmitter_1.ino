#include <Wire.h> //include wire library

void setup() //this will run only once 
{ 
   Wire.begin(); // join i2c bus as master
} 

int age = 100; 

void loop() {   
   Wire.beginTransmission(2); 
   // transmit to device #2
   Wire.write("age is = ");
   Wire.write("545645645"); // sends one byte
   Wire.endTransmission(); // stop transmitting
   delay(1000); 
}
