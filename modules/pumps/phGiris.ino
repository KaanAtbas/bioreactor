//ph giriş


// Pin tanımlamaları
#define pH_PIN A0 // pH sensörünün bağlı olduğu analog pin
#define POMPA_BAZ 2 // Pompanın bağlı olduğu pin

// pH değeri için eşik değeri
const float pH_EsikDegeri = 7.0;

void setup() {
  Serial.begin(9600); // Seri haberleşmeyi başlat
  pinMode(POMPA_BAZ, OUTPUT); // Pompa pini çıkış olarak ayarlanır
}

void loop() {
  float pH_degeri = digitalRead(pH_PIN); // pH sensöründen ham değer okunur

  Serial.print("pH Degeri: ");
  Serial.println(pH_degeri);

  // Ortam asidikleştiğinde (pH 7'nin altında) pompayı çalıştır
  if (pH_degeri < pH_EsikDegeri) {
    digitalWrite(POMPA_BAZ, HIGH); // Pompayı çalıştır
    delay(1000); // Pompayı 1 saniye çalıştır
    digitalWrite(POMPA_BAZ, LOW); // Pompayı durdur
  }

  delay(1000); // Her ölçüm arasında kısa bir gecikme
}
