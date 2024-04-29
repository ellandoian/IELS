#include "Deploii_ESP32.h"

Deploii oi; //lager en "instans"/objekt av biblioteket

const char ssid[] = "NTNU-IOT";  //Sett inn nettverksnavn her
const char passord[] = "";  //Sett inn nettverkspassord her
const char kortID[] = "hU6wrOQH9A7C5ARbgZPM";  //Sett inn Kort-ID her

const int LED = 16;
const int pot = 32;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT); //setter opp et LED-lys på pin 33
  pinMode(pot, INPUT);
  oi.oppkobling(ssid, passord, kortID); //kobler opp til Deploii-nettsiden
}

void sendData() { //Sender data fra kort til nettsiden
  float meat_lover = analogRead(pot);
  oi.send("meat_lover", meat_lover); //Biblioteksfunksjon som sender data
}

void mottaData(String modulID, String data) { //Får data fra nettsiden
  //Reager på kontrollpanelmodulene
  static bool flag1 = false;
  static uint32_t WTimer = millis();
  if (modulID == "tastatur") { //reagerer på kontrollpanelmodulen tastaturstyring
    if ((data == "W") && (flag1 == false) && (millis() - WTimer >= 50)) { //Skrur LED på om "W" trykkes på nettsiden
      digitalWrite(LED, HIGH); 
      flag1 = !flag1;
      WTimer = millis();
    }
    if ((data == "W") && (flag1 == true) && (millis() - WTimer >= 50)) { //Skrur LED av om "S" trykkes på nettsiden
      digitalWrite(LED, LOW);
      flag1 = !flag1;
      WTimer = millis();
    }
  }
}

void loop() {
  oi.loop(); //Holder oppkoblingen til serveren gående
  /* OBS! OBS! Det er veldig viktig at det ikke brukes delay noen som helst sted i koden.
  Delay vil bryte opp koblingen mellom mikrokontrolleren og nettsiden. 
  Bruk oi.intervall() funksjonen for å lage repeternde hendelser istedenfor.
  */

  oi.intervall(2000, sendData); //Kaller sendData funksjonen hvert andre sekund
}