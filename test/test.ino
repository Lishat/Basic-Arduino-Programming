#include <dht.h>
#include <Wire.h>
dht DHT;
#define DHT_PIN 2
void setup() {
   Serial.begin(9600);
}

void loop() {
   DHT.read11(DHT_PIN);
        Serial.println(DHT.humidity);
        Serial.println(DHT.temperature);
        delay(5000);
}
