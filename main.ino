#include "sensorRead.ino"
#include "pumps.ino"
#include "heat.ino"

float heatThreshold = 35;
float pHThreshold = 7;

void setup()
{
    initializeSensors();
    initializePumps();
    initializeHeat();
}

void loop()
{
    if (heatData < heatThreshold)
    {
        heatOn();
    }
    else
    {
        heatOff();
    }

    if (pHThreshold < phData)
    {
        pump2On();
        pump3On();
    }
    else
    {
        pump2Off();
        pump3Off();
    }
}