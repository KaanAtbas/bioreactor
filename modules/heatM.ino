#include <OneWire.h>
#include <DallasTemperature.h>





// Sensörün bağlı olduğu pin
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

// Isıtıcının kontrol edildiği pin
int heaterPin = 3; 

void setup(void)
{
  // Serial port başlat
  Serial.begin(9600);
  // DallasTemperature kütüphanesini başlat
  sensors.begin();
  // Isıtıcı pinini çıkış olarak ayarla
  pinMode(heaterPin, OUTPUT);
}

void loop(void)
{ 
  // Sensörlerden sıcaklık oku
  sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0);
  
  Serial.print("Current temperature is: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  // Sıcaklık 35°C'nin altındaysa ısıtıcıyı aç
  if(temperatureC < 35.0){
    digitalWrite(heaterPin, HIGH);
    Serial.println("Heater is ON");
  }
  // Sıcaklık 35°C'nin üstündeyse ısıtıcıyı kapat
  else if(temperatureC > 35.0){
    digitalWrite(heaterPin, LOW);
    Serial.println("Heater is OFF");
  }
  
  // 1 saniye bekle
  delay(1000);
}
