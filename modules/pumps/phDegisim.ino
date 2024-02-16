//ph değişim
#include <normalTahliye.ino>


// Pin tanımlamaları
#define pH_PIN A0 // pH sensörünün bağlı olduğu analog pin
#define POMPA_BAZ 2 // Pompanın bağlı olduğu pin

// pH değeri için eşik değeri
const float pH_EsikDegeri = 7.0;

void setup() {
  Serial.begin(9600); // Seri haberleşmeyi başlat
  pinMode(POMPA_BAZ, OUTPUT); // Pompa pini çıkış olarak ayarlanır
}

void phDegisim() {
  float pH_degeri = digitalRead(pH_PIN); // pH sensöründen ham değer okunur

  Serial.print("pH Degeri: ");
  Serial.println(pH_degeri);

  // Ortam asidikleştiğinde (pH 7'nin altında) pompayı çalıştır
  if (pH_degeri < pH_EsikDegeri) {
    digitalWrite(POMPA_BAZ, HIGH); // Baz Pompayı çalıştır
    digitalWrite(POMPA_TAHLIYE, HIGH); // Tahliye Pompayı çalıştır
    delay(1000); // Pompayı 1 saniye çalıştır
    digitalWrite(POMPA_BAZ, LOW); // Pompayı durdur
    digitalWrite(POMPA_TAHLIYE,LOW); //Tahliye pompası dur
  }

  delay(1000); // Her ölçüm arasında kısa bir gecikme
}
