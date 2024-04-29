TaskHandle_t blinkTask;
TaskHandle_t fadeTask;
int fadeVar = 0;

void setup() {
  ledcSetup(0, 2000, 8);
  ledcAttachPin(22, 0);
  xTaskCreatePinnedToCore(blinkFunc, "blink", 1000, NULL, 1, &blinkTask, 0);  //setter function "blincFunc", til å kjøre på core 0 med 1000 bytes
  xTaskCreatePinnedToCore(fadeFunc, "fade", 1000, NULL, 1, &fadeTask, 1);     //setter funksjon "fadeFunc", til å kjøre op core 1 med 1000 bytes
}

void blinkFunc(void* pvParameters) {
  for (;;) {  //uendelig for løkke'
    static bool blink = LOW;
    static uint32_t blinkTime = millis();
    static int8_t blinkVar = 0;

    ledcWrite(0, (255 - fadeVar) * blinkVar);
    if ((millis() - blinkTime) >= 250) {
      blinkVar++;
      if (blinkVar > 1) blinkVar = 0;
      blinkTime = millis();
    }
  }
}

void fadeFunc(void* pvParameters) {
  for (;;) {  //uendelig for løkke
    while (fadeVar <= 255){
      fadeVar = fadeVar + 10;
      delay(60);
    }
    while(fadeVar >= 0){
      fadeVar = fadeVar - 10;
      delay(60);
    }
  }
}

void loop() {
}
