const int pushButton = 7;
bool buttonVerdi;
unsigned long currentMillis;
int debounceTimer = 50;
ButtonVerdi = digitalRead(pushButton);

void setup(){
pinMode(pushButton, INPUT);
}

void button(){
    buttonVerdi = digitalRead(pushButton);
    if (buttonVerdi == LOW){
        currentMillis = millis();
    }  
    if((buttonVerdi == HIGH) && (currentMillis - currentMillisOld >= debounceTimer)){
        f
    }
}

void loop(){

}