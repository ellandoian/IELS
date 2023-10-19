int LedPin1 = 12;
int LedPin2 = 11;
int LedPin3 = 13;
bool lastButtonState = LOW;
unsigned long blinkMillis;
unsigned long pressTime;
unsigned long checkTime;
int intervall = 500;
int pushButton = 2;
bool valg, longValg, a, b, state = true;
const int longButtonTimer = 2000;

void setup()
{
    pinMode(LedPin1, OUTPUT);
    pinMode(LedPin2, OUTPUT);
    pinMode(LedPin3, OUTPUT);
}

bool longButton() // funksjonen som ser om det er langt knappetrykk
{
    if (b == false) //så lenge b er usann vill de to tids variablene bli opptatert
    {
        checkTime = millis(); 
        pressTime = millis(); 
    }
    if (digitalRead(pushButton) == HIGH) 
    {
        b = true; // setter b til true mens knappen er klikket ned, siden b er sann vil kun pressTime tids variabelen opptaters
        pressTime = millis();
    }
    if ((digitalRead(pushButton) == LOW) && (b == true) && (longButtonTimer <= pressTime - checkTime)) // vil kjøre når knappen slippes og den har blitt holdt nedei lengre enn 2 sekunder
    {                                                                                 
        longValg = !longValg;
        b = false;
    }
    else if ((digitalRead(pushButton) == LOW) && (b == true) && (longButtonTimer >= pressTime - checkTime))
    {
        b = false; //om knappen har blitt holdt nede i mindre enn 2 sekunder vil b bli satt til false uansett, slik at begge tidsvariablene kan oppdateres
    }
    return longValg;
}

bool button() // må initaliserer "valg" og "a" i oppstart
{
    if (digitalRead(pushButton) == HIGH)
    {
        a = true; // setter a til true mens knappen er klikket ned
    }
    if ((digitalRead(pushButton) == LOW) && (a == true)) // vil kjøre når knappen slippes og endrer retur variablen
    {
        valg = !valg;
        a = false;
    }
    return valg;
}

void switcher()
{
    if (longButton() == true) // om det har verdt et lang knappetrykk vil begge lysene lyse, helt til neste gang det er et langt knappetrykk
    {
        digitalWrite(LedPin2, HIGH);
        digitalWrite(LedPin3, HIGH);
    }
    else
    {
        bool a = button();
        if (a != lastButtonState) // om button() har endret seg vil det endres hvilket lys som er på
        {
            digitalWrite(LedPin2, lastButtonState);
            digitalWrite(LedPin3, !lastButtonState);
            lastButtonState = a;
        }
    }
}

void blink()
{
    if (millis() >= blinkMillis + intervall) // kjører hver hver gang intervallet har hendt
    {
        state = !state; // endrer state slik at LED vil blinke
        digitalWrite(LedPin1, state);
        blinkMillis = millis();
    }
}

void loop()
{
    blink();
    switcher();
}