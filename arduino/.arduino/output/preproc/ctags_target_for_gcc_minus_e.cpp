# 1 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\zumoBatteri\\zumoBatteri.ino"
# 2 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\zumoBatteri\\zumoBatteri.ino" 2
# 3 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\zumoBatteri\\zumoBatteri.ino" 2
# 4 "C:\\Users\\ellan\\Documents\\iesl1001\\arduino\\zumoBatteri\\zumoBatteri.ino" 2

U8G2_SSD1306_128X64_NONAME_1_4W_SW_SPI u8g2((&u8g2_cb_r0), /* clock=*/13, /* data=*/11, /* cs=*/10, /* dc=*/9, /* reset=*/8);

int voltSensor = A0;
int potMeter = A1;
float temperatur;
int pushButton = 7;
bool buttonValue = false;
float voltage;
bool valg = 0;
bool a = false;

void setup()
{
    Serial.begin(9600);
    u8g2.begin();
    pinMode(pushButton, 0x0);
}

void button()
{
    if (digitalRead(pushButton) == 0x1)
    {
        a = true;
        Serial.print("a");
    }
    if ((digitalRead(pushButton) == 0x0) && (a == true))
    {
        valg != valg;
        a = false;
        Serial.print("b");
    }
}

void voltReader()
{
    int sensorValue = analogRead(voltSensor);
    voltage = sensorValue * (5.0 / 1023.0);
}

void potMeterMaaler()
{
    int potMeterValue = analogRead(potMeter);
    temperatur = potMeterValue * (30.0 / 1023.0);
    Serial.println(temperatur);
    delay(300);
}

void skjerm()
{
    button();
    if (valg == false)
    {
        u8g2.firstPage();
        do
        {
            voltReader();
            u8g2.setFont(u8g2_font_ncenB14_tr);
            u8g2.drawRFrame(5, 13, 90, 22, 7);
            u8g2.setCursor(55, 32);
            u8g2.print(voltage);
            u8g2.drawStr(10, 32, "V =");
        } while (u8g2.nextPage());
    }
    if (valg == true)
    {
        u8g2.firstPage();
        do
        {
            potMeterMaaler();
            u8g2.setFont(u8g2_font_ncenB14_tr);
            u8g2.drawRFrame(5, 13, 90, 22, 7);
            u8g2.setCursor(55, 32);
            u8g2.print(temperatur);
            u8g2.drawStr(10, 32, "T =");
        } while (u8g2.nextPage());
    }
}


void loop()
{
    // potMeterMaaler();
    //  voltReader();
    skjerm();
}
