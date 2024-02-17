#define HEAT_PIN 4
void initializeHeat() {
    pinMode(HEAT_PIN, OUTPUT);
}

void heatOn() {
    digitalWrite(HEAT_PIN, HIGH)
}
void heatOff() {
    digitalWrite(HEAT_PIN, LOW)
}

