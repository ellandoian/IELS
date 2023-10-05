int pushButton = 7;
bool buttonValue = false;
float voltage;
bool valg = 0;

void setup(){
pinMode(pushButton, INPUT);
Serial.begin(9600);
}
void loop()
{
    bool lastButtonValue;
    if (buttonValue == HIGH)
    {
        delay(50);
        lastButtonValue = buttonValue;
        Serial.println("a");
        Serial.println(buttonValue);

    }
    buttonValue = digitalRead(pushButton);
    if ((buttonValue == LOW) && (lastButtonValue != buttonValue))
    {
        buttonValue = digitalRead(pushButton);
        valg = !valg;
        lastButtonValue = false;
        delay(50);
        Serial.println("b");
    }
}