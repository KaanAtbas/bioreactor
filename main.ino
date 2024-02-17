#include "sensorRead.ino"
#include "pumps.ino"
#include "heat.ino"

float heatThreshold = 35;
float pHThreshold = 7;
bool stateHeat = false;
bool statePh = false;

void setup()
{
    initializeSensors();
    initializePumps();
    initializeHeat();
}

void loop()
{
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
}