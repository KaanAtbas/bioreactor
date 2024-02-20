#include <functions.h>

float heatThreshold = 35;
float pHThreshold = 7;
bool stateHeat = false;
bool statePh = false;
const unsigned long interval = 21600000;
unsigned long previousMillis = 0;
bool stateTime = false;
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
    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;
        pump1On();
        pump3On();
        //ne kadar süre çalışması gerektiği hesaplanıp ona göre tekrar kodlanacak
    
    }
    

}