int ledTest = 10;

void setup()
{
    Serial.begin(9600);
    pinMode(ledTest, OUTPUT);
}

void testSerial()
{
    Serial.print("hei");
    delay(200);
    digitalWrite(ledTest, HIGH);
}
void loop()
{
    testSerial();
}
