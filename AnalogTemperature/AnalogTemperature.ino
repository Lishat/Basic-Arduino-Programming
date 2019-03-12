  #include <SoftwareSerial.h>
  #define DEBUG true
  int val;
  int tempPin = 1;
  SoftwareSerial mySerial(2,3);
  void setup()
  {
     mySerial.begin(9600);
     Serial.begin(9600); 

     sendData("AT+CWMODE=3\r\n", 1000, DEBUG);
     sendData("AT+CWLAP\r\n", 1000, DEBUG);
     sendData("AT+CWJAP='ApE','pandu1234'\r\n",1000, DEBUG);
     sendData("AT+CIPMUX=1\r\n",1000, DEBUG);
     sendData("AT+CIPSERVER=1,8888\r\n",1000, DEBUG);
     sendData("AT+CIFSR\r\n",1000,DEBUG);
     Serial.println("AT+CIFSR");
     sendData("AT+CISEND=0,100\r\n",1000,DEBUG);
     sendData("AT+CISEND=0,100\r\n",1000,DEBUG);
     
     
  }
  
  void loop()
  {
     val = analogRead(tempPin);
     float mv = (val/1024.0)*5000;    /*5000 represents 5V, 1024 is representation of 10 bits*/
     float cel = mv/100;                /*For every 10mV change 1 degree Centigrade increases*/
     float farh = (cel*9)/5 + 32;
     Serial.print("TEMPERATURE = ");
     Serial.print(cel);
     Serial.print("*C");
     Serial.println();
     delay(1000);
  }

  String sendData(String command, const int timeout, boolean debug)
{
    String response = "";
    
    mySerial.print(command); // send the read character to the Serial1
    
    long int time = millis();
    while( (time+timeout) > millis())
    {
      while(mySerial.available())
      {
        
        // The esp has data so display its output to the serial window 
        char c = mySerial.read(); // read the next character.
        response+=c;
      }  
    }
    if(debug)
    {
      Serial.print(response);
    }
    
    return response;
}
