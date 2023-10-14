# 1 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\poengvisning\\poengvisning.ino"
# 2 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\poengvisning\\poengvisning.ino" 2
const int ledCount = 32;
const int ledPin = 2;
Adafruit_NeoPixel pixels(ledCount, ledPin, ((1 << 6) | (1 << 4) | (0 << 2) | (2)) /*|< Transmit as G,R,B*/ + 0x0000 /*|< 800 KHz data transmission*/);

uint16_t allLys[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
int score = 0;
int tellerA;
int tellerB;

void setup()
{
    pixels.begin();
    Serial.begin(9600);
}

void loop()
{
    tellerA = score % ledCount;
    tellerB = (score-tellerA) / ledCount;
    for(tellerB;tellerB>0;tellerB){}
    /*for(score; score > 0; score--){

        for(tellerA; score)

        pixels.setPixelColor(allLys[tellerA], pixels.Color(180, 0, 60));

        pixels.show();

    }*/
# 27 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\poengvisning\\poengvisning.ino"
}
