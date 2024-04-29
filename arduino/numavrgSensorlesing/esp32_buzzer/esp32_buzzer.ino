void setup() {
  ledcSetup(0, 2000, 8);
  ledcAttachPin(33, 0);
}

void buzz() {
  static unsigned long buzzTime = millis();
  static int tone;
  if (millis() - 500 >= buzzTime) {
    tone = random(200, 800);
    buzzTime = millis();
    ledcWriteTone(0, tone);
  }
}

void loop() {
  buzz();
}
