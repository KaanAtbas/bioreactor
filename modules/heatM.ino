#include <OneWire.h>
#include <DallasTemperature.h>

// Pin tanımlamaları
#define ONE_WIRE_BUS 2 // Dallas sıcaklık sensörünün bağlı olduğu pin
#define ISITICI_PIN 3 // Isıtıcı pin

// Sıcaklık sensörü nesnesi oluşturuluyor
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Sıcaklık limitleri (örnek olarak belirlenmiştir, gerçek değerler projenize göre ayarlanmalıdır)
float sicaklikLimitAlt = 35; // Isıtıcıyı açmak için alt limit
float sicaklikLimitUst = 36; // Isıtıcıyı kapatmak için üst limit
void setup() {
  Serial.begin(9600); // Seri haberleşme başlatılıyor
  sensors.begin(); // Sıcaklık sensörü başlatılıyor
  pinMode(ISITICI_PIN, OUTPUT); // Isıtıcı pin çıkış olarak ayarlanıyor
}

void aa(){
  sensors.requestTemperatures();
    float sicaklik = sensors.getTempCByIndex(0);
      if (sicaklik < sicaklikLimitAlt) {
        // Sıcaklık alt limitin altındaysa ısıtıcıyı aç
        digitalWrite(ISITICI_PIN, HIGH);
      } else if (sicaklik >= sicaklikLimitUst) {
        // Sıcaklık üst limitin üstündeyse ısıtıcıyı kapat
        digitalWrite(ISITICI_PIN, LOW);
  
      }
      delay(100);
  

}

void loop () {
  
  aaa();

}
    

    // Sıcaklık değeri seri porta yazdırılıyor
    Serial.print("Sicaklik: ");
    Serial.print(sicaklik);
    Serial.println(" °C");
  }
}

