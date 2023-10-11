# 1 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\lysFolger\\lysFolger.ino"
# 2 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\lysFolger\\lysFolger.ino" 2







int bigLight;
int bigIndex;

Servo servoLow;
Servo servoHigh;
int lightArray[4];

void setup() {
    Serial.begin(9600);
    servoLow.attach(8, -180, 180);
    servoHigh.attach(7, -180, 180);
    pinMode(A3, 0x0);
    pinMode(A2, 0x0);
    pinMode(A1, 0x0);
    pinMode(A2, 0x0);
}

void light() {
    lightArray[0]=analogRead(A3);
    lightArray[1]=analogRead(A2);
    lightArray[2]=analogRead(A1);
    lightArray[3]=analogRead(A0);
    bigLight=0;
    bigIndex=0;
    for (int i=0; i<4; i++) {
        Serial.println(i);
        if (lightArray[i] > bigLight) {
            bigLight=lightArray[i];
            bigIndex=i;
        }
    }


}

void loop() {
    servoLow.write(30);
    servoHigh.write(120);
    light();
}
