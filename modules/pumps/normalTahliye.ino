#define POMPA_TAHLIYE = 8;

void setup() {
    pinMode(POMPA_TAHLIYE, OUTPUT); //Pompa tahliye 
}

void pompaTahliyeCalistir(){
    digitalWrite(POMPA_TAHLIYE, HIGH);
    
}