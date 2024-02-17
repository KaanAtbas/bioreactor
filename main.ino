#include "sensorRead.ino"
#include "pumps.ino"
#include "heat.ino"

#define besiyeri_pompası= 8; //besiyeri
#define baz_pompası = 2; //baz
#define tahliye_pompası= 3; //tahliye
#define ldkfsş = 4; //filtresiz tahliye

// bu pompaları bir array de sakla ayrı bir sınıfta da olabilir. o array "pumps" olsun mesela 

void setup() {
    initializeSensors();
    initializePumps(pumps); // pumpsı buraya ver
    initializeHeat();
}

void loop() {
    while (true)
    {
        // if (heat is low) 
            manage_pump(ısı_pompası, ON) 
        //else
            manage_pump(ısı_pompası, OFF) 
    }
    

    
}
