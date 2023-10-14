#include <Arduino.h>
#line 1 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\3LEDmillisLangtknappeklikk\\3LEDmillisLangtknappeklikk.ino"
int LedPin1 = 12;
int LedPin2 = 11;
int LedPin3 = 13;
bool lastButtonState = LOW;
unsigned long blinkMillis;
int intervall = 500;
int pushButton = 2;
bool valg, a, state = true;

#line 10 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\3LEDmillisLangtknappeklikk\\3LEDmillisLangtknappeklikk.ino"
void setup();
#line 17 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\3LEDmillisLangtknappeklikk\\3LEDmillisLangtknappeklikk.ino"
bool button();
#line 31 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\3LEDmillisLangtknappeklikk\\3LEDmillisLangtknappeklikk.ino"
void switcher();
#line 40 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\3LEDmillisLangtknappeklikk\\3LEDmillisLangtknappeklikk.ino"
void blink();
#line 50 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\3LEDmillisLangtknappeklikk\\3LEDmillisLangtknappeklikk.ino"
void loop();
#line 10 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\3LEDmillisLangtknappeklikk\\3LEDmillisLangtknappeklikk.ino"
void setup(){
    pinMode(LedPin1, OUTPUT);
    pinMode(LedPin2, OUTPUT);
    pinMode(LedPin3, OUTPUT);
    Serial.begin(9600);
}

bool button() //må initaliserer "valg" og "a" i oppstart
{   
    if (digitalRead(pushButton) == HIGH)
    {
        a = true; //setter a til true mens knappen er klikket ned
    }
    if ((digitalRead(pushButton) == LOW) && (a == true))  //vil kjøre når knappen slippes og endrer retur variablen
    {
        valg = !valg;
        a = false;
    }
    return valg;
}

void switcher(){
    bool a = button();
    if (a != lastButtonState){
        digitalWrite(LedPin2, lastButtonState);
        digitalWrite(LedPin3, !lastButtonState);
        lastButtonState = a;
    }
}

void blink()
{
    if (millis() >= blinkMillis + intervall) //kjører hver hver gang intervallet har hendt
    {
        state = !state; //endrer state slik at LED vil blinke
        digitalWrite(LedPin1, state);
        blinkMillis = millis(); 
    }
}

void loop(){
    blink();
    switcher();
}
