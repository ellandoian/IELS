#include <Arduino.h>
#line 1 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\3LEDmillisLangtknappeklikk\\3LEDmillisLangtknappeklikk.ino"
int LedPin1 = 3;
bool state = HIGH;
unsigned long blinkMillis;
int intervall = 500;

#line 6 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\3LEDmillisLangtknappeklikk\\3LEDmillisLangtknappeklikk.ino"
void setup();
#line 10 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\3LEDmillisLangtknappeklikk\\3LEDmillisLangtknappeklikk.ino"
void blink();
#line 20 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\3LEDmillisLangtknappeklikk\\3LEDmillisLangtknappeklikk.ino"
void loop();
#line 6 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\3LEDmillisLangtknappeklikk\\3LEDmillisLangtknappeklikk.ino"
void setup(){
    pinMode(LedPin1, OUTPUT);
}
void button();
void blink()
{
    if (millis() >= blinkMillis + intervall) //kjører hver hver gang intervallet speed() har hendt
    {
        state = !state; //endrer state slik at LED vil blinke
        digitalWrite(LedPin1, state);
        blinkMillis = millis(); 
    }
}

void loop(){
    blink();
}
