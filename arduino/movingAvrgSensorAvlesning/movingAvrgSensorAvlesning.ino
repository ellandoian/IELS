#include <movingAvg.h>

int LedPin = 7;
int photoresistor = A5;
unsigned long blinkMillis = 0;
bool state = HIGH;
movingAvg lightSensor(5); //setter opp lightSensor til å bestå av fem data punkter

void setup()
{
    lightSensor.begin(); //starter variabelen lightSensor som et moving average av 5 lesniger
    pinMode(LedPin, OUTPUT);
    digitalWrite(LedPin, HIGH);
}

int sensor()
{
    int i = lightSensor.reading(analogRead(photoresistor)); 
    return i; 
    /*tar måling av photoresistor og regner ut gjennomsnittet av de siste fem lesningene, 
    om det har ått mindre enn fem iterasjoner, tar den gjennomsnittet av antall datapunkter den har*/
}

int speed(int x) //tar inn en sensorverdi (x) og setter hastighetene til 1, eller 6 ganger så kjapt 
{
    int a;
    if (x < 100)
    {
        a = 100;
    }
    else
    {
        a = 500;
    }
    return a; //returnerer hastigheten
}

void blink()
{
    if (millis() >= blinkMillis + speed(sensor())) //kjører hver hver gang intervallet speed() har hendt
    {
        state = !state; //endrer state slik at LED vil blinke
        digitalWrite(LedPin, state);
        blinkMillis = millis(); 
    }
}

void loop()
{
    blink();
}