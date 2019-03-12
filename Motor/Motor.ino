const int motorPin1 = 5;
const int motorPin2 = 6;

void setup()
{
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  /*Motor A anticlockwise for 2 secs*/
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  delay(2000);
  /*Motor A clockwise for 2 secs*/
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  delay(2000);
  /*This code will stop motors*/
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}

void loop()
{

}
