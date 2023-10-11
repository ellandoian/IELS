#include <Servo.h>

#define servoHighPIN 7
#define servoLowPIN 8
#define photoTR A3
#define photoTL A2
#define photoBR A1
#define photoBL A0

Servo servoLow;
Servo servoHigh;
int lightArray[4];

void setup() {
    servoLow.attach(servoLowPIN);
    servoHigh.attach(servoHighPIN);
    pinMode(photoTR, INPUT);
    pinMode(photoTL, INPUT);
    pinMode(photoBR, INPUT);
    pinMode(photoTL, INPUT);
}

void light() {

}

void loop() {
    servoLow.write(30);
    servoHigh.write(120);
}