int pushButton = 25;

void setup() {
  pinMode(pushButton, INPUT);
  Serial.begin(9600);
}

bool button(int trueTime)  //trueTime is how long you want the button to return TRUE
//"pushButton" is the physical button, change name accordingly 
{
  static bool val, buttonVar, lastButtonState = false;
  static uint32_t timer;
  if (digitalRead(pushButton) == HIGH) {
    buttonVar = true;  // setter buttonVar til true mens knappen er klikket ned
    timer = millis();
  }
  if ((digitalRead(pushButton) == LOW) && (buttonVar == true))  // vil kjøre når knappen slippes og endrer retur variablen
  {
    val = true;
    if (millis()-timer > trueTime) val, buttonVar = false;
  }
  return val;
}

void loop() {
  if (button(50)) Serial.println('a');
}
