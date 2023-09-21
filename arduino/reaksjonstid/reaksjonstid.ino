#include <Adafruit_NeoPixel.h>
const int ledCount = 32;
const int ledPin = 2;
Adafruit_NeoPixel pixels(LedCount, LedPin, NEO_GRB + NEO_KHZ800);

const int pushButton = 4;
bool buttonState = HIGH;
int i = 0;
uint16_t allLys[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
void setup()
{
    pixels.begin();
    pinMode(pushButton, INPUT);
}

void spill()
{
    while (buttonState == LOW)
    {
        pixels.setPixelColor(allLys[i], pixels.Color(0, 255, 0));
    }
}

void loop()
{

}