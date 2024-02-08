#include <OneWire.h>
#include <DallasTemperature.h>

// Pin tanımlamaları
#define ONE_WIRE_BUS 2 // Dallas sıcaklık sensörünün bağlı olduğu pin
#define ISITICI_PIN 3 // Isıtıcı pin

// Sıcaklık sensörü nesnesi oluşturuluyor
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Sıcaklık limitleri (örnek olarak belirlenmiştir, gerçek değerler projenize göre ayarlanmalıdır)
float sicaklikLimitAlt = 20; // Isıtıcıyı açmak için alt limit
float sicaklikLimitUst = 25; // Isıtıcıyı kapatmak için üst limit

// Zamanlama değişkenleri
unsigned long previousMillis = 0;
const long interval = 1000; // 1 saniyelik zaman aralığı

// Sıcaklık kontrol fonksiyonu
void sicaklikKontrol() {
  unsigned long currentMillis = millis(); // Geçen süre hesaplanıyor

  // Belirli aralıklarla sıcaklık kontrolü yapılıyor
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // Zamanı güncelle

    // Sıcaklık sensöründen veri okunuyor
    sensors.requestTemperatures();
    float sicaklik = sensors.getTempCByIndex(0);

    // Sıcaklık kontrolü
    if (!isnan(sicaklik)) {
      if (sicaklik < sicaklikLimitAlt) {
        // Sıcaklık alt limitin altındaysa ısıtıcıyı aç
        digitalWrite(ISITICI_PIN, HIGH);
      } else if (sicaklik > sicaklikLimitUst) {
        // Sıcaklık üst limitin üstündeyse ısıtıcıyı kapat
        digitalWrite(ISITICI_PIN, LOW);
      }
    }

    // Sıcaklık değeri seri porta yazdırılıyor
    Serial.print("Sicaklik: ");
    Serial.print(sicaklik);
    Serial.println(" °C");
  }
}

void setup() {
  Serial.begin(9600); // Seri haberleşme başlatılıyor
  sensors.begin(); // Sıcaklık sensörü başlatılıyor
  pinMode(ISITICI_PIN, OUTPUT); // Isıtıcı pin çıkış olarak ayarlanıyor
}

void loop() {
  sicaklikKontrol();
  // Diğer işlemler buraya yazılabilir
}
