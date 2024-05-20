#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  for (int i = 2; i < 8; i++)
  {
    pinMode(i, OUTPUT);
  }
}

int i;

void loop() {
  i = Serial.read();
  if (i >= 49 && i <= 54)
  {
    digitalWrite(i - 47, HIGH);
    Serial.print("LED ");
    Serial.print(i - 48);
    Serial.print(" light on\r\n");
    delay(500);
    digitalWrite(i - 47, LOW);
  }
}