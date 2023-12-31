#include <Adafruit_NeoPixel.h>
const int ledCount = 32;
const int ledPin = 2;
Adafruit_NeoPixel pixels(ledCount, ledPin, NEO_GRB + NEO_KHZ800);

const int pushButton = 4;
const int avPaa = 6;
int i = 0;
int o;
uint16_t allLys[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
int x = 1;
int y = 1;
bool aP = false;
int score = 0;
bool chck;
int dly = 65;

void setup()
{
    pixels.begin();
    Serial.begin(9600);
    pinMode(pushButton, INPUT);
    pinMode(avPaa, INPUT);
}

void spill()
{
    for(int l=0; l<ledCount; l++)
    {
        pixels.setPixelColor(allLys[l], pixels.Color(180, 0, 60));
        pixels.show();
    }
    for(o=0; o<4; o)
    {
        if (aP == true)
        {
            while(digitalRead(pushButton) == LOW)
            {
                if(y == 1)
                {
                    pixels.setPixelColor(allLys[i], pixels.Color(0, 155, 0));
                    pixels.show();
                    delay(dly);
                    i += y;
                    if (i == 32)
                    {
                        y = -y;
                    }
                }
                else
                {
                    pixels.setPixelColor(allLys[i], pixels.Color(180, 0, 60));
                    pixels.show();
                    delay(dly);
                    i += y;
                    if (i == -1)
                    {
                        y = -y;
                    }
                }
            }
            if(dly == 65)
            {
                dly = 40;
            }
            else if(dly == 40)
            {
                dly = 20;
            }
            else if(dly == 20)
            {
                dly = 10;
            }
            else if(dly == 10)
            {
                dly = 65;
            }
            if(i == 32)
            {
                score = score;
            }
            else if(y == -1)
            {
                score += 32-i-1;
            }
            else
            {
                score += 32-i;
            }
            aP = false;
            o++;
        }
        else
        {
            delay(100);
            if(digitalRead(avPaa) == HIGH)
            {
                chck = true;
            }
            if((digitalRead(avPaa) == LOW) && (chck == true))
            {
                aP = true;
                chck = false;
            }
        }
    }
    Serial.print("Du mistet ");
    Serial.print(score);
    Serial.println(" poeng");
    o = 0;
    delay(1500);
    score = 0;
}

void loop()
{
    spill();
}