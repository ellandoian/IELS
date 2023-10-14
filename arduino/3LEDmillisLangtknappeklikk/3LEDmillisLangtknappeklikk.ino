int LedPin1 = 3;
bool state = HIGH;
unsigned long blinkMillis;
int intervall = 500;

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