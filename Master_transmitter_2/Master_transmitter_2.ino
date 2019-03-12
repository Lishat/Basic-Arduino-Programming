#include <Wire.h> //include wire library

void setup() {  //this will run only once
   Wire.begin(2); // join i2c bus with address #2
   Wire.onReceive(receiveEvent); // call receiveEvent when the master send any thing 
   Serial.begin(9600); // start serial for output to print what we receive 
}

void loop() {   
   delay(250); 
}

//-----this function will execute whenever data is received from master-----//

void receiveEvent(int howMany) { 
   while (Wire.available()>1) // loop through all but the last 
   {
      char c = Wire.read(); // receive byte as a character
      Serial.print(c); // print the character
   }
}
