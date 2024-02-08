//ph giriş


// Pin tanımlamaları
#define pH_PIN A0 // pH sensörünün bağlı olduğu analog pin
#define POMPA_PIN 2 // Pompanın bağlı olduğu pin

// pH değeri için eşik değeri
const float pH_EsikDegeri = 7.0;

void setup() {
  Serial.begin(9600); // Seri haberleşmeyi başlat
  pinMode(POMPA_PIN, OUTPUT); // Pompa pini çıkış olarak ayarlanır
}

void loop() {
  int pH_degeri_raw = analogRead(pH_PIN); // pH sensöründen ham değer okunur
  float pH_degeri = map(pH_degeri_raw, 0, 1023, 0, 14); // Ham değer 0-14 aralığında pH değerine dönüştürülür

  Serial.print("pH Degeri: ");
  Serial.println(pH_degeri);

  // Ortam asidikleştiğinde (pH 7'nin altında) pompayı çalıştır
  if (pH_degeri < pH_EsikDegeri) {
    digitalWrite(POMPA_PIN, HIGH); // Pompayı çalıştır
    delay(1000); // Pompayı 1 saniye çalıştır
    digitalWrite(POMPA_PIN, LOW); // Pompayı durdur
  }

  delay(1000); // Her ölçüm arasında kısa bir gecikme
}
