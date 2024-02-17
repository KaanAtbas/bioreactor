#define PUMP_1 8 // besiyeri
#define PUMP_2 2 // baz
#define PUMP_3 3 // tahliye
#define PUMP_4 4 // filtresiz tahliye

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
