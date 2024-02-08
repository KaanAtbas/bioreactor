//besiyeri giriş
#define POMPA_PIN 4 // Pompa pin tanımı
#define INTERVAL 3600000 // 1 saat (3600000 milisaniye)

unsigned long previousMillis = 0; // Önceki zaman değişkeni

void setup() {
  pinMode(POMPA_PIN, OUTPUT); // Pompa pinini çıkış olarak ayarla
}

void loop() {
  pompayiKontrolEt();
  // Diğer işlemler buraya yazılabilir
}

void pompa1Calis() {
  unsigned long currentMillis = millis(); // Geçen zamanı al

  // Belirli aralıklarla kontrol et
  if (currentMillis - previousMillis >= INTERVAL) {
    previousMillis = currentMillis; // Zamanı güncelle
    digitalWrite(POMPA_PIN, HIGH); // Pompayı çalıştır
    delay(1000); // Pompanın bir saniye boyunca çalışmasını sağla
    digitalWrite(POMPA_PIN, LOW); // Pompayı durdur
  }
}
