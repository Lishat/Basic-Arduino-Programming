void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

char rx_byte = 0;
void loop() {
  if(Serial.available() > 0)
  {
    rx_byte = Serial.read();
    if((rx_byte >= '0') && (rx_byte <= '9'))
    {
      Serial.print("Number received:");

      Serial.println(rx_byte);
      if((rx_byte >= '0') && (rx_byte <= '5'))
      {
        Serial.print("Forward ");
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
      }
      else if((rx_byte >= '6') && (rx_byte <= '9'))
      {
        Serial.print("Backward ");
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
      }
    }
  }
}
