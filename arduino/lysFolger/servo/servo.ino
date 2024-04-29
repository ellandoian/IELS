#include <ESP32Servo.h>
Servo servo;

void setup() {
 servo.attach(32);
}

void loop() {
  static bool posCheck = HIGH;
  static uint32_t posTimer = millis();
  static uint8_t pos = 0;
  if (posCheck == HIGH){
    if ((millis()-posTimer)>= 15){
      pos++;
      posTimer = millis();
    }
    if (pos>=179) posCheck = !posCheck;
  }
  else{
    if((millis()-posTimer) >= 15){
      pos--;
      posTimer = millis();
    }
    if (pos<=1) posCheck = !posCheck;
  }
  servo.write(pos);
}
