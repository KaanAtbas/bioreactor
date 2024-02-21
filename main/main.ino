#include <functions.h>

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

    int liqData = readSensorLiq(); //taşma durumu önleyici
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

    int butData = readSensorBut(); //filtresiz tahliye için manuel komut
    if (butData == LOW && stateBut == false)
    {
        pump4Off();
        stateBut = true;
    }
    
    int liqData = readSensorLiq();//sıvı dengeleyici.
    if (liqData == 0 && stateStabilizer == false)
    {
        pump1On();
        stateStabilizer = true;
    }
    int liqData = readSensorLiq();
    if (liqData == 1 && stateStabilizer == true)
    {
        pump1Off();
        stateStabilizer = false;
    }

}