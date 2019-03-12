void setup() {
  Serial.begin(9600);
}

void loop() {
  int y = analogRead(A0);
  Serial.println(y);
  y = map(y, 0, 1023, 0, 255);
  Serial.print("Motor Value:");
  Serial.println(y);
  analogWrite(9, y);
  delay(500);
}
