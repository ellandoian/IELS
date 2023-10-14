int LedPin = 7;
int photoresistor = A5;
unsigned long blinkMillis = 0;
bool state = HIGH;
void setup()

{
    Serial.begin(9600);
    pinMode(LedPin, OUTPUT);
    digitalWrite(LedPin, HIGH);
}

float sensor()
{
    float average;
    float value = 0;
    for (int i = 0; i < 5; i++)
    {
        value += analogRead(photoresistor); //summerer fem sensor avlesninger 
    }
    return average = value / 5; //returnerer den gjennomsnitlige sensorverdien over fem avlesninger
}

float speed(float x) //tar inn en sensorverdi (x) og setter hastighetene til 1, eller 6 ganger så kjapt 
{
    float a;
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
    Serial.println(analogRead(photoresistor));
    blink();
}