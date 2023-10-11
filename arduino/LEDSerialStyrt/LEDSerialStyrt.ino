char receivedChar;
int greenLED = 2;
bool greenHL = LOW;
int redLED = 3;
bool redHL = LOW;
int blueLED = 4;
bool blueHL = LOW;
void setup()
{
    pinMode(greenLED, OUTPUT);
    pinMode(redLED, OUTPUT);
    pinMode(blueLED, OUTPUT);
    Serial.begin(9600);
}

void noe()
{
    if (Serial.available() > 0)
    {
        receivedChar = Serial.read();
        switch (receivedChar)
        {
        case 'G':
            greenHL = !greenHL;
            digitalWrite(greenLED, greenHL);
            break;
        case 'R':
            redHL = !redHL;
            digitalWrite(redLED, redHL);
            break;
        case 'B':
            blueHL = !blueHL;
            digitalWrite(blueLED, blueHL);
            break;
        }
    }
}
void loop()
{
    noe();
}