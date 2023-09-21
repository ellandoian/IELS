#include <Adafruit_NeoPixel.h>

int LedCount = 32;
int LedPin = 13;

Adafruit_NeoPixel pixels(LedCount, LedPin, NEO_GRB + NEO_KHZ800);

uint32_t lilla = pixels.Color(146, 43, 226); // setter opp fargene
uint32_t morkeBla = pixels.Color(6, 108, 242);
uint32_t turkis = pixels.Color(0, 227, 255);
uint32_t lyseGron = pixels.Color(0, 242, 197);
uint32_t gronBla = pixels.Color(0, 205, 255);
uint32_t bla = pixels.Color(46, 110, 238);
uint32_t kaldPulserer[6] = {lilla, morkeBla, turkis, lyseGron, gronBla, bla};

uint16_t allLys[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};

int potMeter1 = A1;

int i;
int pixel;
unsigned long currentMillis;
int timer100 = 100;

void setup()
{
    pixels.begin();
    Serial.begin(9600);
}

void lysshow2()
{ // setter alle lysene til det "i" er for tilsvarende index i listen "kaldPulserer" når det er gjort, endres i med +1
    currentMillis = millis();
    i = 0;
    for (pixel = 0; i < LedCount; pixel++)
    {
        pixels.setPixelColor(allLys[pixel], kaldPulserer[i]);
        pixels.show();
        int reader = analogRead(potMeter1);
        delay(1*reader);
        if (pixel >= 31)
        {
            if (millis() >= currentMillis + timer100)
            {
                i++;
                pixel = -1;
                currentMillis = millis();
            }
        }
    }
}
void loop()
{
    lysshow2();
}
