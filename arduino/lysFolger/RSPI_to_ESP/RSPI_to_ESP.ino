#define RXD2 16
#define TXD2 17

void setup() {
  pinMode(19, OUTPUT);
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial.println("Serial Txd is on pin: "+String(TX));
  Serial.println("Serial Rxd is on pin: "+String(RX));
}

void loop() { 
  /*if (Serial2.available() != 0){
    Serial2.print('r');
    Serial.println('hei');
  }*/
  while (Serial2.available()) {
    char data = Serial2.read();
    Serial.println(data);
    if (data == 'Y') {
      digitalWrite(19, HIGH);
    }
    if (data == 'N') {
      digitalWrite(19, LOW);
  }
  }
} 
