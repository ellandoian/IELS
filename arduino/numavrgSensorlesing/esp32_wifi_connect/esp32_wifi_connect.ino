#include <WiFi.h>

const char* ssid = "NTNU-IOT";
const char* password = "";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Connected to WiFi");
  Serial.print("IP:");
  Serial.println(WiFi.localIP());
}

void loop() {
  
}
