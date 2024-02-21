#include <OneWire.h>
#include <DallasTemperature.h>

#define HEAT_PIN 4
#define PUMP_1 8 // besiyeri
#define PUMP_2 2 // baz
#define PUMP_3 3 // tahliye
#define PUMP_4 4 // filtresiz tahliye
#define pH_PIN 2
#define heat_PIN 3
#define liq_PIN 4
#define but_PIN 5

float heatThreshold = 35;
float pHThreshold = 7;
bool stateHeat = false;
bool statePh = false;
const unsigned long interval = 21600000;
unsigned long previousMillis = 0;
bool statePump = false;
const unsigned long intervalPump = 600000;
bool stateOverflow = true;
bool stateBut = true;
bool stateStabilizer = false;

OneWire oneWire(heat_PIN);
DallasTemperature sensors(&oneWire);

void initializeHeat() {
    pinMode(HEAT_PIN, OUTPUT);
}

void heatOn() {
    digitalWrite(HEAT_PIN, HIGH);
}
void heatOff() {
    digitalWrite(HEAT_PIN, LOW);
}
void initializePumps()
{
    pinMode(PUMP_1, OUTPUT);
    pinMode(PUMP_2, OUTPUT);
    pinMode(PUMP_3, OUTPUT);
    pinMode(PUMP_4, OUTPUT);
}
void pump1On()
{
    digitalWrite(PUMP_1, HIGH);
}

void pump1Off()
{
    digitalWrite(PUMP_1, LOW);
}

void pump2On()
{
    digitalWrite(PUMP_2, HIGH);
}

void pump2Off()
{
    digitalWrite(PUMP_2, LOW);
}

void pump3On()
{
    digitalWrite(PUMP_3, HIGH);
}

void pump3Off()
{
    digitalWrite(PUMP_3, LOW);
}

void pump4On()
{
    digitalWrite(PUMP_4, HIGH);
}
void pump4Off()
{
    digitalWrite(PUMP_4, LOW);
}
void initializeSensors()
{
    Serial.begin(9600);
    sensors.begin();
    pinMode(pH_PIN, INPUT);
    pinMode(liq_PIN, INPUT);
    pinMode(but_PIN, INPUT);
}

int readSensorBut() {
    int sensorValue = digitalRead(but_PIN);
    return sensorValue;
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

int butData = readSensorBut();
float phData = readSensorPh();
float heatData = readSensorHeat();
int liqData = readSensorLiq();

void setup()
{
    initializeSensors();
    initializePumps();
    initializeHeat();
}

void loop()
{
    unsigned long currentMillis = millis();

    if (heatData < heatThreshold && !stateHeat)
    {
        heatOn();
        stateHeat = true;
    }
    else if (heatData >= heatThreshold && stateHeat)
    {
        heatOff();
        stateHeat = false;
    }

    if (pHThreshold < phData && !statePh)
    {
        pump2On();
        pump3On();
        statePh = true;
    }
    else if (phData >= pHThreshold && statePh)
    {
        pump2Off();
        pump3Off();
        statePh = false;
    }
    if ((currentMillis - previousMillis >= interval) && statePump == false) // önceden tanımlanmış zaman aralığında otomatik pompa aç
    {
        previousMillis = currentMillis;
        pump1On();
        pump3On();
        statePump = true;
    
    }
    if ((currentMillis >= (previousMillis + intervalPump)) && statePump == true) //// önceden tanımlanmış zaman aralığında otomatik pompa kapat
    {
        pump1Off();
        pump3Off();
        statePump = false;
    }

    int liqData = readSensorLiq(); //taşma durumu önleyici
    if (liqData == 1 && stateOverflow == true)
    {
        pump3On();
        stateOverflow = false;
    }
    if (liqData == 0 && stateOverflow == false)
    {
        pump3Off();
        stateOverflow = true;
    }

    int butData = readSensorBut(); //filtresiz tahliye için manuel komut
    if (butData == HIGH && stateBut == true)
    {
        pump4On();
        stateBut = false;
    }
    if (butData == LOW && stateBut == false)
    {
        pump4Off();
        stateBut = true;
    }
    
    if (liqData == 0 && stateStabilizer == false)
    {
        pump1On();
        stateStabilizer = true;
    }
    if (liqData == 1 && stateStabilizer == true)
    {
        pump1Off();
        stateStabilizer = false;
    }

}
