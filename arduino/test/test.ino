void setup(){
Serial.begin(9600);
}
void loop(){
 static int hasrun = 1;
 delay(3000);
 if (hasrun == 1){
    Serial.println('boo');
    hasrun = 2;
    delay(500);
 }
 Serial.println('ojoj');
}