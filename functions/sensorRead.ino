#include <OneWire.h>
#include <DallasTemperature.h>
#define pH_PIN 2
#define heat_PIN 3
#define liq_PIN 4
OneWire oneWire(heat_PIN);
DallasTemperature sensors(&oneWire);

void initializeSensors()
{
    Serial.begin(9600);
    sensors.begin();
    pinMode(pH_PIN, INPUT)
    pinMode(liq_PIN, INPUT)
}

float readSensorPh()
{
    float sensorValue = digitalRead(pH_PIN); // buraya ph sensörü
    return sensorValue;
}

float readSensorHeat()
{
    sensors.requestTemperatures();
    float sensorValue = sensors.getTempCByIndex(0);
    return sensorValue;
}

int readSensorLiq()
{
    int sensorValue = digitalRead(liq_PIN);
    return sensorValue;
}
float phData = readSensorPh();
float heatData = readSensorHeat();
int liqData = readSensorLiq();
