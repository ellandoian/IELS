#include <Arduino.h>
#include <SPI.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_1_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);

void setup(void) {
  u8g2.begin();
}

void loop(void) {
  u8g2.firstPage();
  do {
    
    u8g2.setFont(u8g2_font_ncenB14_tr);
    int q = 3;    
    u8g2.setCursor(64, 32);
    u8g2.print(q);
  } while ( u8g2.nextPage() );
  delay(1000);
}
