# 1 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\reaksjonstid\\reaksjonstid.ino"
# 2 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\reaksjonstid\\reaksjonstid.ino" 2
const int ledCount = 32;
const int ledPin = 2;
Adafruit_NeoPixel pixels(LedCount, LedPin, ((1 << 6) | (1 << 4) | (0 << 2) | (2)) /*|< Transmit as G,R,B*/ + 0x0000 /*|< 800 KHz data transmission*/);

const int pushButton = 4;
bool buttonState = 0x1;
int i = 0;
uint16_t allLys[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
void setup()
{
    pixels.begin();
    pinMode(pushButton, 0x0);
}

void spill()
{
    while (buttonState == 0x0)
    {
        pixels.setPixelColor(allLys[i], pixels.Color(0, 255, 0));
    }
}

void loop()
{

}
