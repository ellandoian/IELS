# 1 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\32LED\\32LED.ino"
# 2 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\32LED\\32LED.ino" 2

int LedCount = 32;
int LedPin = 7;

Adafruit_NeoPixel pixels(LedCount, LedPin, ((3 << 6) | (1 << 4) | (0 << 2) | (2)) /*|< Transmit as G,R,B,W*/ + 0x0000 /*|< 800 KHz data transmission*/);
void setup(){

}
void loop(){}
