//filtresiz tahliye

// Pin tanımlamaları
const int pompaPin = 2; // Pompanın kontrol pin numarası
const int butonPin = 3; // Butonun bağlı olduğu pin numarası

void setup() {
  pinMode(pompaPin, OUTPUT); // Pompa pinini çıkış olarak ayarla
  pinMode(butonPin, INPUT_PULLUP); // Buton pini giriş olarak ayarla ve dahili pull-up direncini etkinleştir
}

void loop() {
  // Buton durumunu oku
  int butonDurumu = digitalRead(butonPin);

  // Butona basıldığında (HIGH durumunda), pompayı çalıştır
  if (butonDurumu == HIGH) {
    digitalWrite(pompaPin, HIGH); // Pompayı aç
  } else {
    digitalWrite(pompaPin, LOW); // Pompayı kapat
  }
}
