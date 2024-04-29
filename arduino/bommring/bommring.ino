#include <Arduino_APDS9960.h>
int potPin = 27;
int potVal = 2;
void setup() {
  Serial.begin(115200);
  APDS.begin();
}

int carCount(int proxy) {    //teller hvor mange biler som har kjørt forbi bommen, tar inn proximity dataen
  static int cCounter = -1;  //vil autmatisk telle +1 når koden kjøres første gang, verdi på -1 gjør at den starter på 0
  static bool countState = false;

  if (proxy < 235) countState = true;    //veien ligger på runt 242, redisterer når noe har kommet til bommen
  else if (proxy > 235 && countState) {  //når bilen har kjørt helt gjennom bommen, vil bilen bli telt
    cCounter++;
    countState = false;
  }
  return cCounter;
}

int* colorRead() {
  static int rgb[3];
  while (!APDS.colorAvailable()) {
    delay(5);
  }
  APDS.readColor(rgb[0], rgb[1], rgb[2]);
  return rgb;
}

int proxRead() {
  static int proximity;
  if (APDS.proximityAvailable()) proximity = APDS.readProximity();
  return proximity;
}
void IDcheck(){ //funksjonen som skal identisere fargene
  const int baseColor[] = {63,39,29}; //endre dette etter hva farge sensoren måler når ingenting er under
  int* curColor;
  curColor = colorRead();
  
}

void display() {
  int* colorDis;           //om mann skal kalle på farge detektoren, gjør det slikt
  colorDis = colorRead();  //------''-----
  Serial.print("red: ");
  Serial.print(colorDis[0]);
  Serial.print(" ");
  Serial.print("green: ");
  Serial.print(colorDis[1]);
  Serial.print(" ");
  Serial.print("blue: ");
  Serial.print(colorDis[2]);
  Serial.print(" ");
  /*Serial.print("prox: ");
  Serial.println(proxRead());
  Serial.print("count:");
  Serial.println(carCount(proxRead()));*/
  Serial.println();
}

void loop() {
  //colorRead();
  //proxRead();
  potVal = analogRead(potPin); //alt med "pot" i seg er bare for testing, skal fjernes fra ferdig produkt
  if (potVal < 900) display(); //kan starte og stoppe vising av målinger med potmetere (gadd ikke å lage bryter)
  delay(100);
}