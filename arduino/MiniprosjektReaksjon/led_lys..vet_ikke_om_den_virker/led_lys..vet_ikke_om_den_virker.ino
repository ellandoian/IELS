// det er bygd på C++ code
//
const int D1 = 1; 
const int D2 = 2; 
const int D3 = 3; 
const int D4 = 4; 
const int pushButton = 0;

const int D11 = 11;

int buttonState = 0;
int loopCounter = 0;


void slidePaa()
{
  digitalWrite(1, HIGH);
  delay(500);
  digitalWrite(D2, HIGH);
  delay(500);
  digitalWrite(D3, HIGH);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(D4, HIGH);
  delay(500);
  
}
void slideAv ()
{
 digitalWrite(D1, LOW);
 delay(500);
 digitalWrite(D2, LOW);
 delay(500);
 digitalWrite(D3, LOW);
 delay(500); // Wait for 1000 millisecond(s)
 digitalWrite(D4, LOW); 
}
void ferdigLoop()
{
  delay(500);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  delay(250);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  delay(500);
  Serial.print("showet har repertert seg så mange ganger:");
  Serial.println(loopCounter);
}

void setup()
{
  Serial.begin(9600);
  pinMode(D11, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(pushButton, INPUT);
}

void loop()
{
  buttonState = digitalRead(pushButton); //kjekker om knappen er klikket
  if(buttonState == HIGH) {
	digitalWrite(D11, HIGH);
  } 
  else 
  {
    digitalWrite(D11, LOW);
  }
  slidePaa();
  slideAv();
  loopCounter++;
  ferdigLoop();
  
  delay(3000);
}