#include <Servo.h>

#define servoHighPIN 7
#define servoLowPIN 8
#define photoTR A3
#define photoTL A2
#define photoBR A1
#define photoBL A0
int bigLight;
int bigIndex;

Servo servoLow;
Servo servoHigh;
int lightArray[4];

void setup()
{
    Serial.begin(9600);
    servoLow.attach(servoLowPIN, -180, 180);
    servoHigh.attach(servoHighPIN, -180, 180);
    pinMode(photoTR, INPUT);
    pinMode(photoTL, INPUT);
    pinMode(photoBR, INPUT);
    pinMode(photoTL, INPUT);
}

void light()
{
    lightArray[0] = analogRead(photoTR);
    lightArray[1] = analogRead(photoTL);
    lightArray[2] = analogRead(photoBR);
    lightArray[3] = analogRead(photoBL);
    bigLight = 0;
    bigIndex = 0;
    for (int i = 0; i < 4; i++)
    {
        if (lightArray[i] > bigLight)
        {
            bigLight = lightArray[i];
            bigIndex = i;
        }
    }
}

void servoS(){
    light();
}

void loop()
{
    servoLow.write(30);
    servoHigh.write(120);
}