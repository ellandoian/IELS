#include <Zumo32U4.h>
#include <Wire.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;
Zumo32U4ButtonC buttonC;
Zumo32U4IMU imu;
Zumo32U4OLED display;
bool b = true;
#include "TurnSensor.h"
int deg90Check;

void turn90old(int x)
{
    int i = 1;
    while (i <= x)
    {
        motors.setSpeeds(-100, 100);
        while ((int32_t)turnAngle < (turnAngle1*88))
        {
            turnSensorUpdate();
        }
        turnSensorReset();
        motors.setSpeeds(0, 0);
        i++;
    }
}

void square()
{
    unsigned long time = millis();
    static int check, prevCheck;
    for (int i = 0; i <= 4; i)
    {
        motors.setSpeeds(150, 150);
        if ((millis() - 2500) > time)
        {
            motors.setSpeeds(0, 0);
            delay(100);
            turn90old(1);
            time = millis();
            i++;
        }
    }
}

void turn90()
{
    motors.setSpeeds(-100, 100);
    turnSensorUpdate();
    if (turnAngle > (turnAngle1 * 88))
    {
        motors.setSpeeds(0, 0);
        turnSensorReset();
        deg90Check++;
    }
}

void setup()
{
    Serial.begin(9600);
    turnSensorSetup();
}

void loop()
{
    square();
}